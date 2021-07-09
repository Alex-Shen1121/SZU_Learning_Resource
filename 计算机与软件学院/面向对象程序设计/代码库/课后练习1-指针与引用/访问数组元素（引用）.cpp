#include<iostream>
#define N 1000
using namespace std;
int& put(int* p, int i)
{
	return *(p + i);
}
int main()
{
	int num[N];
	int t, n, sum, i;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> put(num, i);
		}
		for (sum = 0, i = 0; i < n; i++)
			sum += num[i];
		cout << "sum=" << sum << endl;
	}
	return 0;
}
