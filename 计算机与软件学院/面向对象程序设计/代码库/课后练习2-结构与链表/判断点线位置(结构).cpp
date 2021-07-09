#include<iostream>
using namespace std;
struct SPoint {
	int x, y;
};
struct SLine {
	SPoint p1, p2;
};
int direction(const SLine& ab, const SPoint& c)
{
	int x1, y1, x2, y2;
	x1 = ab.p2.x - ab.p1.x;
	y1 = ab.p2.y - ab.p1.y;
	x2 = c.x - ab.p1.x;
	y2 = c.y - ab.p1.y;
	if (x1 * y2 - x2 * y1 < 0)
		return -1;
	else if (x1 * y2 - x2 * y1 > 0)
		return 0;
	else if (x1 * y2 - x2 * y1 == 0)
		return 1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		SLine l1, ab, ac;
		SPoint p3;
		int temp;
		cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y
			>> p3.x >> p3.y;
		temp = direction(l1, p3);
		if (temp == -1)
			cout << "clockwise" << endl;
		else if (temp == 1)
			cout << "intersect" << endl;
		else if (temp == 0)
			cout << "anti clockwise" << endl;
	}
	return 0;
}
