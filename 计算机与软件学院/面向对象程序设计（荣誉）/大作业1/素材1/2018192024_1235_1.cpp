2018192024:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;

class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0;
    friend class TotalArea;
};
class Rect:public Geometry
{
    double a,b;
public:
    Rect(double _a,double _b):a(_a),b(_b){}
    virtual double getArea(){return a*b;}
    friend class TotalArea;
};
class Circle:public Geometry
{
    double r;
public:
    Circle(double _r):r(_r){}
    virtual double getArea(){return 3.14*r*r;}
    friend class TotalArea;
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double maxArea=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>maxArea)
                maxArea=t[i]->getArea();
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<maxArea<<endl;
    }
};

int main()
{
    int n;
    cin>>n;
    Geometry** t;
    t=new Geometry*[n];
    int type;
    double a,b,r;
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            Rect rec(a,b);
            t[i]=&rec;
        }
        else if(type==2)
        {
            cin>>r;
            Circle cir(r);
            t[i]=&cir;
        }
    }
    TotalArea cta;
    cta.computerTotalArea(t,n);
    return 0;
}

