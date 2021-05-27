2018151092:Problem1232:正确
#include<iostream>
#include<cstring>
using namespace std;

class Vehicle
{ 	
	protected:
		string no;//编号
	public:
		Vehicle()
		{
		}
		
		Vehicle(string n)
		{
			no=n;
		}

		virtual void display()=0;//应收费用

		~Vehicle()
		{
		}
};

class Car:public Vehicle
{ 	
	protected:
		int passenger;
		int load;
	public:
		Car()
		{
		}
		
		Car(string n,int p,int l):Vehicle(n)
		{
			passenger=p;
			load=l;
		}

		virtual void display()
		{
			int money;
			
			money=passenger*8+load*2;
			
			cout<<no<<" "<<money<<endl;
		}

		~Car()
		{
		}
};

class Truck:public Vehicle
{ 	
	protected:
		int load;
	public:
		Truck()
		{
		}
		
		Truck(string n,int l):Vehicle(n)
		{
			load=l;
		}

		virtual void display()
		{
			int money;
			
			money=load*5;
			
			cout<<no<<" "<<money<<endl;
		}

		~Truck()
		{
		}
};

class Bus:public Vehicle
{ 	
	protected:
		int passenger;
	public:
		Bus()
		{
		}
		
		Bus(string n,int p):Vehicle(n)
		{
			passenger=p;
		}

		virtual void display()
		{
			int money;
			
			money=passenger*3;
			
			cout<<no<<" "<<money<<endl;
		}

		~Bus()
		{
		}
};

int main()
{
	int t;
	int i;
	
	cin>>t;
	Vehicle *pv[t];
	
	for(i=0;i<t;i++)
	{
		int type;
		string no;
		int passenger;
		int load;
		
		cin>>type;
		
		if(type==1)
		{
			cin>>no; 
			cin>>passenger>>load;
			pv[i]=new Car(no,passenger,load);
			pv[i]->display();
		}

		if(type==2)
		{	
			cin>>no; 
			cin>>load;
			pv[i]=new Truck(no,load);	
			pv[i]->display();
		}
		
		if(type==3)
		{
			cin>>no;
			cin>>passenger;
			pv[i]=new Bus(no,passenger);
			pv[i]->display();
		}
	}
	
	return 0;
}
