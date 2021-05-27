2018152029:Problem1232:正确
#include<bits/stdc++.h>
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
protected:
    int num;
    int weight;
public:
    Car(string n,int nu,int we):Vehicle(n),num(nu),weight(we){}
    void display()
    {
        cout<<no<<' ';
        cout<<num*8+weight*2<<endl;
    }

};

class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w){}
    void display()
    {
        cout<<no<<' ';
        cout<<weight*5<<endl;
    }
};

class Bus:public Vehicle
{
protected:
    int num;
public:
    Bus(string n,int nu):Vehicle(n),num(nu){}
    void display()
    {
        cout<<no<<' ';
        cout<<num*3<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    Vehicle *pv;
    int num,weight;
    string no;
    while(t--)
    {
        char judge;
        cin>>judge;
        switch(judge)
        {
            case '1':
            {
                cin>>no>>num>>weight;
                Car a(no,num,weight);
                pv=&a;
                pv->display();
                break;
            }
            case '2':
            {
                cin>>no>>weight;
                Truck a(no,weight);
                pv=&a;
                pv->display();
                break;
            }
            case '3':
            {
                cin>>no>>num;
                Bus a(no,num);
                pv=&a;
                pv->display();
                break;
            }
        }
    }
    return 0;
}

