2018182052:Problem1232:ÕýÈ·
#include<cstdio>
#include<iostream>
#include<iomanip>
#include<string>
#define ADDRESS "D:\\in.txt","r",stdin
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(const string& n):no(n) {}
    virtual void display()const=0;
};
class Car:public Vehicle
{
protected:
    int cnt_peo;
    int wei;
public:
    Car(const string &n,int c,int w):Vehicle(n),cnt_peo(c),wei(w) {}
    virtual void display()const
    {
        cout<<no<<" "<<cnt_peo*8+wei*2<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int wei;
public:
    Truck(const string &n,int w):Vehicle(n),wei(w) {}
    virtual void display()const
    {
        cout<<no<<" "<<wei*5<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int cnt_peo;
public:
    Bus(const string &n,int c):Vehicle(n),cnt_peo(c) {}
    virtual void display()const
    {
        cout<<no<<" "<<cnt_peo*3<<endl;
    }
};
int main()
{
 //   freopen(ADDRESS);
    int T(0);
    cin>>T;
    Vehicle *p;
    while(T--)
    {
        int type;
        string no;
        cin>>type>>no;
        int d[2];
        if(type==1)
        {
            cin>>d[0]>>d[1];
            Car tem(no,d[0],d[1]);
            p=&tem;
            p->display();
        }
        else if(type==2)
        {
            cin>>d[0];
            Truck tem(no,d[0]);
            p=&tem;
            p->display();
        }
        else if(type==3)
        {
            cin>>d[1];
            Bus tem(no,d[1]);
            p=&tem;
            p->display();
        }
    }
    return 0;
}
