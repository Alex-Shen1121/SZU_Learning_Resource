2018152008:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class BaseAccount
{
	protected:
		string name,account;
		double balance;
	public:
		BaseAccount(string n,string a,double b); 
		void deposit(double money);
		virtual bool withdraw(double money);
		virtual void display();
		virtual void error();
};
void BaseAccount::error()
{
	cout<<"insufficient"<<endl;
}
BaseAccount::BaseAccount(string n,string a,double b)
{
	name=n;
	account=a;
	balance=b;
}
void BaseAccount::deposit(double money)
{
	balance+=money;
}
bool BaseAccount::withdraw(double money)
{
	if(balance>=money)
	{
		balance-=money;
		return true;
	}
	return false;
}
void BaseAccount::display()
{
	cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
}
class BasePlus:public BaseAccount
{
	protected:
		double limit;
		double limit_sum;
	public:
		BasePlus(string n,string a,double b);
		bool withdraw(double money);
		void display();
		void error();
};
void BasePlus::error()
{
	cout<<"insufficient"<<endl;
}
BasePlus::BasePlus(string n,string a,double b):BaseAccount(n,a,b),limit(5000),limit_sum(0)
{
	;
} 
bool BasePlus::withdraw(double money)
{
	if(balance+limit-limit_sum>=money)
	{
		balance-=money;
		if(balance<0)
		{
			limit_sum-=balance;
			limit+=balance;
			balance=0;
		}
		return true;
	}		
	return false;
}
void BasePlus::display()
{
	cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		BaseAccount *T;
		string n,p;
		double bal;
		cin>>n>>p>>bal;
		if(p[1]=='A')
			T=new BaseAccount(n,p,bal);
		else
			T=new BasePlus(n,p,bal);
		double x1,x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		T->deposit(x1);
		if(!T->withdraw(x2))
		{
			T->error();
		}
		T->deposit(x3);
		if(!T->withdraw(x4))
		{
			T->error();
		}
		T->display();
	}
}
