2018152026:Problem1235:正确
#include <bits/stdc++.h>
using namespace std;

class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
protected:
    double x,y;
public:
    Rect(double xx,double yy):x(xx),y(yy){}
    virtual double getArea()
    {
        return x*y;
    }
};

class Circle:public Geometry
{
protected:
    double r;
public:
    Circle(double rr):r(rr){}
    virtual double getArea()
    {
        return 3.14*r*r;
    }
};

class TotalArea
{
public:
   static void computerTotalArea(Geometry** t,int n)
   {
       int i;
       double max=0;
       for(i=0;i<n;i++)
       {
           if(max<t[i]->getArea())
            max=t[i]->getArea();
       }
       cout<<"最大面积="<<setiosflags(ios::fixed)<<setprecision(2)<<max<<endl;
   }//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
};

int main()
{
    int n,i;
    cin>>n;
    Geometry** t=new Geometry*[n];
    for(i=0;i<n;i++)
    {
        int m;
        cin>>m;
        if(m==1)
        {
            int xx,yy;
            cin>>xx>>yy;
            Rect *a;
            a=new Rect(xx,yy);
            t[i]=a;
        }
        else
        {
            int rr;
            cin>>rr;
            Circle *b;
            b=new Circle(rr);
            t[i]=b;
        }
    }
    TotalArea p;
    p.computerTotalArea(t,n);
    return 0;
}
