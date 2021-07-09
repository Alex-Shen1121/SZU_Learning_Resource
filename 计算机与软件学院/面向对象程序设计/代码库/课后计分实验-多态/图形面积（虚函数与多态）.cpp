#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

class Shape {
public:
	virtual void Area() = 0;
};

class Circle :public Shape {
	double r;
public:
	Circle(double x) :r(x) {};
	void Area() {
		cout << fixed << setprecision(2) << PI * r * r << endl;
	}
};

class Square :public Shape {
	double r;
public:
	Square(double x) :r(x) {};
	void Area() {
		cout << fixed << setprecision(2) << r * r << endl;
	}
};

class Rectangle :public Shape {
	double w, l;
public:
	Rectangle(double x, double y) :w(x), l(y) {};
	void Area() {
		cout << fixed << setprecision(2) << w * l << endl;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		Shape* p;
		double r, a, w, l;
		cin >> r >> a >> w >> l;
		Circle obj1(r);
		Square obj2(a);
		Rectangle obj3(w, l);
		p = &obj1;
		p->Area();
		p = &obj2;
		p->Area();
		p = &obj3;
		p->Area(); 
	}
	return 0;
}
