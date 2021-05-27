2018152029:Problem1234:��ȷ
#include<bits/stdc++.h>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y) = 0;//����ӷ���������
	virtual int sub(int x, int y) = 0;//���������������
	virtual ~Group() {}
};

class GroupA :public Group
{
public:
	int add(int x, int y)
	{
		return x + y;
	}
	int sub(int x, int y)
	{
		return x - y;
	}
};

class GroupB :public Group
{
public:
	int add(int x, int y)
	{
		return x + y;
	}
	int sub(int x, int y)
	{
		int a[100], i = 0;
		while (x || y)
		{
			a[i++] = (10 + x % 10 - y % 10) % 10;
			x /= 10;
			y /= 10;
		}
		int res = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			res = res * 10 + a[j];
		}
		return res;
	}
};

class GroupC :public Group
{
public:
	int add(int x, int y)
	{
		int a[100], i = 0;
		while (x || y)
		{
			a[i++] = (x % 10 + y % 10) % 10;
			x /= 10;
			y /= 10;
		}
		int res = 0;
		for (int j = i - 1; j >= 0; j--)
			res = res * 10 + a[j];
		return res;
	}
	int sub(int x, int y)
	{
		int a[100], i = 0;
		while (x || y)
		{
			a[i++] = (10 + x % 10 - y % 10) % 10;
			x /= 10;
			y /= 10;
		}
		int res = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			res = res * 10 + a[j];
		}
		return res;
	}
};

int main()
{
	int T;
	cin >> T;
	Group *pv;
	while (T--)
	{
		int judge, a, b;
		char c;
		cin >> judge >> a >> c >> b;
		if (judge == 1)
			pv = new GroupA;
		else if (judge == 2)
			pv = new GroupB;
		else
			pv = new GroupC;
		if (c == '+')
			cout << pv->add(a, b) << endl;
		else
			cout << pv->sub(a, b) << endl;
		delete pv;
	}
	//system("pause");
	return 0;
}
