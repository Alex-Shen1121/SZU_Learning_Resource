2018152106:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;

class Vehicle
{
protected:
	string no;
public:
	Vehicle(string n):no(n){}
	virtual void display()=0;
};

class Car:public Vehicle
{
    int passage_num,weight;
public:
	Car(string n,int pass,int wei):Vehicle(n),passage_num(pass),weight(wei){}
	void display()
	{
		cout<<no<<" "<<passage_num*8+weight*2<<endl;
	}
};

class Turck:public Vehicle
{
    int weight;
public:
	Turck(string n,int wei):Vehicle(n),weight(wei){}
	void display()
	{
		cout<<no<<" "<<+weight*5<<endl;
	}
};
class Bus:public Vehicle
{
    int passage_num;
public:
	Bus(string n,int pass):Vehicle(n),passage_num(pass){}
	void display()
	{
		cout<<no<<" "<<passage_num*3<<endl;
	}
};

int main()
{
	int t;
	Vehicle *pv;
	cin>>t;
	while(t--)
	{
		int h,pass,weight;
		string n;
		cin>>h;
		if(h==1)
		{
			cin>>n>>pass>>weight;
			Car a(n,pass,weight);
			pv=&a;
			pv->display();
		}
		if(h==2)
		{
			cin>>n>>weight;
			Turck a(n,weight);
			pv=&a;
			pv->display();
		}
		if(h==3)
		{
			cin>>n>>pass;
			Bus a(n,pass);
			pv=&a;
			pv->display();
		}
	}
	return 0;
}
