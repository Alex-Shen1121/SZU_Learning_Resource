2018192048:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry{
public:
	virtual double getArea()=0;
};

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
};
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
};

class TotalArea{
public:
	static void computerTotalArea(Geometry**t,int n);
};
void TotalArea::computerTotalArea(Geometry**t,int n){
	double s=0;
	for(int i=0;i<n;i++)
		if(s<t[i]->getArea())
			s=t[i]->getArea();
	cout<<"最大面积="<<fixed<<setprecision(2)<<s<<endl;
}

int main(){
	int t;
	cin>>t;
	Geometry **p;
	p=new Geometry *[t];
	for(int i=0;i<t;i++){
		int type;
		cin>>type;
		if(type==1){
			double x,y;
			cin>>x>>y;
			p[i]=new Rect(x,y);
		}
		else if(type==2){
			double r;
			cin>>r;
			p[i]=new Circle(r);
		}
	}
	TotalArea a;
		a.computerTotalArea(p,t);
	return 0;
}
