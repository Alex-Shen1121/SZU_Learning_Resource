2018192025:Problem1232:正确
#include<iostream>
#include<cstring>
using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string name):no(name) {};
    virtual void display()=0;//应收费用
};

class Car:public Vehicle
{
protected:
    int weight;
    int passenger;
public:
    Car(string name, int wei, int p):Vehicle(name),weight(wei),passenger(p) {};
    virtual void display()
    {
        int i=passenger*2+weight*8;
        cout<<no<<' '<<i<<endl;
    }
};

class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string name, int wei):Vehicle(name),weight(wei) {};
    virtual void display()
    {
        int i=weight*5;
        cout<<no<<' '<<i<<endl;
    }
};

class Bus:public Vehicle
{
protected:
    int passenger;
public:
    Bus(string name, int p):Vehicle(name),passenger(p) {};
    virtual void display()
    {
        int i=passenger*3;
        cout<<no<<' '<<i<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,wei,p;
        string name;
        cin>>m;
        if(m==1)
        {
            cin>>name>>wei>>p;
            Car ss(name,wei,p);
            ss.display();
        }
        else if(m==2)
        {
            cin>>name>>wei;
            Truck ss(name,wei);
            ss.display();
        }
        else if(m==3)
        {
            cin>>name>>p;
            Bus ss(name,p);
            ss.display();
        }
    }
}

