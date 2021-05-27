2018182052:Problem1235:正确
#include <iostream>
#include<cstdio>
#include<cstring>
#include <string>
#include<iomanip>
#define ADDRESS "C:\\Users\\241\\Desktop\\in.txt","r",stdin
using namespace std;
class Geometay
{
public:
    virtual double get_area()const=0;
    virtual ~Geometay(){}
};

class Rect:public Geometay
{
    double x,y;
public:
    Rect(double xx,double yy):x(xx),y(yy) {}
    virtual double get_area()const
    {
        return x*y;
    }
    virtual ~Rect(){}
};
class Circle:public Geometay
{
    double r;
public:
    Circle(double rr):r(rr) {}
    virtual double get_area()const
    {
        return 3.14*r*r;
    }
    virtual ~Circle(){}
};
class TotalArea
{
public:
    static void computeTotalArea(Geometay** t,int n)
    {
        if(n<=0)
            return;
        double ans(t[0]->get_area());
        for(int i=1; i<n; ++i)
        {
            double k=t[i]->get_area();
            if(ans<k)
                ans=k;
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<ans<<endl;
    }
};
int main()
{
 //   freopen(ADDRESS);
    int n(0);
    cin>>n;
    Geometay** pp=new Geometay*[n];
    int cmd(0);
    double d[2];
    for(int i=0; i<n; ++i)
    {
        cin>>cmd;
        if(cmd==1)
        {
            cin>>d[0]>>d[1];
            pp[i]=new Rect(d[0],d[1]);
        }
        else if(cmd==2)
        {
            cin>>d[0];
            pp[i]=new Circle(d[0]);
        }
    }
    TotalArea tem;
    tem.computeTotalArea(pp,n);
    for(int i=0; i<n; ++i)
        delete pp[i];
    delete []pp;
    return 0;
}
