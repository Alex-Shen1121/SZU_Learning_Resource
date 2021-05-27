2018151031:Problem1235:正确
#include <bits/stdc++.h>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect:public Geometry
{
	double length,wide;
public:
	Rect(double l,double w):length(l),wide(w){}
	double getArea()
	{
		/*cout<<"Rect"<<endl;
		cout<<length*wide<<endl;*/
		return length*wide;
	}
};
class Circle:public Geometry
{
	double r;
public:
	Circle(double radius):r(radius){}
	double getArea()
	{
		/*cout<<"C"<<endl;
		cout<<3.14*r*r<<endl;*/
		return 3.14*r*r;
	}
};
class TotalArea
{
	static double maxarea;
public:
   static void computerTotalArea(Geometry** t,int n)
   {
   		for(int i=0;i<n;i++)
   		{
   			double a=t[i]->getArea();
   			if(maxarea<a)
			   maxarea=a;
   		}
   }
   static double getmaxarea()
   {
   		return maxarea;
   }
};
double TotalArea::maxarea=0;
int main()
{
	int t;
	cin>>t;
	Geometry** g=new Geometry*[t];
	for(int i=0;i<t;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			double l,w;
			cin>>l>>w;
			g[i]=new Rect(l,w);
		}
		else if(type==2)
		{
			double r;
			cin>>r;
			g[i]=new Circle(r);
		}
	}
	TotalArea total;
	total.computerTotalArea(g,t);
	cout<<"最大面积=";
	printf("%.2f\n",total.getmaxarea());
	for(int i=0;i<t;i++)
		delete []g[i];
	delete g;
	
}
