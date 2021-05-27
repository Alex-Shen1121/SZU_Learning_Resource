2018041051:Problem1235:运行错误
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};

class Rect:public Geometry
{
protected:
    double dlong,wide;
public:
    Rect(){}
    Rect(double dlong1,double wide1):dlong(dlong1),wide(wide1){}
    double getArea()
    {
        return dlong*wide;
    }
};

class Circle:public Geometry
{
protected:
    double r;
public:
    Circle(){}
    Circle(double r1):r(r1){}
    double getArea()
    {
        return 3.14*r*r;
    }
};

class TotalArea{

public:

    static void computerTotalArea(Geometry** p,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        double biggest=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]->getArea()>biggest)
                biggest=(p[i]->getArea());
        }
        cout<<"最大面积="<<biggest<<endl;
    }
};

int main()
{
    Geometry **p;

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            int dlong,wide;
            cin>>dlong>>wide;
            p[i]=new Rect(dlong,wide);
        }
        else
        {
            int r;
            cin>>r;
            p[i]=new Circle(r);
        }
    }
    TotalArea pr;
    pr.computerTotalArea(p,t);


    return 0;
}

