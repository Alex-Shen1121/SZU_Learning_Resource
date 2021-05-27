2018192044:Problem1232:正确
#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(){}
    Vehicle(string n):no(n){}
    virtual void display()=0;//应收费用
    ~Vehicle(){}
};
class Car:public Vehicle
{
    int number,height;
public:
    Car(string n,int n1,int h):Vehicle(n),number(n1),height(h){}
    void display()
    {
        cout<<no<<" "<<number*8+height*2<<endl;
    }
};
class Truck:public Vehicle
{
    int height;
public:
    Truck(string n,int h):Vehicle(n),height(h){}
    void display()
    {
        cout<<no<<" "<<height*5<<endl;
    }
};
class Bus:public Vehicle
{
    int number;
public:
    Bus(string n,int n1):Vehicle(n),number(n1){}
    void display()
    {
        cout<<no<<" "<<number*3<<endl;
    }
};
int main()
{
    int t,i,number,height;
    string no;
    cin>>t;
    Vehicle *pv;
    while(t--)
    {
        cin>>i>>no;
        if(i==1)
        {
            cin>>number>>height;
            Car A(no,number,height);
            pv=&A;
            pv->display();
        }
        if(i==2)
        {
            cin>>height;
            Truck A(no,height);
            pv=&A;
            pv->display();
        }
        if(i==3)
        {
            cin>>number;
            Bus A(no,number);
            pv=&A;
            pv->display();
        }
    }
    return 0;
}

