2018192050:Problem1235:���д���
#include<bits/stdc++.h>
using namespace std;
class Geometry{
    public:
        Geometry(){
        }
        ~Geometry(){
        }
        virtual double getArea()=0; //����������������С�������λ
};
class Rect:public Geometry
{
    protected:
        int x,y;
    public:
        Rect(){
        }
        Rect(int a,int b){
            x=a;
            y=b;
        }
        ~Rect(){
        }  
        double getArea(){
        	return x*y;
		}
};
class Circle:public Geometry
{
    protected:
        int r;
    public:
        Circle(){
        }
        Circle(int a){
            r=a;
        }
        ~Circle(){
        }
        double getArea(){
        	return r*r*3.14;
		}
};
class TotalArea{
public:
   static void computerTotalArea(Geometry** t,int n)
   {
   		double max=0;
   		for(int i=0;i<n;i++)
   		{
   			if(t[i]->getArea()>max)
   				max=t[i]->getArea();
		}
		cout<<"������="<<fixed<<setprecision(2)<<max;
   }
};
int main(){
	int t,n;
	int x,y,r;
	cin>>t;
	Geometry **p;
	p=new Geometry*[t];
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(n==1)
		{
			cin>>x>>y;
			Rect a(x,y);
			p[i]=&a;
		}
		if(n==2)
		{
			cin>>r;
			Circle a(r);
			p[i]=&a;
		}
	}
	TotalArea a;
	a.computerTotalArea(p,t);
}
