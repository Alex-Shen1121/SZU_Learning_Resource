2016102048:Problem1232:正确
#include <bits/stdc++.h>
using namespace std;

class Vehicle

{ 
protected:

	string no;//编号

public:

	virtual void display()=0;//应收费用
	Vehicle(){
	}
	Vehicle(string n):no(n){
	}
	
	~Vehicle(){
	}
};

class Car:public Vehicle 
{
	int passenger;
	int weight;
public:
	Car(string n,int p,int w):Vehicle(n),passenger(p),weight(w)
	{
	}
	virtual void display()
	{
		cout<<no<<" "<<passenger*8+weight*2<<endl;
	}	
	~Car()
	{
	}
};

class Truck:public Vehicle
{
	int weight;
public:
	Truck(string n,int w):Vehicle(n),weight(w)
	{
	}
	virtual void display()
	{
		cout<<no<<" "<<weight*5<<endl;
	}
	~Truck(){
	}
};

class Bus:public Vehicle
{
	int passenger;
public:
	Bus(string n,int p):Vehicle(n),passenger(p)
	{
		
	}
	virtual void display()
	{
		cout<<no<<" "<<passenger*3<<endl;
	}
	~Bus()
	{
	}
};
int main()
{
	int t;
	cin>>t;
	string no;
	int pass,weight;
	int type;
	
	
	while(t--)
	{
		Vehicle *p;
		cin>>type>>no;
		if(type==1)
		{
			cin>>pass>>weight;
			Car c(no,pass,weight);
			p=&c;
			p->display();
		}
		else if(type==2)
		{
	   		cin>>weight;
			Truck s(no,weight);
			p=&s;
			p->display();
		}
		else if(type==3)
		{
			cin>>pass;
			Bus re(no,pass);
			p=&re;
			p->display();
		}
		
		
		
	}
	return 0;
}
