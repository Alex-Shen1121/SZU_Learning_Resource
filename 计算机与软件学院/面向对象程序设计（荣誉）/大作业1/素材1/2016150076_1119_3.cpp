2016150076:Problem1119:ÕýÈ·
#include<iostream>
using namespace std;

class BaseAccount
{
	protected:
				string name,account;
				int balance;
				
	public:
			BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
			virtual void deposit(int m)
			{
			
				balance+=m;
				
						}
						
			virtual void withdraw(int m)
			{
				if(m<=balance)
					balance-=m;
				else 
					cout<<"insufficient"<<endl;	
			}
						
			virtual void display()
			{
				cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
				
			}
			~BaseAccount(){
			}	
						
			
};

class BasePlus:public BaseAccount
{
	private:
		int limit=5000;
		int limit_sum=0;
	public:
			BasePlus(string n,string a,int b):BaseAccount(n,a,b){}
		  	void deposit(int m)
			{
				if(limit_sum>=m)
				{
					limit_sum-=m;
					limit+=m;
				}
				
				else if(limit_sum>0&&limit_sum<m)
				{
					balance=m-limit_sum;
					limit_sum=0;
					limit=5000;
					}
				
				else
					balance+=m;
				
						}
						
			 void withdraw(int m)
			{
				if(m<=balance)
					balance-=m;
						
				else if (m>balance&&m<=balance+limit)
				{
					limit_sum=m-balance;
					limit=limit+balance-m;
					balance=0;
					
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
	string name,account;
	int balance;
	cin>>t;
	int a,b,c,d;
	BaseAccount *p;
	while(t--)
	{
		cin>>name>>account>>balance;
		cin>>a>>b>>c>>d;
		
		if(account[1]=='A')
			{
				BaseAccount g(name,account,balance);
				g.deposit(a);
				g.withdraw(b);
				g.deposit(c);
				g.withdraw(d);
				g.display();
				
			}
			
		else if(account[1]=='P')	
		{
			BasePlus h(name,account,balance);
				p=&h;
				p->deposit(a);
				p->withdraw(b);
				p->deposit(c);
				p->withdraw(d);
				p->display();
		}
		
		
		
	}
	return 0;
}

