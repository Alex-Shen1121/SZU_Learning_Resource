2018152100:Problem1232:ÕýÈ·
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string no;//±àºÅ
public:
    Vehicle(string noo):no(noo){}
    virtual void display()=0;
};

class Car:virtual public Vehicle
{
    int people,weight;
public:
    Car(string noo,int p,int w):Vehicle(noo),people(p),weight(w){}
    void display(){cout << no << " " << people*8+weight*2 << endl;}
};

class Truck:virtual public Vehicle
{
    int weight;
public:
    Truck(string noo,int w):Vehicle(noo),weight(w){}
    void display(){cout << no << " " << weight*5 << endl;}
};

class Bus:virtual public Vehicle
{
    int people;
public:
    Bus(string noo,int p):Vehicle(noo),people(p){}
    void display(){cout << no << " " << people*3 << endl;}
};
int main()
{
    int t,type;
    string no;
    int p,w;
    cin >> t;
    Vehicle *pv;
    while (t--)
    {
        cin >> type >> no;
        if (type==1)
        {
            cin >> p >> w;
            Car c(no,p,w);
            pv=&c;
            pv->display();
        }
        else if (type==2)
        {
            cin >> w;
            Truck t(no,w);
            pv=&t;
            pv->display();
        }
        else if (type==3)
        {
            cin >> p;
            Bus b(no,p);
            pv=&b;
            pv->display();
        }
    }
    return 0;
}

