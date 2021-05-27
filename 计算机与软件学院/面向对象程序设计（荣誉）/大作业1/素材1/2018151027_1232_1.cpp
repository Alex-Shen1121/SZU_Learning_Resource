2018151027:Problem1232:ÕýÈ·
#include <iostream>
using namespace std;
class CVehicle
{
protected:
    string number;
public:
    virtual void display()=0;
    CVehicle(string n):number(n){}

};
class Car: public CVehicle
{
protected:
    int passenger;
    int weight;
public:
    Car(string n,int p,int w):CVehicle(n),passenger(p),weight(w){}
    void display()
    {
        int fee;
        fee=passenger*8+weight*2;
        cout<<number<<" "<<fee<<endl;
    }
};
class Truck: public CVehicle
{
protected:
    int weight;
public:
    Truck(string n,int w):CVehicle(n),weight(w){}
    void display()
    {
        int fee;
        fee=weight*5;
        cout<<number<<" "<<fee<<endl;
    }
};
class Bus: public CVehicle
{
protected:
    int passenger;
public:
    Bus(string n,int p):CVehicle(n),passenger(p){}
    void display()
    {
        int fee;
        fee=passenger*3;
        cout<<number<<" "<<fee<<endl;
    }
};
main()
{
    int type;
    int passenger;
    int weight;
    string number;
    int t;
    CVehicle *pv;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>number>>passenger>>weight;
            pv=new Car(number,passenger,weight);
            pv->display();
        }
        if(type==2)
        {
            cin>>number>>weight;
            pv=new Truck(number,weight);
            pv->display();
        }
        if(type==3)
        {
            cin>>number>>passenger;
            pv=new Bus(number,passenger);
            pv->display();

        }

    }

}

