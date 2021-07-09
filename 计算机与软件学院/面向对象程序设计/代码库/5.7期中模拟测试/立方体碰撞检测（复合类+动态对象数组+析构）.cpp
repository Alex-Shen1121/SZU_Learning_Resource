#include<iostream>
#include<cmath>
using namespace std;
class CPoint {
	int x, y, z;
	friend class CCube;
public:
	CPoint() {};
	CPoint(int _x, int _y,int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	void set(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	~CPoint() {  };
};

class CCube {
	CPoint* point;
public:
	CCube(int a,int b,int c,int d,int e,int f){
		point = new CPoint[2];
		point[0].set(a, b, c);
		point[1].set(d, e, f);
	}
	~CCube() {
		for (int i = 0; i < 2; i++)
			point[i].~CPoint();
	}
	int collide(CCube r) {
        double z1 = (r.point[0].z + r.point[1].z) / 2.0;
        double y1 = (r.point[0].y + r.point[1].y) / 2.0;
        double x1 = (r.point[0].x + r.point[1].x) / 2.0;
        double z2 = (point[0].z + point[1].z) / 2.0;
        double y2 = (point[0].y + point[1].y) / 2.0;
        double x2 = (point[0].x + point[1].x) / 2.0;

        double a = fabs(point[0].x - point[1].x) / 2.0;
        double b = fabs(r.point[0].x - r.point[1].x) / 2.0;
        double d1 = a + b;
        a = fabs(point[0].y - point[1].y) / 2.0;
        b = fabs(r.point[0].y - r.point[1].y) / 2.0;
        double d2 = a + b;
        a = fabs(point[0].z - point[1].z) / 2.0;
        b = fabs(r.point[0].z - r.point[1].z) / 2.0;
        double d3 = a + b;
        if (fabs(x1 - x2) <= d1 && fabs(y1 - y2) <= d2 && fabs(z1 - z2) <= d3)
            return 1;
        else
			return 0;
	}
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		CCube C1(x1, y1, z1, x2, y2, z2);
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		CCube C2(x1, y1, z1, x2, y2, z2);
		int check = C1.collide(C2);
		if (check == 1)
			cout << "collide" << endl;
		else if (check == 0)
			cout << "have distance" << endl;
	}
	return 0;
}
