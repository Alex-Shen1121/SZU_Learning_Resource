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

//冒泡排序
// 参数：
// data：数组
// size：数组长度
// early_stop:有提前结束标志
void bubble_sort(long *data, long size, bool early_stop)
{
    for (long i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 1; j < size - i; j++)
            if (data[j] < data[j - 1])
            {
                my_swap(data[j], data[j - 1]);
                flag = true;
            }
        if (!flag && early_stop)
            break;
    }
}

//冒泡排序
// 参数：
// data：数组
// size：数组长度
// early_stop:无提前结束标志
void bubble_sort_2(long *data, long size)
{
    for (long i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 1; j < size - i; j++)
            if (data[j] < data[j - 1])
            {
                my_swap(data[j], data[j - 1]);
            }
    }
}

void bubble_sort_3(long *a, int len)
{
    // 首先检查输入数据的合法性（TODO 不完善）
    if (a == NULL || len <= 1)
    {
        return;
    }

    long temp = 0;                 // 临时变量，用于进行数据交换
    int flag = 0;                  // 标记变量，记录单趟排序是否有交换
    int forward_pos_temp = 0;      // 记录前向最后一次交换的位置
    int forward_pos_cur = len - 1; // 当前需要冒泡的前向截止位置
    int reverse_pos_temp = 0;      // 记录前向最后一次交换的位置
    int reverse_pos_cur = 0;       // 当前需要冒泡的后向截止位置
    int j = 0;                     // 内层循环计数变量

    // 确定排序趟数
    for (int i = 0; i < len; ++i)
    { // ++i不会多定义变量，相比i++省空间
        // 每趟排序之前置0
        flag = 0;

        // 正向冒泡寻找最大值
        for (j = 0; j < forward_pos_cur; ++j)
        {
            // 当前比后面的值大，则冒泡到后面去
            if (a[j] > a[j + 1])
            {
                // 进行数据交换
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                forward_pos_temp = j; // 记录最后一次交换的位置
                flag = 1;             // 记录交换
            }
        }
        // 如果标记为1，说明这趟排序未交换，已经排好序，可提前结束
        if (flag == 0)
        {
            break;
        }
        forward_pos_cur = forward_pos_temp;

        // 反向冒泡寻找最小值
        for (j = forward_pos_cur; j > reverse_pos_cur; --j)
        {
            // 当前比前面的值小，则冒泡到前面去
            if (a[j] < a[j - 1])
            {
                // 进行数据交换
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                reverse_pos_temp = j; // 记录最后一次交换的位置
                flag = 1;             // 记录交换
            }
        }
        // 如果标记为1，说明这趟排序未交换，已经排好序，可提前结束
        if (flag == 0)
        {
            break;
        }
        reverse_pos_cur = reverse_pos_temp;
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
    ofstream fout("data_analysis/bubble_sort_analysis.csv");
    fout << "data_size" << ',' << "early_stop" << ',' << "not_early_stop" << ',' << "double_bubble" << endl;
    for (int j = 0; j < data_size.size(); j++)
    {
        long size = data_size[j];
        DWORD sum_time_early = 0, sum_time_not_early = 0, sum_time_double_bubble = 0, start_time = 0, end_time = 0;
        for (int i = 1; i <= batch; i++)
        {
            if (i == 1)
                cout << "data_size: " << size << endl;

            // 有提前结束标志的冒泡排序
            long *data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            bubble_sort(data, size, true);
            end_time = GetTickCount();
            sum_time_early += end_time - start_time;
            delete[] data;

            // 无提前结束标志的冒泡排序
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            bubble_sort_2(data, size);
            end_time = GetTickCount();
            sum_time_not_early += end_time - start_time;
            delete[] data;

            // 无提前结束标志的冒泡排序
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            bubble_sort_3(data, size);
            end_time = GetTickCount();
            sum_time_double_bubble += end_time - start_time;
            delete[] data;
        }

        cout << "avg_time_early = " << sum_time_early / 20 << endl;
        cout << "avg_time_double_bubble = " << sum_time_double_bubble / 20 << endl;
        cout << "avg_time_not_early = " << sum_time_not_early / 20 << endl
             << endl;
        fout << size << ',' << sum_time_early / 20 << ',' << sum_time_not_early / 20 << ',' << sum_time_double_bubble / 20 << endl;
    }
    return 0;
}