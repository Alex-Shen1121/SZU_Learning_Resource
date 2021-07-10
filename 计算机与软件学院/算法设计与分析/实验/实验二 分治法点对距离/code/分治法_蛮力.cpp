#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <Windows.h>
#include <queue>

using namespace std;

class Point
{
public:
    double x, y;
    Point(){};
    Point(double X, double Y) : x(X), y(Y){};
};

// 数据量的规模
vector<long> data_size = {50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};

// 测试次数
int batch = 10;

// 读取数据
void read_data(vector<Point> &data, int size, int batch)
{
    string filename;
    stringstream stream;
    stream << size;
    stream >> filename;
    filename += "_" + to_string(batch) + ".txt";
    ifstream fin("dataset/" + filename);
    double x, y;
    string s;
    int cnt = 0;
    while (fin >> x >> y)
    {
        cnt++;
        Point temp(x, y);
        data.push_back(temp);
    }
    // cout << cnt << endl;
    fin.close();
    //cout << filename << endl;
}

bool cmpx(const Point &p1, const Point &p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

bool cmpy(const Point &p1, const Point &p2)
{
    if (p1.y == p2.y)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

// 打印点集
void print(vector<Point> &data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i].x << ' ' << data[i].y << endl;
    }
    cout << endl;
}

double dis(Point &p1, Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool check(Point &p1, Point &p2, double d)
{
    return (p2.y >= p1.y - d) && (p2.y <= p1.y + d);
}
double cal_x(vector<Point> &data, int l, int r)
{
    double sum = 0;
    for (int i = 0; i < r - l; i++)
        sum += data[i + l].x;
    return sum / (r - l);
}
// 分治法计算
double cal(vector<Point> &data, int l, int r)
{
    if (l >= r)
        return (double)INT_MAX;
    if (l + 1 == r)
        return dis(data[l], data[r]);
    int mid = (l + r) / 2;
    double d = min(cal(data, l, mid), cal(data, mid + 1, r)), ans = d;
    vector<Point> left, right;
    for (int i = mid; i >= l && data[i].x > data[mid].x - d; i--)
        left.push_back(data[i]);
    for (int i = mid + 1; i <= r && data[i].x < data[mid].x + d; i++)
        right.push_back(data[i]);
    int j = 0;
    for (int i = 0; i < left.size(); i++)
    {
        for (int t = 0; t < right.size(); t++)
        {
            if (left[i].x != right[j].x && left[i].y != right[j].y)
                ans = min(ans, dis(left[i], right[t]));
        };
        //     while (h < rr.size() && rr[h].y + d < ll[i].y)
        //         h++;
        // h = min((int)rr.size(), h);
        // for (int j = h; j < min((int)rr.size(), h + 6); j++)
        //     if (!eqfunc()(ll[i], rr[j]))
        //         ans = lfmin(ans, dis(ll[i], rr[j]));
    }
    return min(ans, d);
    // cout << "最小点对为P" << mini << " (" << data[mini].x << " ," << data[mini].y << " )与"
    //      << "P " << minj << "(" << data[minj].x << ", " << data[minj].y << ")" << endl;
    // cout << "距离为" << min << endl;
    // cout << endl;
}

int main()
{
    DWORD start_time, end_time;
    ofstream fout("data_analysis/analysis_5.csv");
    fout << "data_size" << ',' << "time" << endl;
    for (int j = 0; j < data_size.size(); j++)
    {
        long size = data_size[j];
        DWORD sum_time = 0, start_time = 0, end_time = 0;
        for (int i = 1; i <= batch; i++)
        {
            if (i == 1)
                cout << "data_size: " << size << endl;
            vector<Point> data;
            read_data(data, size, i);
            sort(data.begin(), data.end(), cmpx);
            start_time = GetTickCount();
            // print(data, size);
            double ans = cal(data, 0, data.size() - 1);
            end_time = GetTickCount();
            cout << ans << ' ';
            sum_time += end_time - start_time;
        }

        cout << endl
             << "avg_time = " << sum_time / batch << endl
             << endl;
        fout << size << ',' << sum_time / batch << endl;
    }
    return 0;
}