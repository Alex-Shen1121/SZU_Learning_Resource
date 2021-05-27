2018192024:Problem1232:ÕýÈ·
#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(){}
    Vehicle(string _no):no(_no){}
    virtual void display()=0;
};

class Car:public Vehicle
{
    int number,weight;
public:
    Car(string _no,int num,int wei):Vehicle(_no),number(num),weight(wei){}
    virtual void display()
    {
        cout<<setw(3)<<setfill('0')<<no<<" "<<number*8+weight*2<<endl;
    }
};

class Truck:public Vehicle
{
    int weight;
public:
    Truck(string _no,int wei):Vehicle(_no),weight(wei){}
    virtual void display()
    {
        cout<<setw(3)<<setfill('0')<<no<<" "<<weight*5<<endl;
    }
};

class Bus:public Vehicle
{
    int number;
public:
    Bus(string _no,int num):Vehicle(_no),number(num){}
    virtual void display()
    {
        cout<<setw(3)<<setfill('0')<<no<<" "<<number*3<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    Vehicle *pv;
    while(t--)
    {
        string _no;
        int type,num,wei;
        cin>>type;
        if(type==1)
        {
            cin>>_no>>num>>wei;
            Car carl(_no,num,wei);
            carl.display();
        }
        else if(type==2)
        {
            cin>>_no>>wei;
            Truck truckl(_no,wei);
            truckl.display();
        }
        else if(type==3)
        {
            cin>>_no>>num;
            Bus busl(_no,num);
            busl.display();
        }
    }
    return 0;
}

