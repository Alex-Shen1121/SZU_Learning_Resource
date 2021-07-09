#include<iostream>
using namespace std;
void find(int* num, int n, int& minIndex, int& maxIndex)
{
	int i;
	minIndex = 0;
	maxIndex = 0;
	for (i = 0; i < n; i++)
	{
		if (*(num + i) < *(num + minIndex))
			minIndex = i;
		else continue;
	}
	for (i = 0; i < n; i++)
	{
		if (*(num + i) > * (num + maxIndex))
			maxIndex = i;
		else continue;
	}
	cout << "min=" << *(num + minIndex) << " minindex=" << minIndex << endl
		<< "max=" << *(num + maxIndex) << " maxindex=" << maxIndex << endl << endl;
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int n, i;
		int minIndex, maxIndex;
		cin >> n;
		int* p = new int[n];
		for (i = 0; i < n; i++)
			cin >> *(p + i);
		find(p, n, minIndex, maxIndex);
		delete[]p;
	}
	return 0;
}
