#include<iostream>
#include<iomanip>
#include<cmath>
#define PI 3.14
using namespace std;

class C2D {
protected:
	int x, y;
public:
	C2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
	float distance() {
		double dis = sqrt(x*x+y*y);
		return dis;
	}
};

class C3D:public C2D{
protected:
	int z;
public:
	C3D(int x, int y, int z) :C2D(x, y) {
		this->z = z;
	}
	float distance() {
		double dis = sqrt(x * x + y * y + z * z);
		return dis;
	}
};

int main() {
	int x, y, z;
	cin >> x >> y;
	C2D p1(x, y);
	cout << p1.distance() << endl;
	cin >> x >> y >> z;
	C3D p2(x, y, z);
	cout << p2.distance() << endl;
	cin >> x >> y >> z;
	C3D p3(x, y, z);
	cout << p3.distance() << endl;
	cout << p3.C2D::distance() << endl;
	return 0;
}
