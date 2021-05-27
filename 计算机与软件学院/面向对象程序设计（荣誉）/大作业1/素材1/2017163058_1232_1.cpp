2017163058:Problem1232:正确
#include <iostream>
#include <fstream>
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    virtual void display() = 0;//应收费用
};
class Car:public Vehicle
{
private:
    int customers, weight;
public:
    Car(string n, int c, int w):customers(c), weight(w)
    {
        no = n;
    }
    void display()
    {
        cout<<no<<" "<<customers*8 + weight*2<<endl;
    }
};
class Truck:public Vehicle
{
private:
    int weight;
public:
    Truck(string n, int w):weight(w)
    {
        no = n;
    }
    void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
private:
    int customers;
public:
    Bus(string n, int c):customers(c)
    {
        no = n;
    }
    void display()
    {
        cout<<no<<" "<<customers*3<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string no;
    int weight, customers, t;
    char flag;
    Vehicle *pv;
    cin>>t;
    while(t --)
    {
        cin>>flag>>no;
        switch(flag)
        {
        case '1':
            {
                cin>>customers>>weight;
                Car car(no, customers, weight);
                pv = &car;
                pv->display();
                break;
            }
        case '2':
            {
                cin>>weight;
                Truck truck(no, weight);
                pv = &truck;
                pv->display();
                break;
            }
        case '3':
            {
                cin>>customers;
                Bus bus(no, customers);
                pv = &bus;
                pv->display();
                break;
            }
        }
    }
    return 0;
}

