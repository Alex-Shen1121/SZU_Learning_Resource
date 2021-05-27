2016140066:Problem1232:ÕýÈ·
#include <iostream>
#include<string>
using namespace std;
class Vehicle
{
protected:

    string no;

public:
    Vehicle(){}
    Vehicle(string N):no(N){}
    virtual void display()=0;
};
class Car:public Vehicle
{
    int num,heavy;
public:
    Car(){}
    Car(string N,int nu,int he):Vehicle(N),num(nu),heavy(he){}
    virtual void display()
    {
        cout<<no<<" "<<(num*8+heavy*2)<<endl;
    }
};
class Truck:public Vehicle
{
    int heavy;
public:
    Truck(){}
    Truck(string N,int He):Vehicle(N),heavy(He){}
    virtual void display()
    {
        cout<<no<<" "<<(heavy*5)<<endl;
    }
};
class Bus:public Vehicle
{
    int num;
public:
    Bus(){}
    Bus(string N,int Num):Vehicle(N),num(Num){}
    virtual void display()
    {
        cout<<no<<" "<<(num*3)<<endl;
    }
};
int main()
{
    int t,type,Num,He;
    string N;
    cin>>t;
    while(t--)
    {
        cin>>type>>N;
        if(type==1)
        {
            cin>>Num>>He;
            Car *s=new Car(N,Num,He);
            Vehicle *pv=s;
            pv->display();
        }
        else if(type==2)
        {
            cin>>He;
            Truck *s=new Truck(N,He);
            Vehicle *pv=s;
            pv->display();
        }
        else
        {
            cin>>Num;
            Bus *s=new Bus(N,Num);
            Vehicle *pv=s;
            pv->display();
        }
    }
    return 0;
}
