2017182103:Problem1235:运行错误
#include <iostream>
using namespace std;

class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
    int length,width;
public:
    Rect(int l,int w):length(l),width(w) {}
    virtual double getArea()
    {
        return length*width;
    }
};

class Circle:public Geometry
{
    int radius;
public:
    Circle(int r):radius(r) {}
    virtual double getArea()
    {
        return 3.14*radius*radius;
    }
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double *sum = new double[n];
        for(int i=0; i<n; i++)
        {
            sum[i] = t[i]->getArea();
        }
        double max = sum[0];
        for(int i=0; i<n; i++)
        {
            if(sum[i]>max)
                max = sum[i];
        }
        cout<<"最大面积="<<max<<endl;

        delete []sum;
    }
};

int main()
{
    int n;
    cin>>n;

    Geometry **t = new Geometry*[n];

    for(int i=0; i<n; i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,w;
            cin>>l>>w;
            Rect rect(l,w);
            t[i] = &rect;
        }
        else
        {
            int r;
            cin>>r;
            Circle c(r);
            t[i] = &c;
        }
    }

    TotalArea ta;
    ta.computerTotalArea(t,n);

    for(int i=0; i<n; i++)
    {
        delete []t[i];
    }
    delete t;
    return 0;
}

