2017047011:Problem1235:正确
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Geometry{

public:
	virtual double getArea()=0; //保留小数点后两位
	Geometry(){}
	static double max;
};
double Geometry::max=0;
//------------------------
class Rect
{ 
protected:
	double a;
	double b;
public:
	Rect(){}
	Rect(double a1,double b1);
	double getArea();
};

Rect::Rect(double a1,double b1){
	a=a1;b=b1;
}

double Rect::getArea(){
	return a*b;
}
//------------------------
class Circle
{ 
protected:
	double r;
public:
	Circle(){}
	Circle(double r1);
	double getArea();
};

Circle::Circle(double r1){
	r=r1;
}

double Circle::getArea(){
	return 3.14*r*r;
}

class TotalArea
{
public:
   static void computerTotalArea(Geometry** t,int n);
};
//------------------------
int main()
{
	int t;
	int kind;
	double a,b,r;
	
	cin>>t;
	while(t--)
	{
		cin>>kind;
		if(kind==1){
			cin>>a>>b;
			Rect rect1(a,b);
			if(rect1.getArea() > Geometry::max)
				Geometry::max=rect1.getArea();	
		}
		
		else if(kind==2){
			cin>>r;
			Circle cir1(r);
			if(cir1.getArea() > Geometry::max)
				Geometry::max=cir1.getArea();
		}
	}
	cout<<"最大面积="<<fixed<<setprecision(2)<<Geometry::max<<endl;
}
