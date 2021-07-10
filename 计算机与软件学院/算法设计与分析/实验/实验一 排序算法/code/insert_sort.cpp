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

//插入排序
// 参数：
// data：数组
// size：数组长度
void insert_sort(long *data, long size)
{
    for (long i = 1; i < size; i++)
    {
        for (long j = i; j > 0; j--)
            if (data[j] < data[j - 1])
                my_swap(data[j], data[j - 1]);
            else
                break;
    }
    return;
}

// 插入排序优化
// 用赋值替代交换操作
void insert_sort_better(long *data, long size)
{
    for (long i = 1; i < size; i++)
    {
        long e = data[i];
        int j;
        for (j = i; j > 0 && data[j - 1] > e; j--)
            data[j] = data[j - 1];
        data[j] = e;
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
    ofstream fout("data_analysis/insert_sort_analysis.csv");
    fout << "data_size" << ',' << "before" << ',' << "after" << endl;
    for (int j = 0; j < data_size.size(); j++)
    {
        long size = data_size[j];
        DWORD sum_time = 0, sum_time_better = 0, start_time = 0, end_time = 0;
        for (int i = 1; i <= batch; i++)
        {
            if (i == 1)
                cout << "data_size: " << size << endl;

            // 插入排序（未优化）
            long *data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            insert_sort(data, size);
            end_time = GetTickCount();
            sum_time += end_time - start_time;
            delete[] data;

            // 插入排序（优化）
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            insert_sort_better(data, size);
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