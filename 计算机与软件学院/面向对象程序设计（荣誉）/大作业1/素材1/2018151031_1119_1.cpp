2018151031:Problem1119:ÕýÈ·
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BaseAccount{
	protected:
		string name;
		string account;
		float balance;
	public:
		BaseAccount(string _name="Lebron",string _account="BA000",float _balance=10000){
			name=_name;
			account=_account;
			balance=_balance;
		}
		virtual void deposit(float money){
			balance+=money;
		}
		virtual void withdraw(float money){
			if(money>balance)
				cout<<"insufficient"<<endl;
			else
				balance-=money;
		}
		virtual void display(){
			cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
		}
};

class BasePlus:public BaseAccount{
	private:
		float limit;
		float limit_sum;
	public:
		BasePlus(string _name="Lebron",string _account="BP000",float _balance=10000,float _limit=5000,float _limit_sum=0):BaseAccount(_name,_account,_balance){
			limit=_limit;
			limit_sum=_limit_sum;
		}
		void deposit(float money){
			if(limit_sum==0)
			{
				balance+=money;
			}
			else
			{
				if(limit_sum>money)
				{
					limit_sum-=money;
				}
				else
				{
					balance=balance+(money-limit_sum);
					limit_sum=0;
				}
			}
		}
		void withdraw(float money){
			if(money<=balance)
			{
				balance-=money;
			}
			else
			{
				if(money<=(balance+(limit-limit_sum)))
				{
					limit_sum=limit_sum+(money-balance);
					balance=0;
				}
				else
				{
					cout<<"insufficient"<<endl;
				}
			}
		}
		void display(){
			cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
		}
};

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		string _name,_account;
		float _balance;
		float a,b,c,d;
		cin>>_name;
		cin>>_account;
		cin>>_balance>>a>>b>>c>>d;
		BaseAccount *p;
		if(_account[1]=='A')
		{
			BaseAccount account(_name,_account,_balance);
			p=&account;
			p->deposit(a);
			p->withdraw(b);
			p->deposit(c);
			p->withdraw(d);
			p->display();
		}
		else 
		{
			BasePlus account(_name,_account,_balance,5000,0);
			p=&account;
			p->deposit(a);
			p->withdraw(b);
			p->deposit(c);
			p->withdraw(d);
			p->display();
		}
	}
	return 0;
}
