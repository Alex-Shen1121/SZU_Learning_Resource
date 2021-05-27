2018192009:Problem1232:ÕýÈ·
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(){}
    Vehicle(string n):no(n){}
    virtual void display()=0;
};
class car:public Vehicle
{
protected:
    int num;
    int weight;
public:
    car(string n,int nu,int wei):num(nu),weight(wei),Vehicle(n){}
    virtual void display()
    {
        int cost=num*8+weight*2;
        cout<<no<<" "<<cost<<endl;
    }
};
class truck:public Vehicle
{
protected:
    int weight;
public:
    truck(string n,int wei):weight(wei),Vehicle(n){}
    virtual void display()
    {
        int cost=weight*5;
        cout<<no<<" "<<cost<<endl;
    }
};
class bus:public Vehicle
{
protected:
    int num;
public:
    bus(string n,int nu):num(nu),Vehicle(n){}
    virtual void display()
    {
        int cost=num*3;
        cout<<no<<" "<<cost<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    int type;
    string no;
    int weight,num;
    Vehicle *p;
    while(t--)
    {
        cin>>type;
        cin>>no;
        if(type==1)
        {
            cin>>num>>weight;
            car a(no,num,weight);
            p=&a;
            p->display();
        }
        if(type==2)
        {
            cin>>weight;
            truck a(no,weight);
            p=&a;
            p->display();
        }
        if(type==3)
        {
            cin>>num;
            bus a(no,num);
            p=&a;
            p->display();
        }
    }
    return 0;
}

