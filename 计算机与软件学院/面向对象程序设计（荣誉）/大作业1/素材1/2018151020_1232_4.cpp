2018151020:Problem1232:正确
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Vehicle
{
protected:
    string no;//编号
public:
    Vehicle(string _no):no(_no){}
    virtual void display()=0;//应收费用
    virtual ~Vehicle(){}
};
class Car:public Vehicle
{
protected:
    int weight,number;
public:
    Car(string _no,int we,int n):Vehicle(_no),weight(we),number(n)
    {
    }
    void display()
    {
        cout<<no<<" "<<number*8+weight*2<<endl;
    }
    ~Car(){}
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string _no,int we):Vehicle(_no),weight(we){}
    void display()
    {
         cout<<no<<" "<<weight*5<<endl;
    }
    ~Truck(){}
};
class Bus:public Vehicle
{
protected:
    int number;
public:
    Bus(string _no,int n):Vehicle(_no),number(n){}
    void display()
    {
         cout<<no<<" "<<number*3<<endl;
    }
    ~Bus(){}
};
int main()
{
    int t;
    cin>>t;
    int order;
    while(t--)
    {
        Vehicle *K;
        string _no;
        cin>>order;
        if(order==1)
        {
            int we,n;
            cin>>_no>>n>>we;
            Car *C = new Car(_no,we,n);
            K = C;
        }
        else if(order==2)
        {
            int we;
            cin>>_no>>we;
            Truck *T = new Truck(_no,we);
            K = T;
        }
        else if(order==3)
        {
            int n;
            cin>>_no>>n;
            Bus *B = new Bus(_no,n);
            K = B;
        }
        K->display();
        delete K;
    }
    return 0;
}
 
