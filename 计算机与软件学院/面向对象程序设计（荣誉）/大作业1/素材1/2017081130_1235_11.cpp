2017081130:Problem1235:正确
#include <iostream>
#include<iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rect:virtual public Geometry
{
    int x;
    int y;
public:
    Rect(){};
    Rect(int xx,int yy):x(xx),y(yy){};
    double getArea()
    {
        double a;
        a=x*y;
        return a;
    }
};
class Circle:virtual public Geometry
{
    int r;
public:
    Circle(){};
    Circle(int rr):r(rr){};
    double getArea()
    {
        double a;
        a=r*r*3.14;
        return a;
    }
};
class TotalArea
{
    double res;
public:
    TotalArea():res(0){};
    void computerTotalArea(Geometry**t,int n)
    {
        res=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(res<(t[i]->getArea()))
            {
                res=t[i]->getArea();
            }

        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<res<<endl;
    }
};
int main()
{
    int n,i,j,x,y,r,type;
    cin>>n;
    Geometry **p;
    p=new Geometry *[n];
    for(i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
            p[i]=new Rect{x,y};

        }
        else
        {
            cin>>r;
            p[i]=new Circle{r};
        }
    }
    TotalArea total;
    total.computerTotalArea(p,n);
    delete []p;
}

