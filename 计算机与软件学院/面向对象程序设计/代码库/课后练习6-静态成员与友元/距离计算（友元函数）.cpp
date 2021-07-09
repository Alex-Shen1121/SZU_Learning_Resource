#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Point {
public:
	Point(double xx, double yy);
	friend double Distance(Point& a, Point& b);
private:
	double x, y;
};

Point::Point(double xx, double yy)
{
	x = xx;
	y = yy;
}

double Distance(Point& a, Point& b)
{
	double dis;
	dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return dis;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point a(x1, y1), b(x2, y2);
		cout <<fixed << setprecision(0) << Distance(a, b) << endl;
	}
	return 0;
}
