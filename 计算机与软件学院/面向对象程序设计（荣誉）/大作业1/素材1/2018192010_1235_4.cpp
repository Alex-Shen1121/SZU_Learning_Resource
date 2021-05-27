2018192010:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0;
};
class Rect:public Geometry
{
protected:
    int a,b;
public:
    Rect(){}
    Rect(int av,int bv):a(av),b(bv){}
    double getArea()
    {
        return a*b;
    }
};
class Circle:public Geometry
{
protected:
    int r;
public:
    Circle(){}
    Circle(int b):r(b){}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea{

public:
   static void computerTotalArea(Geometry** t,int n)
   {
       float m = 0;
       for(int i=0;i<n;i++)
       {
            if(t[i]->getArea() > m)
                m = t[i]->getArea();
       }
       cout << "最大面积=" << fixed << showpoint << setprecision(2) << m << endl;
   }
};
int main()
{
    int n;
    cin >> n;
    TotalArea a;
    Geometry **t;
    t = new Geometry*[n];
    for(int i=0;i<n;i++)
    {
       int type;
       cin >> type;
       switch(type)
       {
       case 1:
        {
            int a,b;
            cin >> a >> b;
            t[i] = new Rect(a,b);
            break;
        }
       case 2:
        {
            int r;
            cin >> r;
            t[i] = new Circle(r);
            break;
        }
       }
    }
    a.computerTotalArea(t,n);
    return 0;
}

