2016150076:Problem1235:答案错误
#include<iostream>
using namespace std; 

class Geometry{
 
public:
 	double area;
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
 
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
		}
};
 

 
class TotalArea{
 
public:
 
   static void computerTotalArea(Geometry** t,int n);//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
 
};
 
void TotalArea::computerTotalArea(Geometry** t,int n)
{
	double max=0;
	for(int i=0;i<n;i++)
	{
			if(t[i]->getArea()>max)
				max=t[i]->getArea();
	}
	cout<<"最大面积="<<max<<endl;
		
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
	
	TotalArea::computerTotalArea(t, n);
         
}

