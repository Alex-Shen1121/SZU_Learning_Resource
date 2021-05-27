2018192025:Problem1235:正确
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
protected:
    double length;
    double width;
public:
    Rect(double len, double wid):length(len),width(wid) {};
    virtual double getArea()
    {
        return length*width;
    }
};

class Circle:public Geometry
{
protected:
    double R;
public:
    Circle(double r):R(r) {};
    virtual double getArea()
    {
        return 3.14*R*R;
    }
};

class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double maxArea=t[0]->getArea();
        for(int i=0; i<n; i++)
        {
            if(t[i]->getArea()>maxArea)
                maxArea=t[i]->getArea();
        }
        cout<<"最大面积="<<setprecision(2)<<setiosflags(ios::fixed)<<maxArea<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    Geometry **pv=new Geometry*[t];
    for(int i=0; i<t; i++)
    {
        int m;
        double l,w,r;
        cin>>m;
        if(m==1)
        {
            cin>>l>>w;
            Rect ss(l,w);
            pv[i]=&ss;
        }
        else if(m==2)
        {
            cin>>r;
            Circle ss(r);
            pv[i]=&ss;
        }
    }
    TotalArea k;
    k.computerTotalArea(pv,t);
    delete[]pv;
}

