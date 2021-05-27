2016150076:Problem1119:±‡“Î¥ÌŒÛ
#include<iostream>
using namespace std;

class BaseAccount
{
	protected:
				string name,account;
				int balance;
				
	public:
			BaseAccount(string n)
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
						
			virtual void display(int m)
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
						
			void display(int m)
			{
				cout<<name<<account<<" Balance:"<<balance<<endl;
				
						}	
		
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>name>>account>>balance;
		cin>>a>>b>>c>>d;
		
		if
		
		
		
	}
}

