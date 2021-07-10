#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <algorithm>
#include <ratio>
#include <queue>
#include <bitset>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <map>
#include <cstdlib>
// #include <Windows.h>
#include <ctime>
#include <climits>
using namespace std;
using namespace chrono;

// ��¼ʱ��
clock_t start_time, end_time;
// dfs visited����
bool *visited;
// ���鼯
int *parent;
int *RANK;
bool *edge_visited;
bool *is_MST;
int *parent2;
int *RANK2;
#define FILENAME "./dataset/300_1.txt"
// ������ͨ�����Ļ�׼��
void Basic_DFS();
// �ҽ���׼��
void Improved_DFS();
// ���鼯����ͨ��֧
void Union();
// ���鼯����ͨ��֧+��
void Union2();
// ��׼��+������
void Basic_MST_DFS();
// ��׼��+������+����׼
void Basic_MST_IMPROVED_DFS();
// ������+���鼯����ͨ��֧
void Union_MST();
// ������+���鼯����ͨ��֧+��
void Union2_MST();
// lca�㷨
void LCA();
void LCA2();
void BFS_LCA();
// �����ڽӱ������ͨ��֧
int connection_count(vector<int> *Adj_List, int v);
// visited�����ʼ��Ϊn
void visited_init(int n);
// �����������������׼��
void DFS(int i, vector<int> *&Adj_List, int);
// ������С������
void MST_CREATE(vector<int> *&Adj_List, vector<int> *&MST, int v, vector<vector<int>> &edges);
// ���������������MST����
void MST_DFS(int i, int pre, vector<int> *&Adj_List, vector<int> *&MST, int v, vector<vector<int>> &edges);

int main()
{
    // // ������ͨ�����Ļ�׼��
    // Basic_DFS();

    // // �ҽ���׼��
    // Improved_DFS();

    // // ���鼯+·��ѹ��
    // Union();

    // // ���鼯+·��ѹ��+ƽ����
    // Union2();

    // // ������+��׼��
    // Basic_MST_DFS();

    // // ������+��׼���
    // Basic_MST_IMPROVED_DFS();

    // // ������+���鼯����ͨ��֧
    // Union_MST();
    // // ������+���鼯����ͨ��֧+��
    // Union2_MST();

    // // LCA�㷨
    // LCA();

    // LCA2();

    // BFS+LCA �����д����ݼ�
    BFS_LCA();

    return 0;
}

// �����ڽӱ������ͨ��֧
int connection_count(vector<int> *Adj_List, int v)
{
    // int v = Adj_List.size();
    // ��ͨ��֧����
    int cnt = 0;
    visited_init(v);
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
        {
            DFS(i, Adj_List, v);
            cnt++;
        }
    return cnt;
}

// visited�����ʼ��Ϊn
void visited_init(int n)
{
    visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
}

// �����������������׼��
void DFS(int i, vector<int> *&Adj_List, int v)
{
    visited[i] = true;
    for (int next : Adj_List[i])
    {
        if (visited[next] == false)
            DFS(next, Adj_List, v);
    }
}

// ��׼��
void Basic_DFS()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    start_time = clock();
    int bridge_cnt = 0;
    // �����ʼ��ͨ��֧����
    int before = connection_count(Adj_List, v);
    // int k = 0;
    for (auto x : edges)
    {
        // ɾ����
        int v1 = x[0], v2 = x[1];

        Adj_List[v1].erase(remove(Adj_List[v1].begin(), Adj_List[v1].end(), v2), Adj_List[v1].end());
        Adj_List[v2].erase(remove(Adj_List[v2].begin(), Adj_List[v2].end(), v1), Adj_List[v2].end());

        // ����ɾ������ͨ��֧����
        int after = connection_count(Adj_List, v);

        // �����ͨ��֧�����ӣ�˵������
        if (after > before)
        {
            bridge_cnt++;
        }

        // �ָ���
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);
    }
    end_time = clock();
    cout << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}   

// �ҽ���׼��
void Improved_DFS()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    start_time = clock();
    int bridge_cnt = 0;
    for (auto x : edges)
    {
        // ɾ����
        int v1 = x[0], v2 = x[1];

        Adj_List[v1].erase(remove(Adj_List[v1].begin(), Adj_List[v1].end(), v2), Adj_List[v1].end());
        Adj_List[v2].erase(remove(Adj_List[v2].begin(), Adj_List[v2].end(), v1), Adj_List[v2].end());

        visited_init(v);
        DFS(v1, Adj_List, v);
        if (visited[v2] == false)
            bridge_cnt++;

        // �ָ���
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);
    }
    end_time = clock();
    cout << endl
         << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}

int getparent(int x)
{
    // if (parent[x] == x)
    //     return x;
    // parent[x] = getparent(parent[x]);
    // return parent[x];
    // return getparent(parent[x]);
    return x == parent[x] ? x : (parent[x] = getparent(parent[x]));
}

int getparent2(int x)
{
    if (parent[x] == x)
        return x;
    else
        return getparent2(parent[x]);
}

void myUnion(int a, int b, int &n)
{
    int fx, fy;
    fx = getparent(a);
    fy = getparent(b);
    if (fx != fy)
    {
        parent[fx] = fy;
        n--;
    }
}

// ���鼯+·��
void Union()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    parent = new int[v];
    start_time = clock();
    int before = v;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    for (auto x : edges)
        myUnion(x[0], x[1], before);

    int bridge_cnt = 0, after = v;
    for (auto x : edges)
    {

        for (int i = 0; i < v; i++)
            parent[i] = i;
        after = v;
        for (auto edge : edges)
        {
            int v1_ = edge[0], v2_ = edge[1];
            if (x == edge)
                continue;
            myUnion(v1_, v2_, after);
        }

        if (after > before)
            bridge_cnt++;
    }
    end_time = clock();
    cout << endl
         << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}

void myUnion2(int a, int b, int &n)
{
    int x = getparent(a), y = getparent(b);
    if (x != y)
        n--;
    if (RANK[x] <= RANK[y])
        parent[x] = y;
    else
        parent[y] = x;
    if (RANK[x] == RANK[y] && x != y)
    {
        RANK[y]++;
    }
}

// ���鼯+·��+ƽ����
void Union2()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    parent = new int[v];
    RANK = new int[v];
    start_time = clock();
    int before = v;
    for (int i = 0; i < v; i++)
    {
        RANK[i] = 1;
        parent[i] = i;
    }
    for (auto x : edges)
        myUnion2(x[0], x[1], before);

    int bridge_cnt = 0,
        after = v;
    for (auto x : edges)
    {

        for (int i = 0; i < v; i++)
        {
            RANK[i] = 1;
            parent[i] = i;
        }
        after = v;
        for (auto edge : edges)
        {
            int v1_ = edge[0], v2_ = edge[1];
            if (x == edge)
                continue;
            myUnion2(v1_, v2_, after);
        }

        if (after > before)
            bridge_cnt++;
    }
    end_time = clock();
    cout << endl
         << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl
         << endl;
}

// ���������������MST����
void MST_DFS(int i, int pre, vector<int> *&Adj_List, vector<int> *&MST, int v, vector<vector<int>> &edges)
{
    if (pre != -1)
    {
        if (pre <= i)
            edges.push_back(vector<int>{pre, i});
        else
            edges.push_back(vector<int>{i, pre});
        MST[pre].push_back(i);
        MST[i].push_back(pre);
    }
    visited[i] = true;
    for (int next : Adj_List[i])
    {
        if (visited[next] == false)
        {
            MST_DFS(next, i, Adj_List, MST, v, edges);
        }
    }
}

// ������С������
void MST_CREATE(vector<int> *&Adj_List, vector<int> *&MST, int v, vector<vector<int>> &edges)
{
    int cnt = 0;
    visited_init(v);
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
        {
            MST_DFS(i, -1, Adj_List, MST, v, edges);
        }
}

// ��׼��+������
void Basic_MST_DFS()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    vector<int> *MST;
    Adj_List = new vector<int>[v];
    MST = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        // if (n1 == n2)
        //     continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    start_time = clock();
    int bridge_cnt = 0;
    MST_CREATE(Adj_List, MST, v, edges);
    // �����ʼ��ͨ��֧����
    int before = connection_count(Adj_List, v);
    // cout << before << endl;
    // int k = 0;
    for (auto x : edges)
    {
        // ɾ����
        int v1 = x[0], v2 = x[1];

        Adj_List[v1].erase(remove(Adj_List[v1].begin(), Adj_List[v1].end(), v2), Adj_List[v1].end());
        Adj_List[v2].erase(remove(Adj_List[v2].begin(), Adj_List[v2].end(), v1), Adj_List[v2].end());

        // ����ɾ������ͨ��֧����
        int after = connection_count(Adj_List, v);
        // cout << after << endl;

        // �����ͨ��֧�����ӣ�˵������
        if (after > before)
        {
            bridge_cnt++;
        }

        // �ָ���
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);
    }
    end_time = clock();
    cout << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}

// ��׼��+������+����׼
void Basic_MST_IMPROVED_DFS()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    vector<int> *MST;
    Adj_List = new vector<int>[v];
    MST = new vector<int>[v];
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        // if (n1 == n2)
        //     continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    start_time = clock();
    int bridge_cnt = 0;
    MST_CREATE(Adj_List, MST, v, edges);
    // �����ʼ��ͨ��֧����
    int before = connection_count(Adj_List, v);
    // cout << before << endl;
    // int k = 0;
    for (auto x : edges)
    {
        // ɾ����
        int v1 = x[0], v2 = x[1];

        Adj_List[v1].erase(remove(Adj_List[v1].begin(), Adj_List[v1].end(), v2), Adj_List[v1].end());
        Adj_List[v2].erase(remove(Adj_List[v2].begin(), Adj_List[v2].end(), v1), Adj_List[v2].end());

        visited_init(v);
        DFS(v1, Adj_List, v);
        if (visited[v2] == false)
            bridge_cnt++;

        // �ָ���
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);
    }
    end_time = clock();
    cout << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
    cout << endl;
}

// ������+���鼯����ͨ��֧
void Union_MST()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<int> *MST;
    MST = new vector<int>[v];
    vector<vector<int>> edges;
    vector<vector<int>> edges2;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    parent = new int[v];
    start_time = clock();
    MST_CREATE(Adj_List, MST, v, edges2);
    int before = v;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    for (auto x : edges)
        myUnion2(x[0], x[1], before);

    int bridge_cnt = 0, after = v;
    for (auto x : edges2)
    {

        for (int i = 0; i < v; i++)
            parent[i] = i;
        after = v;
        for (auto edge : edges)
        {
            int v1_ = edge[0], v2_ = edge[1];
            if (x == edge)
                continue;
            myUnion(v1_, v2_, after);
        }

        if (after > before)
            bridge_cnt++;
    }
    end_time = clock();
    cout << endl
         << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}

// ������+���鼯����ͨ��֧+��
void Union2_MST()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    vector<int> *Adj_List;
    Adj_List = new vector<int>[v];
    vector<int> *MST;
    MST = new vector<int>[v];
    vector<vector<int>> edges;
    vector<vector<int>> edges2;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            edges.push_back(vector<int>{n1, n2});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    parent = new int[v];
    RANK = new int[v];
    start_time = clock();
    MST_CREATE(Adj_List, MST, v, edges2);
    int before = v;
    for (int i = 0; i < v; i++)
    {
        RANK[i] = 1;
        parent[i] = i;
    }
    for (auto x : edges)
        myUnion2(x[0], x[1], before);

    int bridge_cnt = 0, after = v;
    for (auto x : edges2)
    {

        for (int i = 0; i < v; i++)
            parent[i] = i;
        after = v;
        for (auto edge : edges)
        {
            int v1_ = edge[0], v2_ = edge[1];
            if (x == edge)
                continue;
            myUnion2(v1_, v2_, after);
        }

        if (after > before)
            bridge_cnt++;
    }
    end_time = clock();
    cout << endl
         << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge_cnt << endl;
}

void LCA_DFS(vector<int> *&Adj_List, int v, int i, int pre, int depth, vector<vector<int>> &edges)
{
    if (pre != -1)
    {
        if (pre <= i)
            edges.push_back(vector<int>{pre, i});
        else
            edges.push_back(vector<int>{i, pre});
    }
    visited[i] = true;
    parent[i] = pre;
    RANK[i] = depth;
    for (int next : Adj_List[i])
    {
        if (visited[next] == false)
        {
            LCA_DFS(Adj_List, v, next, i, depth + 1, edges);
        }
    }
}

vector<int> *Adj_List;
// lca�㷨
void LCA()
{
    ifstream fin(FILENAME);
    // ifstream fin("./mediumDG.txt");
    // ifstream fin("./largeG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    // ����������
    vector<vector<int>> edges2;
    // ������������
    vector<vector<int>> edges3;
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            if (n1 <= n2)
                edges.push_back(vector<int>{n1, n2});
            else
                edges.push_back(vector<int>{n2, n1});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    for (int i = 0; i < v; i++)
        sort(Adj_List[i].begin(), Adj_List[i].end());
    parent = new int[v];
    RANK = new int[v];
    edge_visited = new bool[v];
    for (int i = 0; i < v; i++)
        edge_visited[i] = false;
    visited_init(v);
    auto start = system_clock::now();
    // start_time = clock();
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            LCA_DFS(Adj_List, v, i, -1, 0, edges2);
    auto temp = system_clock::now();
    // auto temp = clock();
    for (auto E : edges)
    {
        if (find(edges2.begin(), edges2.end(), E) == edges2.end())
            edges3.push_back(E);
    }
    auto end = system_clock::now();
    // end_time = clock();
    start += end - temp;
    // start_time += end_time - temp;

    int lca_num = 0;
    int cnt = 0;
    for (auto add_e : edges3)
    {
        int left = add_e[0], right = add_e[1];
        int left_depth = RANK[left], right_depth = RANK[right];
        if (left_depth < right_depth)
        {
            int delta = right_depth - left_depth;
            while (delta--)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                right = parent[right];
            }
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
        else if (left_depth > right_depth)
        {
            int delta = left_depth - right_depth;
            while (delta--)
            {
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
            }
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
        else
        {
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
    }
    end = system_clock::now();
    // end_time = clock();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "������"
         << double(duration.count()) * microseconds::period::num / microseconds::period::den
         << "��" << endl;
    // cout << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;

    int ans = edges.size() - edges3.size() - lca_num;
    cout << "bridge_cnt: " << ans << endl;
}

int lca_getparent(int a)
{
    if (parent[a] == a)
        return a;
    else
    {
        RANK[a]++;
        return lca_getparent(parent[a]);
    }
}

void LCA_Union(int a, int b, vector<vector<int>> &edges, int i)
{
    int x = lca_getparent(a), y = lca_getparent(b);
    if (x == y)
    {
        is_MST[i] = false;
        return;
    }
    else
        is_MST[i] = true;
    if (RANK[x] <= RANK[y])
        parent[x] = y;
    else
        parent[y] = x;
    if (RANK[x] == RANK[y] && x != y)
    {
        if (a < b)
            edges.push_back(vector<int>{a, b});
        else
            edges.push_back(vector<int>{b, a});
        RANK[y]++;
    }
}

int getparent3(int x)
{
    // if (parent[x] == x)
    //     return x;
    // parent[x] = getparent(parent[x]);
    // return parent[x];
    // return getparent(parent[x]);
    return x == parent2[x] ? x : (parent2[x] = getparent3(parent2[x]));
}

void myUnion3(int a, int b, vector<vector<int>> &edges)
{
    int x = getparent3(a), y = getparent3(b);
    if (x == y)
    {
        if (a <= b)
            edges.push_back(vector<int>{a, b});
        else
            edges.push_back(vector<int>{b, a});
        // return;
    }
    if (RANK2[x] <= RANK2[y])
        parent2[x] = y;
    else
        parent2[y] = x;
    if (RANK2[x] == RANK2[y] && x != y)
    {
        RANK2[y]++;
    }
}

// lca+���鼯 �㷨
void LCA2()
{
    ifstream fin("./dataset/10000_1.txt");
    // ifstream fin("./mediumDG.txt");
    // ifstream fin("./largeG.txt");
    int v, e; // v:�ڵ��� e:����
    fin >> v >> e;
    Adj_List = new vector<int>[v];
    vector<vector<int>> edges;
    // ����������
    vector<vector<int>> edges2;
    // ������������
    vector<vector<int>> edges3;
    parent = new int[v];
    RANK = new int[v];
    parent2 = new int[v];
    RANK2 = new int[v];
    edge_visited = new bool[v];
    is_MST = new bool[edges.size()];
    for (int i = 0; i < v; i++)
    {
        edge_visited[i] = false;
        parent2[i] = i;
        RANK2[i] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        fin >> n1 >> n2;
        if (n1 == n2)
            continue;
        if (find(Adj_List[n1].begin(), Adj_List[n1].end(), n2) == Adj_List[n1].end())
        {
            if (n1 <= n2)
                edges.push_back(vector<int>{n1, n2});
            else
                edges.push_back(vector<int>{n2, n1});
            Adj_List[n1].push_back(n2);
            Adj_List[n2].push_back(n1);
        }
    }
    for (int i = 0; i < v; i++)
        sort(Adj_List[i].begin(), Adj_List[i].end());
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         {
             if (a[0] < b[0])
                 return true;
             else if (a[0] == b[0])
                 return a[1] <= b[1];
             else
                 return false;
         });

    visited_init(v);
    // start_time = clock();
    auto start = system_clock::now();
    for (int i = 0; i < edges.size(); i++)
        myUnion3(edges[i][0], edges[i][1], edges2);
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            LCA_DFS(Adj_List, v, i, -1, 0, edges2);

    int lca_num = 0;
    int cnt = 0;
    for (auto add_e : edges3)
    {
        int left = add_e[0], right = add_e[1];
        int left_depth = RANK[left], right_depth = RANK[right];
        if (left_depth < right_depth)
        {
            int delta = right_depth - left_depth;
            while (delta--)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                right = parent[right];
            }
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
        else if (left_depth > right_depth)
        {
            int delta = left_depth - right_depth;
            while (delta--)
            {
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
            }
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
        else
        {
            while (left != right)
            {
                if (edge_visited[right] == false)
                {
                    edge_visited[right] = true;
                    lca_num++;
                }
                if (edge_visited[left] == false)
                {
                    edge_visited[left] = true;
                    lca_num++;
                }
                left = parent[left];
                right = parent[right];
            }
        }
    }
    // end_time = clock();
    auto end = system_clock::now();
    // cout << endl
    //      << "time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    auto duration = duration_cast<microseconds>(end - start);
    cout << "������"
         << double(duration.count()) * microseconds::period::num / microseconds::period::den
         << "��" << endl;
    int ans = edges.size() - edges3.size() - lca_num;
    cout << "bridge_cnt: " << ans << endl;
}

class Edge
{
public:
    int a, b;

    void set(int aa, int bb)
    {
        a = aa;
        b = bb;
    };

    void show()
    {
        cout << a << " " << b << endl;
    }
};

class Node
{
public:
    int father;
    int height;
    bool flag;

    Node()
    {
        father = -1;
        height = 0;
        flag = false;
    }
};

int bridge;
int v, e;
bool *book;
Node *node;
Edge *edge;
vector<Edge> NotTreeEdge;
vector<int> *Map;

void CreateGraph()
{
    ifstream is;
    is.open("./mediumDG.txt", ios::in);
    is >> v >> e;
    Map = new vector<int>[v];
    book = new bool[v];
    edge = new Edge[e];
    node = new Node[v];
    for (int i = 0; i < v; ++i)
    {
        book[i] = false;
        node[i].father = -1;
    }
    int a, b;
    for (int i = 0; i < e; ++i)
    {
        is >> a >> b;
        Map[a].push_back(b);
        Map[b].push_back(a);
        edge[i].set(a, b);
    }
    is.close();
}

void Delete()
{
    delete[] Map;
    delete[] book;
    delete[] edge;
    delete[] node;
}

void BFS(int s)
{
    queue<int> bfs;
    book[s] = true;
    node[s].father = -1;
    node[s].height = 0;
    bfs.push(s);
    while (!bfs.empty())
    {
        int now = bfs.front();
        bfs.pop();
        for (int i = 0; i < Map[now].size(); ++i)
        {
            int child = Map[now][i];
            if (!book[child])
            {
                book[child] = true;
                node[child].father = now;
                node[child].height = node[now].height + 1;
                bfs.push(child);
            }
        }
    }
}

void getTree()
{
    bridge = v;
    for (int i = 0; i < v; ++i)
    {
        if (!book[i])
        {
            bridge--;
            BFS(i);
        }
    }
}

void getLCA(int a, int b)
{
    int ha = node[a].height;
    int hb = node[b].height;
    while (ha < hb)
    {
        if (!node[b].flag)
        {
            node[b].flag = true;
            bridge--;
        }
        hb--;
        b = node[b].father;
    }
    while (ha > hb)
    {
        if (!node[a].flag)
        {
            node[a].flag = true;
            bridge--;
        }
        ha--;
        a = node[a].father;
    }
    while (a != b)
    {
        if (!node[a].flag)
        {
            node[a].flag = true;
            bridge--;
        }
        if (!node[b].flag)
        {
            node[b].flag = true;
            bridge--;
        }
        a = node[a].father;
        b = node[b].father;
    }
}

void getRing()
{
    int a, b;
    for (int i = 0; i < e; ++i)
    {
        a = edge[i].a;
        b = edge[i].b;
        if (node[a].father != b && node[b].father != a)
        {
            NotTreeEdge.push_back(edge[i]);
        }
    }
    for (int i = 0; i < NotTreeEdge.size(); ++i)
    {
        getLCA(NotTreeEdge[i].a, NotTreeEdge[i].b);
    }
}

void BFS_LCA()
{
    CreateGraph();
    long start = clock();
    getTree();
    getRing();
    long end = clock();
    cout << endl
         << "time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << "bridge_cnt: " << bridge << endl;
}
