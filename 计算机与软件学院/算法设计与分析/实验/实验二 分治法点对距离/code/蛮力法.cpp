#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <Windows.h>

using namespace std;

class Point
{
public:
    double x, y;
    Point(){};
    Point(double X, double Y) : x(X), y(Y){};
};

// �������Ĺ�ģ
vector<int> data_size = {50};

// ���Դ���
int batch = 10;

// ��ȡ����
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

// ��ӡ�㼯
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
    double x = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return x;
}

// ����������
void cal(vector<Point> &data, int size)
{
    double min = 99999;
    int mini = 0, minj = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            double x = dis(data[i], data[j]);
            // cout<<x<<endl;
            if (x < min)
            {
                min = x;
                mini = i;
                minj = j;
            }
        }
    }
    // cout << "��̵��Ϊ�㣺P" << mini << "(" << data[mini].x << " ," << data[mini].y << " )��"
    //      << "P" << minj << "(" << data[minj].x << ", " << data[minj].y << ")" << endl;
    cout << min<<' ' ;
    // cout << endl;
}

int main()
{
    DWORD start_time, end_time;
    ofstream fout("data_analysis/analysis.csv");
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
            start_time = GetTickCount();
            // print(data, size);
            cal(data, size);
            end_time = GetTickCount();
            sum_time += end_time - start_time;
        }

        cout << "avg_time = " << sum_time / batch << endl
             << endl;
        fout << size << ',' << sum_time / batch << endl;
    }
    return 0;
}