2018192048:Problem1235:±‡“Î¥ÌŒÛ
#include<iostream>
using namespace std;

class Geometry{
public:
	virtual double getArea()=0;
}
class Rect:public Geometry{
protected:
	double x,y;
public:
	Rect(){}
	Rect(double x_,double y_){
		x=x_;
		y=y_;
	}
	double getArea(){
		return x*y;
	}
	~Rect(){}
}
class Circle:public Geometry{
protected:
	double r;
public:
	Circle(){}
	Circle(double r_){
		r=r_;
	}
	double getArea(){
		return 3.14*r*r;
	}
	~Circle(){}
}

class TotalArea{
public:
	static void computerTotalArea(Geometry**t,int n)
};
