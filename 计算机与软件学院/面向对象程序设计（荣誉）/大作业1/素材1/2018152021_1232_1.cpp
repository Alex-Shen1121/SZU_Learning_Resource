2018152021:Problem1232:��ȷ
#include<iostream>
#include <string>
using namespace std;
class Vehicle           // ���ࡢ����  Vehicle
{
protected:              // ��ȫ����
    string no;          // ���
public:                  // ��������
    Vehicle(string n):no(n){}
    virtual void display()=0;//����Ӧ�շ���
};
class Car:Vehicle        // ����Car���̳и���Verhicle
{
public:
    int people,weight;
    Car(string n1,int p,int w):Vehicle(n1),people(p),weight(w){}
    void display()
    {
        cout << people*8+weight*2<<endl;  //  �ؿ���8+����2
    }
};
class Truck:Vehicle  // ����Truck���̳и���Verhicle
{
    public:
    int weight;
    Truck(string n1,int w):Vehicle(n1),weight(w){}
    void display()
    {
        cout << weight*5<<endl;  // ����*5
    }
};
class Bus:Vehicle    // ����Bus���̳и���Verhicle
{
public:
    int people;
    Bus(string n1,int p):Vehicle(n1),people(p){}
    void display()
    {
        cout << people*3<<endl;  // �ؿ���*3
    }
};
int main()
{
    int t,num,people,weight;
    string no;
    Car car("",0,0);  // ʵ���������࣬��ʼ��Car�� �ؿ�����������
    Truck truck("",0);
    Bus bus("",0);
    cin >> t;

    while(t--)
    {
        cin >> num;
        if(num==1)
        {
            cin >> no >> people >> weight;     // ��ȡ Car�� �ؿ�����������
            car = Car(no,people,weight);
            cout << no << ' ';
            car.display();
        }
        if(num==2)
        {
            cin >> no >> weight;     // ��ȡTruck ������
            truck = Truck(no, weight);
            cout << no << ' ';
            truck.display();

        }
        if(num==3)
        {
            cin >> no >> people;     // ��ȡBus���ؿ���
            bus = Bus(no, people);
            cout << no << ' ';
            bus.display();
        }
    }
    return 0;
}
