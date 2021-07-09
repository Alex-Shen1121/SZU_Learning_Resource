#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

class BaseAccount {
protected:
	string name, account;
	double balance;
public:
	BaseAccount() {
		balance = 0;
	}
	BaseAccount(string n,string a,double b) {
		name = n;
		account = a;
		balance = b;
	}
	void set(string n, string a, double b) {
		name = n;
		account = a;
		balance = b;
	}
	virtual void deposit(double m) {
		balance += m;
	}
	virtual void withdraw(double m) {
		if (m > balance) {
			cout << "insufficient" << endl;
			return;
		}
		else {
			balance -= m;
		}
		return;
	}
	virtual void display() {
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};

class BasePlus :public BaseAccount {
protected:
	const double limit = 5000;
	double limit_sum;
public:
	BasePlus() {};
	BasePlus(string n, string a, double b) :BaseAccount(n, a, b) {
		limit_sum = 5000;
	}
	void set(string n, string a, double b) {
		name = n;
		account = a;
		balance = b;
		limit_sum = 5000;
	}
	void deposit(double m) {
		if (limit_sum < limit) {
			double temp = limit - limit_sum;
			if (m <= temp) {
				limit_sum += m;
				return;
			}
			else {
				limit_sum = 5000;
				balance += m - temp;
				return;
			}
		}
		else
			balance += m;
		return;
	}
	void withdraw(double m) {
		if (m > balance + limit_sum) {
			cout << "insufficient" << endl;
			return;
		}
		else {
			if (m <= balance) {
				balance -= m;
				return;
			}
			else {
				limit_sum -= m - balance;
				balance = 0;
				return;
			}
		}
	}
	virtual void display() {
		cout << name << " " << account << " Balance:" << balance << " limit:" << limit_sum << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string name, account;
		double balance;
		BaseAccount obj;
		BasePlus obj1;
		BaseAccount* p = &obj;
		cin >> name >> account >> balance;
		if (account.find("BA") != string::npos) {
			obj.set(name, account, balance);
			p = &obj;
		}
		else if (account.find("BP") != string::npos) {
			obj1.set(name, account, balance);
			p = &obj1;
		}
		if (p != NULL) {
			double a, b, c, d;
			cin >> a >> b >> c >> d;
			p->deposit(a);
			p->withdraw(b);
			p->deposit(c);
			p->withdraw(d);
			p->display();
		}		
	}
	return 0;
}
