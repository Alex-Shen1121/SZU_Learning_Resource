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
    virtual ~Geometry(){}
};

class Rect:public Geometry
{
private:
    double a,b;
public:
    Rect(double aa,double bb):a(aa),b(bb){}
    double getArea(){return a*b;}
};

class Circle:public Geometry
{
    double r;
public:
    Circle(double rr):r(rr){}
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
    double a,b,r;
    int i=0;
    while (n--)
    {
        cin >> m;
        if (m==1)
        {
            cin >> a >> b;
            t[i++]=new Rect(a,b);
        }
        else if (m==2)
        {
            cin >> r;
            t[i++]=new Circle(r);
        }

    }
    TotalArea::computerTotalArea(t,n1);
    cout << "最大面积=";
    cout << fixed << setprecision(2) << TotalArea::biggest << endl;
    for (int i=0;i<n;i++)
        delete []t[i];
    delete []t;
    return 0;
}
