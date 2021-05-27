2017047011:Problem1235:正确
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Geometry{

public:
	virtual double getArea()=0; 
	Geometry(){}
};

//------------------------
class Rect:public Geometry
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
class Circle:public Geometry
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
   static void computer(Geometry** p,int n);
};

void TotalArea::computer(Geometry **p,int n){
	int i,kind;
	double a,b,r,max;
	p=new Geometry*[n];
	max=0;
	
	for(i=0;i<n;i++){
		cin>>kind;
		if(kind==1){
			cin>>a>>b;
			Rect rect(a,b);
			p[i]=&rect; 
		}
		else if(kind==2){
			cin>>r;
			Circle cir(r);
			p[i]=&cir;
		}
	}
	
	for(i=0;i<n;i++){
		if(p[i]->getArea()>max)
			max=p[i]->getArea();
	}
	cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
	
}
//------------------------
int main()
{
	int t;
	int kind;
	double a,b,r;
	Geometry **p;
	
	cin>>t;
	TotalArea maxArea;
	maxArea.computer(p,t);	
}
