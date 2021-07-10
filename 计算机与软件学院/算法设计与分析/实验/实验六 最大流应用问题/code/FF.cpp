// #include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#include <vector>
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// ��mƪ���ĺ�n������ÿƪ������Ҫ����a������ÿ�����������bƪ���ġ�
#define a 5
#define b 100
#define m 1000
#define n 100

const int inf = 0x7fffffff;
struct EDGE
{
    int v;   //ͨ�����
    int c;   //·������
    int rev; //�������ӵ�
};

vector<EDGE> edge[m + n + 2];

bool vis[m + n + 2]; //DFSʱ��¼���ķ������

int dfs(int u, int f)
{
    if (u == m + n + 1)
        return f;
    vis[u] = true;
    for (int i = 0; i < edge[u].size(); ++i)
    {
        EDGE &e = edge[u][i];
        if (!vis[e.v] && e.c > 0)
        {
            int d = dfs(e.v, min(f, e.c)); //���ϸ�������·������С����
            if (d > 0)
            {
                // cout << e.v << ' ';
                e.c -= d;
                edge[e.v][e.rev].c += d; //�ҵ���f֮�󣬻��ݸ��·��ߵ���
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
        edge[i].push_back(in); //Ϊ�����������׼��;
    }
    for (int i = 1; i <= m; i++)
        for (int j = m + 1; j <= m + n; j++)
        {
            EDGE in;
            in.v = j, in.c = 1, in.rev = edge[j].size();
            edge[i].push_back(in);
            in.v = i, in.c = 0, in.rev = edge[i].size() - 1;
            edge[j].push_back(in); //Ϊ�����������׼��;
        }
    for (int i = m + 1; i <= m + n; i++)
    {
        EDGE in;
        in.v = m + n + 1, in.c = b, in.rev = edge[m + n + 1].size();
        edge[i].push_back(in);
        in.v = i, in.c = 0, in.rev = edge[i].size() - 1;
        edge[m + n + 1].push_back(in); //Ϊ�����������׼��;
    }
}

int Ford_Fulkerson()
{
    int flow = 0;
    while (1) //����ѭ������·�����ۼ���
    {
        memset(vis, 0, sizeof(vis));
        int f = dfs(0, inf);
        if (!f)
            break;
        // cout << endl;
        flow += f;
    }
    return flow;
}

int main()
{
    init();
    auto starttime = clock();
    cout << "Max Flow = " << Ford_Fulkerson() << endl;
    cout << "ʱ��Ϊ��" << clock() - starttime << endl;
    return 0;
}
