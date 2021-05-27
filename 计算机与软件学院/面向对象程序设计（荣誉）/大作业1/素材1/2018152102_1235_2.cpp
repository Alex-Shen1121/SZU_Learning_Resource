2018152102:Problem1235:正确
#include <iostream>
#include <iomanip>

using namespace std;
class Geometry{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
class Rect :public Geometry{
protected:
    double a,b;
public:
    Rect(double t0,double t1):a(t0),b(t1) {}
    double getArea() {
        return a*b;
    }
};
class Circle:public Geometry {
protected:
    double r;
public:
    Circle(double t):r(t) {}
    double getArea() {
        return 3.14*r*r;
    }
};
class TotalArea{
public:
   static void computerTotalArea(Geometry** t,int n) {
        double max = -100;
        for(int i=0;i<n;i++) {
            if(t[i]->getArea() > max) {
                max = t[i]->getArea();
            }
        }
        cout<<"最大面积=";
        cout<<fixed<<setprecision(2)<<max;
   }
   //t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
};

int main() {
    int n;

    cin>>n;
    Geometry** p = new Geometry* [n];
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        if(num == 1) {
            double a,b;
            cin>>a>>b;
            p[i] = new Rect(a,b);
        }else {
            double r;
            cin>>r;
            p[i] = new Circle(r);
        }
    }

    TotalArea total;
    total.computerTotalArea(p,n);
    for(int i=0;i<n;i++) {
        delete p[i];
    }
    delete []p;

    return 0;
}

