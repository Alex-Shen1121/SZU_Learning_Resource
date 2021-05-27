2017301020:Problem1232:正确
#include <iostream>

using namespace std;

class Vehicle{
protected:
    string no;//编号
public:
    Vehicle(){}
    Vehicle(string a):no(a){}
    virtual void display()=0;//应收费用
};

class Car:public Vehicle{
    int weight;
    int number;
public:
    Car(){}
    Car(string no1,int number1,int weight1):Vehicle(no1),number(number1),weight(weight1){}
    virtual void display();
};

void Car::display(){
    cout<<no<<" "<<8*number+weight*2<<endl;
}

class Truck:public Vehicle{
    int weight;
public:
    Truck(){}
    Truck(string no1, int weight1):Vehicle(no1),weight(weight1){}
    virtual void display();
};

void Truck::display(){
    cout<<no<<" "<<5*weight<<endl;
}

class Bus:public Vehicle{
    int number;
public:
    Bus(){}
    Bus(string no1,int number1):Vehicle(no1),number(number1){}
    virtual void display();
};

void Bus::display(){
    cout<<no<<" "<<3*number<<endl;
}

int main()
{
    Vehicle *pv;
    int t,i,number,weight;
    string no;
    cin>>t;
    while(t--){
        cin>>i;
        if(i==1){
            cin>>no>>number>>weight;
            Car a(no,number,weight);
            pv=&a;
            pv->display();
        }
        else if(i==2){
            cin>>no>>weight;
            Truck b(no,weight);
            pv=&b;
            pv->display();
        }
        else{
            cin>>no>>weight;
            Bus b(no,weight);
            pv=&b;
            pv->display();
        }
    }
    return 0;
}

