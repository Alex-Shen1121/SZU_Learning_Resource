2018191214:Problem1235:答案错误
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
class Geometry
{
public:
	virtual double getArea()=0;
};
class Rect:public Geometry
{
protected:
	double y,x;
public:
	Rect(){}
	Rect(double x1,double y1):x(x1),y(y1){}
	double getArea()
	{
		return x*y;
	}
};
class Circle:public Geometry
{
protected:
	double r;
public:
	Circle(){}
	Circle(double R):r(R){}
	double getArea()
	{
		return r*r*3.14;
	}
};
class TotalArea
{
public:
	static void computerTotalArea(Geometry **t,int n)
	{
		double max=0;
		for(int i=0;i<n;i++)
			if(t[i]->getArea()>max)
				max=t[i]->getArea();
			cout<<"最大面积="<<setprecision(5)<<max<<endl;
	}
};
int main()
{
	int t,kind;
	double x,y,r;
	cin>>t;
	Geometry **p=new Geometry *[t];
	TotalArea TA;
	for(int i=0;i<t;i++)
	{
		cin>>kind;
		if(kind==1)
		{
			cin>>x>>y;
			p[i]=new Rect(x,y);
		}
		else if(kind==2)
		{
			cin>>r;
			p[i]=new Circle(r);
		}
	}
	TA.computerTotalArea(p,t);
	return 0;
}

