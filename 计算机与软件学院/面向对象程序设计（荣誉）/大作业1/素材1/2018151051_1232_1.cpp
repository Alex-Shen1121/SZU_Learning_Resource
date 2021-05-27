2018151051:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
protected:
	string no;
public:
	Vehicle(){}
	virtual void display()=0;
};
class Car:public Vehicle
{
	int member;
	int zhongliang;
public:
	Car(string n,int m,int z)
	{
		no=n;
		member=m;
		zhongliang=z;
	}
	virtual void display()
	{
		int money;
		money=member*8+zhongliang*2;
		cout<<no<<" "<<money<<endl;
	}
};
class Truck:public Vehicle
{
	int zhongliang1;
public:
	Truck(string n,int z)
	{
		no=n;
		zhongliang1=z;	
	}
	virtual void display()
	{
		int money;
		money=zhongliang1*5;
		cout<<no<<" "<<money<<endl;
	}
};
class Bus:public Vehicle
{
	int member1;
public:
	Bus(string n,int m)
	{
		no=n;
		member1=m;	
	}
	virtual void display()
	{
		int money;
		money=member1*3;
		cout<<no<<" "<<money<<endl;
	}
};
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		Vehicle *p;
		int type;
		cin>>type;
		if(type==1)
		{
			string no;
			int member;
			int zhongliang;
			cin>>no>>member>>zhongliang;
			p=new Car(no,member,zhongliang);
			p->display();
		}
		else if(type==2)
		{
			string no;
			int zhongliang;
			cin>>no>>zhongliang;
			p=new Truck(no,zhongliang);
			p->display();
		}
		else if(type==3)
		{
			string no;
			int member;
			cin>>no>>member;
			p=new Bus(no,member);
			p->display();
		}
	}
	return 0;
}
