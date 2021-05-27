2018152029:Problem1235:��ȷ
#include<bits/stdc++.h>
using namespace std;

class Geometry {
public:
	virtual double getArea() = 0; //����������������С�������λ
	virtual ~Geometry() {}
};

class Rect :public Geometry
{
	double a, b;
public:
	Rect(double aa, double bb) :a(aa), b(bb) {}
	double getArea()
	{
		return a * b;
	}
};

class Circle :public Geometry
{
	int r;
public:
	Circle(double rr) :r(rr) {}
	double getArea()
	{
		return 3.14*r*r;
	}
};
class TotalArea 
{
public:
	static void computerTotalArea(Geometry** t, int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
	{
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans = ans > t[i]->getArea() ? ans : t[i]->getArea();
		}
		cout << "������=" << setprecision(2) << fixed << ans << endl;
	}
};
int main()
{
	int T,a,b,c,t;
	cin >> T;
	t = T;
	Geometry **p = new Geometry*[T];
	while (T--)
	{
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			p[T] = new Rect(b, c);
		}
		else
			p[T] = new Circle(b);
	}
	TotalArea::computerTotalArea(p, t);
	for (int i = 0; i < t; i++)
		delete p[i];
	delete p;
	//system("pause");
	return 0;
}

