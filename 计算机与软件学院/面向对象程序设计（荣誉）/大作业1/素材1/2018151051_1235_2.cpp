2018151051:Problem1235:答案错误
#include<iostream>
#include<cstring>
using namespace std;
class Geometry
{
public:
	virtual double getArea()=0;	
};
class Rect:public Geometry
{
	double chang;
	double kuan;
public:
	Rect(double c,double k)
	{
		chang=c;
		kuan=k;
	}
	virtual double getArea()
	{
		double s;
		s=chang*kuan;
		return s;
	}
};
class Circle:public Geometry
{
	double r;
public:
	Circle(double _r)
	{
		r=_r;
	}
	virtual double getArea()
	{
		double s;
		s=3.14*r*r;
		return s;
	}
};
class TotalArea
{
public:
	static void computerTotalArea(Geometry** t,int n)
	{
		int i;
		double max=0;
		for(i=0;i<n;i++)
		{
			if(t[i]->getArea()>max)
				max=t[i]->getArea();
		}
		cout<<"最大面积="<<max<<endl;
	}
};
int main()
{
    int n,i;
    cin>>n;
    Geometry** t=new Geometry*[n];
    for(i=0;i<n;i++)
    {
    	int type;
    	cin>>type;
    	if(type==1)
    	{
    		double chang;
    		double kuan;
    		cin>>chang>>kuan;
    		t[i]=new Rect(chang,kuan);
		}
		else if(type==2)
		{
			double r;
			cin>>r;
			t[i]=new Circle(r);
		}
    }
    TotalArea p;
    p.computerTotalArea(t,n);
    for(i=0;i<n;i++)
    {
    	delete t[i];
	}
    return 0;
}
