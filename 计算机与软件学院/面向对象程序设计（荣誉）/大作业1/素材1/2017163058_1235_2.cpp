2017163058:Problem1235:正确
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea() = 0;
    virtual ~Geometry(){}
};
class Rect:public Geometry
{
private:
    double length, width;
public:
    Rect(double l, double w):length(l), width(w){}
    double getArea()
    {
        return length * width;
    }
};
class Circle:public Geometry
{
private:
    double radius;
public:
    Circle(double r):radius(r){}
    double getArea()
    {
        return 3.14*radius*radius;
    }
};
class TotalArea
{
public:
    static void computeTotalArea(Geometry **t, int n)
    {
        double max_area = 0;
        for(int i=0; i<n; i++)
        {
            if(max_area < t[i]->getArea())
            {
                max_area = t[i]->getArea();
            }
        }
        cout<<fixed<<setprecision(2)<<"最大面积="<<max_area<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    double length, width, radius;
    int t, sign;
    cin>>t;
    Geometry **p = new Geometry*[t];
    for(int i=0;i<t;i++)
    {
        cin>>sign;
        if(sign == 1)
        {
            cin>>length>>width;
            Rect *rect = new Rect(length, width);
            p[i] = rect;
        }
        else
        {
            cin>>radius;
            Circle *circle = new Circle(radius);
            p[i] = circle;
        }
    }
    TotalArea::computeTotalArea(p, t);
    for(int i=0; i<t; i++)
    {
        delete p[i];
    }
    delete []p;
    return 0;
}

