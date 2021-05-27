2018192022:Problem1232:正确
#include <iostream>
#include <iomanip>
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
    int num,weight;
public:
    Car(){}
    Car(string a,int b,int c):num(b),weight(c){no=a;}
    void display()
    {
        cout<<no<<" ";
        cout<<num*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(){}
    Truck(string a,int b):weight(b){no=a;}
    void display()
    {
        cout<<no<<" ";
        cout<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int num;
public:
    Bus(){}
    Bus(string a,int b):num(b){no=a;}
    void display()
    {
        cout<<no<<" ";
        cout<<num*3<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            string name;
            int num,weight;
            cin>>name>>num>>weight;
            Car p(name,num,weight);
            p.display();
        }
        else if(n==2)
        {
            string name;
            int weight;
            cin>>name>>weight;
            Truck p(name,weight);
            p.display();
        }
        else if(n==3)
        {
            string name;
            int num;
            cin>>name>>num;
            Bus p(name,num);
            p.display();
        }
    }
    return 0;
}
