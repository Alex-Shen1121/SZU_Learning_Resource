2016154114:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(string n):no(n){}
    virtual void display()=0;
};

class Car:public Vehicle
{
protected:
	int customer;
	int weight;
public:
    Car(string n,int c,int w):Vehicle(n),customer(c),weight(w){}
    virtual void display()
    {
		cout<<no<<" "<<customer*8+weight*2<<endl;
    }
};

class Truck:public Vehicle
{
protected:
	int wei;
public:
    Truck(string n,int w):Vehicle(n),wei(w){}
    virtual void display()
    {
		cout<<no<<" "<<wei*5<<endl;
    }
};

class Bus:public Vehicle
{
protected:
	int cus;
public:
    Bus(string n,int c):Vehicle(n),cus(c){}
    virtual void display()
    {
		cout<<no<<" "<<cus*3<<endl;
    }
};

int main()
{
    int i;
    cin>>i;
    while(i--)
    {
		Vehicle *pv;
		string no;
		int type,cus,wei;
        cin>>type>>no;
        if(type==1)
		{
			cin>>cus>>wei;
			Car c(no,cus,wei);
			pv=&c;
			pv->display();
		}
		else if(type==2)
        {
			cin>>wei;
			Truck t(no,wei);
			pv=&t;
			pv->display();
        }
		else if(type==3)
        {
			cin>>cus;
			Bus b(no,cus);
			pv=&b;
			pv->display();
        }
    }
	return 0;
}
