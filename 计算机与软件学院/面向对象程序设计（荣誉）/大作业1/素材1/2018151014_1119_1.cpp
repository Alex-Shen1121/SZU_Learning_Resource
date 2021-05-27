2018151014:Problem1119:ÕýÈ·
#include <iostream>
#include <string>

using namespace std;

class BaseAccount {
public:
	BaseAccount(string n, string acc, float b) : name(n), account(acc), balance(b) {
		
	}
	
	virtual void deposit(int s) {
		balance += s;
	}
	
	virtual void withdraw(int s) {
		
		if (s > balance) {
			cout << "insufficient\n";
			return;
		}
		else {
			balance -= s;
		}
	}
	
	virtual void display() {
		cout << name << ' ' << account << " Balance:" << balance << endl;
	}
protected:
	string name;
	string account;
	float balance;
};

class BasePlus : public BaseAccount {
public:
	BasePlus(string name, string acc, float b) : BaseAccount(name, acc, b) {
		limit = 5000;
		limit_sum = 0;
	}
	
	void deposit(int s) {
		if (limit_sum != 0) {
			if (limit + s >= 5000) {
				balance = limit + s - 5000;
				limit = 5000;
				limit_sum = 0;
			}
			else {
				limit += s;
				limit_sum -= s;
			}
		}
		else {
			balance += s;
		}
	}
	
	void withdraw(int s) {
		if (s > balance) {
			int sub = s - balance;
			if (sub <= limit) {
				balance = 0;
				limit_sum += sub;
				limit -= sub;
			}
			else {
				cout << "insufficient\n";
			}
		}
		else {
			balance -= s;
		}
	}
	
	void display() {
		cout << name << ' ' << account << " Balance:" << balance << " limit:" << limit << endl;
	}
private:
	int limit;
	int limit_sum;
};

int main(void) {
	
	int t;
	cin >> t;
	while (t--) {
		BaseAccount *ptr;
		string name;
		string acc;
		float balance;
		
		cin >> name >> acc >> balance;
		
		if (acc[1] == 'A') {
			ptr = new BaseAccount(name, acc, balance);
			
			int in1, out1, in2, out2;
			cin >> in1 >> out1 >> in2 >> out2;
			ptr->deposit(in1);
			ptr->withdraw(out1);
			ptr->deposit(in2);
			ptr->withdraw(out2);
			ptr->display();
			delete ptr;
		}
		else if (acc[1] == 'P') {
			ptr = new BasePlus(name, acc, balance);
			
			int in1, out1, in2, out2;
			cin >> in1 >> out1 >> in2 >> out2;
			
			ptr->deposit(in1);
			ptr->withdraw(out1);
			ptr->deposit(in2);
			ptr->withdraw(out2);
			ptr->display();
			delete ptr;
		}
		
	}
	
	return 0;
}
