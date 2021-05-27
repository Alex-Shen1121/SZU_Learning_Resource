2017182103:Problem1232:正确
#include <iostream>

using namespace std;

class Vehicle

{
protected:

    string no;//编号

public:
    Vehicle(string n=" "):no(n) {}
    virtual void display()=0;//应收费用
};

class Car:public Vehicle
{
    int num;
    int weight;
public:
    Car(string n=" ",int num_=0,int w=0):Vehicle(n),num(num_),weight(w) {}
    virtual void display()
    {
        int fee = num * 8 + weight *2;
        cout<<no<<" "<<fee<<endl;
    }
};

class Truck:public Vehicle
{
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w) {}
    virtual void display()
    {
        int fee = weight * 5;
        cout<<no<<" "<<fee<<endl;
    }
};

class Bus:public Vehicle
{
    int num;
public:
    Bus(string n,int num_):Vehicle(n),num(num_) {}
    virtual void display()
    {
        int fee = num * 3;
        cout<<no<<" "<<fee<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int type;
        cin>>type;

        Vehicle *pv;
        string no;
        cin>>no;

        if(type==1)
        {
            int num,w;
            cin>>num>>w;
            Car c(no,num,w);
            pv = &c;
            pv->display();
        }
        else if(type==2)
        {
            int w;
            cin>>w;
            Truck t(no,w);
            pv = &t;
            pv->display();
        }
        else if(type==3)
        {
            int num;
            cin>>num;
            Bus b(no,num);
            pv = &b;
            pv->display();
        }
    }
    return 0;
}

