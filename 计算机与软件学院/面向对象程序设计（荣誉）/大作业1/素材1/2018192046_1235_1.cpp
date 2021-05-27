2018192046:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;
class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rect:public Geometry
{
    double lenth,width;
public:
    Rect(double _lenth,double _width):lenth(_lenth),width(_width){}
    double getArea()
    {
        return lenth*width;
    }
};
class Circle:public Geometry
{
    double r;
public:
    Circle(double _r):r(_r){}
    double getArea()
    {
        return r*r*3.14;
    }
};
class TotalArea{

public:
   static void computerTotalArea(Geometry** t,int n)
   {
       double *Area=new double[n];
       for(int i=0;i<n;i++)
       {
           Area[i]=t[i]->getArea();
       }
       double max=Area[0];
       for(int i=0;i<n;i++)
       {
           if(max<Area[i])
           {
               max=Area[i];
           }
       }
       cout<<"最大面积="<<setprecision(2)<<setiosflags(ios::fixed)<<max<<endl;
   }
};
int main()
{
    int t;
    cin>>t;
    int flag=t;
    int i=0;
    Geometry **pv=new Geometry*[flag];
    while(t--)
    {
        int type;
        double a,b,r;
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            Rect P(a,b);
            pv[i]=&P;
        }
        else if(type==2)
        {
            cin>>r;
            Circle P(r);
            pv[i]=&P;
        }
        i++;
    }
    TotalArea AR;
    AR.computerTotalArea(pv,flag);
}

