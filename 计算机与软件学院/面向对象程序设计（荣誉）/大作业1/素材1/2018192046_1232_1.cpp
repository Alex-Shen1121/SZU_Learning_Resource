2018192046:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(string _no):no(_no){}
    virtual void display()=0;
};
class Car:public Vehicle
{
    int Person;
    int hat;
public:
    Car(string _no,int _P,int _hat):Vehicle(_no),Person(_P),hat(_hat){}
    void display()
    {
        cout<<no<<" "<<Person*8+hat*2<<endl;
    }
};
class Truck:public Vehicle
{
    int hat;
public:
    Truck(string _no,int _hat):Vehicle(_no),hat(_hat){}
    void display()
    {
        cout<<no<<" "<<5*hat<<endl;
    }
};
class Bus:public Vehicle
{
    int Person;
public:
    Bus(string _no,int _P):Vehicle(_no),Person(_P){}
    void display()
    {
        cout<<no<<" "<<Person*3<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehicle *pv;
        int type;
        string name;
        int person,hat;
        cin>>type;
        cin>>name;
        if(type==1)
        {
            cin>>person>>hat;
            Car P(name,person,hat);
            pv=&P;
            pv->display();
        }
        else if(type==2)
        {
            cin>>hat;
            Truck P(name,hat);
            pv=&P;
            pv->display();
        }
        else if(type==3)
        {
            cin>>person;
            Bus P(name,person);
            pv=&P;
            pv->display();
        }
    }
}

