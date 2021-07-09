#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int m, n, min=0, max=0, i;
		cin >> m >> n;
		int *p= new int[m*n];
		for (i = 0; i < m * n; i++)
			cin >> *(p + i);
		min = *p;
		max = *p;
		for (i = 0; i < m * n; i++)
		{
			if (*(p + i) < min)
				min = *(p + i);
			if (*(p + i) > max)
				max= *(p + i);
		}
		cout << min << ' ' << max << endl;
	}
 	return 0;
}
