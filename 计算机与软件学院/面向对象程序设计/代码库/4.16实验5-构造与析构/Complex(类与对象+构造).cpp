#include<iostream>
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
	void sum(Complex& c2)
	{
		Complex temp;
		temp.a = a + c2.a;
		temp.b = b + c2.b;
		cout << "sum:";
		print(temp);
	}
	void sub(Complex& c2)
	{
		Complex temp;
		temp.a = a - c2.a;
		temp.b = b - c2.b;
		cout << "remainder:";
		print(temp);
	}
	void print(Complex temp)
	{
		if (temp.a == 0 && temp.b == 0)
			cout << "0" << endl;
		else if (temp.a == 0)
		{
			if (temp.b != 1)
				cout << temp.b << "i" << endl;
			else
				cout << "i" << endl;
		}	
		else if (temp.b == 0)
			cout << temp.a << endl;
		else
		{
			if(temp.b==1)
				cout << temp.a << "+" << "i" << endl;
			else if(temp.b==-1)
				cout << temp.a <<  "-i" << endl;
			else if(temp.b>0)
				cout << temp.a << "+" << temp.b << "i" << endl;
			else if(temp.b<0)
				cout << temp.a << temp.b << "i" << endl;
		}
	};
	~Complex(){};
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
		C1.sum(C2);
		C1.sub(C2);
	}
	return 0;
}
