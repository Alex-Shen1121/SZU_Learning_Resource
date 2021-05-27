2018192044:Problem1235:�𰸴���
#include <iostream>
using namespace std;
class Geometry
{
public:
    Geometry(){}
    virtual double getArea()=0; //����������������С�������λ
};
class Rect:public Geometry
{
    int l,h;
public:
    Rect(int l1,int h1):l(l1),h(h1){}
    double getArea()
    {
        return l*h;
    }
};
class Circle:public Geometry
{
    int r;
public:
    Circle(int r1):r(r1){}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea
{
public:
   static void computerTotalArea(Geometry** t,int n)
   {
        double max=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>max)
                max=t[i]->getArea();
        }
        cout<<"������="<<max<<endl;
   }
};
int main()
{
    int t,r,l,h,i,type;
    cin>>t;
    Geometry **p=new Geometry*[t];

    for(i=0;i<t;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>h;
            Rect A(l,h);
            p[i]=&A;
        }
        else
        {
            cin>>r;
            Circle A(r);
            p[i]=&A;
        }
    }
    TotalArea::computerTotalArea(p,t);
    return 0;
}

