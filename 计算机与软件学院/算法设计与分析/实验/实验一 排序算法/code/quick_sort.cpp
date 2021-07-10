#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <Windows.h>

using namespace std;

// 数据量的规模
vector<long> data_size = {100000, 200000, 300000, 400000, 500000, 1000000, 5000000, 10000000, 15000000, 20000000, 50000000};

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

// 快速排序
// 参数：
// data：数组
// size：数组长度
long Paritition1(long A[], long low, long high)
{
    long pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quick_sort(long A[], long low, long high) //快排母函数
{
    if (low < high)
    {
        long pivot = Paritition1(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
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
    ofstream fout("data_analysis/quick_sort_analysis.csv");
    fout << "data_size" << ',' << "before" << endl;
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
            quick_sort(data, 0, size);
            end_time = GetTickCount();
            sum_time += end_time - start_time;
            delete[] data;
        }

        cout << "avg_time = " << sum_time / 20 << endl
             << endl;
        fout << size << ',' << sum_time / 20 << endl;
    }
    return 0;
}