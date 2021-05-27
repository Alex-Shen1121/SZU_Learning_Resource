2018152007:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry
{

public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rect:public Geometry
{
private:
    int a,b;
public:
    Rect(int A,int B):a(A),b(B){}
    double getArea()
    {
        return a*b;
    }
};
class Circle:public Geometry
{
private:
    int r;
public:
    Circle(int R):r(R){}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea{

public:
    TotalArea(){}
   static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {

        int a;
        double b=0;
        for(a=0;a<n;a++)
        {
            if(t[a]->getArea()>b)
            {
                b=t[a]->getArea();
            }
        }
        cout<<"最大面积="<<fixed<<setprecision(2)<<b<<endl;
    }
};


int main()
{
    int time,a;
    cin>>time;
    Geometry **t=new Geometry*[time];
    for(a=0;a<time;a++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int chang,kuan;
            cin>>chang>>kuan;
            t[a]=new Rect(chang,kuan);
        }
        else
        {
            int radiu;
            cin>>radiu;
            t[a]=new Circle(radiu);
        }
    }
    TotalArea t1;
    t1.computerTotalArea(t,time);
    return 0;
}

