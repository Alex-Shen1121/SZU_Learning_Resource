2018152008:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Vehicle
{
	protected:
		string no;
		int count;
	public:
		virtual void display()=0;
		Vehicle(string n);
};
Vehicle::Vehicle(string n)
{
	no=n;
}
class Car:public Vehicle
{
	protected:
		int weight;
		int sum;
	public:
		Car(string n,int w,int s);
		void display();
};
Car::Car(string n,int w,int s):Vehicle(n)
{
		weight=w;
		sum=s;
};
void Car::display()
{
	count=weight*8+sum*2;
	cout<<setw(3)<<setfill('0')<<no<<" "<<count<<endl;
}
class Truck:public Vehicle
{
	protected:
		int weight;
	public:
		Truck(string n,int w);
		void display();	
};
Truck::Truck(string n,int w):Vehicle(n)
{
	weight=w;
}
void Truck::display()
{
	count=weight*5;
	cout<<setw(3)<<setfill('0')<<no<<" "<<count<<endl;	
}
class Bus:public Vehicle
{
	protected:
		int sum;	
	public:
		Bus(string n,int s);
		void display();
};
Bus::Bus(string n,int s):Vehicle(n)
{
	sum=s;
}
void Bus::display()
{
	count=sum*3;
	cout<<setw(3)<<setfill('0')<<no<<" "<<count<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Vehicle * pol;
		int kind,s,w;
		string n;
		cin>>kind;
		if(kind==1)
		{
			cin>>n>>w>>s;
			pol=new Car(n,w,s);
			pol->display();
		}
		else if(kind==2)
		{
			cin>>n>>w;
			pol=new Truck(n,w);
			pol->display();
		}
		else
		{
			cin>>n>>s;
			pol=new Bus(n,s);
			pol->display();
		}
		delete pol;
	}
	return 0;
}
