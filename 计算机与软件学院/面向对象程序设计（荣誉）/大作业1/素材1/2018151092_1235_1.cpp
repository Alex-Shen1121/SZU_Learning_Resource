2018151092:Problem1235:答案错误
#include<iostream>
#include<cstring>
#include<iomanip>
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
	protected:
		double length;
		double width;
	public:
		Rect()
		{
		}
		
		Rect(double l,double w)
		{
			length=l;
			width=w;
		}
		
		virtual double getArea()
		{
			return length*width;
		}
		
		~Rect()
		{
		}
};

class Circle:public Geometry
{
	protected:
		double radius;
	public:
		Circle()
		{
		}
		
		Circle(double r)
		{
			radius=r;
		}
		
		virtual double getArea()
		{
			return 3.14*radius*radius;
		}
		
		~Circle()
		{
		}
};

class TotalArea
{
	public:
		TotalArea()
		{
		}
		
   		static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
   		{
   			double max=0;
   			int i;
   			
   			for(i=0;i<n;i++)
   			{
   				if(t[i]->getArea()>max)
   				{
   					max=t[i]->getArea();
				}
			}
			
			cout<<"最大值="<<fixed<<setprecision(2)<<max<<endl;
		}

};

int main()
{
	int t;
	int i;
	int type;
	double L;
	double W;
	double R;
	
	cin>>t;
	
	Geometry *Ace[t];
	
	for(i=0;i<t;i++)
	{
		cin>>type;
		
		if(type==1)
		{
			cin>>L>>W;
			Ace[i]=new Rect(L,W);
		}
		
		else if(type==2)
		{
			cin>>R;
			Ace[i]=new Circle(R);
		}
	}
	
	TotalArea Summary;
	
	Summary.computerTotalArea(Ace,t);
	
	return 0;
}
