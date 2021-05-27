2018192038:Problem1232:正确
#include <iostream>

using namespace std;

class Vehicle

{
protected:

    string no;//编号

public:
    Vehicle(string nonono):no(nonono){}
    virtual void display()=0;//应收费用

};

class Car:public Vehicle
{
    int num;
    int weight;
public:
    Car(string nonono,int nn,int ww):Vehicle(nonono),num(nn),weight(ww){}
    void display()
    {
        cout<<no<<" "<<num*8+weight*2<<endl;
    }
};

class Truck:public Vehicle
{
    //int num;
    int weight;
public:
    Truck(string nonono,int ww):Vehicle(nonono),weight(ww){}
    void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
};

class Bus:public Vehicle
{
    int num;
    //int weight;
public:
    Bus(string nonono,int nn):Vehicle(nonono),num(nn){}
    void display()
    {
        cout<<no<<" "<<num*3<<endl;
    }
};

int main()
{
    string no;
    int num,weight,type;
    int t;
    cin>>t;
    Vehicle *pv=NULL;
    while(t--)
    {
        cin>>type;
        cin>>no;
        if(type==1)
        {
            cin>>num>>weight;
            Car cc(no,num,weight);
            pv=&cc;
            pv->display();
        }
        else if(type==2)
        {
            cin>>weight;
            Truck tt(no,weight);
            pv=&tt;
            pv->display();
        }
        else if(type==3)
        {
            cin>>num;
            Bus bb(no,num);
            pv=&bb;
            pv->display();
        }

    }
    return 0;
}

