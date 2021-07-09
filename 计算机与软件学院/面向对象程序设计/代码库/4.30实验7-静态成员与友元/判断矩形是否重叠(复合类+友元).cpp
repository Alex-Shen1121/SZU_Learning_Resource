#include<iostream>
using namespace std;

class CRect;

class CPoint {
	float x, y;
	friend class CRect;
public:
	CPoint();
	CPoint(float _x, float _y);
	float getX();
	float getY();
	void setX(float a);
	void setY(float a);
};

class CRect {
	CPoint p1, p2;
public:
	CRect();
	CRect(CPoint& _p1, CPoint& _p2);
	void Reset();
	friend void check(CRect& R1, CRect& R2);
};

CPoint::CPoint()
{
	x = 0; y = 0;
}

CPoint::CPoint(float _x, float _y)
{
	x = _x;
	y = _y;
}

float CPoint::getX()
{
	return x;
}

float CPoint::getY()
{
	return y;
}

void CPoint::setX(float a)
{
	x = a;
}

void CPoint::setY(float a)
{
	y = a;
}

CRect::CRect():p1(0,0),p2(0,0)
{
}

CRect::CRect(CPoint& _p1, CPoint& _p2)
{
	p1 = _p1;
	p2 = _p2;
}

void CRect::Reset()
{
	float p1x, p1y, p2x, p2y;
	if (p1.getX() > p2.getX())
	{
		float temp;
		temp = p2.getX();
		p2.setX(p1.getX());
		p1.setX(temp);
		temp = p2.getY();
		p2.setY(p1.getY());
		p1.setY(temp);
	}
	p1x = p1.getX();
	p1y = p1.getY();
	p2x = p2.getX();
	p2y = p2.getY();
	if (p1.getY() > p2.getY())
	{
		p1.setY(p2y);
		p2.setY(p1y);
	}
}

void check(CRect& R1, CRect& R2)
{
	if (R2.p2.getX() < R1.p1.getX() || R2.p1.getY() > R1.p2.getY() || R2.p1.getX() > R1.p2.getX() || R2.p2.getY() < R1.p1.getY())
		cout << "not overlapped" << endl;
	else
		cout << "overlapped" << endl;
}

int main() {
	int n;
	cin >> n;
	while (n--)
	{
		float x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		CPoint p1(x1, y1), p2(x2, y2);
		CRect R1(p1, p2);
		cin >> x1 >> y1 >> x2 >> y2;
		CPoint p3(x1, y1), p4(x2, y2);
		CRect R2(p3, p4);
		R1.Reset();
		R2.Reset();
		check(R1, R2);
	}
	return 0;

}
