#include<iostream>
#include<string.h>
using namespace std;
int cal(int a, int b)
{
	int i,x=1;
	for (i = 0; i < b; i++)
		x *= a;
	return x;
}
int isNumber(char* p, int l)
{
	int i, sum = 0;
	for (i = 0; i < l; i++)
	{
		if (*(p + i) <= '9' && *(p + i) >= '0')
			continue;
		else
			return -1;
	}
	for (i = 0; i < l; i++)
		sum += (*(p + i) - '0') * cal(10, l - 1 - i);
	return sum;
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int l, x;
		char* p = new char[100];
		cin >> p;
		l = strlen(p);
		x = isNumber(p, l);
		cout << x << endl;
		delete []p;
	}
	return 0;
}
