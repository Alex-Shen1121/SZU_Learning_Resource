#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <algorithm>
#include <ratio>
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
using namespace std::chrono;

// 计时器
clock_t start_time = 0, end_time = 0;

void BF_test()
{
    std::uniform_int_distribution<int> dis(1, 1000);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int *a[3], *t[3];
#define n_single_test_bf 20
    long num = 0;
    int sum = 0;
    // 开辟空间
    a[1] = new int[n_single_test_bf + 1];
    a[2] = new int[n_single_test_bf + 1];
    t[1] = new int[n_single_test_bf];
    t[2] = new int[n_single_test_bf];

    // 数据初始化
    e1 = dis(rng), e2 = dis(rng);
    x1 = dis(rng), x2 = dis(rng);
    for (int i = 1; i <= n_single_test_bf; i++)
    {
        a[1][i] = dis(rng);
        a[2][i] = dis(rng);
        // cout << a[1][i] << ' ' << a[2][i] << ' ';
    }
    for (int i = 1; i <= n_single_test_bf - 1; i++)
    {
        t[1][i] = dis(rng);
        t[2][i] = dis(rng);
        // cout << t[1][i] << ' ' << t[2][i] << ' ';
    }

    // 计算总时间
    start_time = clock();
    // 遍历所有情况
    int min = INT_MAX;
    bitset<n_single_test_bf> res_route;
    for (int i = 0; i <= pow(2, n_single_test_bf) - 1; i++)
    {
        sum = 0;
        bitset<n_single_test_bf> route(i);
        // cout << route << ' ' << route[n - 1] << endl;
        // 判断起始路径
        if (route[0] == 0)
            sum += e1 + a[1][1];
        else if (route[0] == 1)
            sum += e2 + a[2][1];
        // 开始搜索
        for (int j = 2; j <= n_single_test_bf; j++)
        {
            // pre:前一结点流水线号
            // cur:当前结点流水线号
            int pre = route[j - 2] + 1, cur = route[j - 1] + 1;
            if (pre != cur) // 转移
                sum += t[pre][j - 1] + a[cur][j];
            else if (pre == cur) // 不转移
                sum += a[cur][j];
        }
        // 判断末尾路径
        if (route[n_single_test_bf - 1] == 0)
            sum += x1;
        else if (route[n_single_test_bf - 1] == 1)
            sum += x2;
        // cout << sum << endl;
        if (sum < min)
        {
            min = sum;
            res_route = route;
        }
    }
    end_time = clock();
    cout << "蛮力法时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "蛮力法解：" << min << endl;
    cout << "蛮力法路径" << res_route << endl;
}

void DP_test()
{
    std::uniform_int_distribution<int> dis(1, 100);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int *a[3], *t[3], *route[3];
#define n_single_test_dp 10000000
    long long num = 0;
    long long sum = 0;
    // 开辟空间
    a[1] = new int[n_single_test_dp + 1];
    a[2] = new int[n_single_test_dp + 1];
    t[1] = new int[n_single_test_dp];
    t[2] = new int[n_single_test_dp];
    route[1] = new int[n_single_test_dp + 1];
    route[2] = new int[n_single_test_dp + 1];

    // 数据初始化
    e1 = dis(rng), e2 = dis(rng);
    x1 = dis(rng), x2 = dis(rng);
    for (long long i = 1; i <= n_single_test_dp; i++)
    {
        a[1][i] = dis(rng);
        a[2][i] = dis(rng);
        // cout << a[1][i] << ' ' << a[2][i] << ' ';
    }
    for (long long i = 1; i <= n_single_test_dp - 1; i++)
    {
        t[1][i] = dis(rng);
        t[2][i] = dis(rng);
        // cout << t[1][i] << ' ' << t[2][i] << ' ';
    }

    start_time = clock();
    // 动态规划
    long long dp1 = e1 + a[1][1], dp2 = e2 + a[2][1];
    route[1][1] = 0, route[2][1] = 1;
    for (int i = 2; i <= n_single_test_dp; i++)
    {
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a[1][i] < dp2 + t[2][i - 1] + a[1][i])
        {
            dp1 = dp1 + a[1][i];
            route[1][i] = 0;
        }
        else
        {
            dp1 = dp2 + t[2][i - 1] + a[1][i];
            route[1][i] = 1;
        }
        if (temp + t[1][i - 1] + a[2][i] < dp2 + a[2][i])
        {
            dp2 = temp + t[1][i - 1] + a[2][i];
            route[2][i] = 0;
        }
        else
        {
            dp2 = dp2 + a[2][i];
            route[2][i] = 1;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
    // cout << "动态规划路径";
    // int temp;
    // if (dp1 + x1 < dp2 + x2)
    //     temp = 1;
    // else
    //     temp = 2;
    // cout << temp - 1;
    // for (int i = n_single_test_dp; i > 1; i--)
    // {
    //     cout << route[temp][i];
    //     temp = route[temp][i] + 1;
    // }
    // cout << endl;
    cout << endl;
}

void Correction_Test()
{
    std::uniform_int_distribution<int> dis(1, 1000);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int *a[3], *t[3];
#define n_test 20
    vector<vector<int>> Route;
    Route.resize(3, vector<int>(n_test + 1));
    long num = 0;
    int sum = 0;
    // 开辟空间
    a[1] = new int[n_test + 1];
    a[2] = new int[n_test + 1];
    t[1] = new int[n_test];
    t[2] = new int[n_test];

    // 数据初始化
    e1 = dis(rng), e2 = dis(rng);
    x1 = dis(rng), x2 = dis(rng);
    for (int i = 1; i <= n_test; i++)
    {
        a[1][i] = dis(rng);
        a[2][i] = dis(rng);
        // cout << a[1][i] << ' ' << a[2][i] << ' ';
    }
    for (int i = 1; i <= n_test - 1; i++)
    {
        t[1][i] = dis(rng);
        t[2][i] = dis(rng);
        // cout << t[1][i] << ' ' << t[2][i] << ' ';
    }

    // 蛮力法
    // 遍历所有情况
    int Min = INT_MAX;
    bitset<n_test> res_route;
    for (int i = 0; i <= pow(2, n_test) - 1; i++)
    {
        sum = 0;
        bitset<n_test> route(i);
        // cout << route << ' ' << route[n - 1] << endl;
        // 判断起始路径
        if (route[0] == 0)
            sum += e1 + a[1][1];
        else if (route[0] == 1)
            sum += e2 + a[2][1];
        // 开始搜索
        for (int j = 2; j <= n_test; j++)
        {
            // pre:前一结点流水线号
            // cur:当前结点流水线号
            int pre = route[j - 2] + 1, cur = route[j - 1] + 1;
            if (pre != cur) // 转移
                sum += t[pre][j - 1] + a[cur][j];
            else if (pre == cur) // 不转移
                sum += a[cur][j];
        }
        // 判断末尾路径
        if (route[n_test - 1] == 0)
            sum += x1;
        else if (route[n_test - 1] == 1)
            sum += x2;
        // cout << sum << endl;
        if (sum < Min)
        {
            Min = sum;
            res_route = route;
        }
    }
    cout << "蛮力法解：" << Min << endl;
    cout << "蛮力法路径  " << res_route << endl;

    // 动态规划
    int dp1 = e1 + a[1][1], dp2 = e2 + a[2][1];
    Route[1][1] = 0, Route[2][1] = 1;
    for (int i = 2; i <= n_test; i++)
    {
        int temp = dp1;
        Route[0] = Route[1];
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a[1][i] < dp2 + t[2][i - 1] + a[1][i])
        {
            dp1 = dp1 + a[1][i];
            Route[1][i] = 0;
        }
        else
        {
            dp1 = dp2 + t[2][i - 1] + a[1][i];
            Route[1] = Route[2];
            Route[1][i] = 0;
        }
        if (temp + t[1][i - 1] + a[2][i] < dp2 + a[2][i])
        {
            dp2 = temp + t[1][i - 1] + a[2][i];
            Route[2] = Route[0];
            Route[2][i] = 1;
        }
        else
        {
            dp2 = dp2 + a[2][i];
            Route[2][i] = 1;
        }
    }
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
    cout << "动态规划路径";
    if (dp1 + x1 < dp2 + x2)
    {
        for (int i = n_test; i >= 1; i--)
            cout << Route[1][i];
    }
    else
    {
        for (int i = n_test; i >= 1; i--)
            cout << Route[2][i];
    }
    cout << endl;
    cout << endl;
}

void Discrete_Test()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 100);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    long long n = 100000000000;
    long long num = 0;
    long long sum = 0;
    ofstream fout("Max_Test_5.txt");
    vector<char> route[3];

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1].push_back(1);
    route[2].push_back(1);
    char A_end = 0, B_end = 1;
    for (long long i = 2; i <= n; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            if (A_end == 0)
                route[1].back()++;
            else
            {
                route[1].push_back(0);
                A_end = 0;
            }
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            if (A_end == 1)
                route[1].back()++;
            else
            {
                route[1].push_back(1);
                A_end = 1;
            }
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            if (B_end == 0)
                route[2].back()++;
            else
            {
                route[2].push_back(0);
                B_end = 0;
            }
        }
        else
        {
            dp2 = dp2 + a2;
            if (B_end == 1)
                route[2].back()++;
            else
            {
                route[2].push_back(1);
                B_end = 1;
            }
        }
        if (i % 10000000 == 0)
        {
            // cout << "max = " << *max_element(route[1].begin(), route[1].end()) << " avg = " << accumulate(route[1].begin(), route[1].end(), 0) / (double)route[1].size() << endl;
            int max = *max_element(route[1].begin(), route[1].end());
            double avg = accumulate(route[1].begin(), route[1].end(), 0) / (double)route[1].size();
            cout << " max = " << max << " avg = " << avg << endl;
            // end_time = clock();
            // cout << i << " 当前已运行时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
            // fout << i << " 当前已运行时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 无压缩 char存储
void Max_Test_1()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 5);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    char *route[3];
#define n_max1_test_dp 800000000
    long long num = 0;
    long long sum = 0;
    ofstream fout("Max_Test_1.txt");

    // 开辟空间
    route[1] = new char[n_max1_test_dp + 1];
    route[2] = new char[n_max1_test_dp + 1];

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1][1] = 0, route[2][1] = 1;
    for (long long i = 2; i <= n_max1_test_dp; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            route[1][i] = 0;
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            route[1][i] = 1;
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            route[2][i] = 0;
        }
        else
        {
            dp2 = dp2 + a2;
            route[2][i] = 1;
        }
        if (i % 100000000 == 0)
        {
            end_time = clock();
            fout << i << "time: " << end_time - start_time << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 压缩 n位连续压缩
void Max_Test_2()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 100);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    long long n = 100000000000;
    long long num = 0;
    long long sum = 0;
    ofstream fout("record.txt");
    vector<pair<char, bitset<1>>> route[3];

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);

    start_time = clock();
    bitset<1> zero(0), one(1);
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1].push_back({1, zero});
    route[2].push_back({1, one});
    for (long long i = 2; i <= n; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        vector<pair<char, bitset<1>>> temp1 = route[1];
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            if (route[1].back().second == 0)
                route[1].back().first++;
            else
                route[1].push_back({1, zero});
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            route[1] = route[2];
            if (route[1].back().second == 0)
                route[1].back().first++;
            else
                route[1].push_back({1, zero});
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            route[2] = temp1;
            if (route[2].back().second == 0)
                route[2].back().first++;
            else
                route[2].push_back({1, one});
        }
        else
        {
            dp2 = dp2 + a2;
            if (route[2].back().second == 0)
                route[2].back().first++;
            else
                route[2].push_back({1, one});
        }
        if (i % 100000000 == 0)
        {
            end_time = clock();
            cout << i << " 当前已运行时间：" << end_time - start_time << " size:" << route[1].size() << "压缩比例：" << (double)i / route[1].size() << endl;
            fout << i << " 当前已运行时间：" << end_time - start_time << " size:" << route[1].size() << "压缩比例：" << (double)i / route[1].size() << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 压缩 字典压缩
void Max_Test_3()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 100);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    long long n = 100000000000;
    long long num = 0;
    long long sum = 0;
    ofstream fout("record1.txt");
    vector<int> route[3];
    unordered_map<string, int> hashtable;
    string s1, c1, s2, c2;

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);
    hashtable["0"] = 1;
    hashtable["1"] = 2;

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1].push_back(1);
    route[2].push_back(2);
    s1 = "0";
    s2 = "1";
    for (long long i = 2; i <= n; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        route[0] = route[1];
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            c1 = "0";
            if (hashtable.find(s1 + c1) != hashtable.end())
                s1 = s1 + c1;
            else
            {
                route[1].push_back(hashtable[s1]);
                hashtable[s1 + c1] = hashtable.size() + 1;
                s1 = c1;
            }
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            route[1] = route[2];
            s1 = s2;
            c1 = "0";
            if (hashtable.find(s1 + c1) != hashtable.end())
                s1 = s1 + c1;
            else
            {
                route[1].push_back(hashtable[s1]);
                hashtable[s1 + c1] = hashtable.size() + 1;
                s1 = c1;
            }
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            route[2] = route[0];
            s2 = s1;
            c2 = "1";
            if (hashtable.find(s2 + c2) != hashtable.end())
                s2 = s2 + c2;
            else
            {
                route[2].push_back(hashtable[s2]);
                hashtable[s2 + c2] = hashtable.size() + 1;
                s2 = c2;
            }
        }
        else
        {
            dp2 = dp2 + a2;
            c2 = "1";
            if (hashtable.find(s2 + c2) != hashtable.end())
                s2 = s2 + c2;
            else
            {
                route[2].push_back(hashtable[s2]);
                hashtable[s2 + c2] = hashtable.size() + 1;
                s2 = c2;
            }
        }
        if (i % 1000000 == 0)
        {
            end_time = clock();
            cout << i << " 当前已运行时间：" << end_time - start_time << " hashtable.size:" << hashtable.size() << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
            fout << i << " 当前已运行时间：" << end_time - start_time << " hashtable.size:" << hashtable.size() << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 压缩 char存储 O(n)
void Max_Test_4()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 5);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    char *route[3];
#define n_max4_test_dp 800000000
    long long num = 0;
    long long sum = 0;
    ofstream fout("Max_Test_4.txt");

    // 开辟空间
    route[1] = new char[n_max4_test_dp + 1];
    route[2] = new char[n_max4_test_dp + 1];

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1][1] = 0, route[2][1] = 1;
    for (long long i = 2; i <= n_max4_test_dp; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            route[1][i] = 0;
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            route[1][i] = 1;
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            route[2][i] = 0;
        }
        else
        {
            dp2 = dp2 + a2;
            route[2][i] = 1;
        }
        if (i % 100000000 == 0)
        {
            end_time = clock();
            cout << i << " time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
            fout << i << " time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 压缩 n位连续压缩
void Max_Test_5()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 5);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    long long n = 100000000000;
    long long num = 0;
    long long sum = 0;
    ofstream fout("Max_Test_5.txt");
    vector<char> route[3];

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    route[1].push_back(1);
    route[2].push_back(1);
    char A_end = 0, B_end = 1;
    for (long long i = 2; i <= n; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            if (A_end == 0)
                route[1].back()++;
            else
            {
                route[1].push_back(0);
                A_end = 0;
            }
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            if (A_end == 1)
                route[1].back()++;
            else
            {
                route[1].push_back(1);
                A_end = 1;
            }
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            if (B_end == 0)
                route[2].back()++;
            else
            {
                route[2].push_back(0);
                B_end = 0;
            }
        }
        else
        {
            dp2 = dp2 + a2;
            if (B_end == 1)
                route[2].back()++;
            else
            {
                route[2].push_back(1);
                B_end = 1;
            }
        }
        if (i % 1000000 == 0)
        {
            int max = *max_element(route[1].begin(), route[1].end());
            double avg = accumulate(route[1].begin(), route[1].end(), 0) / (double)route[1].size();
            cout << " max = " << max << " avg = " << avg << endl;

            // end_time = clock();
            // cout << i << " 当前已运行时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
            // fout << i << " 当前已运行时间：" << (double)(end_time - start_time) / CLOCKS_PER_SEC << " size:" << route[1].size() << " 压缩比例：" << (double)i / route[1].size() << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

// 压缩 字典压缩(有问题)
void Max_Test_6()
{
    std::uniform_int_distribution<int> dis_main(1, 100);
    std::uniform_int_distribution<int> dis_transform(1, 5);
    std::default_random_engine rng(time(nullptr)); // Create random number generator
    int e1, e2, x1, x2;
    int a1, a2, t1, t2;
    long long n = 100000000000;
    long long num = 0;
    long long sum = 0;
    ofstream fout("Max_Test_6.txt");
    vector<int> route[3];
    unordered_map<string, int> hashtable;
    string s1, c1, s2, c2;

    // 数据初始化
    e1 = dis_main(rng), e2 = dis_main(rng);
    x1 = dis_main(rng), x2 = dis_main(rng);
    hashtable["0"] = 1;
    hashtable["1"] = 2;

    start_time = clock();
    // 动态规划
    a1 = dis_main(rng), a2 = dis_main(rng);
    long long dp1 = e1 + a1, dp2 = e2 + a2;
    // route[1].push_back(1);
    // route[2].push_back(2);
    s1 = "0";
    s2 = "1";
    for (long long i = 2; i <= n; i++)
    {
        a1 = dis_main(rng), a2 = dis_main(rng);
        t1 = dis_transform(rng), t2 = dis_transform(rng);
        long long temp = dp1;
        // dp1 = min(dp1 + a[1][i], dp2 + t[2][i - 1] + a[1][i]);
        // dp2 = min(temp + t[1][i - 1] + a[2][i], dp2 + a[2][i]);
        if (dp1 + a1 < dp2 + t2 + a1)
        {
            dp1 = dp1 + a1;
            c1 = "0";
            if (hashtable.find(s1 + c1) != hashtable.end())
                s1 = s1 + c1;
            else
            {
                route[1].push_back(hashtable[s1]);
                hashtable[s1 + c1] = hashtable.size() + 1;
                s1 = c1;
            }
        }
        else
        {
            dp1 = dp2 + t2 + a1;
            c1 = "1";
            if (hashtable.find(s1 + c1) != hashtable.end())
                s1 = s1 + c1;
            else
            {
                route[1].push_back(hashtable[s1]);
                hashtable[s1 + c1] = hashtable.size() + 1;
                s1 = c1;
            }
        }
        if (temp + t1 + a2 < dp2 + a2)
        {
            dp2 = temp + t1 + a2;
            c2 = "0";
            if (hashtable.find(s2 + c2) != hashtable.end())
                s2 = s2 + c2;
            else
            {
                route[2].push_back(hashtable[s2]);
                hashtable[s2 + c2] = hashtable.size() + 1;
                s2 = c2;
            }
        }
        else
        {
            dp2 = dp2 + a2;
            c2 = "1";
            if (hashtable.find(s2 + c2) != hashtable.end())
                s2 = s2 + c2;
            else
            {
                route[2].push_back(hashtable[s2]);
                hashtable[s2 + c2] = hashtable.size() + 1;
                s2 = c2;
            }
        }
        // if (i % 1000000 == 0)
        // {
        //     end_time = clock();
        //     cout << i << " 当前已运行时间：" << end_time - start_time << " 字典长度:" << hashtable.size() << " size1:" << route[1].size() << " size2:" << route[2].size() << " 压缩比例：" << (double)i / route[1].size() << " eff:" << route[1].size() * ceil(log2(hashtable.size())) / i << endl;
        //     fout << i << " 当前已运行时间：" << end_time - start_time << " 字典长度:" << hashtable.size() << " size1:" << route[1].size() << " size2:" << route[2].size() << " 压缩比例：" << (double)i / route[1].size() << " eff:" << route[1].size() * ceil(log2(hashtable.size())) / i << endl;
        // }
        if (i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000 || i == 10000000 || i == 100000000)
        {
            end_time = clock();
            cout << i << " 字典长度:" << hashtable.size() << " size1:" << route[1].size() << " size2:" << route[2].size() << " 压缩比例：" << (double)i / route[1].size() << " eff:" << route[1].size() * ceil(log2(hashtable.size())) / i << endl;
            fout << i << " 字典长度:" << hashtable.size() << " size1:" << route[1].size() << " size2:" << route[2].size() << " 压缩比例：" << (double)i / route[1].size() << " eff:" << route[1].size() * ceil(log2(hashtable.size())) / i << endl;
        }
    }
    end_time = clock();
    cout << "动态规划时间：" << end_time - start_time << endl;
    cout << "动态规划解：" << min(dp1 + x1, dp2 + x2) << endl;
}

int main()
{
    // // 动态规划单次测试。
    // DP_test();
    // // 蛮力法单次测试。
    // BF_test();

    // 正确性测试
    int t = 10;
    while (t--)
    {
        Correction_Test();
        system("pause");
    }

    // // 数据离散性测试
    // int k = 3;
    // while (k--)
    // {
    //     Discrete_Test();
    //     system("pause");
    //     // pause();
    // }

    // 最大规模测试
    // Max_Test_1();
    // Max_Test_2();
    // Max_Test_3();
    // Max_Test_4();
    // Max_Test_5();
    // Max_Test_6();

    return 0;
}