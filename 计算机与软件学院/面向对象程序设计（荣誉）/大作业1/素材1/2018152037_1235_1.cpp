2018152037:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry
{
	public:
		Geometry()
		{
		}
		virtual double getArea()=0;
};

class Rect:public Geometry
{
	double x;
	double y;
public:
	Rect(double x1,double y1)
	{
		x=x1;
		y=y1;
	}
	double getArea()
	{
		return x*y;
	}
};

class Circle:public Geometry
{
	double bj;
public:
	Circle(double b)
	{
		bj=b;
	}
	double getArea()
	{
		return 3.14*bj*bj;
	}
};

class TotalArea
{
public:
	static void computerTotalArea(Geometry** t,int n)
	{
		double max;
		max=t[0]->getArea();
		for(int i=1;i<n;i++)
		{
			if(max<t[i]->getArea())
				max=t[i]->getArea();
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	Geometry **p;
	p=new Geometry*[t];
	for(int i=0;i<t;i++)
	{
		int pd;
		cin>>pd;
		if(pd==1)
		{
			int x,y;
			cin>>x>>y;
			Rect a1(x,y);
			p[i]=&a1;
		}
		if(pd==2)
		{
			int r;
			cin>>r;
			Circle a1(r);
			p[i]=&a1;
		}
	}
	TotalArea ak;
	ak.computerTotalArea(p,t);
	delete []p;
	return 0;
}
