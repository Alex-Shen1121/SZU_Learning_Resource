2018192026:Problem1235:正确
#include<stdio.h>
class Geometry
{
public:
	virtual double getArea()=0;
};
class Rect:public Geometry
{
protected:
	double length,width;
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
	double radius;
public:
	Circle(double r):radius(r){}
	double getArea()
	{
		return 3.14*radius*radius;
	}
};
class MaxArea
{
public:
	static void getMaxArea(Geometry **t,int n)
	{
		int i;
		double max=t[0]->getArea();
		for(i=1;i<n;i++)
			if(max<t[i]->getArea())
				max=t[i]->getArea();
		printf("最大面积=%.2lf\n",max);
	}
};
int main()
{
	int t,i;
	scanf("%d",&t);
	Geometry **G;
	G=new Geometry *[t];
	for(i=0;i<t;i++)
	{
		int kind;
		double length,width,radius;
		scanf("%d",&kind);
		if(kind-1)
		{
			scanf("%lf",&radius);
			Circle C(radius);
			G[i]=&C;
		}
		else
		{
			scanf("%lf %lf",&length,&width);
			Rect R(length,width);
			G[i]=&R;
		}
	}
	MaxArea area;
	area.getMaxArea(G,t);
	delete []G;
	return 0;
}
	


			

