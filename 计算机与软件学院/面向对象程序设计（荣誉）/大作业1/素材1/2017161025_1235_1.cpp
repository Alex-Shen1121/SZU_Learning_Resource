2017161025:Problem1235:正确
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Geometry 
{
public:
	virtual double getArea() = 0; //计算面积，结果保留小数点后两位
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
	static void computerTotalArea(Geometry** t, int n);//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
	static void print()
	{
		cout << "最大面积=" << fixed << setprecision(2) << max_value << endl;
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

