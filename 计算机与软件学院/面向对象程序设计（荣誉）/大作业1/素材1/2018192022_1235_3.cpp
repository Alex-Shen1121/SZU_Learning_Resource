2018192022:Problem1235:正确
#include <iostream>
#include <iomanip>
#define PI 3.14
using namespace std;
class Geometry{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rect:public Geometry
{
protected:
    double x,y;
public:
    Rect(double a,double b):x(a),y(b){}
    double getArea()
    {
        return x*y;
    }
};
class Circle:public Geometry
{
protected:
    double r;
public:
    Circle(double c):r(c){}
    double getArea()
    {
        return r*r*PI;
    }
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry**t,int n);
};
void TotalArea::computerTotalArea(Geometry **t, int n)
{
    int i;
    double s=0;
    for(i=0;i<n;i++)
        if(s<t[i]->getArea())
            s=t[i]->getArea();
    cout<<"最大面积="<<fixed<<setprecision(2)<<s<<endl;
}
int main()
{
    int t,i;
    cin>>t;
    Geometry **p;
    p =new Geometry *[t];

    for(i=0;i<t;i++)
    {
        int num;
        cin>>num;
        if(num==1)
        {
            double x,y;
            cin>>x>>y;
            p[i] = new Rect(x,y);
        }
        else if(num==2)
        {
            double r;
            cin>>r;
            p[i]=new Circle(r);
        }
    }
    TotalArea q;
    q.computerTotalArea(p,t);
    return 0;
}
