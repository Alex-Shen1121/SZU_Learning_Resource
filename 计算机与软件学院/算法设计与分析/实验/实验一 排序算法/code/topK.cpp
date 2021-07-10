#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

// sting --> long
long string_to_long(string str)
{
    long result;
    istringstream is(str);
    is >> result;
    return result;
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

vector<long> data_size = {100000, 200000, 300000, 400000, 500000, 1000000, 5000000, 10000000, 15000000, 20000000, 50000000};

int batch = 5;

//TopK问题
int K = 10;

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

void quick_sort(long *A, long low, long high) //快排母函数
{
    if (low < high)
    {
        long pivot = Paritition1(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
    }
}

//冒泡排序
// 参数：
// data：数组
// size：数组长度
// early_stop:无提前结束标志
vector<long> bubble_sort_2(long *data, long size)
{
    for (long i = 0; i < 10; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
    }
    vector<long> ans(data + size - K, data + size);
    return ans;
}

void adjustMinHeap(vector<long> &nums, long root, long len) //小顶堆结点调整
{
    long lch = 2 * root + 1; //左子结点
    long rch = lch + 1;      //右子结点
    long index = root;       //较大结点

    if (rch < len && nums[rch] < nums[index])
        index = rch;

    if (lch < len && nums[lch] < nums[index])
        index = lch;

    if (index != root) //当前结点非最小结点
    {
        swap(nums[index], nums[root]);
        adjustMinHeap(nums, index, len);
    }
    return;
}

vector<long> heap_sort(long *data, long k, long len)
{
    vector<long> nums(data, data + len);
    vector<long> res(nums.begin(), nums.begin() + k);

    for (long i = k / 2 - 1; i >= 0; i--)
    {
        adjustMinHeap(res, i, k);
    }

    for (long i = k; i < len; i++)
    {
        if (nums[i] > res[0])
        {
            res[0] = nums[i];
            adjustMinHeap(res, 0, k);
        }
    }
    return res;
}

int main()
{
    DWORD start_time, end_time;
    ofstream fout("data_analysis/TopK_analysis.csv");
    fout << "data_size" << ',' << "nlogn" << ',' << "kn" << ',' << "nlogk" << endl;
    for (int j = 0; j < data_size.size(); j++)
    {
        long size = data_size[j];
        DWORD sum_time_nlogn = 0, sum_time_kn = 0, sum_time_nlogk = 0, start_time = 0, end_time = 0;
        for (int i = 1; i <= batch; i++)
        {
            if (i == 1)
                cout << "data_size: " << size << endl;

            // 排序取10位 O(nlogn)
            long *data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            quick_sort(data, -1, size - 1);
            end_time = GetTickCount();
            vector<long> ans(data + size - K, data + size);
            cout << "O(nlogn) ans:";
            for (auto x : ans)
            {
                cout << x << ' ';
            }
            cout << endl;
            sum_time_nlogn += end_time - start_time;
            delete[] data;

            // 遍历 O(kn)
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            ans = bubble_sort_2(data, size);
            end_time = GetTickCount();
            cout << "O(kn) ans:";
            for (auto x : ans)
            {
                cout << x << ' ';
            }
            cout << endl;
            sum_time_kn += end_time - start_time;
            delete[] data;

            // 小顶堆 O(nlogk)
            data = new long[size];
            read_data(data, size, i);
            start_time = GetTickCount();
            ans = heap_sort(data, K, size);
            end_time = GetTickCount();
            cout << "O(nlogk) ans:";
            for (auto x : ans)
            {
                cout << x << ' ';
            }
            cout << endl;
            sum_time_nlogk += end_time - start_time;
            delete[] data;
            cout << endl;
        }

        cout << "avg_time_nlogn = " << sum_time_nlogn / 20 << endl;
        cout << "avg_time_kn = " << sum_time_kn / 20 << endl;
        cout << "avg_time_nlogk = " << sum_time_nlogk / 20 << endl
             << endl;
        fout << size << ',' << sum_time_nlogn / 20 << ',' << sum_time_kn / 20 << ',' << sum_time_nlogk / 20 << endl;
    }
    return 0;
}

