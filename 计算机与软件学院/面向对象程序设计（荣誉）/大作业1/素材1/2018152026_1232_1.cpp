2018152026:Problem1232:正确
#include <bits/stdc++.h>

using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string _n){no=_n;}
    virtual void display()=0;//应收费用
};
class Car:public Vehicle
{
protected:
    int weight;
    int num;
public:
    Car(string _n,int _num,int w):Vehicle(_n)
    {
        num=_num;
        weight=w;
    }
    virtual void display()
    {
        int sum;
        sum=num*8+weight*2;
        cout<<no<<" "<<sum<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string _n,int w):Vehicle(_n)
    {
        weight=w;
    }
    virtual void display()
    {
        int sum;
        sum=weight*5;
        cout<<no<<" "<<sum<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int num;
public:
    Bus(string _n,int _num):Vehicle(_n)
    {
        num=_num;
    }
    virtual void display()
    {
        int sum;
        sum=num*3;
        cout<<no<<" "<<sum<<endl;
    }
};
void print(Vehicle *pv)
{
    pv->display();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehicle *pv;
        int n;
        string _no;
        int _num,w;
        cin>>n;
        if(n==1)
        {
            cin>>_no>>_num>>w;
            Car a(_no,_num,w);
            pv=&a;
            print(pv);
        }
        if(n==2)
        {
            cin>>_no>>w;
            Truck b(_no,w);
            pv=&b;
            print(pv);
        }
        if(n==3)
        {
            cin>>_no>>_num;
            Bus c(_no,_num);
            pv=&c;
            print(pv);
        }
    }
    return 0;
}
