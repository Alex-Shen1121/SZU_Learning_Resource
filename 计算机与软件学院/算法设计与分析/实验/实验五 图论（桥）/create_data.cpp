#include <iostream>
#include <sstream>
#include <random>
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

// 用于生成数据集文件

// 数据量的规模
vector<long> data_size = {1000, 2000, 3000, 5000, 8000, 10000, 15000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
// vector<long> data_size = {100, 150, 200, 250, 300};
// vector<long> data_size = {1000};

// 需要batch组数据
int batch = 1;

int main()
{
    for (int j = 1; j <= batch; j++)
    {
        for (long size : data_size)
        {
            // 均匀分布生成数据
            std::uniform_int_distribution<long long> dist(0, size - 1);
            std::random_device rd;                // Non-deterministic seed source
            std::default_random_engine rng{rd()}; // Create random number generator
            // 写入文件
            stringstream stream;
            stream << size;
            string filename;
            stream >> filename;
            filename += "_" + to_string(j) + ".txt";
            ifstream f(filename.c_str());
            if (f.good())
                continue;
            ofstream fout("dataset/" + filename, ios::trunc);
            fout << size << endl;
            fout << int(size) << endl;
            for (long long i = 0; i < int(size); i++)
            {
                fout << dist(rng) << ' ' << dist(rng) << endl;
            }
        }
    }
    return 0;
}