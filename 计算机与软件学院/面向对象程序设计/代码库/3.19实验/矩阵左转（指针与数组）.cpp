#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a[2][3], i, j;
		int* p;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 3; j++)
				cin >> a[i][j];
		p = a[0];
		for (j = 2; j >= 0; j--)
		{
			for (i = 0; i < 2; i++)
				cout << *(p + j + i * 3) << ' ';
			cout << endl;
		}
			
				
	}
	return 0;
}
