2017081130:Problem1235:编译错误
#include <iostream>
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
        a=r*r*3.141;
        return a;
    }
};
class TotalArea:virtual public Geometry
{
public:
    static  int num;
    static void computerTotalArea(Geometry**t,int n)
    {
        int i,j;
        double areamax;
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(t[j]->getArea()>t[j+1]->getArea())
                    areamax=t[j]->getArea();
            }

        }
    }
};
int TotalArea::num=0;
int main()
{
    int n,i,j,x,y,r;
    cin>>n;
    Geometry **p;
    p=new Geometry*[n];
    for(i=1;i<=n;i++)
    {
        p[i]=new Geometry[n];
    }
    for(i=1;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
            Rect rect(x,y);
            p[i]=&rect;

        }
        else
        {
            cin>>r;
            Circle c(r);
            p[i]=&c;
        }
    }
    TotalArea total(Geometry **p,t);
}

