2018151085:Problem1232:±‡“Î¥ÌŒÛ
#include<bits/stdc++.h>
using namespace std;

class Vehicle
{ 
protected:
	string no;
public:
	Vehicle(string No):no(No){}
	virtual void display()=0;
};

class Car:public Vehicle
{
protected:
	int num;
	int weight;
public:
	Car(string No,int Num,int Weight):Vehicle(No),num(Num),weight(Weight){}
	virtual void display()
	{
		cout<<no<<" "<<num*8+weight*2<<endl;
	}
};

class Truck:public Vehicle
{
protected:
	int	weight;
public:
	Truck(string No,int Weight):Vehicle(No),weight(Weight){}
	virtual void display()
	{
		cout<<no<<" "<<weight*5<<endl;
	}
};

class Bus:public Vehicle
{
protected:
	int num;
public:
	Bus(string No,int Num):Vehicle(No),num(Num){}
	virtual void display()
	{
		cout<<no<<" "<<num*3<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	Vehicle *p;
	p=new Vehicle[t];
	
	string No;
	int Num,Weight,n;
	for(int i=0;i<t;i++)
	{
		p[i];
		cin>>n;
		if(n==1)
		{
			cin>>No>>Num>>Weight;
			Car p[i](No,Num,Weight);
			p[i]->display();
		}
		
		if(n==2)
		{
			cin>>No>>Weight;
			Truck p[i](No,Weight);
			p[i]->display();
		}
		
		if(n==3)
		{
			cin>>No>>Num;
			Bus p[i](No,Num);
			p[i]->display();
		}
	}
}
