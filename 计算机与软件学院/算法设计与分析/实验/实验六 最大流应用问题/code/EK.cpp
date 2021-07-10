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
int edge[m + n + 2][m + n + 2]; //邻接矩阵存边的权值，附带建立反边
int flow[m + n + 2];            //记录增广路径上的最小流
int pre[m + n + 2];             //记录增广路径上每个点的前驱，并且判断是否连通到汇点

int bfs() //bfs搜索增广路径
{
    memset(pre, -1, sizeof(pre));
    queue<int> q; //bfs常规操作
    pre[0] = 0;
    flow[0] = inf;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == m + n + 1)
            break;
        for (int i = 0; i <= m + n + 1; ++i)
        {
            if (i != 0 && edge[u][i] > 0 && pre[i] == -1) //寻找能够增广的结点
            {
                pre[i] = u;                         //记录前驱
                flow[i] = min(flow[u], edge[u][i]); //迭代出合适的流的大小
                q.push(i);
            }
        }
    }
    if (pre[m + n + 1] == -1)
        return -1; //判断是否连通到汇点
    return flow[m + n + 1];
}

int Edmond_Karp()
{
    int addflow = 0;
    int sumflow = 0;
    while (addflow = bfs() != -1) //寻找增广路径，当无增广路径时结束循环
    {
        int node = m + n + 1;
        while (node != 0) //通过查看前驱，找到增广路径上的每一条边和点，并减少边的容量和建立反边
        {
            int last = pre[node];
            edge[node][last] += addflow;
            edge[last][node] -= addflow;
            node = last;
        }
        sumflow += addflow;
    }
    return sumflow;
}

void init()
{
    for (int i = 1; i <= m; i++)
        edge[0][i] = a;

    for (int i = 1; i <= m; i++)
        for (int j = m + 1; j <= m + n; j++)
            edge[i][j] = 1;
    for (int i = m + 1; i <= m + n; i++)
        edge[i][m + n + 1] = b;
}

int main()
{
    init();
    auto starttime = clock();
    cout << "Max Flow = " << Edmond_Karp() << endl;
    cout << "时间为：" << clock() - starttime << endl;

    return 0;
}
