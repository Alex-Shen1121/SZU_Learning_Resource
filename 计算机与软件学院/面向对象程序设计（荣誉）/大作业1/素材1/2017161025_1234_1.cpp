2017161025:Problem1234:正确
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Group
{

public:

	virtual int add(int x, int y) = 0;//输出加法的运算结果

	virtual int sub(int x, int y) = 0;//输出减法的运算结果

};

class GroupA : public Group
{
	virtual int add(int x, int y)
	{
		return x + y;
	}

	virtual int sub(int x, int y)
	{
		return x - y;
	}
};

class GroupB : public Group
{
	virtual int add(int x, int y)
	{
		return x + y;
	}

	virtual int sub(int x, int y)
	{
		int res = 0;
		int flag = 0;

		while (max(x, y))
		{
			int tmp = x % 10 - y % 10;

			if (tmp < 0)
				tmp += 10;

			res += tmp * pow(10, flag++);

			x /= 10;
			y /= 10;
		}

		return res;
	}
};

class GroupC : public Group
{
	virtual int add(int x, int y)
	{
		int res = 0;
		int flag = 0;

		while (max(x, y))
		{
			int tmp = x % 10 + y % 10;

			if (tmp > 9)
				tmp -= 10;

			res += tmp * pow(10, flag++);

			x /= 10;
			y /= 10;
		}

		return res;
	}

	virtual int sub(int x, int y)
	{
		int res = 0;
		int flag = 0;

		while (max(x, y))
		{
			int tmp = x % 10 - y % 10;

			if (tmp < 0)
				tmp += 10;

			res += tmp * pow(10, flag++);

			x /= 10;
			y /= 10;
		}

		return res;
	}
};

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int type;
		cin >> type;

		Group * p = nullptr;

		if (type == 1)
			p = new GroupA();
		else if (type == 2)
			p = new GroupB();
		else
			p = new GroupC();

		int x, y;
		char sym;

		cin >> x >> sym >> y;

		cout << (sym == '+' ? p->add(x, y) : p->sub(x, y)) << endl;

		delete p;
	}

	return 0;
}
