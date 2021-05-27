2018152086:Problem1119:´ð°¸´íÎó
#include<iostream>

using namespace std;

class BaseAccount {
	protected:
		string name;
		string account;
		float balance;
	public:
		BaseAccount() {
		}
		BaseAccount(string a,string b,float c) {
			name=a;
			account=b;
			balance=c;
		}
		void virtual deposit(float a) {
			balance+=a;
		}
		void virtual withdraw(float a) {
			if(balance>=a)
				balance-=a;
			else
				cout<<"insufficient"<<endl;
		}
		void virtual display() {
			cout<<name<<' '<<account<<' '<<"Balance:"<<balance<<endl;
		}
};
class BasePlus:public BaseAccount {
	protected:
		int limit;
		int limit_sum;
	public:
		BasePlus(string a,string b,float c) {
			name=a;
			account=b;
			balance=c;
			limit=5000;
			limit_sum=0;
		}
		void virtual deposit(float a) {
			balance+=a;
		}
		void virtual withdraw(float a) {
			if((balance+limit-limit_sum)>=a) {
				if(balance>=a)
					balance-=a;
				else {
					limit_sum+=(a=balance);
					balance=0;
				}

			}
			else
				cout<<"insufficient"<<endl;
		}
		void virtual display() {
			cout<<name<<' '<<account<<' '<<"Balance:"<<balance<<' '<<"limit:"<<limit_sum<<endl;
		}
};

int main() {
	int t;
	string a;
	string b;
	float  c,Q,W,E,R;
	BaseAccount *P;
	cin>>t;
	while(t--) {
		cin>>a>>b>>c;
		cin>>Q>>W>>E>>R;
		if(b[1]=='A') {
			BaseAccount BA(a,b,c);
			P=&BA;
			P->deposit(Q);
			P->withdraw(W);
			P->deposit(E);
			P->withdraw(R);
			P->display();
		} else if(b[1]=='P') {
			BasePlus BP(a,b,c);
			P=&BP;
			P->deposit(Q);
			P->withdraw(W);
			P->deposit(E);
			P->withdraw(R);
			P->display();
		}
	}
	return 0;
}
