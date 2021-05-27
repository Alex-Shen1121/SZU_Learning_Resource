2017163101:Problem1235:答案错误
#include<iostream>
#include<iomanip>
using namespace std;
class Geometry{
public:
    virtual double getArea()=0; 

};
class Rect:public Geometry{
	private:
		double l,h;
	public:
		double getArea(){
			double area=l*h;
			return area;
		}
		Rect(double _l,double _h):l(_l),h(_h){
			
		}
};
class Circle:public Geometry{
	private:
		double r;
	public:
		double getArea(){
			double area=3.14*r*r;
		}
		Circle(double _r):r(_r){
			
		}
};
/*
class TotalArea{
public:
   static void computerTotalArea(Geometry* t,int n){
   	double area=t[0].getArea();
   	for(int i=0;i<n;i++){
   		//area=t.getArea();
   		if(area>t[i].getArea())
   		area=t[i].getArea();
	   }
   	cout<<"最大面积="<<area<<endl;
   }
};*/
int main(){
	int t;
	cin>>t;
	double area=0.0;
	while(t--){
		Geometry *g;
		int flag;
		double l,h,r;
		cin>>flag;
		if(flag==1){
			cin>>l>>h;
			g=new Rect(l,h);
			if(g->getArea()>area)
			area=g->getArea();
			//t.computerTotalArea(g,t);
		}
		else{
			cin>>r;
			g=new Circle(r);
			//g->getArea();
			if(g->getArea()>area)
			area=g->getArea();
		}
	}
	cout<<"最大面积="<<setiosflags(ios::fixed)<<setprecision(2)<<area;
	return 0;
}
