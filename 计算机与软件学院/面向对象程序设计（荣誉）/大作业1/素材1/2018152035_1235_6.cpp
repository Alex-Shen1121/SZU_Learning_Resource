2018152035:Problem1235:正确
#include <iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect:public Geometry
{
    double l,w;
public:
    Rect(int ll,int ww):l(ll),w(ww) {}
    double getArea()
    {
        return l*w;
    }
};
class Circle:public Geometry
{
    double r;
public:
    Circle(int rr):r(rr) {}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        double maxx=0;
        for(int i=0; i<n; i++)
        {
            if(t[i]->getArea()>maxx)
                maxx=t[i]->getArea();
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<maxx<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\1.txt","r",stdin);
    int n,t,w,l,r;
    cin>>n;
    Geometry **p;
    p=new Geometry*[n];
    for(int i=0; i<n; i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l>>w;
            p[i]=new Rect(l,w);
        }
        if(t==2)
        {
            cin>>r;
            p[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(p,n);
    for(int i=0;i<n;i++)
    {
        delete p[i];
    }
    delete []p;
}

