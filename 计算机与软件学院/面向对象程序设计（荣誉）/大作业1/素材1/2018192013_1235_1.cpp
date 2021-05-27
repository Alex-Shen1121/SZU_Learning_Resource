2018192013:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;

class Geometry
{
public:
    virtual double getArea()=0;
};

class Rect:public Geometry
{
    double a,b;
public:
    Rect(double a_,double b_):a(a_),b(b_){}
    double getArea(){return a*b;}
    friend class TotalArea;
};

class Circle:public Geometry
{
    double r;
public:
    Circle(double r_):r(r_){}
    double getArea(){return 3.14*r*r;}
    friend class TotalArea;
};

class TotalArea
{
public:
    static void computerTotalArea(Geometry **t,int n)
    {
        int i;
        double maxArea;
        maxArea=t[0]->getArea();
        for(i=1;i<n;i++)
            if(t[i]->getArea()>maxArea)
                maxArea=t[i]->getArea();
        cout<<"最大面积="<<fixed<<setprecision(2)<<maxArea<<endl;
    }
};

int main()
{
    int n,i;
    cin>>n;
    Geometry **t;
    t=new Geometry*[n];
    for(i=0;i<n;i++)
    {
        int type;
        double a,b,r;
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            Rect rect(a,b);
            t[i]=&rect;
        }
        else if(type==2)
        {
            cin>>r;
            Circle c(r);
            t[i]=&c;
        }
    }
    TotalArea::computerTotalArea(t,n);
    return 0;
}

