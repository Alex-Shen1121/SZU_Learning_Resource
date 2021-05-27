2018151044:Problem1232:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{ 
protected:
	string no;//¡À¨¤o?
public:
	Vehicle(string no):no(no) {}
	virtual void display()=0;//¨®|¨º?¡¤?¨®?
};
class Car:public Vehicle
{
	int p,w;
public:
	Car(string no,int p,int w):Vehicle(no),p(p),w(w) {}
	virtual void display()
	{
		cout<<no<<' '<<p*8+w*2<<endl;
	}
};
class Truck:public Vehicle
{
	int w;
public:
	Truck(string no,int w):Vehicle(no),w(w) {}
	virtual void display()
	{
		cout<<no<<" "<<w*5<<endl;
	}
};
class Bus:public Vehicle
{
	int p;
public:
	Bus(string no,int p):Vehicle(no),p(p) {}
	virtual void display()
	{
		cout<<no<<" "<<p*3<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	Vehicle *pv;
	int type,a,b;
	string no;
	while(t--)
	{
		cin>>type>>no>>a;
		if(type==1)
		{
			cin>>b;
			pv=new Car(no,a,b);
		}
		else if(type==2)
		{
			pv=new Truck(no,a);
		}
		else 
		{
			pv=new Bus(no,a);
		} 
		pv->display();
		delete pv;
	}
}
