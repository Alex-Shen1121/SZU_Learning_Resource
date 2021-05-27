2018192008:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry {

public:
	virtual double getArea() = 0;

};
class TotalArea {

public:
	static void computerTotalArea(Geometry **t, int n)
	{
		int i = 0;
		double maxa = 0;
		for (i = 0; i < n; i++)
		{
			if (t[i]->getArea() > maxa)
				maxa = t[i]->getArea();

		}
		cout << "最大面积=" << fixed << setprecision(2) << maxa << endl;
	}
};

class Rect :public Geometry
{
	int len, wid;
public:
	Rect(int l, int w) :len(l), wid(w) {}
	double getArea()
	{
		double s;
		s = len * wid;
		return s;
	}
	virtual ~Rect(){}
};

class Circle :public Geometry
{
	int r;
public:
	Circle(int r1) :r(r1) {}
	double getArea()
	{
		double s;
		s = 3.14*r*r;
		return s;
	}
	virtual ~Circle(){}
};

int main()
{
	int t;
	cin >> t;
	int n = t;
	Geometry **g;
	g = new Geometry*[n];
	int i = 0;
	while (t--)
	{

		int k;
		cin >> k;
		if (k == 1)
		{
			int l, w;
			cin >> l >> w;
			g[i] = new Rect(l, w);
		}
		else
		{
			int r1;
			cin >> r1;
			g[i] = new Circle(r1);
		}
		i++;
	}
	TotalArea::computerTotalArea(g, n);
	
	delete []g;
}

