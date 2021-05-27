2016150076:Problem1235:正确
#include<iostream>
using namespace std;
#include<iomanip>

class Geometry{
 
public:
 	double area;
 	Geometry(){
	 }
    virtual double getArea()=0; 
 
};

class Rect:public Geometry
{
	private:
		int length,wide;
	public:
		Rect(int l,int w):length(l),wide(w){}
		double getArea()
		{
			area=length*wide;
			return area;
		}
};

class Circle:public Geometry
{
	private:
		int r;
	public:
		Circle(int r1):r(r1){}
		double getArea()
		{
			area=r*r*3.14;
			return area;
		}
};
 

 
class TotalArea{
 
public:
	static double max;
   static void computerTotalArea(Geometry** t,int n);
 
};
 double TotalArea::max=0;
 
void TotalArea::computerTotalArea(Geometry** t,int n)
{
	
	for(int i=0;i<n;i++)
	{
			if(t[i]->getArea()>max)
				max=t[i]->getArea();
	}
	cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
		
}

int main()
{
    int n;
    cin>>n;
    int type;
	int a,b,r; 
     
    Geometry **t=new Geometry *[n];
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            t[i]=new Rect(a,b);
        }
         
        else
        {
            cin>>r;
            t[i]=new Circle(r);
        }
        
	}
	
	TotalArea::computerTotalArea(t,n);
	return 0;
         
}
