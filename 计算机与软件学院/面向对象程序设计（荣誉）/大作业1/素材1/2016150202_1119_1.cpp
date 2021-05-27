2016150202:Problem1119:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class BA{
	protected:
		string name,account;
		int balance;
		public:
			BA(string n,string a,int b):name(n),account(a),balance(b){}
			~BA(){}
			void deposit(int m)
			{
				balance=balance+m;
			}
			void withdraw(int m)
			{
				if(m>balance)
				cout<<"insufficient"<<endl;
				else
				balance=balance-m;
				
			}
		     virtual void display()
			{
				cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
			}
};

class BP:public BA
{
	protected:
		int limit;
		int limit_sum;
		public:
		
			BP(string n,string a,int b):BA(n,a,b){limit=5000;}
			~BP(){}
			
			void deposit(int m)//cunkuan
			{
			
				balance=balance+m;
				
			}
		
			void withdraw(int m)//qukuan
			{
				
		    
		    	if(m>balance+limit)
		    	cout<<"insufficient"<<endl;
		    	
		    	else 
		    	{
		    	
				balance=balance-m;
		    	if(balance<0)
		    	{
				
	        	limit=limit+(balance-m);
	        	limit_sum=limit+5000;
	        	balance=0;
		        }
		        else
		        limit_sum=5000;
				}
		    
			  }   
		
		
			
			 void display()
			{
				cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit_sum<<endl;
			}
			
};
int main()
{
	string name,account;
	int balance;
	int t;
	int m1,m2,m3,m4;
	BA *pv;
	cin>>t;
	while(t--)
	{
		cin>>name>>account;
		
			if(account[1]=='A')
			{
				cin>>balance;
				BA aa(name,account,balance);
				pv=&aa;
				cin>>m1;
				pv->deposit(m1);
				cin>>m2;
				pv->withdraw(m2);
				cin>>m3;
				pv->deposit(m3);
				cin>>m4;
				pv->withdraw(m4);
				pv->display();
				
			}
			else if(account[1]='P')
			{
				cin>>balance;
				BP bb(name,account,balance);
				
				
				cin>>m1;
				bb.deposit(m1);
				cin>>m2;
				bb.withdraw(m2);
				cin>>m3;
				bb.deposit(m3);
				cin>>m4;
				bb.withdraw(m4);
				bb.display();
			}
			else 
			cout<<"ushdsufgsdjf skfhjksdfh jsdfhks jfh"<<endl;
		}
		
		
}



