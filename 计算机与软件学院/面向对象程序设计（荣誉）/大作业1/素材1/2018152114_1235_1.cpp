2018152114:Problem1235:答案错误
#include<iostream>
#include<cstring>
using namespace std;
class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位
    virtual ~Geometry(){
	}

};
class Rect:public Geometry
{
	double x,y;
public:
	Rect(double _x,double _y):x(_x),y(_y){}
	virtual double getArea()
	{
		return x*y;
	}
	~Rect()
	{
	}
};
class Circle:public Geometry
{
	double r;
public:
	Circle(double _r):r(_r){}
	virtual double getArea()
	{
		return 3.14*r*r;
	}
	~Circle()
	{
	}
};
class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
	{
		double _max=-1.0;
		for(int i=0;i<n;i++)
		{
			double temp=t[i]->getArea();
			if(_max<temp)
				_max=temp;
		}
		cout<<"最大面积="<<_max<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	int type;
	double _x,_y,_r;
	Geometry** M;
	M=new Geometry*[t];
	for(int i=0;i<t;i++){
		cin>>type;
		switch(type){
			case 1:
				cin>>_x>>_y;
				M[i]=new Rect(_x,_y);
				break;
			case 2:
				cin>>_r;
				M[i]=new Circle(_r);
				break;
		}
	}
	TotalArea::computerTotalArea(M,t);
}
