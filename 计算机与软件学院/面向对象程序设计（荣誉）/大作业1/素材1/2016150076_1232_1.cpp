2016150076:Problem1232:编译错误
#include<iostream>
using namespace std;

class Vehicle

{ protected:

string no;
int charge;


public:
Vehicle(string n):no(n){
}

virtual void display()=0;//应收费用
~Vehicle(){
}

};

class Car:public Vehicle
{
	private:
			int number,weight;
	public:
			Car(string n,int nu,int w):Vehicle(n),number(nu),weight(w){}
			void display()
			{
				charge=number*8+weight*2;
				cout<<no<<" "<<charge<<endl;	
			}
			~Car(){}	
	
};

class Truck:public Vehicle
{
	
		private:
				int weight;
		public:
			Truck(string n,int w):Vehicle(n),weight(w){}
			void display()
			{
				charge=weight*5;
				cout<<no<<" "<<charge<<endl;
				
			}
			~Truck(){}
	
};

class Bus:public Vehicle
{
	
		private:
			int number;
		public:
			Bus(string n,int nu):Vehicle(n),number(nu){}
			void display()
			{
				charge=number*3;
				cout<<no<<" "<<charge<<endl;
			}
			~Bus(){}
};

int main()
{
	int no,number,weight,type,t;
	Vehicle *pv;
	
	cin>>t;
	while(t--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>no>>number>>weight;
			Car a(no,number,weight);
			pv=&a;
			pv->display();
			
		}
		
		if(type==2)
		{
			cin>>no>>weight;
			Truck b(no,weight);
			pv=&b;
			pv->display();
			
		}
		
		if(type==3)
		{
			cin>>no>>number;
			Bus c(no,number);
			pv=&c;
			pv->display();
			
		}
	}
	
	return 0;
	
}
