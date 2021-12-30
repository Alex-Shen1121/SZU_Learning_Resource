#include <bits/stdc++.h>

#define B 1
#define KB 1024
#define MB 1048576 

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

random_device rd;//随机数生成
mt19937 gen(rd());

void random_access(int size)
{
	int n = size / sizeof(char);
	char* buffer = new char[n];
	fill(buffer, buffer+n, 1);
	
	uniform_int_distribution<> dis(0, n-1);
	
	int test_times = 11451419 * 10;
	
	vector<int> random_index;
	for(int i=0; i<test_times; i++)
	{
		int index = dis(gen);
		random_index.push_back(index); 
	}
	
	int sum = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i=0; i<test_times; i++)
	{
		sum += buffer[random_index[i]];
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	double dt = time_span.count();
	
	cout<<(size/1024)<<" "<<(((double)sum/1024.0) / dt)<<endl;
	
	delete[] buffer;
}

void test1()
{
	int size = 64 * KB;
	vector<int> sizes{128*KB,192*KB,256*KB,384*KB,512*KB,640*KB,1024*KB,1536*KB,2048*KB,3072*KB,4096*KB,6144*KB,8192*KB,9*1024*KB,12*1024*KB,14*1024*KB,16*1024*KB,18*1024*KB};

	for(auto s : sizes)
	{
		random_access(s);
	}
}

void stride_access(char* buffer, int stride, int size)
{
	int n = size / sizeof(char);
	int sum = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int j=0; j<stride; j++)
	{
		for(int i=0; i<n; i+=stride)
		{
			sum += buffer[i];
		}
	}
		
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	double dt = time_span.count();

	cout<<stride<<" "<<(((double)sum/1024.0) / dt)<<endl;
}

void test2()
{
	int size = 400 * MB;
	int n = size / sizeof(char);
	char* buffer = new char[n];
	fill(buffer, buffer+n, 1);
	
	vector<int> strides{1*B,2*B,4*B,8*B,16*B,32*B,64*B,96*B,128*B,192*B,256*B,512*B,1024*B,1536*B,2048*B};
	
	for(auto s : strides)
	{
		stride_access(buffer, s, size);
	}
}

int main()
{
	// test1();
	test2();
	
	return 0;
}
