#include<iostream>
using namespace std;
int main()
{
	int I, N;
	cin >> I;
	for (N = 1; N <= I; N++)
	{
		int n=0,i=0,k=0;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			if ((i % 7 == 0) && (i % 3 != 0) && (i % 4 != 0))
				k++;
		}
		cout << k<< endl;
	}
	return 0;
}
