2018151014:Problem1235:答案错误
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Geometry {
public:
	virtual double getArea() = 0;
};

class Rect : public Geometry {
public:
	Rect(double l, double w) : length(l), width(w) {
		
	}
	
	double getArea() {
		return length * width;
	}
private:
	double length;
	double width;
};

class Circle : public Geometry {
public:
	Circle(double r) : radius(r) {
	
	}
	
	double getArea() {
		return 3.14 * radius * radius;
	}
protected:
	double radius;
};

class TotalArea {	
public:
	static void computerTotalArea(Geometry **t, int n) {
		double *areas = new double[n];
		
		for (int i = 0; i < n; i++) {
			areas[i] = t[i]->getArea();
		}
		
		double max_value = areas[0];
		for (int i = 1; i < n; i++) {
			if (areas[i] > max_value) {
				max_value = areas[i];
			}
		} 
		
		cout << "最大面积=" << max_value;
		delete[] areas;
	}
};

int main(void) {
	
	int t;
	cin >> t;
	
	Geometry **ptr = new Geometry *[t];
	for (int i = 0; i < t; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			double x;
			double y;
			
			cin >> x >> y;
			ptr[i] = new Rect(x, y);
		}
		else if (type == 2) {
			double r;
			
			cin >> r;
			ptr[i] = new Circle(r);
		}
	}
	
	TotalArea::computerTotalArea(ptr, t);
	for (int i = 0; i < t; i++) {
		delete ptr[i];
	}
	delete[] ptr;
	
	return 0;
}
