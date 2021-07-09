#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Equation
{
private:
	float a, b, c;
public:
	Equation(float x = 1, float y = 1, float z = 0)
	{
		a = x;
		b = y; 
		c = z;
	}
	~Equation()
	{

	};
	void set(float x = 1, float y = 1, float z = 0);
	void getRoot();
	
};


void Equation::set(float x, float y, float z)
{
	a = x;
	b = y;
	c = z;
}

void Equation::getRoot()
{
	float delta;
	delta = b * b - 4 * a * c;
	if (delta > 0)//有不等实根
	{
		float x1, x2;
		x1 = (-b + sqrt(delta)) / 2 / a;
		x2 = (-b - sqrt(delta)) / 2 / a;
		cout << fixed << setprecision(2) << "x1=" << x1 << " x2=" << x2 << endl;
	}
	else if (delta == 0)//两个相等实根
	{
		float x;
		x = (-b + delta) / 2 / a;
		cout << fixed << setprecision(2) << "x1=x2=" << x << endl;
	}
	else if (delta < 0)
	{
		float x, y;
		x = -b / a / 2;
		y = sqrt(-delta) / a / 2;
		cout << "x1=" << x << "+" << y << "i x2=" << x << "-" << y << "i" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float a, b, c;
		cin >> a >> b >> c;
		Equation test(a, b, c);
		test.getRoot();
	}
	return 0;
}

