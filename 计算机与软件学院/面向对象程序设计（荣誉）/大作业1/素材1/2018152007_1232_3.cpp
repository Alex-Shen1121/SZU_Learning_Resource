2018152007:Problem1232:正确
#include <iostream>

using namespace std;
class Vehicle
{
    protected:
        string no;
    public:
        Vehicle(){}
        Vehicle(string n)
        {
            no=n;
        }
        virtual void display()=0;//应收费用

};
class Car:public Vehicle
{
private:
    int num;
    int weight;
public:
    Car(string  n,int N,int w):Vehicle(n),num(N),weight(w){}
    void display()
    {
        cout<<no<<' '<<num*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
private:
    int weight;
public:
    Truck(string  n,int w):Vehicle(n),weight(w){}
    void display()
    {
        cout<<no<<' '<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
private:
    int num;
public:
    Bus(string n,int N):Vehicle(n),num(N){};
    void display()
    {
        cout<<no<<' '<<num*3<<endl;
    }
};
int main()
{
    int time;
    cin>>time;
    while(time--)
    {
        Vehicle *pv;
        int type;
        cin>>type;
        if(type==1)
        {
            string n;
            int N,w;
            cin>>n>>N>>w;
            Car *c1=new Car(n,N,w);
            pv=c1;
        }
        else if(type==2)
        {
            string n;
            int w;
            cin>>n>>w;
            Truck *t1=new Truck(n,w);
            pv=t1;
        }
        else
        {
            string n;
            int N;
            cin>>n>>N;
            Bus *b1=new Bus(n,N);
            pv=b1;
        }
        pv->display();
        delete pv;
    }
    return 0;
}

