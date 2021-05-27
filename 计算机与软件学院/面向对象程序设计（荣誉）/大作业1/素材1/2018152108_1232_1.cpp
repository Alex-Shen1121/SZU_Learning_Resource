2018152108:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;

class Vehicle
{
protected:
	string no;
public:
	Vehicle(string nov)
	{
		no = nov;
	}
	virtual void display()=0;
};

class Car:public Vehicle
{
	int n,weight;
public:
	Car(string nov,int num,int w):Vehicle(nov),n(num),weight(w){}
	void display()
	{
		cout<<no<<" "<<n*8+weight*2<<endl;
	}
};

class Truck:public Vehicle
{
	int weight;
public:
	Truck(string nov,int w):Vehicle(nov),weight(w){}
	void display()
	{
		cout<<no<<" "<<weight*5<<endl;
	}
};

class Bus:public Vehicle
{
	int n;
public:
	Bus(string nov,int num):Vehicle(nov),n(num){}
	void display()
	{
		cout<<no<<" "<<n*3<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Vehicle *pv;
		int type;
		cin>>type;
		if(type==1)
		{
			string nov;
			int num,w;
			cin>>nov>>num>>w;
			Car c(nov,num,w);
			pv = &c;
			pv->display();
		}
		if(type==2)
		{
			string nov;
			int w;
			cin>>nov>>w;
			Truck T(nov,w);
			pv = &T;
			pv->display();
		}
		if(type==3)
		{
			string nov;
			int num;
			cin>>nov>>num;
			Bus b(nov,num);
			pv = &b;
			pv->display();
		}
	}
	return 0;
}


