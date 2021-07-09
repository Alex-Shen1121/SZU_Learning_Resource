#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class CRectangle;

class CPoint {
	float x, y;
public:
	CPoint(float _x = 0, float _y = 0) {
		x = _x;
		y = _y;
	}
	float getX() {
		return x;
	}
	float getY() {
		return y;;
	}
	bool operator==(CPoint& p) {
		if (x == p.x && y == p.y)
			return true;
		else
			return false;
	}
};

class CRectangle {
	CPoint p1, p2;
public:
	CRectangle():p1(0, 0), p2(0, 0) {};
	CRectangle(int x1, int y1, int x2, int y2) :p1(x1, y1), p2(x2, y2) {};
	operator int() {
		return (p2.getX() - p1.getX()) * (p1.getY() - p2.getY());
	}
	friend ostream& operator<<(ostream& out, CRectangle& obj) {
		out << obj.p1.getX() << " " << obj.p1.getY() << " " << obj.p2.getX() << " " << obj.p2.getY();
		return out;
	}
	bool operator==(CRectangle& obj) {
		if (p1 == obj.p1 && p2 == obj.p2)
			return true;
		else
			return false;
	}
	bool operator>(CPoint& p) {
		if ((p.getX() <= p2.getX() && p.getX() >= p1.getX()) && (p.getY() <= p1.getY() && p.getY() >= p2.getY()))
			return true;
		else
			return false;
	}
	bool operator*(CRectangle& R2) {
		if (R2.p2.getX() < p1.getX() || R2.p2.getY() > p1.getY() || R2.p1.getX() > p2.getX() || R2.p1.getY() < p2.getY())
			return false;
		else
			return true;
	}
	bool operator>(CRectangle& obj) {
		if (*this > obj.p1 && *this > obj.p2)
			return true;
		else
			return false;
	}
};

int main() {
	int t, x1, x2, y1, y2;
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect1(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect2(x1, y1, x2, y2);
		cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
		cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
		if (rect1 == rect2)
			cout << "矩形1和矩形2相等" << endl;
		else if (rect2 > rect1)
			cout << "矩形2包含矩形1" << endl;
		else if (rect1 > rect2)
			cout << "矩形1包含矩形2" << endl;
		else if (rect1 * rect2)
			cout << "矩形1和矩形2相交" << endl;
		else
			cout << "矩形1和矩形2不相交" << endl;
		cout << endl;
	}
	return 0;
}



