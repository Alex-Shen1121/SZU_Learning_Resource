2017161095:Problem1232:正确
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Vehicle

{
protected:

    string no;//编号

public:
    Vehicle(string n):no(n){}
    virtual void display()=0;//应收费用

};

class Car : virtual public Vehicle
{
    int people,weight;
public:
    Car(string n,int p,int w):Vehicle(n),people(p),weight(w){}
    virtual void display()
    {
        cout<<no<<" "<<people*8+weight*2<<endl;
    }
};

class Truck : virtual public Vehicle
{
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w){}
    virtual void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
};

class Bus : virtual public Vehicle
{
    int people;
public:
    Bus(string n,int p):Vehicle(n),people(p){}
    virtual void display()
    {
        cout<<no<<" "<<people*3<<endl;
    }
};
int main()
{
    int n,m,t,i,j,k,ans,num,sum,p,w;
    string s;
    Vehicle *pp;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        if(n==1)
        {
            cin>>p>>w;
            Car a(s,p,w);
            pp=&a;
            pp->display();
        }
        else if(n==2)
        {
            cin>>w;
            Truck b(s,w);
            pp=&b;
            pp->display();
        }
        else
        {
            cin>>p;
            Bus c(s,p);
            pp=&c;
            pp->display();
        }
    }
}

