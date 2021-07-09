#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//类定义
class Point
{
private:
	float x, y;
public:
	void SetPoint(float a, float b);
	float GetX();
	float GetY();
};
class Circle
{
private:
	float rx, ry, r;
public:
	void SetCenter(float x, float y);
	void SetRadius(float x);
	float getArea();
	float getLength();
	bool Contain(Point p);
};
//类实现

void Point::SetPoint(float a, float b)
{
	x = a;
	y = b;
}

float Point::GetX()
{
	return x;
}

float Point::GetY()
{
	return y;
}

void Circle::SetCenter(float x, float y)
{
	rx = x;
	ry = y;
}

void Circle::SetRadius(float x)
{
	r = x;
}

float Circle::getArea()
{
	return 3.14 * r * r;
}

float Circle::getLength()
{
	return 2 * 3.14 * r;
}

bool Circle::Contain(Point p)
{
	float temp;
	temp = sqrt(pow(p.GetX() - rx, 2) + pow(p.GetY() - ry, 2));
	if ((temp - r) < 0.000001)
		return true;
	else
		return false;
}

int main()
{
	float x, y, r;
	Circle C1;
	Point P;
	cin >> x >> y >> r;
	C1.SetCenter(x, y);
	C1.SetRadius(r);
	cin >> x >> y;
	P.SetPoint(x, y);
	cout << fixed << setprecision(2) << C1.getArea() << ' ' << C1.getLength() << endl;
	if (C1.Contain(P))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
