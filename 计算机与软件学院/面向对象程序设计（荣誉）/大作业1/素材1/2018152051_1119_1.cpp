2018152051:Problem1119:´ğ°¸´íÎó
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
	BaseAccount(string n,string _acc,int _ba)
	{
		name = n;
		account = _acc;
		balance = _ba;
	}
	virtual void deposit(int num)
	{
		balance+=num;
	}
	virtual void withdraw(int num)
	{
		if(num>balance)
		{
			cout<<"insufficient"<<endl;
		}
		else
		{
			balance-=num;
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
public:
	BasePlus(){}
	BasePlus(string n,string _acc,int _ba,int _li)
	{
		name = n;
		account = _acc;
		balance = _ba;
		limit = _li;
	}
	void deposit(int n)
	{
		if(balance==0)
		{
			limit+=n;
			if(limit>5000)
			{
				balance+=(limit-5000);
				limit = 5000;
			}
		}
		else
		{
			balance+=n;
		}
	}
	void withdraw(int m)
	{
		if(m+balance>limit)
		{
			cout<<"insufficient"<<endl;
		}
		else
		{
			balance-=m;
			int tmp = balance;
			if(balance<0)
			{
				balance = 0;
				limit += tmp;
			}
		}
	}
	void display()
	{
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" "<<"limit:"<<limit<<endl;
	}
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		BaseAccount *b;
		string name,_acc;
		int ba,num1,num2,num3,num4,s;
		cin>>name>>_acc>>ba;
		if(_acc[1]=='A')
		{
			BaseAccount bacc(name,_acc,ba);
			b = &bacc;
			cin>>num1;
			b->deposit(num1);
			cin>>num2;
			b->withdraw(num2);
			cin>>num3;
			b->deposit(num3);
			cin>>num4;
			b->withdraw(num4);
			b->display();
		}
		else if(_acc[1]=='P')
		{
			BasePlus bacc2(name,_acc,ba,5000);
			b = &bacc2;
			cin>>num1;
			b->deposit(num1);
			cin>>num2;
			b->withdraw(num2);
			cin>>num3;
			b->deposit(num3);
			cin>>num4;
			b->withdraw(num4);
			b->display();
		}	
	}
}
