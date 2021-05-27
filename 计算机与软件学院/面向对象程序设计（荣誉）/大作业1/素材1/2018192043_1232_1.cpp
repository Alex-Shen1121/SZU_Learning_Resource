2018192043:Problem1232:正确
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string nos):no(nos) {}
    virtual void display()=0;//应收费用
    ~Vehicle() {}
};
class Car:public Vehicle
{
    int people,weight;
public:
    Car(string no,int peoples,int weights):Vehicle(no),people(peoples),weight(weights) {}
    void display()
    {
        cout<<no<<" "<<people*8+weight*2<<endl;
    }
    ~Car() {}
};
class Truck:public Vehicle
{
    int weight;
public:
    Truck(string no,int weights):Vehicle(no),weight(weights) {}
    void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
    ~Truck() {}
};
class Bus:public Vehicle
{
    int people;
public:
    Bus(string no,int peoples):Vehicle(no),people(peoples) {}
    void display()
    {
        cout<<no<<" "<<people*3<<endl;
    }
    ~Bus() {}
};
int main()
{
    Vehicle *pv;
    int t,people,weight;
    string no;
    char type;
    cin>>t;
    while(t--)
    {
        cin>>type>>no;
        if(type=='1')
        {
            cin>>people>>weight;
            Car a(no,people,weight);
            pv=&a;
            pv->display();
        }
        else if(type=='2')
        {
            cin>>weight;
            Truck a(no,weight);
            pv=&a;
            pv->display();
        }
        else if(type=='3')
        {
            cin>>people;
            Bus a(no,people);
            pv=&a;
            pv->display();
        }
    }
    return 0;
}

