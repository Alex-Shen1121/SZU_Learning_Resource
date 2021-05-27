2018152035:Problem1232:正确
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string n):no(n) {}
    virtual void display()=0;//应收费用
};
class car:public Vehicle
{
    int people;
    int weight;
public:
    car(string n,int p,int w):Vehicle(n),people(p),weight(w) {}
    void display()
    {
        cout<<no<<' '<<people*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
    int weight;
public:
    Truck(string n,int w):Vehicle(n),weight(w) {}
    void display()
    {
        cout<<no<<' '<<weight*5<<endl;
    }
};
class bus:public Vehicle
{
    int people;
public:
    bus(string n,int p):Vehicle(n),people(p) {}
    void display()
    {
        cout<<no<<' '<<people*3<<endl;
    }
};
int main()
{
    int T,pe,w,t;
    string n;
    cin>>T;
    while(T--)
    {
        Vehicle *p;
        cin>>t>>n;
        if(t==1)
        {
            cin>>pe>>w;
            car c(n,pe,w);
            p=&c;
            p->display();
        }
        else if(t==2)
        {
            cin>>pe;
            Truck t(n,pe);
            p=&t;
            p->display();
        }
        else
        {
            cin>>w;
            bus b(n,w);
            p=&b;
            p->display();
        }
    }
}

