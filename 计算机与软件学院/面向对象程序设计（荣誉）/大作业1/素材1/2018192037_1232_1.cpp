2018192037:Problem1232:正确
#include<bits/stdc++.h>
using namespace std;

class Vehicle{
protected:
    string no;//编号
public:
    Vehicle(){}
    virtual void display()=0;//应收费用
};

class Car:public Vehicle
{
protected:
    int zk,zl;
public:
    Car(string n,int k,int l):zk(k),zl(l){no = n;}
    void display()
    {
        cout<<no<<" "
        <<zk*8+zl*2<<endl;
    }
};

class Truck:public Vehicle
{
protected:

    int zl;
public:
    Truck(string n,int l):zl(l){no = n;}
    void display()
    {
        cout<<no<<" "
        <<zl*5<<endl;
    }
};

class Bus:public Vehicle
{
protected:
    int zk;
public:
    Bus(string n,int l):zk(l){no = n;}
    void display()
    {
        cout<<no<<" "
        <<zk*3<<endl;
    }

};


int main()
{
    Vehicle *pv;
    int n;
    cin>>n;
    while(n--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            string no;
            cin>>no;
            int zk,zl;
            cin>>zk>>zl;
            Car car(no,zk,zl);
            car.display();
        }
        else if(type==2)
        {
            string no;
            cin>>no;
            int zk,zl;
            cin>>zl;
            Truck turck(no,zl);
            turck.display();
        }
        else if(type==3)
        {
            string no;
            cin>>no;
            int zk,zl;
            cin>>zk;
            Bus bus(no,zk);
            bus.display();
        }
    }
}

