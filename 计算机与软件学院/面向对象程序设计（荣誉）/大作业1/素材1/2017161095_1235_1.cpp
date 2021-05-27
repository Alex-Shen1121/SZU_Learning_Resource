2017161095:Problem1235:正确
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

//double pi = acos(-1);
double pi=3.14;

class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};

class Rect : virtual public Geometry
{
    double x,y;
public:
    Rect(double x,double y):x(x),y(y){}
    virtual double getArea()
    {
        return x*y;
    }
};

class Circle : virtual public Geometry
{
    double r;
public:
    Circle(double r):r(r){}
    virtual double getArea()
    {
        return pi*r*r;
    }
};

class TotalArea{
    static double maxn;
public:
   static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
   {
       for(int i=0;i<n;i++)
       {
           if(maxn<(t[i]->getArea()))
            maxn=t[i]->getArea();
       }
   }
   static double getm();
};

double TotalArea::maxn=0;

double TotalArea::getm()
{
    return  maxn;
}

int main()
{
    int n,m,t,i,j,k,ans,num,sum,p,tot=0;
    string s,ss;
    double x,y,r;
    cin>>t,num=t;
    Geometry **w=new Geometry *[t];
    while(t--)
    {
        cin>>p;
        if(p==1)
        {
            cin>>x>>y;
            w[tot++]=new Rect(x,y);
        }
        else
        {
            cin>>r;
            w[tot++]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(w,num);
    cout<<"最大面积="<<fixed<<setprecision(2)<<TotalArea::getm()<<endl;
    return 0;
}

