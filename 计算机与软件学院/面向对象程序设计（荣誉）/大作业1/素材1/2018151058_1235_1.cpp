2018151058:Problem1235:正确
#include <iostream>
#include<iomanip>
using namespace std;
class Geometry
{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rector:public Geometry
{
protected:
    double x,y;
public:
Rector() {};
    Rector(double a,double b)
    {
        x=a,y=b;
    }
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
    Circle() {};
    Circle(double c)
    {
        r=c;
    }
    double getArea()
    {
        return 3.14*r*r;
    }

};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double max=0;
        for(int i=0;i<n;i++)
        {
           if(t[i]->getArea()>max)
            max=t[i]->getArea();

        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    Geometry **p=new Geometry*[t];
   for(int i=0;i<t;i++)
   {
        int type;
        cin>>type;
        double a,b;
        if(type==1)
        {
            cin>>a>>b;
            Rector a1(a,b);
            p[i]=&a1;
        }
        if(type==2)
        {
            cin>>a;
            Circle b1(a);
            p[i]=&b1;
        }

    }
    TotalArea::computerTotalArea(p,t);
    return 0;
}

