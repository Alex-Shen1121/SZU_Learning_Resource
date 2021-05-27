2017044015:Problem1235:�𰸴���
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Geometry{
public:
    virtual double getArea() = 0; //����������������С�������λ

};

class Rect: public Geometry{
    double a, b;
public:
    Rect(double a0, double b0){
        a = a0;
        b = b0;
    }
    virtual double getArea(){
        return a*b;
    }
};

class Circle: public Geometry{
    double r;
public:
    Circle(double r0){
        r = r0;
    }
    virtual double getArea(){
        return 3.14*r*r;
    }
};

class TotalArea{
    static double max_area;
public:
    TotalArea(){
    }
    //tΪ�������ָ�룬ָ��һ�����ද̬����
    //�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
   static void computerTotalArea(Geometry** t, int n){
        for(int i=0; i<n; i++){
            if(t[i][0].getArea() > max_area)
                max_area = t[i][0].getArea();
        }
   }
    static double getMax_Area(){
        return max_area;
    }
};

double TotalArea::max_area = 0;

int main()
{
    int t, type;
    double a, b, r;
    TotalArea TA();
    cin>>t;
    Geometry** gep = new Geometry*[t];
    //gep = new Geometry[t];
    for(int i=0; i<t; i++){
        cin>>type;
        if(type == 1){
            cin>>a>>b;
            Rect rect(a, b);
            gep[i] = &rect;
        }
        if(type == 2){
            cin>>r;
            Circle circle(r);
            gep[i] = &circle;
        }
    }
    TotalArea::computerTotalArea(gep, t);
    cout<<TotalArea::getMax_Area()<<endl;
    return 0;
}

