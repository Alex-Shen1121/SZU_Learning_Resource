2018192010:Problem1232:ÕýÈ·
#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string no;
public:
    Vehicle(){}
    Vehicle(string N):no(N){}
    ~Vehicle(){}
    virtual void display()=0;
};
class Car:public Vehicle
{
protected:
    int num;
    int weight;
public:
    Car(){}
    Car(string N,int n,int w):Vehicle(N),num(n),weight(w){}
    void display()
    {
        cout << no << ' ';
        cout << num*8 + weight*2 << endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(){}
    Truck(string N,int w):Vehicle(N),weight(w){}
    void display()
    {
        cout << no<< ' ';
        cout << weight*5 << endl;
    }
};
class Bus:public Vehicle
{
protected:
    int num;
public:
    Bus(){}
    Bus(string N,int n):Vehicle(N),num(n){}
    void display()
    {
        cout << no<< ' ';
        cout << num*3 << endl;
    }
};
int main()
{
    int type,t;
    string no;
    int num,weight;
    cin >> t;
    while(t--)
    {
        Vehicle *pv;
        cin >> type;
        switch(type)
        {
        case 1:
            {
                cin >> no >> num >> weight;
                pv = new Car(no,num,weight);
                pv->display();
                delete pv;
                break;
            }
        case 2:
            {
                cin >> no >> weight;
                pv = new Truck(no,weight);
                pv->display();
                delete pv;
                break;
            }
        case 3:
            {
                cin >> no >> num;
                pv = new Bus(no,num);
                pv->display();
                delete pv;
                break;
            }
        }
    }
    return 0;
}

