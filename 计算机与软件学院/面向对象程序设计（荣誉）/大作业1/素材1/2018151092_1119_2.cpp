2018151092:Problem1119:ÔËÐÐ´íÎó
#include<iostream>
#include<cstring>
using namespace std;

class BaseAccount
{
	protected:
		string name;
		string account;
		float balance;
	public:
		BaseAccount()
		{
		}
		
		BaseAccount(string n,string a,float b)
		{
			name=n;
			account=a;
			balance=b;
		}
		
		virtual void deposit(float add)
		{
			balance+=add;
		}
		
		virtual void withdraw(float diff)
		{
			if(balance>=diff)
			{
				balance-=diff;
			}
			
			else
			{
				cout<<"insufficient"<<endl;
			}
		}
		
		virtual void display()
		{
			cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
		}
		
		~BaseAccount()
		{
		}
};

class BasePlus:public BaseAccount
{
	protected:
		float limit;
		float limit_sum;
	public:
		BasePlus()
		{
		}
		
		BasePlus(string n,string a,float b):BaseAccount(n,a,b)
		{
			limit=5000;
			limit_sum=0;
		}
		
		virtual void deposit(float add)
		{
			balance+=add;
		}
		
		virtual void withdraw(float diff)
		{
			if(diff<=balance+limit-limit_sum)
			{
				if(diff<=balance)
				{
					balance-=diff;
				}
				
				else
				{
					diff-=balance;
					balance=0;
					limit_sum=diff;
					limit-=limit_sum;
				}
			}
			
			else
			{
				cout<<"insufficient"<<endl;
			}
		}
		
		virtual void display()
		{
			cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" limit:"<<limit<<endl;
		}
		
		~BasePlus()
		{
		}
};

int main()
{
	string name;
	string account;
	float balance;
	float dep;
	float with;
	int t;
	int i;
	
	cin>>t;
	
	BaseAccount *Ace[t];
	
	for(i=0;i<t;i++)
	{
		cin>>name>>account>>balance;
		
		if(account[1]=='A')
		{
			Ace[i]=new BaseAccount(name,account,balance);
			cin>>dep;
			Ace[i]->deposit(dep);
			cin>>with;
			Ace[i]->withdraw(with);
			cin>>dep;
			Ace[i]->deposit(dep);
			cin>>with;
			Ace[i]->withdraw(with);
			Ace[i]->display();
		}

		if(account[1]=='P')
		{
			Ace[i]=new BasePlus(name,account,balance);
			cin>>dep;
			Ace[i]->deposit(dep);
			cin>>with;
			Ace[i]->withdraw(with);
			cin>>dep;
			Ace[i]->deposit(dep);
			cin>>with;
			Ace[i]->withdraw(with);
			Ace[i]->display();
		}
	}
	
	delete []Ace;
	return 0;
}
	
