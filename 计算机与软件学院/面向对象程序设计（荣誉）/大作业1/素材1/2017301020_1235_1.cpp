2017301020:Problem1235:��ȷ
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Geometry{
public:
    virtual double getArea()=0; //����������������С�������λ
    virtual ~Geometry(){}
};

class Rect:public Geometry{
    double length,width;
public:
    Rect(double length1,double width1):length(length1),width(width1){}
    virtual double getArea();
};

double Rect::getArea(){
    return length*width;
}

class Circle:public Geometry{
    double r;
public:
    Circle(double r1):r(r1){}
    virtual double getArea();
    ~Circle(){}
};

double Circle::getArea(){
    return 3.14*r*r;
}

class TotalArea{
public:
    TotalArea(){}
    static void computerTotalarea(Geometry** t,int n);
};

void TotalArea::computerTotalarea(Geometry** t,int n){
    double s=t[0]->getArea();
    for(int i=0;i<n-1;i++){
        if(t[i]->getArea()<t[i+1]->getArea())
            s=t[i+1]->getArea();
    }
    cout<<"������="<<fixed<<setprecision(2)<<s<<endl;
}

int main()
{
    int t,type;
    double x,y,r;
    Geometry **M;
    cin>>t;
    M=new Geometry*[t];
    for(int i=0;i<t;i++){
        cin>>type;
        if(type==1){
            cin>>x>>y;
            M[i]=new Rect(x,y);
        }
        else{
            cin>>r;
            M[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalarea(M,t);
    for(int i=0;i<t;i++)
        delete M[i];
    delete []M;
    return 0;
}

