2017047011:Problem1232:ÕýÈ·
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Vehicle
{ 
protected:
	string no;
public:
	Vehicle(){}
	virtual void display()=0;
};
//------------------------
class car:public Vehicle
{
protected:
	int num;
	int weigh;
public:
	car(string no1,int num1,int weigh1);
	void display();
};

car::car(string no1,int num1,int weigh1){
	no=no1;num=num1;weigh=weigh1;
}

void car::display(){
	cout<<no<<" "<<num*8+weigh*2<<endl; 
}
//------------------------
class truck:public Vehicle
{
protected:
	int weigh;
public:
	truck(string no1,int w);
	void display();
};

truck::truck(string no1,int w){
	no=no1;weigh=w;
}

void truck::display(){
	cout<<no<<" "<<weigh*5<<endl; 
}
//------------------------
class bus:public Vehicle
{
protected:
	int num; 
public:
	bus(string no1,int n);
	void display();
};

bus::bus(string no1,int n){
	no=no1;num=n;
}

void bus::display(){
	cout<<no<<" "<<num*3<<endl;
}
//------------------------

int main()
{
	int t;
	int kind,num,weigh;
	string no;
	Vehicle *pv;
	
	cin>>t;
	while(t--)
	{
		cin>>kind;
		
		if(kind==1){
			cin>>no>>num>>weigh;
			car car1(no,num,weigh);
			car1.display();
			
		}
		
		else if(kind==2){
			cin>>no>>weigh;
			truck truck1(no,weigh);
			truck1.display();
		}
		
		else if(kind==3){
			cin>>no>>num;
			bus bus1(no,num);
			bus1.display();
		}
		
	}	
}
