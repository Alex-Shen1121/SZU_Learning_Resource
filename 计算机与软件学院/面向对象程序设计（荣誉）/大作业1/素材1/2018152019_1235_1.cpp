2018152019:Problem1235:正确
#include <iostream>

#include<iomanip>

using namespace std;

class Geometry
{

public:

    virtual double getArea()=0;

};

class Rect:public Geometry
{
    double length,width;
public:
    Rect(double le,double wi):length(le),width(wi){}
    virtual double getArea()
    {
        return length*width;
    }
};

class Circle:public Geometry
{
    double radius;
public:
    Circle(double r):radius(r){}
    virtual double getArea()
    {
        return 3.14*radius*radius;
    }
};

class TotalArea
{

public:

   static void computerTotalArea(Geometry** t,int n)
   {
       Geometry* temp;
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<n-1;j++)
           {
               if(t[j]->getArea()<t[j+1]->getArea())
               {
                   temp=t[j];
                   t[j]=t[j+1];
                   t[j+1]=temp;
               }
           }
       }
   }

};

int main()
{
    int n;
    cin>>n;
    Geometry** geo=new Geometry* [n];
    int type;
    double le,wi,ra;
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>le>>wi;
            Rect rect(le,wi);
            geo[i]=&rect;
        }
        else
        {
            cin>>ra;
            Circle circle(ra);
            geo[i]=&circle;
        }
    }
    TotalArea compare;
    compare.computerTotalArea(geo,n);
    cout<<"最大面积="<<fixed<<setprecision(2)<<geo[0]->getArea()<<endl;
    return 0;
}

