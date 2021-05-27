2018152100:Problem1235:正确
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI=3.14;

class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0;
};

class Rect:public Geometry
{
private:
    double a,b;
public:
    Rect(){}
    Rect(double aa,double bb):a(aa),b(bb){}
    void setting(double aa,double bb){a=aa;b=bb;}
    double getArea(){return a*b;}
};

class Circle:public Geometry
{
    double r;
public:
    Circle(){}
    Circle(double rr):r(rr){}
    void setting(double rr){r=rr;}
    double getArea(){return PI*r*r;}
};

class TotalArea
{
public:
    static double biggest;
    static void computerTotalArea(Geometry** t,int n)
    {
        for (int i=0;i<n;i++)
        {
            if (biggest<(t[i]->getArea()))
                biggest=t[i]->getArea();
        }
    }
};

double TotalArea::biggest=0;

int main()
{
    int n,m;
    cin >> n;
    int n1=n;
    Geometry **t=new Geometry*[n];
    Rect *rec=new Rect[n];
    Circle *cir=new Circle[n];
    double a,b,r;
    int ir=0,ic=0,i=0;
    while (n--)
    {
        cin >> m;
        if (m==1)
        {
            cin >> a >> b;
            rec[ir].setting(a,b);
            t[i++]=&rec[ir++];
        }
        else if (m==2)
        {
            cin >> r;
            cir[ic].setting(r);
            t[i++]=&cir[ic++];
        }

    }
    TotalArea::computerTotalArea(t,n1);
    cout << "最大面积=";
    cout << fixed << setprecision(2) << TotalArea::biggest << endl;
    delete []t;
    delete []rec;
    delete []cir;
    return 0;
}
