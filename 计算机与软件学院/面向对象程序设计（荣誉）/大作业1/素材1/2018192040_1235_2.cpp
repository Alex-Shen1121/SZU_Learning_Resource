2018192040:Problem1235:�������
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
double pi = 3.14;
class Geometry{

public:

    virtual double getArea()=0; //����������������С�������λ

};

class Rect:public Geometry{
	double l,w;
public:
	Rect(){
	};
	Rect(double L,double W):l(L),w(W){
	};
	double getArea(){
		return l*w;
	}
};

class Circle:public Geometry{
	double r;
public:
	Circle(){
	};
	Circle(double R):r(R){
	};
	double getArea(){
		return r*r*pi;
	}
};

class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n){
   		double max = *t[0]->getArea()
	   	if(max<*t[1]->getArea())
	   		max = *t[1]->getArea();
	   	if(max<*t[2]->getArea())
	   		max = *t[2]->getArea();
	   	cout<<"������="<<setprecision(2)<<max<<endl; 
   }

};


int main(){
	int n;
	cin>>n;
	TotalArea ta;
	Geometry *p = (Geometry*)operator new[](sizeof(Geometry)*n);
	Geometry **p1 = &p;
	for(int i=0;i<n;i++){
		int type,r,w,l;
		cin>>type;
		if(type == 1){
			cin>>l>>w;
			Rect re(l,w);
			p[i] = re;
		}
		if(type == 2){
			cin>>r;
			Circle ci(r);
			p[i] = ci;
		}
	}
	ta.computerTotalArea(p1,n);
}
