2018192043:Problem1235:��ȷ
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //����������������С�������λ
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
    static void computerTotalArea(Geometry** t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
    {
        double area=t[0]->getArea();
        for(int i=1;i<n;i++)
        {
            if(t[i]->getArea()>area)
                area=t[i]->getArea();
        }
        cout<<"������="<<fixed<<setprecision(2)<<area<<endl;
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

