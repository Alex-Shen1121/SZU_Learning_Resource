2018152086:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry {
	public:
		Geometry() {

		}
		virtual double getArea()=0;
		virtual ~Geometry() {

		}
};

class Rect:public Geometry {
	protected:
		int a,b;
	public:
		Rect() {
		}
		Rect(double A,double B) {
			a=A;
			b=B;
		}
		double getArea() {
			return a*b;
		}
};
class Circle:public Geometry {
	protected:
		double r;
	public:
		Circle() {
		}
		Circle(double a) {
			r=a;
		}
		double getArea() {
			return r*r*3.14;
		}
};

class TotalArea
{
	static double max;
public:
	static void computerTotalArea(Geometry **t,int n)
	{
		for(int i=0;i<n;i++)
		{
			double s=t[i]->getArea();
			if(max<s)
				max=s;
		} 
		cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
	}
};
double TotalArea::max=0;
int main() {
	int t;
	int type;
	double a,b,r;
	Geometry **P=new Geometry *[t];
	cin>>t;
	int i=0;
	while(t--) {
		cin>>type;
		if(type==1) {
			cin>>a>>b;
			P[i]=new Rect(a,b);
		}
		if(type==2) {
			cin>>r;
			P[i]=new Circle(r);
		}
		i++;
	}
	TotalArea temp;
	temp.computerTotalArea(P,i);
}
