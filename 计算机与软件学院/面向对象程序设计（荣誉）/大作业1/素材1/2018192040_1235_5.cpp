2018192040:Problem1235:正确
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
double pi = 3.14;
class Geometry{
 
public:
 
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
 
};
 
class Rect:public Geometry{
    double l,w;
public:
    Rect(){
    };
    Rect(double L,double W):l(L),w(W){
    };
    double getArea(){
        return l*w;
    }
};
 
class Circle:public Geometry{
    double r;
public:
    Circle(){
    };
    Circle(double R):r(R){
    };
    double getArea(){
        return r*r*pi;
    }
};
 
class TotalArea{
 
public:
 
   static void computerTotalArea(Geometry** t,int n){
        double max = t[0]->getArea();
        for(int i=0;i<n;i++)
            if(max<t[i]->getArea())
                max = t[i]->getArea();
        cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl; 
   }
 
};
 
 
int main(){
    int n;
    cin>>n;
    TotalArea ta;
    Geometry **p1;
    p1 = new Geometry*[n];
    for(int i=0;i<n;i++){
        int type,r,w,l;
        cin>>type;
        if(type == 1){
            cin>>l>>w;
            Rect re(l,w);
            p1[i] = new Rect(l,w);
        }
        if(type == 2){
            cin>>r;
            p1[i] = new Circle(r);
        }
    }
    ta.computerTotalArea(p1,n);
    for(int i=0;i<n;i++)
    	delete p1[i];
    delete []p1;
}
