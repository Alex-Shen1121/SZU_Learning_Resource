// #include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;

// 有m篇论文和n个评审，每篇论文需要安排a个评审，每个评审最多评b篇论文。
#define a 100
#define b 100
#define m 100
#define n 100

const int inf = 0x7fffffff;
struct EDGE
{
    int v;   //通往结点
    int c;   //路径容量
    int rev; //反向连接点
};

vector<EDGE> edge[m + n + 2];
queue<int> q;
int level[m + n + 2]; //分层图各个结点的等级
int iter[m + n + 2];  //弧优化

void bfs() //一个普通的bfs，记录每个点被发现的顺序
{
    memset(level, -1, sizeof(level));
    level[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < edge[u].size(); ++i)
        {
            EDGE &e = edge[u][i];
            if (e.c > 0 && level[e.v] == -1)
            {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
}
int dfs(int u, int f)
{
    if (u == m + n + 1)
        return f;
    for (int &i = iter[u]; i < edge[u].size(); ++i) //弧优化，标记结点u没有遍历的位置，避免重复搜索
    {
        EDGE &e = edge[u][i];
        if (e.c > 0 && level[e.v] > level[u])
        {
            int d = dfs(e.v, min(f, e.c)); //迭代寻找这条路径流的大小。
            if (d > 0)
            {
                e.c -= d;
                edge[e.v][e.rev].c += d;
                return d;
            }
        }
    }
    return 0;
}

void init()
{
    for (int i = 1; i <= m; i++)
    {
        EDGE in;
        in.v = i, in.c = a, in.rev = edge[i].size();
        edge[0].push_back(in);
        in.v = 0, in.c = 0, in.rev = edge[0].size() - 1;
        edge[i].push_back(in); //为建立方向边做准备;
    }
    for (int i = 1; i <= m; i++)
        for (int j = m + 1; j <= m + n; j++)
        {
            EDGE in;
            in.v = j, in.c = 1, in.rev = edge[j].size();
            edge[i].push_back(in);
            in.v = i, in.c = 0, in.rev = edge[i].size() - 1;
            edge[j].push_back(in); //为建立方向边做准备;
        }
    for (int i = m + 1; i <= m + n; i++)
    {
        EDGE in;
        in.v = m + n + 1, in.c = b, in.rev = edge[m + n + 1].size();
        edge[i].push_back(in);
        in.v = i, in.c = 0, in.rev = edge[i].size() - 1;
        edge[m + n + 1].push_back(in); //为建立方向边做准备;
    }
}

int Dinic()
{
    int sumflow = 0;
    while (1)
    {
        bfs(); //预处理，对图分层
        if (level[m + n + 1] < 0)
            break;                     //判断是否能连通汇点
        memset(iter, 0, sizeof(iter)); //初始化弧
        int addflow;
        while (1) //迭代找最短增广路
        {
            addflow = dfs(0, inf);
            if (!addflow)
                break;
            sumflow += addflow;
        }
    }
    return sumflow;
}

int main()
{
    init();
    auto starttime = clock();
    cout << "Max Flow = " << Dinic() << endl;
    cout << "时间为：" << clock() - starttime << endl;
    return 0;
}
