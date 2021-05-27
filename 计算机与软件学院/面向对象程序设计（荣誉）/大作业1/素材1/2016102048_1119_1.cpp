2016102048:Problem1119:´ð°¸´íÎó
#include <bits/stdc++.h>
using namespace std;

class BaseAccount
{ 
protected:

	string name;
	string account;
	float balance;

public:

	
	BaseAccount(string n,string a,float b):name(n),account(a),balance(b){
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
	virtual void depoist(float m)
	{
		balance+=m;
	}
	virtual void withdraw(float m)
	{
		if(balance<m)
			cout<<"insufficient"<<endl;
		else
			balance-=m;
	}
	~BaseAccount(){
	}
};

class BasePlus:public BaseAccount 
{
	float limit;
	float limit_sum;
public:
	BasePlus(string n,string a,float b):BaseAccount(n,a,b),limit(5000),limit_sum(0) 
	{
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
	}
	virtual void depoist(float m)
	{
		balance+=m;
	}
	virtual void withdraw(float m)
	{
		if(balance+limit<m)
			cout<<"insufficient"<<endl;
		else if(balance==m)
			balance=0;
		else
		{
			balance=0;
			limit_sum=m-balance;
		}
	}	
	~BasePlus()
	{
	}
};



int main()
{
	int t;
	cin>>t;
	string name;
	string account;
	float balance;
	float m1,m2,m3,m4;
	while(t--)
	{
		BaseAccount *p;
		cin>>name>>account>>balance;
		if(account.compare( 0,2,"BA",0,2)==0)
		{
			//cout<<"ba"<<endl;
			BaseAccount a(name,account,balance);
			p=&a;
			cin>>m1>>m2>>m3>>m4;
			p->depoist(m1);
			p->withdraw(m2);
			p->depoist(m3);
			p->withdraw(m4);
			p->display();
		}
		else if(account.compare( 0,2,"BP",0,2)==0)
		{
			//cout<<"bp"<<endl;
			BasePlus bp(name,account,balance);
			p=&bp;
			cin>>m1>>m2>>m3>>m4;
			p->depoist(m1);
			p->withdraw(m2);
			p->depoist(m3);
			p->withdraw(m4);
			p->display();
		}

		
	}
	return 0;
}
