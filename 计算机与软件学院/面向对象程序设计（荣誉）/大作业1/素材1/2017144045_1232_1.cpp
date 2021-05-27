2017144045:Problem1232:正确
#include <iostream>
using namespace std;
 
class Vehicle
{ 
protected:
    string no;//编号
    int num;
    int weight;
public:
    virtual void display()=0;//应收费用
    Vehicle()
    {
	}
    Vehicle(string nom,int n,int w)
    {
    	no=nom;
    	num=n;
    	weight=w;
	}
};
class Car:public Vehicle
{
public:
	Car(string nom,int n,int w):Vehicle(nom,n,w)
	{
	} 
	virtual void display()
	{
		cout<<no<<" "<<num*8+weight*2<<endl;
	}
};

class Truck:public Vehicle
{
public:
	Truck(string nom,int w)
	{
		no=nom;
		weight=w;
	} 
	virtual void display()
	{
		cout<<no<<" "<<5*weight<<endl;
	}
};

class Bus:public Vehicle
{
public:
	Bus(string nom,int n)
	{
		no=nom;
		num=n;
	} 
	virtual void display()
	{
		cout<<no<<" "<<3*num<<endl;
	}
};

int main()
{
	int t;
	int a;
	string nom;
	int n,w;
	cin>>t;
	while(t--)
	{
		cin>>a>>nom;
		if(a==1)
		{
			cin>>n>>w;
			Vehicle *pv=new Car(nom,n,w);
			pv->display();
		}
		else if(a==2)
		{
			cin>>w;
			Vehicle *pv=new Truck(nom,w);
			pv->display();
		}
		else if(a==3)
		{
			cin>>n;
			Vehicle *pv=new Bus(nom,n);
			pv->display();
		}
	}
}

