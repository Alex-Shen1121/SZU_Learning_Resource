2018192038:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;

class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
    virtual ~Geometry(){}
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
    ~Rect(){}
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
    ~Circle(){}
};


class TotalArea
{
    double res;
public:
    TotalArea():res(0){}
    void computerTotalArea(Geometry** t,int n)
    {
       for(int i=0;i<n;i++)
       {
           if(res< t[i]->getArea())
           {
               res= t[i]->getArea();
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
            p[i]=new Rect(length,width);
        }
        else if(type==2)
        {
            cin>>r;
            p[i]=new Circle(r);
        }
    }
    TotalArea total;
    total.computerTotalArea(p,n);

    for(int i=0;i<n;i++)
    {
        delete p[i];
    }
    return 0;
}

