2018192045:Problem1235:正确
#include<iostream>
using namespace std;
#include<cstring>
#include<iomanip>
class Geometry
{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};
class Rect:public Geometry
{
    int chang,kuang;
public:
    Rect(int c,int k):chang(c),kuang(k) {}
    double getArea()
    {
        return chang*kuang;
    }

};
class Circle:public Geometry
{
    int r;
public:
    Circle(int r1):r(r1) {}
    double getArea()
    {
        return 3.14*r*r;
    }

};
class TotalArea
{

public:

    static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        Geometry *temp;
        int i,j;

        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-i-1; j++)
            {

                if((t[j]->getArea())>(t[j+1]->getArea()))
                {
                    temp=t[j+1];
                    t[j+1]=t[j];
                    t[j]=temp;

                }
            }
        }
        cout<<"最大面积="<<setprecision(2)<<setiosflags(ios::fixed)<<t[n-1]->getArea()<<endl;
    }

};
int main()
{
    int type,chang,kuang,r,i=0,t,flag,j;
    cin>>t;
    flag=t;
    Geometry **p;
    TotalArea C;
    p=new Geometry*[t];
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>chang>>kuang;
            Rect A(chang,kuang);
            p[i]=&A;
        }
        if(type==2)
        {
            cin>>r;
            Circle B(r);
            p[i]=&B;
        }
        i++;
    }
    C.computerTotalArea(p,flag);
}

