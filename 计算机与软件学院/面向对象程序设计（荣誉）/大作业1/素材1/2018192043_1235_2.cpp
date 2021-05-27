2018192043:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect:public Geometry
{
    int longs,shorts;
public:
    Rect(int ls,int ss):longs(ls),shorts(ss) {}
    double getArea()
    {
        return longs*shorts;
    }
    ~Rect() {}
};
class Circle:public Geometry
{
    int r;
public:
    Circle(int rs):r(rs) {}
    double getArea()
    {
        return 3.14*r*r;
    }
    ~Circle() {}
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        double area=t[0]->getArea();
        for(int i=1;i<n;i++)
        {
            if(t[i]->getArea()>area)
                area=t[i]->getArea();
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<area<<endl;
    }
};
int main()
{
    Geometry **p;
    int t,type,shorts,longs,r,counts=0;
    cin>>t;
    p=new Geometry*[t];
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>shorts>>longs;
            Rect a(longs,shorts);
            p[counts]=&a;
        }
        else
        {
            cin>>r;
            Circle a(r);
            p[counts]=&a;
        }
        counts++;
    }
    TotalArea x;
    x.computerTotalArea(p,counts);
    delete p;
    return 0;
}

