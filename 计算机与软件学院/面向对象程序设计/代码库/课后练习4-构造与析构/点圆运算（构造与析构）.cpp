#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
	float x, y;
	
public:
	Point* p;
	Point(float xi = 0, float yi = 0)
	{
		x = xi;
		y = yi;
	};
	void newP(int n)
	{
		p = new Point[n];
	}
	void setXY(float xi = 0, float yi = 0)
	{
		x = xi;
		y = yi;
	}
	float getX()
	{
		return x;
	};
	float getY()
	{
		return y;
	};
	~Point()
	{
		x = 0;
		y = 0;
		cout << "point clear" << endl;
	}
};

class Circle
{
public:
	float rx, ry, r;
public:
	Circle(float xi, float yi, float ri)
	{
		rx = xi;
		ry = yi;
		r = ri;
	};
	bool Contain(Point& p)
	{
		float temp;
		temp = sqrt((p.getX() - rx) * (p.getX() - rx) + (p.getY() - ry) * (p.getY() - ry));
		if (temp <= r)
			return true;
		else
			return false;
	};
	~Circle()
	{
		rx = 0;
		ry = 0;
		r = 0;
		cout << "circle clear" << endl;
	};
};

int main()
{
	float x, y, r;
	cin >> x >> y;
	Point p1(x, y);
	int n;
	cin >> n;
	p1.newP(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		p1.p[i].setXY(x, y);
	}
		
	cin >> x >> y >> r;
	Circle c1(x, y, r);
	if (c1.Contain(p1))
		cout << "in" << endl;
	else
		cout << "out" << endl;
	for (int i = 0; i < n; i++)
	{
		if (c1.Contain(p1.p[i]))
			cout << "in" << endl;
		else
			cout << "out" << endl;
	}
	return 0;
}
