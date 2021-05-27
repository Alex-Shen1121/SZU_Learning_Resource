2018192009:Problem1235:答案错误
#include <iostream>

using namespace std;
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0;
};
class rect:public Geometry
{
protected:
    int len,width;
public:
    rect(){}
    rect(int l,int w):len(l),width(w){}
    virtual double getArea()
    {
        double a;
        a=len*width;
        return a;
    }
};
class circle:public Geometry
{
protected:
    int r;
public:
    circle(){}
    circle(int rr):r(rr){}
    virtual double getArea()
    {
        double a;
        a=r*r*3.14;
        return a;
    }
};
class TotalArea
{
public:
    TotalArea(){}
    static void computerTotalArea(Geometry** t,int n)
    {
        double maxx=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>maxx)
                maxx=t[i]->getArea();
        }
        cout<<"最大面积="<<maxx;
    }
};
int main()
{
    int t;
    int type,len,wid,r;
    cin>>t;
    Geometry **p;
    p=new Geometry*[t];
    for(int i=0;i<t;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>len>>wid;
            p[i]=new rect(len,wid);
        }
        else if(type==2)
        {
            cin>>r;
            p[i]=new circle(r);
        }
    }
    TotalArea a;
    a.computerTotalArea(p,t);
    return 0;
}

