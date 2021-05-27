2018192014:Problem1235:正确
#include<bits/stdc++.h>
using namespace std;
class Geometry{
 
public:
 
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
    virtual ~Geometry()
    {
	}
};
class Rect:virtual public Geometry{
protected:
    double a,b;
public:
    Rect(double a1,double b1):
        a(a1),b(b1){    
        }
    virtual double getArea(){
        return a*b;
    }
    virtual ~Rect(){
	}
};
class Circle:virtual public Geometry{
protected:
    double r;
public:
    Circle(double r1):
        r(r1){
        }
    virtual double getArea(){
        return r*r*3.14;
    }
    virtual ~Circle(){
	}
};
class TotalArea{
 
public:
 
   static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        double res;
        for(int i=0;i<n;i++)
        {
            if(res<t[i]->getArea())
            {
                res=t[i]->getArea();
            }
        }
        cout<<"最大面积="<<fixed<<showpoint<<setprecision(2)<<res;
    }
};
int main ()
{
    Geometry **t;
    int n;
    cin>>n;
    t=new Geometry*[n];
    for(int i=0;i<n;i++)
    {
        int command;
        double a,b,r;
        cin>>command;
        if(command==1)
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
    TotalArea a;
    a.computerTotalArea(t,n); 
	for(int i=0;i<n;i++)
    {
    	delete t[i];
	}
	delete []t;
    return 0;
}
