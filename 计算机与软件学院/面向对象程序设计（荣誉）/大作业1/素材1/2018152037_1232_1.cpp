2018152037:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
protected:
	string no;
public:
	Vehicle()
	{
	}
	Vehicle(string n)
	{
		no=n;
	}
	virtual void display()
	{
	}
	void print()
	{
		cout<<no<<" ";
	}
};

class Car:public Vehicle
{
	int zai;
	int zl;
public:
	Car(string n,int z1,int z2):Vehicle(n)
	{
		zai=z1;
		zl=z2;
	}
	void display()
	{
		cout<<zai*8+zl*2<<endl;
	}
};

class Truck:public Vehicle
{
	int zl;
public:
	Truck(string n,int z):Vehicle(n)
	{
		zl=z;
	}
	void display()
	{
		cout<<zl*5<<endl;
	}
};

class Bus:public Vehicle
{
	int zai;
public:
	Bus(string n,int z):Vehicle(n)
	{
		zai=z;
	}
	void display()
	{
		cout<<zai*3<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Vehicle *a1;
		int k;
		cin>>k;
		string n;
		cin>>n;
		if(k==1)
		{
			int z1,z2;
			cin>>z1>>z2;
			Car a2(n,z1,z2);
			a1=&a2;
			a1->print();
			a1->display();
		}
		if(k==2)
		{
			int z1;
			cin>>z1;
			Truck a3(n,z1);
			a1=&a3;
			a1->print();
			a1->display();
		}
		if(k==3)
		{
			int z2;
			cin>>z2;
			Bus a4(n,z2);
			a1=&a4;
			a1->print();
			a1->display();
		}
	}
	return 0;
}
