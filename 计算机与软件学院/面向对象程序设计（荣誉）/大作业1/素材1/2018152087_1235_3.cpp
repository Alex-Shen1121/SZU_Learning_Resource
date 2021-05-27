2018152087:Problem1235:运行错误
#include<iostream>
#include <iomanip>
using namespace std;
class Geometry
{
public:
	Geometry()
	{
		
	}
	virtual double getArea()=0;
	virtual ~Geometry()
	{
		
	} 
};
class Rect:public Geometry
{
	double len;
	double wid;
public:
	Rect(double l,double w)
	{
		len=l;
		wid=w;
	}
	double getArea()
	{
		return len*wid;
	}
	~Rect()
	{
		
	}
};
class Circle:public Geometry
{
	double r;
public:
	Circle(double rr)
	{
		r=rr;
	}
	double getArea()
	{
		return r*r*3.14;
	}
	~Circle()
	{
		
	}
};
class TotalArea
{
	static double max;
public:
	static void computerTotalArea(Geometry **t,int n)
	{
		for(int i=0;i<n;i++)
		{
			double s=t[i]->getArea();
			if(max<s)
				max=s;
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
	}
};
double TotalArea::max=0;
int main()
{
	int t;
	cin>>t;
	Geometry **p=new Geometry *[t];
	for(int i=0;i<t;i++)
	{
		int flag;
		cin>>flag;
		if(flag==1)
		{
			int l,w;
			cin>>l>>w;
			Rect ex(l,w);
			p[i]=&ex;
		}
		else
		{
			int r;
			cin>>r;
			Circle ex(r);
			p[i]=&ex;
		}
	}
	TotalArea temp;
	temp.computerTotalArea(p,t);
	for(int i=0;i<t;i++)
		delete p[i];
	delete []p;
}
