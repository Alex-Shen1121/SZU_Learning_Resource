2018152062:Problem1232:运行错误
#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string _no):no(_no){}
    virtual void display()=0;//应收费用
};
class Car:public Vehicle
{
protected:
    int weight;
    int load_num;
public:
    Car(string _no,int _load_num,int _weight):Vehicle(_no),weight(_weight),load_num(_load_num){}
    void display()
    {
        cout<<no<<" ";
        cout<<weight*2+load_num*8<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string _no,int _weight):Vehicle(_no),weight(_weight){}
    void display()
    {
        cout<<no<<" ";
        cout<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int load_num;
public:
    Bus(string _no,int _load_num):Vehicle(_no),load_num(_load_num){}
    void display()
    {
        cout<<no<<" ";
        cout<<load_num*3<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehicle *pv;
        string no;
        int weight=0,load_num=0;
        int cnt;
        cin>>cnt;
        if(cnt==1)
        {
            cin>>no>>load_num>>weight;
            Car car(no,load_num,weight);
            pv=&car;
            pv->display();
        }
        if(cnt==2)
        {
            cin>>no>>weight;
            Truck truck(no,weight);
            pv=&truck;
            pv->display();
        }
        if(cnt==3)
        {
            cin>>no>>load_num;
            Bus bus(no,load_num);
            pv=&bus;
            pv->display();
        }
        delete []pv;
    }
    return 0;
}

