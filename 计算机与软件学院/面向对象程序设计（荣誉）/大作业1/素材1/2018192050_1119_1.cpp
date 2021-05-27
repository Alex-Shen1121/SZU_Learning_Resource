2018192050:Problem1119:´ğ°¸´íÎó
#include<bits/stdc++.h>
using namespace std;
class BaseAccount{
    protected:
        string name;
        string account;
        int balance;
    public:
        BaseAccount(){
        }
        BaseAccount(string a,string b,int c){
            name=a;
            account=b;
            balance= c;
        }
        ~BaseAccount(){
        }
        void deposit(int num)
        {
        	balance+=num;
		}
		void withdraw(int num)
		{
			if(balance>=num)
			{
				balance-=num;
			}
			else
			{
				cout<<"insufficient"<<endl;
			}
		}
		void display()
		{
			cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
		}
};
class BasePlus:public BaseAccount
{
    protected:
        int limit;
        int limitSum;
    public:
        BasePlus(){
        }
        BasePlus(string a,string b,int c){
            name=a;
            account=b;
            balance=c;
            limit=5000;
            limitSum=0;
        }
        ~BasePlus(){
        }
        void despoit(int n){
        	balance+=n;
		}
		void withdraw(int a)
		{
			if((balance+limit)<a)
			{
				cout<<"insufficient"<<endl;
			}
			else
			{
				if(balance<a)
				{
					balance=0;
					limitSum=(a-balance);
					limit-=limitSum;
				}
				else
					balance-=a;
			}
		}
		void display(){
			cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
		}
};
int main(){
	int t;
	string name,n;
	int num1,num2,num3,num4,num;
	cin>>t;
	BaseAccount *pv;
	while(t--)
	{
		cin>>name>>n>>num;
		cin>>num1>>num2>>num3>>num4;
		if(n[1]=='P')
		{
			BasePlus a(name,n,num);
			pv=&a;
			pv->deposit(num1);
			pv->withdraw(num2);
			pv->deposit(num3);
			pv->withdraw(num4);
			pv->display();
		}
		else
		{
			BaseAccount b(name,n,num);
			pv=&b;
			pv->deposit(num1);
			pv->withdraw(num2);
			pv->deposit(num3);
			pv->withdraw(num4);
			pv->display();
		}
	}
}
