2017151066:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;
class Vehicle
{
protected:
	string no;
public:
	Vehicle(string n):no(n){}
	virtual void display()=0;
	virtual ~Vehicle(){}
	
};
class Car:public Vehicle
{
protected:
	int zai;
	int zhong;
public:
	Car(int z,int zh,string n):zai(z),zhong(zh),Vehicle(n){}
	void display()
	{
		cout<<no<<" "<<zai*8+zhong*2<<endl;
	}
	virtual ~Car(){}
};
class Truck:public Vehicle
{
protected:
	int zhongliang;
public:
	Truck(int z,string n):zhongliang(z),Vehicle(n){}
	void display()
	{
		cout<<no<<" "<<zhongliang*5<<endl;
	}
	virtual ~Truck(){}
};
class Bus:public Vehicle
{
protected:
	int zai;
public:
	Bus(int z,string n):zai(z),Vehicle(n){}
	void display()
	{
		cout<<no<<" "<<zai*3<<endl;
	}
	virtual ~Bus(){}
};
int main()
{
	int t;
	cin>>t;
	string no;	
	int z,zh;
	Vehicle *pv;
	while(t--)
	{
		int n;
		cin>>n;
	   if(n==1)
		{
			cin>>no>>z>>zh;
			pv=new Car(z,zh,no);
			pv->display();
			delete pv;		
		}
     	else if(n==2)
		{
			cin>>no>>zh;
			pv=new Truck(zh,no);
			pv->display();
			delete pv;	
		}
    	else if(n==3)
		{
			cin>>no>>z;
			pv=new Bus(z,no);
			pv->display();
			delete pv;	
		}
	}
	return 0;
}
