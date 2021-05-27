2016154114:Problem1119:ÕýÈ·
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
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
	virtual void deposit(int m)
	{
		balance+=m;
	}
	virtual void withdraw(int m)
	{
		if(m>balance)
			cout<<"insufficient"<<endl;
		else
			balance-=m;
	}
    virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
};

class BasePlus:public BaseAccount
{
protected:
	int limit;
	int limit_sum;
public:
    BasePlus(string n,string a,int b):BaseAccount(n,a,b),limit(5000){}
    void deposit(int m)
	{
		balance+=m;
	}
	void withdraw(int m)
	{
		if(m<=balance)
			balance-=m;
		else if(m>balance && m<balance+limit)
		{
			m-=balance;
			balance=0;
			balance=0;
			limit-=m;
			limit_sum+=m;
		}
		else
			cout<<"insufficient"<<endl;
	}
    void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
	}
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
		BaseAccount *a;
		string name,account;
		int balance,m1,m2,m3,m4;
        cin>>name>>account>>balance;
        if(account.find("BA")!=string::npos)
		{
			BaseAccount ba(name,account,balance);
			a=&ba;
			cin>>m1>>m2>>m3>>m4;
			a->deposit(m1);
			a->withdraw(m2);
			a->deposit(m3);
			a->withdraw(m4);
			a->display();
		}
		else if(account.find("BP")!=string::npos)
        {
			BasePlus bp(name,account,balance);
			a=&bp;
			cin>>m1>>m2>>m3>>m4;
			a->deposit(m1);
			a->withdraw(m2);
			a->deposit(m3);
			a->withdraw(m4);
			a->display();
        }
    }
	return 0;
}
