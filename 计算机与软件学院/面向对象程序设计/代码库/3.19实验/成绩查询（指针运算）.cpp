#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, n, a[100], * p1, x, * p2, * p, * p3, * pmid;
		cin >> n;
		for (i = 0 ; i < n; i++)
			cin >> a[i];
		pmid = &a[n / 2];
		p1 = --pmid;
		p2 = pmid + 2;
		cout << *p1 << ' ' << *p2 << endl;
		cin >> x;
		p3 = pmid - (n / 2 - x);
		cout << *p3 << endl;
	}
	return 0;
}
