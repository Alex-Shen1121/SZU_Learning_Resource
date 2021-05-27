2017144045:Problem1235:正确
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Geometry
{
public:
	Geometry()
	{
	}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
	double chang;
	double kuan;
public:
	Rect(double x,double y)
	{
		chang=x;
		kuan=y;
	}
    virtual double getArea()
	{
		return chang*kuan;
	}	
};

class Circle:public Geometry
{
	double radius;
public:
	Circle(double r)
	{
		radius=r;
	}
	virtual double getArea()
	{
		return 3.14*radius*radius;
	}
};

class TotalArea
{
public:
	TotalArea()
	{
	}
    static void computerTotalArea(Geometry** t,int n)
    {
    	double max=0.0;
    	//cout<<t[1]->getArea()<<endl;
    	for(int i=0;i<n;i++)
    	{
    		if(t[i]->getArea()>max)
    		{
    			max=t[i]->getArea();
			}
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl; 
	}
		
};

int main()
{
	int t;
	int a;
	int num;
	double x,y,r;
	cin>>t;
	num=t;
	double Area[t];
	Geometry *tu[t];
	int i=0;
	while(t--)
	{
		cin>>a;
		if(a==1)
		{
			cin>>x>>y;
			tu[i]=new Rect(x,y);
			Area[i]=tu[i]->getArea(); 
		}
		else if(a==2)
		{
			cin>>r;
			tu[i]=new Circle(r);
			Area[i]=tu[i]->getArea(); 
		}		
		i++;
	}
	TotalArea area;
	area.computerTotalArea(tu,num);
}
