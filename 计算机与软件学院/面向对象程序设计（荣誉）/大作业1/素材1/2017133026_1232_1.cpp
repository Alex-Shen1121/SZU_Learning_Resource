2017133026:Problem1232:ÕýÈ·
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(string no_){
        no=no_;
    }
    virtual void display()=0;

};
class Car:public Vehicle{
    int num,weight;
public:
    Car(string no_,int n,int w):Vehicle(no_){
        num=n;
        weight=w;
    }
    void display(){
        cout<<no<<" "<<num*8+weight*2<<endl;
    }
};
class Truck:public Vehicle{
    int weight;
public:
    Truck(string no_,int w):Vehicle(no_){
        weight=w;
    }
    void display(){
        cout<<no<<" "<<weight*5<<endl;
    }
};
class Bus:public Vehicle{
    int num;
public:
    Bus(string no_,int n):Vehicle(no_){
        num=n;
    }
    void display(){
        cout<<no<<" "<<num*3<<endl;
    }
};
int main()
{
    Vehicle *pv;
    string no;
    int n,w,t;
    cin>>t;
    while(t--){
        int type;
        cin>>type;
        if(type==1){
            cin>>no>>n>>w;
            Car c(no,n,w);
            pv=&c;
            pv->display();
        }else if(type==2){
            cin>>no>>w;
            Truck t1(no,w);
            pv=&t1;
            pv->display();
        }else if(type==3){
            cin>>no>>n;
            Bus b(no,n);
            pv=&b;
            pv->display();
        }
    }
    return 0;
}

