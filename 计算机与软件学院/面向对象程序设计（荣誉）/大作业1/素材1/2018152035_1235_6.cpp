2018152035:Problem1235:��ȷ
#include <iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //����������������С�������λ
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
    static void computerTotalArea(Geometry** t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
    {
        double maxx=0;
        for(int i=0; i<n; i++)
        {
            if(t[i]->getArea()>maxx)
                maxx=t[i]->getArea();
        }
        cout<<"������="<<fixed<<setprecision(2)<<maxx<<endl;
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

