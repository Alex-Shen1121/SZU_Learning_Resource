2018152051:Problem1232:正确
#include<iostream>
using namespace std;
class Vehicle
{ 
protected:
	string no;//编号
public:
	virtual void display()=0;//应收费用
};
class CCar:public Vehicle
{
protected:
	int num;
	int weight;
public:
	CCar(){}
	CCar(string s,int n,int w)
	{
		no = s;
		num = n;
		weight = w;
	}
	void display()
	{
		cout<<no<<" "<<num*8+weight*2<<endl;
	}
};
class CTruck:public Vehicle
{
protected:
	int weight;
public:
	CTruck(){}
	CTruck(string s,int w)
	{
		no = s;
		weight = w;
	}
	void display()
	{
		cout<<no<<" "<<weight*5<<endl;
	}
};
class CBus:public Vehicle
{
protected:
	int num;
public:
	CBus(){}
	CBus(string s,int n)
	{
		no = s;
		num = n;
	}
	void display()
	{
		cout<<no<<" "<<num*3<<endl;
	}
};
int main()
{
	int T;
	cin>>T;
	Vehicle *pv;
	while(T--)
	{
		int number,num,weight;
		string S;
		cin>>number;
		if(number == 1)
		{
			cin>>S>>num>>weight;
			CCar car(S,num,weight);
			pv = &car;
			pv->display();
		}
		else if(number == 2)
		{
			cin>>S>>weight;
			CTruck truck(S,weight);
			pv = &truck;
			pv->display();
		}
		else if(number == 3)
		{
			cin>>S>>num;
			CBus bus(S,num);
			pv = &bus;
			pv->display();
		}
	}
}
