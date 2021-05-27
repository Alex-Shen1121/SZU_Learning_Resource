2018151078:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(string n):no(n){}
    virtual void display()=0;
    virtual ~Vehicle(){}
     
};
class Car:public Vehicle
{
protected:
    int passenger;
    int weight;
public:
    Car(int p,int w,string n):passenger(p),weight(w),Vehicle(n){}
    void display()
    {
        cout<<no<<" "<<passenger*8+weight*2<<endl;
    }
    virtual ~Car(){}
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(int p,string n):weight(p),Vehicle(n){}
    void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
    virtual ~Truck(){}
};
class Bus:public Vehicle
{
protected:
    int passenger;
public:
    Bus(int p,string n):passenger(p),Vehicle(n){}
    void display()
    {
        cout<<no<<" "<<passenger*3<<endl;
    }
    virtual ~Bus(){}
};
int main()
{
    int t;
    cin>>t;
    string no;  
    int p,w;
    Vehicle *pv;
    while(t--)
    {
        int n;
        cin>>n;
       if(n==1)
        {
            cin>>no>>p>>w;
            pv=new Car(p,w,no);
            pv->display();
            delete pv;      
        }
        else if(n==2)
        {
            cin>>no>>w;
            pv=new Truck(w,no);
            pv->display();
            delete pv;  
        }
        else if(n==3)
        {
            cin>>no>>p;
            pv=new Bus(p,no);
            pv->display();
            delete pv;  
        }
    }
    return 0;
}
