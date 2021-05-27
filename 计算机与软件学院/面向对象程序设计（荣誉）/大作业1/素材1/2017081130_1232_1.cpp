2017081130:Problem1232:正确
#include <iostream>
using namespace std;
class Vehicle
{
protected:

    string no;//编号

public:
    Vehicle(){};
    Vehicle(string n):no(n){};
    virtual void display()=0;//应收费用

};
class Car:virtual public Vehicle
{
protected:
    int people;
    int weight;
public:
    Car(){};
    Car(string n,int p,int w):Vehicle(n),people(p),weight(w){};
    int addp()
    {
        int price=people*8+weight*2;
        return price;
    }
    void display()
    {
        cout<<no<<" "<<addp()<<endl;
    }

};
class Truck:virtual public Vehicle
{
protected:
    int weight1;
public:
    Truck(){};
    Truck(string n,int w):Vehicle(n),weight1(w){};
    int addp1()
    {
        int price=weight1*5;
        return price;
    }
    void display()
    {
        cout<<no<<" "<<addp1()<<endl;
    }
};
class Bus:virtual public Vehicle
{
protected:
    int people1;
public:
    Bus(){};
    Bus(string n,int p):Vehicle(n),people1(p){};
    int addp2()
    {
        int price=people1*3;
        return price;
    }
    void display()
    {
        cout<<no<<" "<<addp2()<<endl;
    }
};
int main()
{
    int t,people,weight,type;
    string no;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>no>>people>>weight;
            Car c(no,people,weight);
            c.display();
        }
        else if(type==2)
        {
            cin>>no>>weight;
            Truck truck(no,weight);
            truck.display();
        }
        else if(type==3)
        {
            cin>>no>>people;
            Bus bus(no,people);
            bus.display();
        }
    }
}

