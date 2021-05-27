2017163101:Problem1119:ÔËÐÐ´íÎó
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
class BaseAccount{
	protected:
		string name,account;
		int balance;
	public:
		BaseAccount(){
		}
		virtual void Deposit(int accno){
			balance+=accno;
		}
		virtual void Withdraw(int accno){
			if(balance<accno){
				cout<<"insufficient"<<endl;
			}
			else{
			balance-=accno;
		}
		
		}
		virtual void display(){
			cout<<name<<" "<<account<<" "<<" "<<"Balance:"<<balance;
			cout<<endl;
		}
		BaseAccount(string n,string a,int b):name(n),account(a),balance(b){
			
		}
};
class BasePlus:public BaseAccount{
	private:
		int limit;
		int limit_sum;
	public:
		BasePlus(){
			limit=5000;
			limit_sum=0;
		}
		void Deposit(int accno){
			//balance+=accno;
			if(limit_sum>0){
				if(limit_sum>accno){
					limit_sum-=accno;
					accno=0;
				}
				else {
					accno-=limit_sum;
					limit_sum=0;
				}
			}
			balance+=accno;
		}
		void Withdraw(int accno){
			if(balance>=accno){
				balance-=accno;
			}
			else if(accno<=balance+limit-limit_sum){
				limit_sum+=accno-balance;
				balance=0;
			}
			else{
			//	cout<"insufficient"<<endl;
			cout<<"insufficient"<<endl;
			}
		}
		void display(){
			cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum;
			cout<<endl;
		}
		BasePlus(string n,string a,int b):BaseAccount(name,account,balance){
			limit=5000;
			limit_sum=0;
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		string name,account;
		int balance;
		cin>>name>>account>>balance;
		int d1,w1,d2,w2;
		cin>>d1>>w1>>d2>>w2;
		BaseAccount *b;
		if(account[1]=='A'){
			BaseAccount BA(name,account,balance);
			b=&BA;
			b->Deposit(d1);
			b->Withdraw(w1);
			b->Deposit(d2);
			b->Withdraw(w2);
			b->display();
		//	delete b;
		}
		else{
			BasePlus BP(name,account,balance);
			b=&BP;
			b->Deposit(d1);
			b->Withdraw(w1);
			b->Deposit(d2);
			b->Withdraw(w2);
			b->display();
			//delete b;
		}
		//delete b;
	}
	return 0;
}
