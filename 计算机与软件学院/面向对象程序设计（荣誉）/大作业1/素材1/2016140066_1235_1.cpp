2016140066:Problem1235:正确
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Geometry
{
public:
	virtual double getArea() = 0;
};
class Rect :public Geometry
{
protected:
	int chang, kuan;
public:
	Rect(){}
	Rect(int a, int b) :chang(a), kuan(b) {}
	virtual double getArea()
	{
		return chang * kuan;
	}
};
class Circle :public Geometry
{
protected:
	int r;
public:
	Circle(){}
	Circle(int R) :r(R) {}
	virtual double getArea()
	{
		return 3.14*r*r;
	}
};
class TotalArea
{
public:
	TotalArea(){}
	static void computerTotalArea(Geometry** t, int n)
	{
		double max;
		t = new Geometry*[n];
		for (int i = 0; i < n; i++)
		{
			t[i] = new Rect;
		}
		max = t[0]->getArea();
		for (int i = 1; i < n; i++)
		{
			if (t[i] > t[i - 1])
			{
				max = t[i]->getArea();
			}
		}
		cout << "最大面积=" << max << endl;
		delete[]t;
	}
};
int main()
{
	int t, type, a, b, r;
	double max;
	cin >> t;
	Geometry **p;
	p = new Geometry*[t];
	while (t--)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> a >> b;
			p[t] = new Rect(a, b);
		}
		else
		{
			cin >> r;
			p[t] = new Circle(r);
		}
	}
	
	for (int i = 0; i < t; i++)
	{
		p[i] = new Rect;
	}
	max = p[0]->getArea();
	for (int i = 1; i < t; i++)
	{
		if (p[i] > p[i - 1])
		{
			max = p[i]->getArea();
		}
	}
	cout << "最大面积=" << fixed<<setprecision(2)<<max << endl;
	delete[]p;
}
