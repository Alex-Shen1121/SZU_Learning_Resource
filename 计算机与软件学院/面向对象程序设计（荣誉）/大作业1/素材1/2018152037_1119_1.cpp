2018152037:Problem1119:∏Ò Ω¥ÌŒÛ
#include<iostream>
#include<string>
using namespace std;

class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string n,string ac,int ba)
	{
	 	name=n;
	 	account=ac;
	 	balance=ba;
	}
	void deposit(int k)
	{
	 	balance=balance+k;
	}
	virtual void withdraw(int k)
	{
	 	if(balance-k<0)
	 		cout<<"insufficient"<<endl;
	 	else
	 	{
	 		balance=balance-k;
		}
	}
	virtual void dispalay()
	{
	 	cout<<name<<" "<<account<<" "<<" Balance:"<<balance<<endl;
	} 
};

class BasePlus:public BaseAccount
{
	int limit;
	int limit_sum;
public:
	BasePlus(string n,string ac,int ba):BaseAccount(n,ac,ba)
	{
		limit=5000;
		limit_sum=0;
	}
	void withdraw(int k)
	{
		if(balance+limit-k<0)
			cout<<"insufficient"<<endl;
		else
		{
			if(balance-k>=0)
				balance=balance-k;
			else
			{
				limit=limit+balance-k;
				limit_sum=5000-limit;
				balance=0;
			}
		}
	}
	void dispalay()
	{
		cout<<name<<" "<<account<<" "<<" Balance:"<<balance<<" limit:"<<limit<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		BaseAccount *aa;
		string n,ac;
		int ba,m1,m2,m3,m4;
		cin>>n>>ac>>ba>>m1>>m2>>m3>>m4;
		if(ac[1]=='A')
		{
			BaseAccount a1(n,ac,ba);
			aa=&a1;
			aa->deposit(m1);
			aa->withdraw(m2);
			aa->deposit(m3);
			aa->withdraw(m4);
			aa->dispalay();
		}
		if(ac[1]=='P')
		{
			BasePlus a2(n,ac,ba);
			aa=&a2;
			aa->deposit(m1);
			aa->withdraw(m2);
			aa->deposit(m3);
			aa->withdraw(m4);
			aa->dispalay();
		}
	}
	return 0;
}
