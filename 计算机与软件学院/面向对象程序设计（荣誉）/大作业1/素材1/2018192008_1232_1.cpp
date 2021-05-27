2018192008:Problem1232:正确
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string n):no(n){}
    virtual void display()=0;//应收费用
};

class Car:public Vehicle
{
    int num,weight;
public:
    Car(string n,int nu,int w):Vehicle(n),num(nu),weight(w){}
    virtual void display()
    {
        int m;
        m=num*8+weight*2;
        cout<<no<<" "<<m<<endl;
    }
};

class Truck:public Vehicle
{
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w){}
    virtual void display()
    {
        int m;
        m=weight*5;
        cout<<no<<" "<<m<<endl;
    }
};
class Bus:public Vehicle
{
    int num;
public:
    Bus(string n,int nu):Vehicle(n),num(nu){}
    virtual void display()
    {
        int m;
        m=num*3;
        cout<<no<<" "<<m<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehicle *pv;
        int k;
        string no;
        cin>>k;
        if(k==1)
        {
           int  nu,w;
           cin>>no>>nu>>w;
           Car c1(no,nu,w);
           pv=&c1;
           pv->display();
        }
        else if(k==2)
        {
            int w;
            cin>>no>>w;
            Truck t1(no,w);
            pv=&t1;
            pv->display();
        }
        else if(k==3)
        {
            int nu;
            cin>>no>>nu;
            Bus b1(no,nu);
            pv=&b1;
            pv->display();
        }
    }
}

