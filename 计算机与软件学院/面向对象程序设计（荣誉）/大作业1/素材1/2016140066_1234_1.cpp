2016140066:Problem1234:ÕıÈ·
#include <iostream>
using namespace std;
class Group
{
public:
	virtual int add(int x, int y) = 0;
	virtual int sub(int x, int y) = 0;
};
class GroupA:public Group
{
public:
	virtual int add(int x, int y)
	{
		return x + y;
	}
	virtual int sub(int x, int y)
	{
		return x - y;
	}
};
class GroupB:public Group
{
public:
	virtual int add(int x, int y)
	{
		return x + y;
	}
	virtual int sub(int x, int y)
	{
		if (((x % 10) < (y % 10)) && (((x % 100) / 10) >= ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y + 10;
		}
		else if (((x % 10) < (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y+110;
		}
		else if (((x % 10) < (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) < ((y % 1000) / 100)))
		{
			return x - y + 1110;
		}
		else if (((x % 10) >= (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y + 100;
		}
		else if (((x % 10) >= (y % 10)) && (((x % 100) / 10) >= ((y % 100) / 10)) && (((x % 1000) / 100) < ((y % 1000) / 100)))
		{
			return x - y + 100;
		}
	}
};
class GroupC :public Group
{
public:
	virtual int add(int x, int y)
	{
		int sum;
		sum = x + y;
		if (((x % 10) + (y % 10)) >= 10)
		{
			sum =sum- 10;
		}
		if (((x % 100) / 10) + ((y % 100) / 10) >= 10)
		{
			sum=sum - 100;
		}
		if (((x % 1000) / 100) + ((y % 1000) / 100) >= 10)
		{
			sum=sum - 1000;
		}
		return sum;
	}
	virtual int sub(int x, int y)
	{
		if (((x % 10) < (y % 10)) && (((x % 100) / 10) >= ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y + 10;
		}
		else if (((x % 10) < (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y + 110;
		}
		else if (((x % 10) < (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) < ((y % 1000) / 100)))
		{
			return x - y + 1110;
		}
		else if (((x % 10) >= (y % 10)) && (((x % 100) / 10) < ((y % 100) / 10)) && (((x % 1000) / 100) >= ((y % 1000) / 100)))
		{
			return x - y + 100;
		}
		else if (((x % 10) >= (y % 10)) && (((x % 100) / 10) >= ((y % 100) / 10)) && (((x % 1000) / 100) < ((y % 1000) / 100)))
		{
			return x - y + 100;
		}
	}
};
int main()
{
	int t,x,y,type;
	char f;
	Group *p;
	cin >> t;
	while (t--)
	{
		cin >> type >> x >> f >> y;
		if (type == 1)
		{
			GroupA s;
			p = &s;
			if (f == '+')
			{
				cout << p->add(x, y) << endl;
			}
			else
			{
				cout << p->sub(x, y) << endl;
			}

		}
		else if (type == 2)
		{
			GroupB s;
			p = &s;
			if (f == '+')
			{
				cout << p->add(x, y) << endl;
			}
			else
			{
				cout << p->sub(x, y) << endl;
			}
		}
		else if (type == 3)
		{
			GroupC s;
			p = &s;
			if (f == '+')
			{
				cout << p->add(x, y) << endl;
			}
			else
			{
				cout << p->sub(x, y) << endl;
			}

		}
	}
	return 0;
}
