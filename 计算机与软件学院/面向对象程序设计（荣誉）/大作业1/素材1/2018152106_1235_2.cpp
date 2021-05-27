2018152106:Problem1235:答案错误
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry
{
public:
	virtual double getArea()=0;
};

class Rect:public Geometry
{
	double x,y;
public:
    Rect(double x_,double y_):x(x_),y(y_){}
    double getArea()
    {
    	return x*y;
	}
};

class Circle:public Geometry
{
	double r;
public:
	Circle(double r_):r(r_){}
	double getArea()
	{
		return 3.14*r*r;
    }	 
};

class TotalArea
{
public:
	TotalArea(){}
    static void computerTotalArea(Geometry** t,int n)
    {
   	    double max=t[0]->getArea();
   		for(int i=1;i<n;i++)
   	    {
   		    if(t[i]->getArea()>max)
   			{
   				max=t[i]->getArea();
		    }
	    }
	    cout<<"最大面积="<<setprecision(2)<<max<<endl;
    }
};
int main()
{
	int t;
	cin>>t;
	Geometry **p=new Geometry *[t];
	for(int i=0;i<t;i++)
	{
		int type,x,y,r;
		cin>>type;
		if(type==1)
		{
			cin>>x>>y;
			p[i]=new Rect(x,y);
		}
		else if(type==2)
		{
			cin>>r;
			p[i]=new Circle(r);
		}
	}
	TotalArea a;
	a.computerTotalArea(p,t);
	for(int i=0;i<t;i++)
	{
		delete p[i];
	}
	delete []p;
}
