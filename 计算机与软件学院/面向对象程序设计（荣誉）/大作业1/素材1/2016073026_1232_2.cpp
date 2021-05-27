2016073026:Problem1232:ÕýÈ·
#include <iostream>

using namespace std;

class Vehicle{
protected:
    string no;
public:
    //Vehicle(string n):no(n){}
    virtual void display()=0;
};

class Car:public Vehicle{
    int seat_num;
    int weight;
public:
    Car(string n,int sn,int w):seat_num(sn),weight(w){no=n;}
    virtual void display(){cout<<no<<" "<<8*seat_num+weight*2<<endl;}
};

class Truck:public Vehicle{
    int weight;
public:
    Truck(string n,int w):weight(w){no=n;}
    virtual void display(){cout<<no<<" "<<weight*5<<endl;}
};

class Bus:public Vehicle{
    int seat_num;
public:
    Bus(string n,int sn):seat_num(sn){no=n;}
    virtual void display(){cout<<no<<" "<<seat_num*3<<endl;}
};

int main()
{
    Vehicle *pv;
    int t;
    cin>>t;
    while(t--){
        int type;
        string no;
        int seat_num,weight;
        cin>>type;
        switch(type){
            case 1:{
                cin>>no>>seat_num>>weight;
                pv=new Car(no,seat_num,weight);
                pv->display();
            }break;
            case 2:{
                cin>>no>>weight;
                pv=new Truck(no,weight);
                pv->display();
            }break;
            case 3:{
                cin>>no>>seat_num;
                pv=new Bus(no,seat_num);
                pv->display();
            }
        }
    }
    return 0;
}

