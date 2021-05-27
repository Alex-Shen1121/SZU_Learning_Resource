2018151020:Problem1235:正确
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
    virtual ~Geometry(){}
};
class Rect:public Geometry
{
protected:
    double length,width;
public:
    Rect(double l,double w):length(l),width(w){}
    double getArea()
    {
        return length*width;
    }
    ~Rect(){}
};
class Circle:public Geometry
{
protected:
    double r;
public:
    Circle(double _r):r(_r){}
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
        double Max=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>Max)
                Max = t[i]->getArea();
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<Max<<endl;
    }
} ;
int main()
{
    int t;
    cin>>t;
    Geometry **G = new Geometry *[t];
    for(int i=0;i<t;i++)
    {
        int k;
        cin>>k;
        if(k==1)
        {
            double l,w;
            cin>>l>>w;
            G[i] = new Rect(l,w);
        }
        else if(k==2)
        {
            double r;
            cin>>r;
            G[i] = new Circle(r);
        }
    }
    TotalArea::computerTotalArea(G,t);
    for(int i=0;i<t;i++)
        delete G[i];
    delete G;
    return 0;
}

