#include<iostream>
using namespace std;
struct SPoint {
	int x, y;
};
struct SLine {
	SPoint p1, p2;
};
struct SRect {
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
}//
void swap(int& a, int& b)
{
	int temp;
	temp = b;
	b = a;
	a = temp;
}
void Reset(SRect& temp)
{
	int p1x, p1y, p2x, p2y;

	if (temp.p1.x > temp.p2.x)
	{
		swap(temp.p1.x, temp.p2.x);
		swap(temp.p1.y, temp.p2.y);
	}
	p1x = temp.p1.x;
	p1y = temp.p1.y;
	p2x = temp.p2.x;
	p2y = temp.p2.y;
	if (temp.p1.y > temp.p2.y)
	{
		temp.p1.y = p2y;
		temp.p2.y = p1y;
	}
}
int check(SRect a, SRect b)
{
	if (b.p2.x < a.p1.x || b.p1.y > a.p2.y || b.p1.x > a.p2.x || b.p2.y < a.p1.y)
		return -1;
	else
		return 1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int check1;
		SRect Rect[2];
		SPoint a, b, c, d;
		cin >> Rect[0].p1.x >> Rect[0].p1.y >> Rect[0].p2.x >> Rect[0].p2.y
			>> Rect[1].p1.x >> Rect[1].p1.y >> Rect[1].p2.x >> Rect[1].p2.y;
		a.x = Rect[0].p1.x;
		a.y = Rect[0].p1.y;
		b.x = Rect[0].p2.x;
		b.y = Rect[0].p2.y;
		c.x = Rect[1].p1.x;
		c.y = Rect[1].p1.y;
		d.x = Rect[1].p2.x;
		d.y = Rect[1].p2.y;
		double u, v, w, z;
		Reset(Rect[0]);
		Reset(Rect[1]);
		check1 = check(Rect[0], Rect[1]);
		if (check1 == -1)
			cout << "disjoint" << endl;
		else if (check1 == 1)
		{
			u = (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
			v = (d.x - a.x) * (b.y - a.y) - (b.x - a.x) * (d.y - a.y);
			w = (a.x - c.x) * (d.y - c.y) - (d.x - c.x) * (a.y - c.y);
			z = (b.x - c.x) * (d.y - c.y) - (d.x - c.x) * (b.y - c.y);
			if (u * v <= 0.00000001 && w * z <= 0.00000001)
				cout << "intersect" << endl;
			else 
				cout << "disjoint" << endl;
		}
	}
	return 0;
}
