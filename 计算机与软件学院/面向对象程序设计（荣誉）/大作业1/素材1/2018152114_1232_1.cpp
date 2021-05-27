2018152114:Problem1232:正确
#include<iostream>
using namespace std;
class Vehicle

{ 
protected:

	string no;//编号

public:
 	Vehicle(string n5):no(n5)
 	{
	 }
	virtual void display()=0;//应收费用

};
class Car:public Vehicle
{
protected:
	int _people,_weight;
public:
	Car(string n1,int p,int w):Vehicle(n1),_people(p),_weight(w)
	{
	}
	virtual void display()
	{
		cout<<_people*8+_weight*2<<endl;
	}
	
};
class Truck:public Vehicle
{
protected:
	int weight_;
public:
 	Truck(string n2,int w2):Vehicle(n2),weight_(w2)
	 {
	}
	virtual void display()
	{
		cout<<weight_*5<<endl;
	}	
};
class Bus:public Vehicle
{
protected:
	int people_;
public:
	Bus(string n3,int p2):Vehicle(n3),people_(p2)
	{
	}
	virtual void display()
	{
		cout<<people_*3<<endl;
	}	
};
int main()
{
	int t;
	cin>>t;
	int type;
	string _no;
	int people;
	int weight;
	
	while(t--)
	{
		Vehicle* s;
		cin>>type>>_no;
		cout<<_no<<" ";
		if(type==1)
		{
			cin>>people>>weight;
			Car c(_no,people,weight);
			s=&c;
			s->display();
		}
		if(type==2)
		{
			cin>>weight;
			Truck tr(_no,weight);
			s=&tr;
			s->display();
		}
		if(type==3)
		{
			cin>>people;
			Bus b(_no,people);
			s=&b;
			s->display();
		}
	}
		return 0;
}
