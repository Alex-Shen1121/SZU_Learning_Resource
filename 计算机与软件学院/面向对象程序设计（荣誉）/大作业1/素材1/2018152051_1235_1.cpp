2018152051:Problem1235:正确
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Geometry
{
public:
	virtual double getArea()=0; 
};
class CRect:public Geometry
{
	int x;
	int y;
public:
	CRect(int x1 = 0 , int y1 = 0)
	{
		x = x1;
		y = y1;
	}
	double getArea()
	{
		return (x*y); 
	}
};
class CCircle:public Geometry
{
	int radius;
public:
	CCircle(int r = 0)
	{
		radius = r;
	}
	double getArea()
	{
		return (3.14*radius*radius);
	}
};
class TotalArea
{
	/*Geometry** t;
	int n;*/
public:
	static void computerTotalArea(Geometry** T,int N)
	{
		double a[100];
		for(int i=0;i<N;i++)
		{
			a[i] = T[i]->getArea();
		}
		sort(a,a+N);
		cout<<"最大面积="<<setiosflags(ios::fixed)<<setprecision(2)<<T[N-1]->getArea()<<endl;
	}
};
int main()
{
	int n,type,i,x,y,r;
	cin>>n;
	Geometry **t = new Geometry *[n];
	for(i=0;i<n;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>x>>y;
			t[i] = new CRect(x,y);
		}
		else if(type==2)
		{
			cin>>r;
			t[i] = new CCircle(r);
		}
	}
	TotalArea::computerTotalArea(t,n);
}
