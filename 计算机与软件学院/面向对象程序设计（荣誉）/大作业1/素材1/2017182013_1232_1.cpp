2017182013:Problem1232:ÕýÈ·
#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(string n=""):no(n){}
    virtual void display()=0;
};
class Car:public Vehicle
{
protected:
    int people;
    int weight;
public:
    Car(string n,int p,int w):Vehicle(n),people(p),weight(w){}
    void display()
    {
        cout<<no<<" "<<people*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w)
    {

    }
    void display()
    {
        cout<<no<<" "<<weight *5<<endl;
    }
};
class Bus:public Vehicle
{
    int people;
public :
    Bus(string n,int p):Vehicle(n),people(p)
    {

    }
    void display()
    {
        cout<<no<<" "<<people*3<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\c\\s.txt",stdin,"r");
    int n;
    cin>>n;
    while(n--)
    {
        Vehicle *pv;
        int type;
        cin>>type;
        string no;
        int p,w;
        if(type == 1)
        {
            cin>>no>>p>>w;
            Car c(no,p,w);
            pv = &c;
            pv->display();
        }
        else if(type == 2)
        {
            cin>>no>>w;
            Truck t(no,w);
            pv = &t;
            pv->display();
        }
        else if(type == 3)
        {
            cin>>no>>p;
            Bus b(no,p);
            pv = &b;
            pv->display();
        }

    }
    return 0;
}

