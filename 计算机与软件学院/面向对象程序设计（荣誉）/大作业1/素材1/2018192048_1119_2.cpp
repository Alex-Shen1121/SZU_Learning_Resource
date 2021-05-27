2018192048:Problem1119:´ð°¸´íÎó
#include<iostream>
using namespace std;
 
class BaseAccount{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(){}
    BaseAccount(string n,string a,int b){
		name=n;
		account=a;
		balance=b;
	}
    virtual void deposit(int m){
        balance+=m;
    }
    virtual void withdraw(int m){
        if(balance>=m)
            balance-=m;
        else
            cout<<"insufficient"<<endl;
         
    }
    virtual void display(){
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
    ~BaseAccount(){}
};
 
class BasePlus:public BaseAccount{
protected:
    int limit,limit_sum;
public:
    BasePlus(){}
    BasePlus(string n,string a,int b):BaseAccount(n,a,b){
        limit=5000;
        limit_sum=0;
    }
    void deposit(int m){
        balance+=m;
    }
    void withdraw(int m){
        if(balance>=m)
            balance-=m;
        else if(balance<m&&m<=balance+limit){
            limit_sum=m-balance;
            balance=0;
        }
        else if(m>balance+limit)
            cout<<"insufficient"<<endl;
    }
    void display(){
        cout<<BaseAccount::name<<" "<<BaseAccount::account<<" Balance:";
        cout<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
    ~BasePlus(){}
};
 
int main(){
    int t;
    cin>>t;
    BaseAccount *pv;
    while(t--){
        string name,account;
		int balance;
        cin>>name>>account>>balance;
        if(account.at(1)=='A'){
        	BaseAccount a(name,account,balance);
        	pv=&a;
        	for(int i=1;i<=4;i++){
	            int m;
	            cin>>m;
	            if(i%2)
	                pv->deposit(m);
	            else
	                pv->withdraw(m);
        	}
        	pv->display();
		}
		else if(account.at(1)=='P'){
			BasePlus b(name,account,balance);
        	pv=&b;
        	for(int i=1;i<=4;i++){
	            int m;
	            cin>>m;
	            if(i%2)
	                pv->deposit(m);
	            else
	                pv->withdraw(m);
        	}
        	pv->display();
		}
            
    }
    return 0;
}
