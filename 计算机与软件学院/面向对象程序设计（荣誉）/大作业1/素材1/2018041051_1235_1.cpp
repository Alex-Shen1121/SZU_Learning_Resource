2018041051:Problem1235:���д���
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Geometry{

public:

    virtual double getArea()=0; //����������������С�������λ

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

    static void computerTotalArea(Geometry** p,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
    {
        double biggest=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]->getArea()>biggest)
                biggest=(p[i]->getArea());
        }
        cout<<"������="<<biggest<<endl;
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

