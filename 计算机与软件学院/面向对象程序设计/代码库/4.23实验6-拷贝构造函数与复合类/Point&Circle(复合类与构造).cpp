#include<iostream>
#include<cmath>
using namespace std;
class Point {
	double x, y;
public:
	Point() {
		x = 0; y = 0;
	}
	Point(double x_value, double y_value) {
		x = x_value;
		y = y_value;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void setXY(double x1,double y1) {
		x = x1;
		y = y1;
	}
	void setX(double x1) {
		x = x1;
	}
	void setY(double y1) {
		y = y1;
	}
	double getDisTo(Point& p) {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	~Point() {};
};
class Circle {
	Point centre;
	double radius;
public:
	Circle() {
		centre.setXY(0, 0);
		radius = 1;
	}
	Circle(double x1, double y1, double r1) {
		centre.setXY(x1, y1);
		radius = r1;
	}
	double getArea() {
		return 3.1415926 * radius * radius;
	}
	void moveCentreTo(double x1, double y1) {
		centre.setXY(x1, y1);
	}
	int contain(Point& p) {
		if (centre.getDisTo(p) > radius)
			return 0;
		else
			return 1;
	}
};

int main()
{
	double x, y, r;
	cin >> x >> y >> r;
	Circle c(x, y, r);
	int n, i;
	Point* p;
	cin >> n;
	p = new Point[n];
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		p[i].setXY(x, y);
		if (c.contain(p[i]) == 1)
			cout << "inside" << endl;
		else if (c.contain(p[i]) == 0)
			cout << "outside" << endl;
	}
	cin >> x >> y;
	c.moveCentreTo(x, y);
	cout << "after move the centre of circle:" << endl;
	for (i = 0; i < n; i++)
	{
		if (c.contain(p[i]) == 1)
			cout << "inside" << endl;
		else if (c.contain(p[i]) == 0)
			cout << "outside" << endl;
	}
	return 0;
}

