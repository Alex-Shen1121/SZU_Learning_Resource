2018152102:Problem1235:��ȷ
#include <iostream>
#include <iomanip>

using namespace std;
class Geometry{
public:
    virtual double getArea()=0; //����������������С�������λ
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
        cout<<"������=";
        cout<<fixed<<setprecision(2)<<max;
   }
   //tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
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

