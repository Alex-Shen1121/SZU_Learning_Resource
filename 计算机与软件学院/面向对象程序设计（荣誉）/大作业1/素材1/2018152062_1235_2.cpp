2018152062:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;
/*请编写程序，从图形数组中找出最大面积。基类框架如下所示：
以Geometry为基类，构建出Rect（矩形，数据成员为长和宽）和Circle（圆，数据成员为半径）两个类，
重写etArea()方法，其他方法根据需要自拟。
写一个TotalArea类，该类结构如下：
生成上述四个类并编写主函数，结果保留两位小数。*/
class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect:public Geometry
{
protected:
    float length;
    float width;
public:
    Rect(float _length,float _width):length(_length),width(_width){}
    double getArea()
    {
        return length*width;
    }
};
class Circle:public Geometry
{
protected:
    float r;
public:
    Circle(float _r):r(_r){}
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
        float maxS=-999999;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>maxS)
                maxS=t[i]->getArea();
        }
        cout<<"最大面积="<<setiosflags(ios::fixed)<<setprecision(2)<<maxS<<endl;
    }
    //t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小

};
int main()
{
    int n;
    cin>>n;
    Geometry **u=new Geometry*[n];
    for(int i=0; i<n; i++)
    {
        int cnt;
        float length,width,r;
        cin>>cnt;
        if(cnt==1)
        {
            cin>>length>>width;
            u[i]=new Rect(length,width);
        }
        else
        {
            cin>>r;
            u[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(u,n);
    for(int i=0;i<n;i++)
        delete u[i];
    delete []u;
}

