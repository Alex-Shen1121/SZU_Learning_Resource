2018152087:Problem1232:ÔËÐÐ´íÎó
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{ 
protected:
	string no;
public:
	Vehicle(string s):no(s){
	}
	virtual void display()=0;
};
class Car:public Vehicle
{
	int weight;
	int num;
public:
	Car(string s,int w,int n):Vehicle(s)
	{
		weight=w;
		num=n;
	}
	virtual void display()
	{
		cout<<no<<" "<<num*8+weight*2<<endl;
	}
};
class Truck:public Vehicle
{
	int weight;
public:
	Truck(string s,int w):Vehicle(s)
	{
		//no=s;
		weight=w;
	}
	virtual void display()
	{
		cout<<no<<" "<<weight*5<<endl;
	}
};
class Bus:public Vehicle
{
	int num;
public:
	Bus(string s,int n):Vehicle(s)
	{
		//no=s;
		num=n;
	}
	virtual void display()
	{
		cout<<no<<" "<<num*3<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	Vehicle *pv;
	while(t--)
	{	
		int flag;
		cin>>flag;
		if(flag==1)
		{
			string name;
			int num;
			int weight;
			cin>>name>>num>>weight;
			Car ex(name,num,weight);
			pv=&ex;
		}
		else if(flag==2)
		{
			string name;
			int weight;
			cin>>name>>weight;
			Truck ex(name,weight);
			pv=&ex;
		}
		else if(flag==3)
		{
			string name;
			int num;
			cin>>name>>num;
			Bus ex(name,num);
			pv=&ex;
		}
		pv->display();
	}
}
