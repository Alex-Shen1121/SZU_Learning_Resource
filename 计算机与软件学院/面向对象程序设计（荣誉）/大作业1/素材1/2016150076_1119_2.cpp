2016150076:Problem1119:´ð°¸´íÎó
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
				if(m<balance)
					balance-=m;
				else 
					cout<<"insufficient"<<endl;	
			}
						
			virtual void display()
			{
				cout<<name<<account<<" Balance:"<<balance<<endl;
				
			}	
						
			
};

class BasePlus:public BaseAccount
{
	private:
		int limit,limit_sum;
	public:
		  	void deposit(int m)
			{
				if(limit_sum>m)
				limit_sum-=m;
				
				else if(limit_sum>0&&limit_sum<m)
				balance=m-limit_sum;
				
				else
					balance+=m;
				
						}
						
			 void withdraw(int m)
			{
				if(m<balance)
					balance-=m;
						
				else if (m>balance&&m<balance+limit)
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
				cout<<name<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
				
						}	
		
};


int main()
{
	int t;
	string name,account;
	int balance;
	cin>>t;
	int a,b,c,d;
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
			BaseAccount h(name,account,balance);
				h.deposit(a);
				h.withdraw(b);
				h.deposit(c);
				h.withdraw(d);
				h.display();
		}
		
		
		
	}
	return 0;
}
