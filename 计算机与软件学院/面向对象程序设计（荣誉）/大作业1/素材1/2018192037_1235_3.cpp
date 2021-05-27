2018192037:Problem1235:答案错误
#include<bits/stdc++.h>
using namespace std;
class Geometry{

public:
    Geometry(){}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};

class CRect:public Geometry
{
protected:
    int x;
    int y;
public:
    CRect(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    double getArea()
    {
        return x*y;
    }
};

class CCircle:public Geometry
{
protected:
    int r;
public:
    CCircle(int y)
    {
        this->r = y;
    }
    double getArea()
    {
        return 3.14*r*r;
    }
};

class TotalArea{
private:
    static double max;
public:
    static void computerTotalArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        for(int i=0;i<n;i++)
        {
            double mid = t[i]->getArea();
            if(mid>max)
                max = mid;
        }
    }
    static double get_max()
    {
        return max;
    }
};

double TotalArea::max;

int main()
{
    int n;
    cin>>n;
    Geometry **t;
    t = new Geometry*[n];
    for(int i=0;i<n;i++)
    {
        int ty,x,y;
        cin>>ty;
        if(ty==1)
        {
            cin>>x>>y;
            CRect rect(x,y);
            t[i] = &rect;
        }
        if(ty==2)
        {
            cin>>x;
            CCircle cri(x);
            t[i] = &cri;
        }
    }
    TotalArea::computerTotalArea(t,n);
    cout<<setw(2)<<setfill('0')<<"最大面积="<<TotalArea::get_max();
}



