2018151005:Problem1232:正确
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(){}
    Vehicle(string no0):no(no0){}
    virtual void display()=0;//应收费用
};
class Car:public Vehicle
{
private:
    int num,weight;
public:
    Car(){}
    Car(string no0,int num0,int weight0):Vehicle(no0),num(num0),weight(weight0){}
    void display()
    {
        cout<<no<<" ";
        int fee=8*num+2*weight;
        cout<<fee<<endl;
    }
};
class Truck:public Vehicle
{
private:
    int weight;
public:
    Truck(){}
    Truck(string no0,int weight0):Vehicle(no0),weight(weight0){}
    void display()
    {
        cout<<no<<" ";
        int fee=5*weight;
        cout<<fee<<endl;
    }
};
class Bus:public Vehicle
{
private:
    int num;
public:
    Bus(){}
    Bus(string no0,int num0):Vehicle(no0),num(num0){}
    void display()
    {
        cout<<no<<" ";
        int fee=3*num;
        cout<<fee<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    Vehicle *pv;
    while(t--)
    {
        string no;
        int type,num,weight;
        cin>>type>>no;
        switch(type)
        {
        case 1:
            {
                cin>>num>>weight;
                Car a(no,num,weight);
                pv=&a;
                pv->display();
                break;
            }
        case 2:
            {
                cin>>weight;
                Truck a(no,weight);
                pv=&a;
                pv->display();
                break;
            }
        case 3:
            {
                cin>>num;
                Bus a(no,num);
                pv=&a;
                pv->display();
                break;
            }
        }
    }
}

