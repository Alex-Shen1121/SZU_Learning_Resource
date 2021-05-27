2018152010:Problem1232:ÕýÈ·
#include<iostream>

using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(string n):no(n){}
    virtual void display()=0;
};

class Car:public Vehicle
{
    int cus,weight;
public:
    Car(string n,int wei,int c):cus(c),weight(wei),Vehicle(n){}
    void display()
    {
        cout<<no<<' '<<cus*8+weight*2<<endl;
    }
};

class Truck:public Vehicle
{
    int weight;
public:
    Truck(string n,int wei):Vehicle(n),weight(wei){}
    void display()
    {
        cout<<no<<' '<<weight*5<<endl;
    }
};

class Bus:public Vehicle
{
    int cus;
public:
    Bus(string n,int c):Vehicle(n),cus(c){}
    void display()
    {
        cout<<no<<' '<<cus*3<<endl;
    }
};



int main()
{

    int t,type,cus,wei;
    string no;
    Vehicle *p;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>no>>cus>>wei;
            Car car(no,wei,cus);
            p=&car;
            p->display();
        }
        else if(type==2)
        {
            cin>>no>>wei;
            Truck truck(no,wei);
            p=&truck;
            p->display();
        }
        else
        {
            cin>>no>>cus;
            Bus bus(no,cus);
            p=&bus;
            p->display();
        }

    }

}

