2018152021:Problem1232:正确
#include<iostream>
#include <string>
using namespace std;
class Vehicle           // 父类、基类  Vehicle
{
protected:              // 安全属性
    string no;          // 编号
public:                  // 公共属性
    Vehicle(string n):no(n){}
    virtual void display()=0;//计算应收费用
};
class Car:Vehicle        // 子类Car，继承父类Verhicle
{
public:
    int people,weight;
    Car(string n1,int p,int w):Vehicle(n1),people(p),weight(w){}
    void display()
    {
        cout << people*8+weight*2<<endl;  //  载客数8+重量2
    }
};
class Truck:Vehicle  // 子类Truck，继承父类Verhicle
{
    public:
    int weight;
    Truck(string n1,int w):Vehicle(n1),weight(w){}
    void display()
    {
        cout << weight*5<<endl;  // 重量*5
    }
};
class Bus:Vehicle    // 子类Bus，继承父类Verhicle
{
public:
    int people;
    Bus(string n1,int p):Vehicle(n1),people(p){}
    void display()
    {
        cout << people*3<<endl;  // 载客数*3
    }
};
int main()
{
    int t,num,people,weight;
    string no;
    Car car("",0,0);  // 实例化对象类，初始化Car的 载客数量，重量
    Truck truck("",0);
    Bus bus("",0);
    cin >> t;

    while(t--)
    {
        cin >> num;
        if(num==1)
        {
            cin >> no >> people >> weight;     // 获取 Car的 载客数量，重量
            car = Car(no,people,weight);
            cout << no << ' ';
            car.display();
        }
        if(num==2)
        {
            cin >> no >> weight;     // 获取Truck 的重量
            truck = Truck(no, weight);
            cout << no << ' ';
            truck.display();

        }
        if(num==3)
        {
            cin >> no >> people;     // 获取Bus的载客数
            bus = Bus(no, people);
            cout << no << ' ';
            bus.display();
        }
    }
    return 0;
}
