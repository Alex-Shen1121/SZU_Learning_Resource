2018151066:Problem1235:��ȷ
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Geometry
{
public:
	virtual double getArea() = 0;
};

class Rect : public Geometry
{
protected:
	double w, h;
public:
	Rect(double w_, double h_) :w(w_), h(h_) {}
	double getArea()
	{
		return w * h;
	}
};

class Circle : public Geometry
{
protected:
	double r;
public:
	Circle(double r_) :r(r_) {}
	double getArea()
	{
		return 3.14*r*r;
	}
};

class TotalArea :public Rect, public Circle
{
public:
	static void computerTotalArea(Geometry** data, int n);
};

void TotalArea::computerTotalArea(Geometry **data, int n)
{
	double maxArea = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i]->getArea() > maxArea)
			maxArea = data[i]->getArea();
	}
	cout << "������=" << setiosflags(ios::fixed) << setprecision(2) << maxArea << endl;

}
int main()
{
	int t;
	cin >> t;
	Geometry **data = new Geometry*[t];
	for (int i = 0; i < t; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int w, h;
			cin >> w >> h;
			data[i]=new Rect(w, h);
		}
		else
		{
			int r;
			cin >> r;
			data[i]=new Circle(r);
		}
	}
	TotalArea::computerTotalArea(data, t);
	for (int i = 0; i < t; i++)
	{
		delete data[i];
	}
}
