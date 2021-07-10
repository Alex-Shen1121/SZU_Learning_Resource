#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <Windows.h>

using namespace std;

// 数据量的规模
vector<long> data_size = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

// 测试次数
int batch = 20;

// sting --> long
long string_to_long(string str)
{
    long result;
    istringstream is(str);
    is >> result;
    return result;
}

//交换数组元素
void my_swap(long &a, long &b)
{
    long temp = a;
    a = b;
    b = temp;
}

// 读取数据
void read_data(long *data, long size, int batch)
{
    string filename;
    stringstream stream;
    stream << size;
    stream >> filename;
    filename += "_" + to_string(batch) + ".txt";
    ifstream fin("dataset/" + filename);
    string s;
    long cur = 0;
    while (fin >> s)
    {
        data[cur] = string_to_long(s);
        cur++;
    }
    fin.close();
    //cout << filename << endl;
}

//选择排序，利用数组下标
// 参数：
// data：数组
// size：数组长度
void select_sort(long *data, long size)
{
    for (int i = 0; i < size; i++)
    {
        int id = i, val = data[id];
        for (int j = i + 1; j < size; j++)
            if (data[j] < val)
                val = data[j], id = j;
        my_swap(data[id], data[i]);
    }
}

// 优化选择排序
// 同时找到最大、最小值，优化一半循环次数
void select_sort_better(long *a, long size)
{
    // 首先检查数据的合法性（TODO 不完善）.
    if (a == NULL || size <= 1)
    {
        return;
    }

    int min = 0;   // 当前待排序的数据中最小值的下标
    int max = 0;   // 当前待排序的数据中最小值的下标
    int j = 0;     // 内层循环（移动数据）计数变量
    int k = size;  // 记录已排序空间中最大值的交换位
    long temp = 0; // 用于数据交换的临时变量

    // 对未排序区间进行遍历 (每次更新头尾的位置)
    for (int i = 0; i < k; ++i, --k)
    {
        min = i;
        max = i;
        // 在未排序区间中查找最小值和最小值
        for (j = i + 1; j < k; ++j)
        {
            if (a[j] < a[min])
            {
                // 更新最小值下标
                min = j;
            }
            if (a[j] > a[max])
            {
                // 更新最大值下标
                max = j;
            }
        }
        if (min != i)
        {
            // 数据交换-最小值
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        if (max == i)
        {
            // 防止之前的已经被换掉
            max = min;
        }
        if (max != k - 1)
        {
            // 数据交换-最大值
            temp = a[k - 1];
            a[k - 1] = a[max];
            a[max] = temp;
        }
    }
}

// 打印数组
void print(long *data, long size)
{
    for (long i = 0; i < size; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main()
{
    DWORD start_time, end_time;
    ofstream fout("data_analysis/select_sort_analysis.csv");
    fout << "data_size" << ',' << "before" << ',' << "after" << endl;
    for (int j = 0; j < data_size.size(); j++)
    {
        long size = data_size[j];
        DWORD sum_time = 0, sum_time_better = 0, start_time = 0, end_time = 0;
        for (int i = 1; i <= batch; i++)
        {
            if (i == 1)
                cout << "data_size: " << size << endl;

            // 选择排序（未优化）
            long *data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            select_sort(data, size);
            end_time = GetTickCount();
            sum_time += end_time - start_time;
            delete[] data;

            // 选择排序（优化）
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            select_sort_better(data, size);
            end_time = GetTickCount();
            sum_time_better += end_time - start_time;
            delete[] data;
        }

        cout << "avg_time = " << sum_time / 20 << endl;
        cout << "avg_time_better = " << sum_time_better / 20 << endl
             << endl;
        fout << size << ',' << sum_time / 20 << ',' << sum_time_better / 20 << endl;
    }
    return 0;
}