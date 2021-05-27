2018152010:Problem1235:答案错误
#include<iostream>

using namespace std;

class Geometry
{
public:
    virtual double getArea()=0;
};

class Rect:public Geometry
{
    int wide,_long;
public:
    Rect(int w,int l):wide(w),_long(l){}
    double getArea()
    {
        double area;
        area=wide*_long;
        return area;
    }
};

class Circle:public Geometry
{
    int R;
public:
    Circle(int r):R(r){}
    double getArea()
    {
        double area;
        area=R*R*3.14;
        return area;
    }
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry **t,int n)
    {
        int i,j;
        double area=0;
        for(i=0;i<n;i++)
        {
            if(area<t[i]->getArea())
                area=t[i]->getArea();
        }
        cout<<"最大面积="<<area<<endl;
    }
};

int main()
{
    int n,w,l,r,type,i;
    cin>>n;
    Geometry **t;
    t=new Geometry*[n];
    for(i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>w>>l;
            t[i]=new Rect(w,l);
        }
        else
        {
            cin>>r;
            t[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(t,n);
}

