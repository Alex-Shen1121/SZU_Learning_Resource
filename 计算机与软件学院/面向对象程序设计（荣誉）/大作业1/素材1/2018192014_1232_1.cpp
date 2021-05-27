2018192014:Problem1232:正确
#include<bits/stdc++.h>
using namespace std;
class Vehicle
{ 
protected:

string no;//编号

public:
Vehicle(string n):no(n){
}
virtual void display()=0;//应收费用
};
class Car:virtual public Vehicle{
protected:
	int guest,weight;
public:
	Car(string n,int g,int w):
		Vehicle(n),guest(g),weight(w){
		}
	virtual void display(){
		cout<<no<<" "<<guest*8+weight*2<<endl;
	}
};
class Truck:virtual public Vehicle{
protected:
	int weight;
public:
	Truck(string n,int w):
		Vehicle(n),weight(w){
		}
	virtual void display(){
		cout<<no<<" "<<weight*5<<endl;
	}
};
class Bus:virtual public Vehicle{
protected:
	int guest;
public:
	Bus(string n,int g):
		Vehicle(n),guest(g){
		}
	virtual void display(){
		cout<<no<<" "<<guest*3<<endl;
	}
};
int main ()
{
	Vehicle *pv;
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		int g,w;
		int command;
		cin>>command;
		if(command==1)
		{
			cin>>n>>g>>w;
			pv=new Car(n,g,w);
			pv->display();
		}
		if(command==2)
		{
			cin>>n>>w;
			pv=new Truck(n,w);
			pv->display();
		}
		if(command==3)
		{
			cin>>n>>g;
			pv=new Bus(n,g);
			pv->display();
		}
	}
	return 0;
}
