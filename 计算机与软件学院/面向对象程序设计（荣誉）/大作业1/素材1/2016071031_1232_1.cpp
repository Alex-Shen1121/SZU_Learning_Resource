2016071031:Problem1232:编译错误
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Vehicle{
protected:
    string no;//编号
public:
    Vehicle();
    Vehicle(string no_) {
        no = no_;
    }
    virtual void display()=0;//应收费用
    string getNo() {
        return no;
    }
};

class Car: public Vehicle {
    int amount;
    int weight;
public:
    Car(string no_, int amount_, int weight_): Vehicle(no_) {
        amount = amount_;
        weight = weight_;
    }
    void display() {
        cout<< getNo() << " " << amount * 8 + weight * 2 <<endl;
    }
};

class Truck: public Vehicle {
    int weight;
public:
    Truck(string no_, int weight_):Vehicle(no_) {
        weight = weight_;
    }
    void display() {
        cout<< getNo() << " " << weight * 5 <<endl;
    }
};

class Bus: public Vehicle {
    int amount;
public:
    Bus(string no_, int amount_): Vehicle(no_) {
        amount = amount_;
    }
    void display() {
        cout<< getNo() << " " << amount * 3 <<endl;
    }
} ;

int main()
{
    int t, type, amount, weight;
    string no;

    cin>>t;
    Vehicle * pv = nullptr;
    while (t--) {
        cin>>type;
        if (type == 1) {
            cin>>no>>amount>>weight;
            pv = Car(no, amount, weight);
            pv.display();
        } else if (type == 2) {
            cin>>no>>weight;
            pv = Truck(no, weight);
            pv.display();
        } else {
            cin>>no>>amount;
            pv = Bus(no, amount);
            pv.display();
        }
    }

    return 0;
}

