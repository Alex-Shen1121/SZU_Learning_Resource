2018151031:Problem1232:编译错误
#include <bits/stdc++.h>
using namespace std;
class Vehicle
{ 
protected:
	string no;//编号
public:
	virtual void display()=0;//应收费用
	Vehicle(string no_in):no(no_in){}
};
class Car:public Vehicle
{
	int carry;
	int weight;
public:
	Car(string no_in,int c,int w):Vehicle(no_in),carry(c),weight(w){}
	void display()
	{
		cout<<no<<' '<<carry*8+weight*2<<endl;
	}
};
class Truck:public Vehicle
{
	int weight;
public:
	Truck(string no_in,int w):Vehicle(no_in),weight(w){}
	void display()
	{
		cout<<no<<' '<<weight*5<<endl;
	}
};
class Bus:public Vehicle
{
	int carry;
public:
	Bus(string no_in,int c):Vehicle(no_in),carry(c){}
	void display()
	{
		cout<<no<<' '<<carry*3<<endl;
	}
};
int main() 
{
	Vehicle *pv;
	int t;
	cin>>t;
	while(t--)
	{
		int type,w,c;
		cin>>type;
		string  no;
		if(type==1)
		{
			
			cin>>no>>c>>w;
			Car c1(no,c,w);
			c1.display();
		}
		else if(type==2)
		{
	
			cin>>no>>w;
			Truck t(no,w);
			t.display();
		}
		else if(type==3)
		{
			
			cin>>no>>c;
			Bus b(no,c);
			b.display();
		}
	}
	return 0;
}
