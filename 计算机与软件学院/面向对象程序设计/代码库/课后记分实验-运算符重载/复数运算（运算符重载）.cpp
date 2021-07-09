#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Complex
{
private:
	int a, b;
public:
	Complex() {
		a = 0; b = 0;
	};
	Complex(int x, int y)
	{
		a = x;
		b = y;
	};
	Complex operator+(Complex& c2)
	{
		Complex temp;
		temp.a = a + c2.a;
		temp.b = b + c2.b;
		return temp;
	}
	Complex operator-(Complex& c2)
	{
		Complex temp;
		temp.a = a - c2.a;
		temp.b = b - c2.b;
		return temp;
	}
	void print()
	{
		if (a == 0 && b == 0)
			cout << "0" << endl;
		else if (a == 0)
		{
			if (b == 1)
				cout << "i" << endl;
			else if (b == -1)
				cout << "-i" << endl;
			else
				cout << b << "i" << endl;
		}
		else if (b == 0)
			cout << a << endl;
		else
		{
			if (b == 1)
				cout << a << "+" << "i" << endl;
			else if (b == -1)
				cout << a << "-i" << endl;
			else if (b > 0)
				cout << a << "+" << b << "i" << endl;
			else if (b < 0)
				cout << a << b << "i" << endl;
		}
	};
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		Complex C1(a, b);
		cin >> a >> b;
		Complex C2(a, b);
		Complex C3;
		C3 = C1 + C2;
		C3.print();
		C3 = C1 - C2;
		C3.print();
	}
	return 0;
}
