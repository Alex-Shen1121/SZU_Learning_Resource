2017144045:Problem1119:ÕýÈ·
#include <iostream>
#include <cstring>
using namespace std;
class BaseAccount
{
protected:
	string name;
	string account;
	int balance;	
public:
	BaseAccount()
	{
	}
	BaseAccount(string n,string a,int b)
	{
		name=n;
		account=a;
		balance=b;
	}
	void deposit(int money)
	{
		balance=balance+money;
	}
	virtual void withdraw(int money)
	{
		balance=balance-money;
		if(balance<0)
		{
			cout<<"insufficient"<<endl;
			balance=balance+money;
		}
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
	}
};

class BasePlus:public BaseAccount
{
	int limit;
    int limit_sum;
public:
	BasePlus(string n,string a,int b):BaseAccount(n,a,b)
	{
		limit=5000;
		limit_sum=5000;
	}
    virtual void withdraw(int money)
	{
		balance=balance-money;
		if(balance<0-limit)
		{
			cout<<"insufficient"<<endl;
			balance=balance+money;
		}
		if(balance<0)
		{
			limit_sum=limit+balance;
		}
	}
	virtual void display()
	{
		if(balance<0)
		    balance=0;
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" limit:"<<limit_sum<<endl;
	}
};

int main()
{
	int t;
	string n;
	string a;
	int b;
	int c,d,e,f;
	int money;
	cin>>t;
	while(t--)
	{
		BaseAccount *ac;
		cin>>n>>a>>b;
		//cout<<a<<endl;
		//cout<<a[1]<<endl;
		if(a[1]=='P')
		{
			ac=new BasePlus(n,a,b);
		}
		else
		{
			ac=new BaseAccount(n,a,b);
		}
		cin>>c>>d>>e>>f;
		ac->deposit(c);
		ac->withdraw(d);
		ac->deposit(e);
		ac->withdraw(f);
		ac->display();
	 } 
}
