2015110226:Problem1235:正确
#include <bits/stdc++.h>
using namespace std;

class Geometry{
public:
    virtual double getArea()=0;
};
class Rect:public Geometry{
private:
    double a,b;
public:
    Rect(double a,double b):a(a),b(b){}
    double getArea(){
        return a*b;
    }
};
class Circle:public Geometry{
private:
    double r;
public:
    Circle(double r):r(r){}
    double getArea(){
        return 3.14*r*r;
    }
};
class TotalArea{
public:
    static double maxs;
   static void computerTotalArea(Geometry** t,int n){
        for(int i=0;i<n;++i){
            double tmp = t[i]->getArea();
            if(maxs < tmp)
                maxs = tmp;
        }
   }
};
double TotalArea::maxs = 0;

int main(){
    int time;
    cin>>time;
    int a,b,c;
    Geometry **p = new Geometry*[time];
    for(int i=0;i<time;++i){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            p[i] = new Rect(b,c);
        }
        else{
            cin>>b;
            p[i] = new Circle(b);
        }
    }
    TotalArea::computerTotalArea(p,time);
    cout<<"最大面积="<<fixed<<setprecision(2)<<TotalArea::maxs;
    return 0;
}


