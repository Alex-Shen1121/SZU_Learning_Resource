#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point
{
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};
Point::Point()
{
	x = y = 0;
}
Point::Point(double x_value, double y_value):x(x_value),y(y_value)
{
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setX(double x_value)
{
	x = x_value;
}
void Point::setY(double y_value)
{
	y = y_value;
}
double Point::distanceToAnotherPoint(Point p)
{
	return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double x, y;
		cin >> x >> y;
		Point p1(x, y);
		cin >> x >> y;
		Point p2(x, y);
		cout << fixed << setprecision(2) << "Distance of Point(" << p1.getX() << ',' << p1.getY() << ") to Point(" << p2.getX() << ',' << p2.getY() << ") is " << p1.distanceToAnotherPoint(p2) << endl;
	}
	return 0;
}
