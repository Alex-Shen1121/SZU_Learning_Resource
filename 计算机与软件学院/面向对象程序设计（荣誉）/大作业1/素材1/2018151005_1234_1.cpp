2018151005:Problem1234:正确
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
class Group
{
public:
	virtual int add(int x, int y) = 0;//输出加法的运算结果
	virtual int sub(int x, int y) = 0;//输出减法的运算结果
};
class GroupA:public Group
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
		int sum = 0;
		int i = 0;
		while (!(x == 0 && y == 0))
		{
			int a = x % 10;
			int b = y % 10;
			int c = a - b;
			if (c < 0)
				c += 10;
			sum += (int)pow(10, i)*c;
			x /= 10;
			y /= 10;
			i++;
		}
		return sum;
	}
};
class GroupC: public Group
{
public:
	int add(int x, int y)
	{
		int sum = 0;
		int i = 0;
		while (!(x == 0 && y == 0))
		{
			int a = x % 10;
			int b = y % 10;
			int c = a + b;
			if (c >= 10)
				c -= 10;
			sum += (int)pow(10, i)*c;
			x /= 10;
			y /= 10;
			i++;
		}
		return sum;
	}
	int sub(int x, int y)
	{
		int sum = 0;
		int i = 0;
		while (!(x == 0 && y == 0))
		{
			int a = x % 10;
			int b = y % 10;
			int c = a - b;
			if (c < 0)
				c += 10;
			sum += (int)pow(10, i)*c;
			x /= 10;
			y /= 10;
			i++;
		}
		return sum;
	}
};
void change(char* str, int &num1, int &num2, char &sign)
{
	char str1[5], str2[5];
	int i = 1;
	while (str[i-1] >= '0'&&str[i-1] <= '9')
	{
		str1[i-1] = str[i-1];
		i++;
	}
	str1[i - 1] = '\0';
	sign = str[i-1];
	int j = i;
	i++;
	while (str[i - 1] >= '0'&&str[i - 1] <= '9')
	{
		str2[i - j - 1] = str[i - 1];
		i++;
	}
	str2[i - j - 1] = '\0';
	num1 = atoi(str1);
	num2 = atoi(str2);
}
int main()
{
	int t;
	cin >> t;
	Group* p;
	while (t--)
	{
		int type;
		char str[16];
		int x, y;
		char sign;
		cin >> type >> str;
		change(str, x, y, sign);
		int sum;
		switch (type)
		{
		case 1:
			{
				GroupA a;
				p = &a;
				if (sign == '+')
					sum = p->add(x, y);
				else if (sign == '-')
					sum = p->sub(x, y);
				break;
			}
		case 2:
			{
				GroupB a;
				p = &a;
				if (sign == '+')
					sum = p->add(x, y);
				else if (sign == '-')
					sum = p->sub(x, y);
				break;
				break;
			}
		case 3:
			{
				GroupC a;
				p = &a;
				if (sign == '+')
					sum = p->add(x, y);
				else if (sign == '-')
					sum = p->sub(x, y);
				break;
				break;
			}
		}
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}
