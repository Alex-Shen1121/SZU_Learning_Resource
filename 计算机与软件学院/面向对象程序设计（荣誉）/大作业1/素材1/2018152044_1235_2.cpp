2018152044:Problem1235:��ȷ
#include<iostream>
#include<iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0;
};
class Rect:public Geometry
{
protected:
    double length,width;
public:
    Rect()
    {
    }
    Rect(double l,double w)
    {
        length=l;
        width=w;
    }
    double getArea()
    {
        double area=length*width;
        return area;
    }
};
class Circle:public Geometry
{
protected:
    double r;
public:
    Circle()
    {
    }
    Circle(double r_)
    {
        r=r_;
    }
    double getArea()
    {
        double area=r*r*3.14;
        return area;
    }
};
class TotalArea
{
public:
    TotalArea()
    {
    }
    static void computerTotalArea(Geometry **t,int n)
    {
        double *area;
        area=new double[n];
        for(int i=0;i<n;i++)
        {
            area[i]=t[i]->getArea();
        }
        double maxarea=area[0];
        for(int i=0;i<n;i++)
        {
            if(maxarea<area[i])
                maxarea=area[i];
        }
        cout<<"������="<<fixed<<setprecision(2)<<maxarea<<endl;
    }
};

int main()
{
    int n;
    cin>>n;
    Geometry *s[1000];
    for(int i=0;i<n;i++)
    {
        double x,y,r;
        int type;
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
            s[i]=new Rect(x,y);
        }
        else if(type==2)
        {
            cin>>r;
            s[i]=new Circle(r);
        }
    }
    TotalArea Total;
    Total.computerTotalArea(s,n);
    return 0;
}
