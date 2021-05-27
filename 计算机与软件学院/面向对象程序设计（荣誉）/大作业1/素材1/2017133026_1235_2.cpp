2017133026:Problem1235:正确
#include <iostream>
#include <iomanip>
using namespace std;
class Geometry{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry{
    int w,h;
public:
    Rect(int _w,int _h){
        w=_w;
        h=_h;
    }
    double getArea(){
        return w*h;
    }
};

class Circle:public Geometry{
    int r;
public:
    Circle(int _r){
        r=_r;
    }
    double getArea(){
        return 3.14*r*r;
    }

};
class TotalArea{
public:
   static void computerTotalArea(Geometry** t,int n){
    double max=0;
    for(int i=0;i<n;i++){
        double temp=t[i]->getArea();
        if(temp>max){
            max=temp;
        }
    }
    cout<<"最大面积="<<fixed<<setprecision(2)<<max<<endl;
   }
};

int main()
{
    int t;
    cin>>t;
    int type,w,h,r;
    Geometry** t1=new Geometry*[t];
    int pos=0;
    while(t--){
        cin>>type;
        if(type==1){
            cin>>w>>h;
            Rect r1(w,h);
            t1[pos++]=&r1;
        }else if(type==2){
            cin>>r;
            Circle c1(r);
            t1[pos++]=&c1;
        }
    }
    TotalArea::computerTotalArea(t1,pos);
    return 0;
}

