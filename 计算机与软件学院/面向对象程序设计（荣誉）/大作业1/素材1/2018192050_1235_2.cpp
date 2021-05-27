2018192050:Problem1235:正确
#include<bits/stdc++.h>
using namespace std;
class Geometry{
    public:
        Geometry(){
        }
        virtual ~Geometry(){
        }
        virtual double getArea()=0; //计算面积，结果保留小数点后两位
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
   		double max=0,tmp;
   		for(int i=0;i<n;i++)
   		{
   			tmp=t[i]->getArea();
   			if(tmp>max)
   				max=tmp;
		}
		cout<<"最大面积="<<fixed<<setprecision(2)<<max;
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
			p[i]=new Rect(x,y);
		}
		if(n==2)
		{
			cin>>r;
			p[i]=new Circle(r);
		}
	}
	TotalArea b;
	b.computerTotalArea(p,t);
	for(int i=0;i<t;i++)
	{
		delete p[i];
	}
	delete []p;
}
