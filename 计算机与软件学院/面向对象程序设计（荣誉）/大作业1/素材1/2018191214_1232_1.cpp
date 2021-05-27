2018191214:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Vehicle
{
protected:
	string no;
public:
	Vehicle(){}
	Vehicle(string n):no(n){}
	virtual void display()=0;
};
class Car:public Vehicle
{
protected:
	int people,weight;
public:
	Car(){}
    Car(int p,int w,string no):people(p),weight(w),Vehicle(no){}
	void display()
	{
		int price;
		price=people*8+weight*2;
	    cout<<price<<endl;
	}
};
class Truck:public Vehicle
{
protected:
	int weight;
public:
    Truck(){}
	Truck(int w,string no):weight(w),Vehicle(no){}
	void display()
	{
		int p;
		p=weight*5;
		cout<<p<<endl;
	}
};
class Bus:public Vehicle
{
protected:
	int people;
public:
	Bus(){}
	Bus(int p,string no):people(p),Vehicle(no){}
	void display()
	{
		int p;
		p=people*3;
		cout<<p<<endl;
	}
};
int main()
{
	int t,kind,people,weight;
	string no;
	Vehicle *pv;
	cin>>t;
	while(t--)
	{
		cin>>kind;
		if(kind==1)
		{
			cin>>no>>people>>weight;
			pv=new Car(people,weight,no);
			cout<<no<<" ";
			pv->display();
		}
		else if(kind==3)
		{
			cin>>no>>people;
			pv = new Bus(people,no);
			cout<<no<<" ";
			pv->display();
		}
		else if(kind==2)
		{
			cin>>no>>weight;
	        pv=new Truck(weight,no);
			cout<<no<<" ";
			pv->display();
		}
	}
	return 0;
}
