2017161025:Problem1235:��ȷ
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Geometry 
{
public:
	virtual double getArea() = 0; //����������������С�������λ
};

class Rect : public Geometry
{
protected:
	double a, b;

public:
	Rect() { cin >> a >> b; }
	virtual double getArea() { return a * b; }
};

class Circle : public Geometry
{
protected:
	double r;

public:
	Circle() { cin >> r; }
	virtual double getArea() { return 3.14 * r * r; }
};


class TotalArea 
{
	static double max_value;

public:
	TotalArea() { max_value = 0.0; }
	static void computerTotalArea(Geometry** t, int n);//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
	static void print()
	{
		cout << "������=" << fixed << setprecision(2) << max_value << endl;
	}
};

double TotalArea::max_value = 0;

int main()
{
	int n;
	cin >> n;

	Geometry **a = new Geometry *[n];

	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;

		type == 1 ? a[i] = new Rect() : a[i] = new Circle();	
	}

	TotalArea t;
	t.computerTotalArea(a, n);
	t.print();

	//system("pause");
	return 0;
}

void TotalArea::computerTotalArea(Geometry ** t, int n)
{
	max_value = 0;

	for (int i = 0; i < n; i++)
	{
		double tmp = t[i]->getArea();

		if (tmp > max_value)
			max_value = tmp;
	}

	return;
}

