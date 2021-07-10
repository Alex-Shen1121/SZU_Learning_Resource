#include <iostream>
#include <sstream>
#include <random>
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

// 数据量的规模
vector<long> data_size = {50};
// vector<long> data_size = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000};

// 需要batch组数据
int batch = 10;

int main()
{
    std::random_device rd;                // Non-deterministic seed source
    std::default_random_engine rng{rd()}; // Create random number generator
    for (int j = 1; j <= batch; j++)
    {
        for (int size : data_size)
        {
            // 均匀分布生成数据
            std::uniform_int_distribution<int> dist(0, size * 1000);

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
            for (long long i = 0; i < size; i++)
            {
                fout << dist(rng) / 10000.0 << ' ' << dist(rng) / 10000.0 << endl;
            }
        }
    }
    return 0;
}