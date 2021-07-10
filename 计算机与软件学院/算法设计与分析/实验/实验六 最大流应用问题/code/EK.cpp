// #include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;

// ��mƪ���ĺ�n������ÿƪ������Ҫ����a������ÿ�����������bƪ���ġ�
#define a 100
#define b 100
#define m 100
#define n 100

const int inf = 0x7fffffff;
int edge[m + n + 2][m + n + 2]; //�ڽӾ����ߵ�Ȩֵ��������������
int flow[m + n + 2];            //��¼����·���ϵ���С��
int pre[m + n + 2];             //��¼����·����ÿ�����ǰ���������ж��Ƿ���ͨ�����

int bfs() //bfs��������·��
{
    memset(pre, -1, sizeof(pre));
    queue<int> q; //bfs�������
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
            if (i != 0 && edge[u][i] > 0 && pre[i] == -1) //Ѱ���ܹ�����Ľ��
            {
                pre[i] = u;                         //��¼ǰ��
                flow[i] = min(flow[u], edge[u][i]); //���������ʵ����Ĵ�С
                q.push(i);
            }
        }
    }
    if (pre[m + n + 1] == -1)
        return -1; //�ж��Ƿ���ͨ�����
    return flow[m + n + 1];
}

int Edmond_Karp()
{
    int addflow = 0;
    int sumflow = 0;
    while (addflow = bfs() != -1) //Ѱ������·������������·��ʱ����ѭ��
    {
        int node = m + n + 1;
        while (node != 0) //ͨ���鿴ǰ�����ҵ�����·���ϵ�ÿһ���ߺ͵㣬�����ٱߵ������ͽ�������
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
    cout << "ʱ��Ϊ��" << clock() - starttime << endl;

    return 0;
}
