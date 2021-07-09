#include<iostream>
#include<algorithm>
using namespace std;

class point {
		int x, y, z;
	public:
		point(int X = 0, int Y = 0, int Z = 0) {
			x = X;
			y = Y;
			z = Z;
		}
		void set(int X = 0, int Y = 0, int Z = 0) {
			x = X;
			y = Y;
			z = Z;
		}
		friend point operator++(point& a);
		friend point operator++(point& a, int);
		friend point operator--(point& a);
		friend point operator--(point& a, int);
		void show() {
			cout << "x=" << x << " y=" << y << " z=" << z << endl;
		}
};


int main() {
	int x, y, z;
	cin >> x >> y >> z;
	point p1(x, y, z);
	p1++;
	p1.show();
	p1.set(x, y, z);
	point p2 = p1++;
	p2.show();
	p1.set(x, y, z);
	(++p1).show();
	p1.show();
	p1.set(x, y, z);
	p1--;
	p1.show();
	p1.set(x, y, z);
	p1.show();
	(--p1).show();
	p1.show();
}

point operator++(point& a) {
	a.x++;
	a.y++;
	a.z++;
	return a;
}

point operator++(point& a, int) {
	point temp = a;
	a.x++;
	a.y++;
	a.z++;
	return temp;
}

point operator--(point& a) {
	a.x--;
	a.y--;
	a.z--;
	return a;
}

point operator--(point& a, int) {
	point temp = a;
	a.x--;
	a.y--;
	a.z--;
	return temp;
}

