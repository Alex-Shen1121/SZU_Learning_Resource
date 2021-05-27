2018192030:Problem1232:ÕýÈ·
#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(string num):no(num){}
    virtual void display(){}
};
class Car:public Vehicle 
{
    int guest,weight; 
public:  
    Car(Vehicle vehicle,int guestv,int weightv):Vehicle(vehicle),guest(guestv),weight(weightv){}
    void display()  
    {     
        cout<<no<<" "<<guest*8+weight*2<<endl;
    }  
};
class Truck:public Vehicle  
{  
    int weight; 
public:
    Truck(Vehicle vehicle,int weightv):Vehicle(vehicle),weight(weightv){} 
    void display()  
    {     
        cout<<no<<" "<<weight*5<<endl;
    }  
};
class Bus:public Vehicle
{   
    int guest;
public:  
    Bus(Vehicle vehicle,int guestv):Vehicle(vehicle),guest(guestv){}  
    void display()  
    {     
        cout<<no<<" "<<guest*3<<endl; 
    }  
};  
int main()
{
    Vehicle *pv;
    int t,type,g,w;
    string num;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>num>>g>>w;
            Car a(num,g,w);
            pv=&a;
            pv->display();
        }
        if(type==2)
        {
            cin>>num>>w;
            Truck b(num,w);
            pv=&b;
            pv->display();
        }
        if(type==3)
        {
            cin>>num>>g;
            Bus c(num,g);
            pv=&c;
            pv->display();
        }
    }
	return 0;
}
