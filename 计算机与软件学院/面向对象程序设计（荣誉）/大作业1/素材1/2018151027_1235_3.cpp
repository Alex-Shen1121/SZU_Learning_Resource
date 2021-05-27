2018151027:Problem1235:正确
#include <iostream>
#include<iomanip>
using namespace std;
class Geometry
{
protected:

public:
    virtual double getArea()=0;
};
class Rect: public Geometry
{
protected:
    int x;
    int y;
public:
    Rect(int xv,int yv):x(xv),y(yv){}
    double getArea()
    {
        return x*y;
    }
};
class Circle: public Geometry
{
protected:
    int r;
public:
    Circle(int rv):r(rv){}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea
{
public:
   static void computerTotalArea(Geometry *t[],int n)
   {
        double area=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>area)
                area=t[i]->getArea();
        }
        cout<<"最大面积="<<setiosflags(ios::fixed)<<setprecision(2)<<area;
   }
};
main()
{
    int t,type,x,y,r,n,i=0;
    cin>>t;
    n=t;
    Geometry *p[t];
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
            p[i]=new Rect(x,y);
            i++;
        }
        else
        {
            cin>>r;
            p[i]=new Circle(r);
            i++;
        }
    }
    TotalArea tt;
    tt.computerTotalArea(p,n);


}

