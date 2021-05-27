2017044015:Problem1232:正确
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Vehicle{
protected:
    int weight, volume;
    string no;//编号
public:
    Vehicle(){}
    virtual void display()=0;//应收费用
    virtual ~Vehicle(){}
};

class Car: public Vehicle{
public:
    Car(string s, int w, int v){
        no = s;
        weight = w;
        volume = v;
    };
    virtual void display(){
        cout<<no<<" "<<(weight*2 + volume*8)<<endl;
    }
};

class Truck: public Vehicle{
public:
    Truck(string s, int w){
        no = s;
        weight = w;
    };
    virtual void display(){
        cout<<no<<" "<<(weight*5)<<endl;
    }
};

class Bus: public Vehicle{
public:
    Bus(string s, int v){
        no = s;
        volume = v;
    };
    virtual void display(){
        cout<<no<<" "<<(volume*3)<<endl;
    }
};

int main()
{
    int t, w, v, type;
    string s;
    Vehicle* vc;
    cin>>t;
    while(t--){
        cin>>type>>s;
        if(type == 1){
            cin>>v>>w;
            Car car(s, w, v);
            vc = &car;
            vc->display();
        }
        if(type == 2){
            cin>>w;
            Truck truck(s, w);
            vc = &truck;
            vc->display();
        }
        if(type == 3){
            cin>>v;
            Bus bus(s, v);
            vc = &bus;
            vc->display();
        }
    }
    return 0;
}

