2018192050:Problem1232:正确
#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
protected:
	string no;//编号
public:
	virtual void display()=0;//应收费用
};
class Car:public Vehicle
{
	protected:
		int num;
		int weight;
    public:
        Car(){
        }
        Car(string n,int a,int b)
		{
			no=n;
			num=a;
			weight=b;
        }
        void display(){
        	cout<<no<<" "<<num*8+weight*2<<endl;
		}
        ~Car(){
        }
};
class Truck:public Vehicle
{
	protected:
		int weight;
    public:
        Truck(){
        }
        Truck(string n,int b)
		{
			no=n;
			weight=b;
        }
        void display(){
        	cout<<no<<" "<<weight*5<<endl;
		}
        ~Truck(){
        }
};
class Bus:public Vehicle
{
	protected:
		int num;
    public:
        Bus(){
        }
        Bus(string n,int a)
		{
			no=n;
			num=a;
        }
        void display(){
        	cout<<no<<" "<<num*3<<endl;
		}
        ~Bus(){
        }
};
int main(){
	int t,n,type,w;
	string name;
	cin>>t;
	Vehicle *pv;
	while(t--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>name>>n>>w;
			Car a(name,n,w);
			pv=&a;
			pv->display();
		}
		if(type==2)
		{
			cin>>name>>n;
			Truck b(name,n);
			pv=&b;
			pv->display();
		}
		if(type==3)
		{
			cin>>name>>w;
			Bus c(name,w);
			pv=&c;
			pv->display();
		}
	}
}
