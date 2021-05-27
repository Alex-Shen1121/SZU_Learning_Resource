2018192045:Problem1232:正确
#include<iostream>
using namespace std;
#include<cstring>
class Vehicle
{
protected:
    string no;//编号

public:
    Vehicle(string no1):no(no1) {}
    Vehicle() {}
    virtual void display()=0;//应收费用

};
class Car:public Vehicle
{
    int number,weight;
public:
    Car(string no1,int n,int w):Vehicle(no1),number(n),weight(w) {}
    void display()
    {
        cout<<no<<' ';
        cout<<number*8+weight*2<<endl;
    }

};
class Truck:public Vehicle
{
    int weight;
public:
    Truck(string no1,int w):Vehicle(no1),weight(w) {}
    void display()
    {
        cout<<no<<' ';
        cout<<weight*5<<endl;
    }

};
class Bus:public Vehicle
{
    int number;
public:
    Bus(string no1,int n):Vehicle(no1),number(n) {}
    void display()
    {
        cout<<no<<' ';
        cout<<number*3<<endl;
    }
};
int main()
{
    char type;
    string no;
    int t,number,weight;
    cin>>t;
    Vehicle *p;
    while(t--)
    {
        cin>>type>>no;
        if(type=='1')
        {
            cin>>number>>weight;
            Car A(no,number,weight);
            p=&A;
            p->display();
        }
        if(type=='2')
        {
            cin>>weight;
            Truck A(no,weight);
            p=&A;
            p->display();
        }
        if(type=='3')
        {
            cin>>number;
            Bus A(no,number);
            p=&A;
            p->display();
        }
    }
}

