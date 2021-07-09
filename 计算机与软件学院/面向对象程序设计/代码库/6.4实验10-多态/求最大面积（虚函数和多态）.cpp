#include<iostream>
#include<iomanip>
using namespace std;
#define PI 3.14

class Geometry {
public:
	virtual double getArea() = 0; //计算面积，结果保留小数点后两位
};

class Rect :public Geometry {
	double w, l;
public:
	Rect(double a, double b) {
		w = a;
		l = b;
	}
	double getArea() {
		return w * l;
	}
};

class Circle :public Geometry {
	double r;
public:
	Circle(double a) {
		r = a;
	}
	double getArea() {
		return r * r * PI;
	}
};

class TotalArea {
public:
	static void computerTotalArea(Geometry** t, int n) {
		double max;
		max = t[0]->getArea();
		for (int i = 1; i < n; i++) {
			if (t[i]->getArea() > max)
				max = t[i]->getArea();
		}
		cout << "最大面积=" << fixed << setprecision(2) << max << endl;
	}

};

int main() {
	int t;
	cin >> t;
	Geometry** p = new Geometry*[t];
	for (int i = 0; i < t; i++) {
		int type;
		cin >> type;
		switch (type) {
		case 1: {
			int w, l;
			cin >> w >> l;
			p[i] = new Rect(w, l);
			break;
		}
		case 2: {
			int r;
			cin >> r;
			p[i] = new Circle(r);
			break;
		}
		}
	}
	TotalArea::computerTotalArea(p, t);
	return 0;
}
