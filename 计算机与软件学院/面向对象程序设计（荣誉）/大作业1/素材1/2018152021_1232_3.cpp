2018152021:Problem1232:ÕýÈ·
#include<iostream>
#include <string>
using namespace std;
class Vehicle           
{
protected:              
    string no;          
public:                  
    virtual void display()=0;
};
class Car:public Vehicle        
{
public:
    int people,weight;
    Car(int p,int w):people(p),weight(w){}
    void display()
    {
        cout << people*8+weight*2 << endl;  
    }
};
class Truck:public Vehicle 
{
public:
    int weight;
    Truck(int w):weight(w){}
    void display()
    {
        cout << weight*5 << endl;
    }
};
class Bus:public Vehicle    
{
public:
    int people;
    Bus(int p):people(p){}
    void display()
    {
        cout << people*3 << endl; 
    }
};
int main()
{
    int t,num,people,weight;
    string no;
    Vehicle *pv;
    cin >> t;

    while(t--)
    {
        cin >> num >> no;
        cout << no << ' ';
        if(num==1)
        {
            cin >> people >> weight;     
            pv=new Car(people,weight);
            pv->display();
        }
        if(num==2)
        {
            cin >> weight;     
            pv =new Truck(weight);
            pv->display();

        }
        if(num==3)
        {
            cin >> people;     
            pv=new Bus(people);
            pv->display();
        }
    }
    return 0;
}
