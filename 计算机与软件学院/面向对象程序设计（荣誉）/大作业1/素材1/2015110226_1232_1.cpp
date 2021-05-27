2015110226:Problem1232:ÕýÈ·
#include <bits/stdc++.h>
using namespace std;

class Vehicle{
protected:
    string no;
public:
    Vehicle(string a):no(a){}
    virtual void display()=0;
};
class Car:public Vehicle{
public:
    Car(string a,int b,int c):Vehicle(a),num(b),wei(c){}
    void display(){cout<<no<<' '<<8*num+2*wei<<endl;}
private:
    int num;
    int wei;
};
class Truck:public Vehicle{
public:
    Truck(string a,int c):Vehicle(a),wei(c){}
    void display(){cout<<no<<' '<<5*wei<<endl;}
private:
    int num;
    int wei;
};
class Bus:public Vehicle{
public:
    Bus(string a,int b):Vehicle(a),num(b){}
    void display(){cout<<no<<' '<<3*num<<endl;}
private:
    int num;
    int wei;
};
int main(){
    int time;
    cin>>time;
    while(time--){
        int a,c,d;
        string b;
        cin>>a>>b;
        Vehicle *v;
        if(a==1){
            cin>>c>>d;
            v = new Car(b,c,d);
            v->display();
        }
        if(a==2){
            cin>>c;
            v = new Truck(b,c);
            v->display();
        }
        if(a==3){
            cin>>c;
            v = new Bus(b,c);
            v->display();
        }
    }
    return 0;
}


