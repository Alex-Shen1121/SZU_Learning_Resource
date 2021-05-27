2018151005:Problem1235:答案错误
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
/*题目描述

请编写程序，从图形数组中找出最大面积。基类框架如下所示：

class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};*/
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
/*以Geometry为基类，构建出Rect（矩形，数据成员为长和宽）和Circle（圆，数据成员为半径）两个类，重写getArea()方法，
其他方法根据需要自拟。*/
class Rect:public Geometry
{
private:
    double length,width;
public:
    Rect(){}
    Rect(double length0,double width0):length(length0),width(width0){}
    double getArea()
    {
        return length*width;
    }
};
class Circle:public Geometry
{
private:
    double radius;
public:
    Circle(){}
    Circle(double radius0):radius(radius0){}
    double getArea()
    {
        return 3.14*radius*radius;
    }
};
/*写一个TotalArea类，该类结构如下：

class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)；//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向
   一个子类图形，n为数组的大小

};*/
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double max_area=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i-1]->getArea()>max_area)
                max_area=t[i-1]->getArea();
        }
        cout<<"最大面积="<<double(int(max_area*100+0.5))/100<<endl;
    }
};
/*
生成上述四个类并编写主函数，结果保留两位小数。

输入

第一行表示测试次数。从第二行开始，每个测试用例占一行，每行数据意义如下：图形类型（1为Rect(矩形)，2为Circle(圆)）、
基本信息（Rect是长和宽，Circle是半径）。

输出

最大图形的面积
样例输入

3
1 3 4
2 5
2 6
样例输出

最大面积=113.04
提示*/
int main()
{
    int t;
    cin>>t;
    Geometry** p;
    p=new Geometry*[t];
    for(int i=1;i<=t;i++)
    {
        int type;
        cin>>type;
        switch(type)
        {
        case 1:
            {
                double length,width;
                cin>>length>>width;
                Rect a(length,width);
                p[i-1]=&a;
                break;
            }
        case 2:
            {
                double radius;
                cin>>radius;
                Circle a(radius);
                p[i-1]=&a;
                break;
            }
        }
    }
    TotalArea b;
    b.computerTotalArea(p,t);
}

