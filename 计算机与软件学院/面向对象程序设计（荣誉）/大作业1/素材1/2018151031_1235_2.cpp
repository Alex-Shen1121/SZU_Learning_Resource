2018151031:Problem1235:答案错误
#include <bits/stdc++.h>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect:public Geometry
{
	int length,wide;
public:
	Rect(int l,int w):length(l),wide(w){}
	double getArea()
	{
		cout<<"Rect"<<endl;
		cout<<length*wide<<endl;
		return length*wide;
	}
};
class Circle:public Geometry
{
	int r;
public:
	Circle(int radius):r(radius){}
	double getArea()
	{
		cout<<"C"<<endl;
		cout<<3.14*r*r<<endl;
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
			int l,w;
			cin>>l>>w;
			g[i]=new Rect(l,w);
		}
		else if(type==2)
		{
			int r;
			cin>>r;
			g[i]=new Circle(r);
		}
	}
	TotalArea total;
	total.computerTotalArea(g,t);
	cout<<"最大面积="<<total.getmaxarea()<<endl;
	for(int i=0;i<t;i++)
		delete []g[i];
	delete g;
	
}
