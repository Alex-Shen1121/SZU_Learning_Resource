2018152044:Problem1232:正确
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(string no1)
    {
        no=no1;
    }
    virtual void display()=0;///应收费用
};

class Car:public Vehicle
{
protected:
    int number;
    int weight;
    int fee;
public:
    Car(string no1,int n,int w):Vehicle(no1)
    {
        number=n;
        weight=w;
        fee=0;
    }
    void display()
    {
        fee=number*8+weight*2;
        cout<<no<<" "<<fee<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
    int fee;
public:
    Truck(string no1,int w):Vehicle(no1)
    {
        weight=w;
        fee=0;
    }
    void display()
    {
        fee=weight*5;
        cout<<no<<" "<<fee<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int number;
    int fee;
public:
    Bus(string no1,int n):Vehicle(no1)
    {
        number=n;
        fee=0;
    }
    void display()
    {
        fee=number*3;
        cout<<no<<" "<<fee<<endl;
    }
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int type;
        string no;
        int number;
        int weight;
        Vehicle *pv;
        cin>>type;
        if(type==1)
        {
            cin>>no>>number>>weight;
            Car tem(no,number,weight);
            pv=&tem;
            pv->display();
        }
        else if(type==2)
        {
            cin>>no>>weight;
            Truck tem(no,weight);
            pv=&tem;
            pv->display();
        }
        else if(type==3)
        {
            cin>>no>>number;
            Bus tem(no,number);
            pv=&tem;
            pv->display();
        }
    }
    return 0;
}
