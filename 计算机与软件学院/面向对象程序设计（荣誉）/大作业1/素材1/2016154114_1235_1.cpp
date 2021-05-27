2016154114:Problem1235:正确
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
protected:
	double length;
	double width;
public:
    Rect(double l,double w):length(l),width(w){}
    double getArea()
	{
		return length*width;
	}
};

class Circle:public Geometry
{
protected:
	double r;
public:
    Circle(double _r):r(_r){}
    double getArea()
	{
		return 3.14*r*r;
	}
};

class TotalArea
{
public:
	static void computerTotalArea(Geometry** t,int n)
	{
		double max=0;
		for(int i=0;i<n;i++)
		{
			if(t[i]->getArea()>max)
				max=t[i]->getArea();
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
	}
};

int main()
{
	Geometry** t;
	int n;
	cin>>n;
	t=new Geometry* [n];
    for(int i=0;i<n;i++)
    {
		int type;
        cin>>type;
        if(type==1)
		{
			int l,w;
			cin>>l>>w;
			Rect rect(l,w);
			t[i]=&rect;
		}
		else if(type==2)
        {
			int r;
			cin>>r;
			Circle circle(r);
			t[i]=&circle;
        }
    }
	TotalArea::computerTotalArea(t,n);
	return 0;
}
