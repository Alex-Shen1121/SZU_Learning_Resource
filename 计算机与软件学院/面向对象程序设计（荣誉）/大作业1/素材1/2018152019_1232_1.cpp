2018152019:Problem1232:正确
#include<iostream>

#include<string.h>

using namespace std;

class Vehicle
{
protected:

    string no;//编号

public:

    virtual void display()=0;//应收费用

};

class Car:public Vehicle
{
protected:
    //int type=1;
    int member;
    int weight;
public:
    Car(string n,int me,int we)
    {
        no=n;
        member=me;
        weight=we;
    }
    //:no(n),member(me),weight(we){}

    virtual void display()
    {
        cout<<no<<" "<<member*8+weight*2<<endl;
    }

    //void getType(){return type;}
};

class Truck:public Vehicle
{
protected:
    //int type=2;
    int weight;
public:
    Truck(string n,int we)
    {
        no=n;
        weight=we;
    }
    //:no(n),weight(we){}

    virtual void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }

    //void getType(){return type;}
};

class Bus:public Vehicle
{
protected:
    //int type=3;
    int member;
public:
    Bus(string n,int me)
    {
        no=n;
        member=me;
    }
    //:no(n),member(me){}

    virtual void display()
    {
        cout<<no<<" "<<member*3<<endl;
    }

    //void getType(){return type;}
};

int main()
{
    Vehicle *pv;
    int times;
    cin>>times;
    while(times--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            string n;
            int me,we;
            cin>>n>>me>>we;
            Car car(n,me,we);
            pv=&car;
            pv->display();
        }
        if(t==2)
        {
            string n;
            int we;
            cin>>n>>we;
            Truck truck(n,we);
            pv=&truck;
            pv->display();
        }
        if(t==3)
        {
            string n;
            int me;
            cin>>n>>me;
            Bus bus(n,me);
            pv=&bus;
            pv->display();
        }
    }
    return 0;
}
