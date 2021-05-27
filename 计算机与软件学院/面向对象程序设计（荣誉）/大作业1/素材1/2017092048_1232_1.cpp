2017092048:Problem1232:ÕýÈ·
// May.27, 2019
// Author: Wenzhuo Dong
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle{
protected:
    string no;
public:
    Vehicle(){}
    Vehicle(string n=""):no(n){}
    virtual void display() = 0;
};

class Car:public Vehicle {
private:
    int num;
    int weight;
public:
    //Car(){};
    Car(string no, int n=1, int w=1):Vehicle(no), num(n), weight(w){};
    ~Car(){}
    void display() {
        cout << no << " " << num*8+weight*2 << endl;
    }
};

class Truck:public Vehicle{
private:
    int weight;
public:
    //Truck(){}
    Truck(string no, int w=0):Vehicle(no), weight(w){};
    ~Truck(){}
    void display() {
        cout << no << " " << weight*5 << endl;
    }
};

class Bus:public Vehicle{
private:
    int num;
public:
    //Bus(){}
    Bus(string no, int n = 1):Vehicle(no), num(n){}
    ~Bus(){}
    void display() {
        cout << no << " " << num*3 << endl;
    }
};


int main() {
    int samples;
    cin >> samples;
    while(samples--) {
        Vehicle *pv;

        int opt;
        string no;
        int n, w;
        cin >> opt;
        switch (opt) {
            case 1:
                //car
                cin >> no >> n >> w;
                pv = new Car(no, n, w);
                break;
            case 2:
                // truck
                cin >> no >> w;
                pv = new Truck(no, w);
                break;
            case 3:
                // bus
                cin >> no >> n;
                pv = new Bus(no, n);
                break;
            default:
                //
                break;
        }
        pv->display();
    }
    return 0;
}



