2018192013:Problem1232:ÕýÈ·
#include <iostream>
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
    int num,heavy;
public:
    Car(string no,int n,int h):Vehicle(no),num(n),heavy(h){}
    int Paid(){return num*8+heavy*2;}
    void display(){cout<<no<<" "<<Paid()<<endl;}
};
class Truck:public Vehicle
{
    int heavy;
public:
    Truck(string no,int h):Vehicle(no),heavy(h){}
    int Paid(){return heavy*5;}
    void display(){cout<<no<<" "<<Paid()<<endl;}
};
class Bus:public Vehicle
{
    int num;
public:
    Bus(string no,int n):Vehicle(no),num(n){}
    int Paid(){return num*3;}
    void display(){cout<<no<<" "<<Paid()<<endl;}
};

int main()
{
    int t;
    cin>>t;
    Vehicle *pv;
    while(t--)
    {
        int type,num,heavy;
        string no;
        cin>>type>>no;
        if(type==1)
        {
            cin>>num>>heavy;
            Car c(no,num,heavy);
            pv=&c;
            pv->display();
        }
        else if(type==2)
        {
            cin>>heavy;
            Truck t(no,heavy);
            pv=&t;
            pv->display();
        }
        else if(type==3)
        {
            cin>>num;
            Bus b(no,num);
            pv=&b;
            pv->display();
        }
    }
    return 0;
}

