2016150201:Problem1119:ÕıÈ·
#include<iostream>
using namespace std;
class BaseAccount{
	protected:
		string name;
		string id;
		int bal;
	public:
		BaseAccount(string na,string ids,int b):name(na),id(ids),bal(b){
		}
	    void deposit(int n){
	    	bal=bal+n;
		}
		void virtual withdraw(int n){
			if(n>bal)
			cout<<"insufficient"<<endl;
			else
			bal=bal-n;
		}
		void virtual display(){
		cout<<name<<" "<<id<<" Balance:"<<bal<<endl;	
		}	
};
class BasePlus:public BaseAccount{
	int limit;
public:
	BasePlus(string na,string ids,int b):BaseAccount(na,ids,b){
		limit=5000;
}
	void virtual deposit(int n){
       bal=bal+n;
	}
	void virtual withdraw(int n){
		if(n>bal+limit)
		cout<<"insufficient"<<endl;
		else
		bal=bal-n;
		if(bal<0){
			limit=limit+bal;
			bal=0;
		}		
	}
	void virtual display(){
	cout<<name<<" "<<id<<" Balance:"<<bal<<" limit:"<<limit<<endl;	
	}	
};
int main(){
	int t,n,n1,m,m1;
	string na,ids;
	BaseAccount *BA; 
	int bal;
	cin>>t;
	while(t--){
	cin>>na>>ids>>bal;
	cin>>n>>m>>n1>>m1;
	if(ids[1]=='A'){
	BaseAccount ba(na,ids,bal);
	BA=&ba;
	BA->deposit(n);
	BA->withdraw(m);
	BA->deposit(n1);
	BA->withdraw(m1);
	BA->display();
	}
	else if(ids[1]=='P'){
	BasePlus bp(na,ids,bal);
	BA=&bp;
	BA->deposit(n);
	BA->withdraw(m);
	BA->deposit(n1);
	BA->withdraw(m1);	
	BA->display();	
	}
}
}
