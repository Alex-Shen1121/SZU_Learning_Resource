2018152108:Problem1119:ÕýÈ·
#include<iostream>
using namespace std;

class BaseAccount
{
protected:
	string name,account;
	int balance;
public:
	BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
	void deposit(int m)
	{
		balance+=m;
	}
	virtual void withdraw(int m)
	{
		if(m<=balance)
		{
			balance-=m;
		}
		else
		{
			cout<<"insufficient"<<endl;
		}
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
};

class BasePlus:public BaseAccount
{
	int limit,limit_sum;
public:
	BasePlus(string n,string a,int b):BaseAccount(n,a,b)
	{
		limit = 5000;
		limit_sum = 0;
	}
	void withdraw(int m)
	{
		if(m<=balance)
		{
			balance-=m;
		}
		else if(m<=balance+limit)
		{
			limit_sum = m-balance;
			limit -= m-balance;
			balance = 0;
		}
		else
		{
			cout<<"insufficient"<<endl;
		}
	}
	void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
	}
};

int main()
{
	int t;
	BaseAccount *p;
	cin>>t;
	while(t--)
	{
		string n,ac;
		int b,x1,x2,x3,x4;
		cin>>n>>ac>>b>>x1>>x2>>x3>>x4;
		if(ac[1]=='A')
		{
			BaseAccount a(n,ac,b);
			p = &a;
			p->deposit(x1);
			p->withdraw(x2);
			p->deposit(x3);
			p->withdraw(x4);  
			p->display();
		}
		if(ac[1]=='P')
		{
			BasePlus a(n,ac,b);
			p = &a;
			p->deposit(x1);
			p->withdraw(x2);
			p->deposit(x3);
			p->withdraw(x4);  
			p->display();
		}
	}
	return 0;
}
