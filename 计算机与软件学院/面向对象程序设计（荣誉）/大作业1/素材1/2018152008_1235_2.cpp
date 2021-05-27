2018152008:Problem1235:正确
#include<iostream>
#include<string>
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
		float c,k;
	public:
		Rect(float c,float k);
		double getArea();	
};
Rect::Rect(float c1,float k1)
{
	c=c1;
	k=k1;
}
double Rect::getArea()
{
	return c*k;
}
class Circle:public Geometry
{
	protected:
		float radius;
	public:
		Circle(float r);
		double getArea();		
};
Circle::Circle(float r)
{
	radius=r;
}
double Circle::getArea()
{
	return 3.14*radius*radius;
}
class TotalArea
{
	public:
		static void computerTotalArea(Geometry** t,int n)
		{
			int i;
			double max=-1;
			for(i=0;i<n;i++)
			{
				if(t[i]->getArea()>max)
					max=t[i]->getArea();
			}
			cout<<fixed<<setprecision(2)<<"最大面积="<<max<<endl;
		}
};
int main()
{
	int t,i;
	cin>>t;
	Geometry **p=new Geometry*[t];
	for(i=0;i<t;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			float c1,k1;
			cin>>c1>>k1;
			p[i]=new Rect(c1,k1);
		}
		else
		{
			float r;
			cin>>r;
			p[i]=new Circle(r);
		}
	}
	TotalArea::computerTotalArea(p,t);
	return 0;
}

