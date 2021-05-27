2018192044:Problem1235:正确
#include <iostream>
using namespace std;
#include<iomanip>
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
    virtual ~Geometry(){}
};
class Rect:public Geometry
{
    double l,h;
public:
    Rect(double l1,double h1):l(l1),h(h1){}
    double getArea()
    {
        return l*h;
    }
    ~Rect(){}
};
class Circle:public Geometry
{
    int r;
public:
    Circle(int r1):r(r1){}
    double getArea()
    {
        return 3.14*r*r;
    }
    ~Circle(){}
};
class TotalArea
{
public:
   static void computerTotalArea(Geometry** t,int n)
   {
        double max=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>max)
                max=t[i]->getArea();
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
   }
};
int main()
{
    int t,r,i,type;
    double l,h;
    cin>>t;
    Geometry **p=new Geometry*[t];
    for(i=0;i<t;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>h;
            p[i]=new Rect(l,h);
        }
        else
        {
            cin>>r;
            p[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(p,t);
    for(i=0;i<t;i++)
        delete p[i];
    delete []p;
    return 0;
}
