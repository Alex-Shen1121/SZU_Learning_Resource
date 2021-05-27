2018152007:Problem1235:��ȷ
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry
{

public:
    virtual double getArea()=0; //����������������С�������λ

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
   static void computerTotalArea(Geometry** t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
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
        cout<<"������="<<fixed<<setprecision(2)<<b<<endl;
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

