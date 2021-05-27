2018152108:Problem1235:正确
#include<iostream>
#include<iomanip>
#define PI 3.14
using namespace std;

class Geometry
{
public:
    virtual double getArea()=0;
};

class Rect:public Geometry
{
	double length,width;
public:
	friend class TotalArea;
	Rect(double a,double b)
	{
		length = a;
		width = b;
	}
	double getArea()
	{
		return length*width;
	}
};

class Circle:public Geometry
{
	double radius;
public:
	friend class TotalArea;
	Circle(double r)
	{
		radius = r;
	}
	double getArea()
	{
		return PI*radius*radius;
	}
};

class TotalArea
{
public:
    void computerTotalArea(Geometry** t,int n)
   {
   		double max = t[0]->getArea();
		for(int i=1;i<n;i++)
		{
			if(t[i]->getArea()>max)
			{
				max = t[i]->getArea();
			}
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
   }
};

int main()
{
	int t,i;
	cin>>t;
	Geometry **p = new Geometry*[t];
	for(i=0;i<t;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			double a,b;
			cin>>a>>b;
			p[i] = new Rect(a,b);
		}
		if(type==2)
		{
			double r;
			cin>>r;
			p[i] = new Circle(r);
		}
	}
	TotalArea x;
	x.computerTotalArea(p,t);
	for(i=0;i<t;i++)
		delete p[i];
	return 0;
}
