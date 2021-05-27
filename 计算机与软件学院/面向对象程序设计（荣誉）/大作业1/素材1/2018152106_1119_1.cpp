2018152106:Problem1119:‘À––¥ÌŒÛ
#include<iostream>
using namespace std;

class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(){}
	BaseAccount(string n,string a,int ba):name(n),account(a),balance(ba){}
	void setv(string n,string a,int ba)
	{
		name=n;
		account=a;
		balance=ba;
	}
	void deposit(int num)
	{
		balance+=num;
	}
	virtual void withdraw(int num)
	{
		if(num<=balance)
			balance-=num;
		else
			cout<<"insufficient"<<endl;
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
};

class BasePlus:public BaseAccount
{
	int limit;
	int limit_sum;
public:
	BasePlus(){}
	BasePlus(string n,string a,int ba):BaseAccount(n,a,ba),limit(5000),limit_sum(0){}
	void deposit(int num)
	{
		balance+=num;
	}
	void withdraw(int num)
	{
		if(num<=balance)
		{
			balance-=num;
		}
		else if(num>balance&&num<=balance+limit)
		{
			limit_sum=(num-balance);
			limit-=limit_sum;
			balance=0;
		}
		else
			cout<<"insufficient"<<endl;
	}
	void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<" "<<endl;
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
		int b,x1,y1,x2,y2;
		cin>>n>>ac>>b>>x1>>y1>>x2>>y2;
		if(ac[1]=='A')
		{
			p=new BaseAccount;
			p->setv(n,ac,b);
			p->deposit(x1);
			p->withdraw(y1);
			p->deposit(x2);
			p->withdraw(y2);
			p->display();
		}
		if(ac[1]=='P')
		{
			BasePlus a(n,ac,b);
			p=&a;
			p->deposit(x1);
			p->withdraw(y1);
			p->deposit(x2);
			p->withdraw(y2);
			p->display();
		}
	}
	delete p;
	return 0;
}
