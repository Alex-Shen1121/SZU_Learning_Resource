2017182013:Problem1235:正确
#include <bits/stdc++.h>

using namespace std;

class Geometry
{
public:
    virtual double getArea()=0;
};
class Rect:public Geometry
{
protected:
    double x,y;
public:
    Rect(double xv,double yv):x(xv),y(yv){}
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
    Circle(double rv):r(rv)
    {

    }
    double getArea()
    {
        return 3.14*r*r;
    }

};
class TotalArea
{
    static double maxArea;
public:
    static double getMax()
    {
        return maxArea;
    }
    static void computerTotalArea(Geometry **t,int n);
};
void TotalArea::computerTotalArea(Geometry **t,int n)
{
    maxArea = t[0]->getArea();
    for(int i=1; i<n; i++)
    {
        if(maxArea<t[i]->getArea())
            maxArea = t[i]->getArea();
    }
}
double TotalArea::maxArea=0;
int main()
{
    int n;
    cin>>n;
    Geometry **t = new Geometry*[n];
    for(int i=0; i<n; i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            double x,y;
            cin>>x>>y;
            Rect r(x,y);
            t[i] = &r;
        }
        else if(type==2)
        {
            int r;
            cin>>r;
            Circle c(r);
            t[i] = &c;
        }
    }
    TotalArea::computerTotalArea(t,n);
    printf("最大面积=%.2f\n",TotalArea::getMax());
    delete[]t;
    return 0;
}

