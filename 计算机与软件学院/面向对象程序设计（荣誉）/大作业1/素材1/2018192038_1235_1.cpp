2018192038:Problem1235:运行错误
#include <iostream>
#include <iomanip>
using namespace std;

class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
    double length;
    double width;
public:
    Rect(double ll,double ww):length(ll),width(ww){}
    double getArea()
    {
        return length*width;
    }
};

class Circle:public Geometry
{
    double r;
public:
    Circle(double rr):r(rr){}
    double getArea()
    {
        return r*r*3.14;
    }
};


class TotalArea
{
    double res;
public:
    TotalArea():res(0){}
    void computerTotalArea(Geometry** t,int n)
    {
           res=0;
           for(int i=0;i<n;i++)
           {
               double mm=(*t[i]).getArea();
               if(res<mm)
               {
                   res=mm;
               }
           }
           cout<<"最大面积="<<fixed<<setprecision(2)<<res<<endl;
    }
};


int main()
{
    double length;
    double width;
    double r;
    int n,type;
    cin>>n;
    Geometry **p=new Geometry*[n];
   // Rect *rr=new Rect[n];
    //Circle *cc=new Circle[n];
   // Geometry **pp=&p;
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>length>>width;
            Rect re(length,width);
            p[i]=&re;
        }
        else if(type==2)
        {
            cin>>r;
            Circle cir(r);
            p[i]=&cir;
        }
    }
    TotalArea total;
    total.computerTotalArea(p,n);
    return 0;
}

