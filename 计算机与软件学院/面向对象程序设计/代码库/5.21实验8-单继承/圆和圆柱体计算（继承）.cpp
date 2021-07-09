#include<iostream>
#include<iomanip>
#define PI 3.14
using namespace std;
class CPoint {
protected:
	float x, y;
public:
	CPoint() {
		x = 0;
		y = 0;
	}
	CPoint(float x, float y) {
		this->x = x;
		this->y = y;
	}
	void displayPoint() {
		cout << "(" << x << "," << y << ")";
	}
};

class CCircle :public CPoint {
protected:
	float r;
public:
	CCircle():CPoint() {
		r = 0;
	}
	CCircle(float x,float y,float r) :CPoint(x,y){
		this->r = r;
	}
	void displayCircle() {
		cout << "Circle:" << setprecision(0) << "(" << x << "," << y << ")" << "," << r << endl;
		cout << "Area:" << fixed << setprecision(2) << PI * r * r << endl;
	}
};

class CCylinder :public CCircle {
protected:
	float h;
public:
	CCylinder():CCircle() {
		h = 0;
	}
	CCylinder(float x, float y, float r, float h) :CCircle(x, y, r) {
		this->h = h;
	}
	void displayCylinder() {
		cout << "Cylinder:" << setprecision(0) << "(" << x << "," << y << ")" << "," << r << "," << h << endl;
		cout << "Volume:" << fixed << setprecision(2) << PI * r * r * h << endl;
	}
};

int main() {
	float x, y, r, h;
	cin >> x >> y >> r;
	CCircle circle(x, y, r);
	circle.displayCircle();
	cin >> x >> y >> r >> h;
	CCylinder cylinder(x, y, r, h);
	cylinder.displayCylinder();
	return 0;
}
