#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void swap(float &x, float &y)
{
	float temp;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}
}
class CTriangle
{
private:
	float a, b, c;
	string type;
	void resetTriangle();
public:
	CTriangle(float x, float y, float z);
	~CTriangle();
	string checkTriangle();
	float getArea();
};

CTriangle::CTriangle(float x, float y, float z)
{
	a = x;
	b = y;
	c = z;
}

CTriangle::~CTriangle()
{
	a = 0; b = 0; c = 0;
	type = "none";
}

string CTriangle::checkTriangle()
{
	resetTriangle();
	if (a + b < c)
		return "no triangle";
	else
	{
		if (a == b && b == c)
			return "equilateral triangle";//�ȱ�������
		else if (a == b || a == c || c == b)
		{
			if ((a * a + b * b) - (c * c)<1e-3)
				return "isosceles right triangle";//����ֱ��������
			else
				return "isosceles triangle";//����������
		}
		else if ((a * a + b * b) - (c * c) < 1e-6)
			return "right triangle";//ֱ��������
		else
			return "general triangle";//һ��������
	}
}

float CTriangle::getArea()
{
	float p, s;
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

void CTriangle::resetTriangle()
{
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float a, b, c;
		cin >> a >> b >> c;
		CTriangle T(a, b, c);
		if (T.checkTriangle() != "no triangle")
		{
			cout << fixed << setprecision(1) << T.checkTriangle() << ", " << T.getArea() << endl;
		}
		else 
			cout << T.checkTriangle() << endl;
	}
	return 0;
}
