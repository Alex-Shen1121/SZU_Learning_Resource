2018041051:Problem1232:正确
#include<iostream>
#include<string>

using namespace std;

class Vehicle

{
protected:

    string num;//编号

public:
    Vehicle(){}
    Vehicle(string num1):num(num1){}
    virtual void display()=0;//应收费用

};

class Car:public Vehicle{
protected:
    int passenge,weight;
public:
    Car(){}
    Car(string num1,int passenge1,int weight1):Vehicle(num1),passenge(passenge1),weight(weight1){}
    void display()
    {
        int fee;
        fee=passenge*8+weight*2;
        cout<<num<<" "<<fee<<endl;
    }
};

class Truck:public Vehicle{
protected:
    int weight;
public:
    Truck(){}
    Truck(string num1,int weight1):Vehicle(num1),weight(weight1){}
    void display()
    {
        int fee;
        fee=weight*5;
        cout<<num<<" "<<fee<<endl;
    }
};

class Bus:public Vehicle{
protected:
    int passenge;
public:
    Bus(){}
    Bus(string num1,int passenge1):Vehicle(num1),passenge(passenge1){}
    void display()
    {
        int fee;
        fee=passenge*3;
        cout<<num<<" "<<fee<<endl;
    }
};

int main()
{
    Vehicle *pv;

    int t;
    cin>>t;
    while(t--)
    {
        int n,passenge,weight;
        string num;
        cin>>n;
        if(n==1)
        {
            cin>>num>>passenge>>weight;
            pv=new Car(num,passenge,weight);
            pv->display();
        }
        else if(n==2)
        {
            cin>>num>>weight;
            pv=new Truck(num,weight);
            pv->display();
        }
        else
        {
            cin>>num>>passenge;
            pv=new Bus(num,passenge);
            pv->display();
        }
    }

    return 0;
}

