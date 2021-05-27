2016102048:Problem1235:���д���
#include <bits/stdc++.h>
using namespace std;

class Geometry
{ 

public:

	virtual double getArea()=0; 
	Geometry(){
	}

	
	~Geometry(){
	}
};

class Rect:public Geometry 
{
	float a;
	float b;
public:
	Rect(float av,float bv):a(av),b(bv)
	{
	}
	virtual double getArea()
	{
		return a*b;
	}
	~Rect()
	{
	}
};

class Circle:public Geometry
{
	float r;
public:
	Circle(float rv):r(rv)
	{
	}
	virtual double getArea()
	{
		return 3.14*r*r;
	}
	~Circle(){
	}
};

class TotalArea{

public:
	TotalArea(){
	}
   	static void computerTotalArea(Geometry** p,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
	{
	
		float a,b,r;
		int type;
		int i;
		double max=0;
		for(i=0;i<n;i++)
		{
			cin>>type;
			if(type==1)
			{
				cin>>a>>b;
				Rect rect(a,b);
				p[i]=&rect;
				if(max<p[i]->getArea())
					max=p[i]->getArea();
			}
			else if(type==2)
			{
	   			cin>>r;
				Circle c(r);
				p[i]=&c;
				if(max<p[i]->getArea())
					max=p[i]->getArea();
			}
			
		}
		cout<<"������="<<max<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	Geometry **p;
	p=new Geometry*[t];
	TotalArea a;
	a.computerTotalArea(p,t);
	int i;
	for(i=0;i<t;i++)
		delete []p[i];
	return 0;
}
