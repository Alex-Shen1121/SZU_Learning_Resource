2018152102:Problem1232:正确
#include <iostream>

using namespace std;

class Vehicle {
protected:
    string no;//编号
public:
    virtual void display()=0;//应收费用
};
class Car: public Vehicle {
protected:
    int zaikeshu;
    int weight;
public:
    void display() {
        cout<<no<<" "<<zaikeshu*8 + weight*2<<endl;
    }
    void set(string num,int zai,int wei) {
        no = num;
        zaikeshu = zai;
        weight = wei;
    }
};
class Truck:public Vehicle {
protected:
    int weight;
public:
    void display() {
        cout<<no<<" "<<weight * 5<<endl;
    }
    void set(string num,int wei) {
        no = num;
        weight = wei;
    }
};
class Bus :public Vehicle {
protected:
    int zhaikeshu;
public:
    void display() {
        cout<<no<<" "<<zhaikeshu * 3<<endl;
    }
    void set(string num,int zai) {
        no = num;
        zhaikeshu = zai;
    }
};
int main()
{
    Vehicle *pv;
    int t;
    string no;
    int zhaikeshu;
    int weight;

    Car car;
    Truck truck;
    Bus bus;
    cin>>t;
    while(t--) {
        int num;
        cin>>num;
        if(num == 1) {
            cin>>no>>zhaikeshu>>weight;
            car.set(no,zhaikeshu,weight);
            pv = &car;
        }else if(num == 2) {
            cin>>no>>weight;
            truck.set(no,weight);
            pv = &truck;
        }else {
            cin>>no>>zhaikeshu;
            bus.set(no,zhaikeshu);
            pv = &bus;
        }
        pv->display();
    }


    return 0;
}

