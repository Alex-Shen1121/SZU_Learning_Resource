2018151058:Problem1232:ÕýÈ·
#include <iostream>
using namespace std;
class Vehilcle
{
protected:
    string no;
public:
    virtual void display()=0;
};
class Car:public Vehilcle
{
protected:
    int num;
    int weight;
public:
    Car(string n,int nm,int w)
    {
        no=n;
        num=nm;
        weight=w;

    }
    void display()
    {
        cout<<no<<" "<<(num*8+weight*2)<<endl;

    }
};
class Truck:public Vehilcle
{
protected:
    int weight;
public:
    Truck(string n,int w)
    {
        no=n;
        weight=w;
    }
    void display()
    {
        cout<<no<<" "<<(weight*5)<<endl;

    }
};
class Bus:public Vehilcle
{
protected:
    int num;
public:
    Bus(string n,int nm)
    {
        no=n;
        num=nm;
    }
    void display()
    {
        cout<<no<<" "<<(num*3)<<endl;

    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehilcle *pv;
        int type;
        cin>>type;
        string no;
        int weight,num;
        if(type==1)
        {
            cin>>no>>num>>weight;
            pv=new Car(no,num,weight);


        }
        if(type==2)
        {
            cin>>no>>weight;
            pv=new Truck(no,weight);

        }
        if(type==3)
        {
            cin>>no>>num;
            pv=new Bus(no,num);

        }
        pv->display();

    }
    return 0;
}

