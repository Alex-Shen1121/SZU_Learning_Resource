2016150201:Problem1235:±‡“Î¥ÌŒÛ
#include<iostream>
#define PI 3.14
using namespace std;
class Geometry{
	public:
		virtual double getArea()=0;
};
class Rect:public Geometry{
	int a,b;
public:	
	Rect(int aa,int bb):a(aa),b(bb){
	}
	double virtual getArea(){
		return a*b;
	}
};
class Circle:public Geometry{
	int r;
public:	
	Circle(int rr):r(rr){
	}
	double virtual getArea(){
		return PI*r*r;
	}
};
class TotalArea{
public:
   static void computerTotalArea(Geometry** t,int n);
};
void computerTotalArea(Geometry** t,int n){
	double d=0;
	for(int i=0;i<n;i++){
	if(*t[i].getArea()>d)
	d=*t[i].getArea();	
	}
	cout<<d<<endl;
}
int main(){
	int t,id,a,b,r;
	cin>>t;
	Geometry *g;
	cin>>id;
	while(t--){
		if(id==1){
			cin>>a>>b;
			Rect r(a,b);
			g=&r;
		}
		else if(id==2){
			cin>>r;
			Circle c(r);
			g=&c;
		}
	}
	TotalArea t;
	t.computerTotalArea(*g,t);
}
