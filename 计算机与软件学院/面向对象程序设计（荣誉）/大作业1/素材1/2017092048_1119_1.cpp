2017092048:Problem1119:ÕýÈ·
// May.27, 2019
// Author: Wenzhuo Dong
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

class Base {
protected:
public:
	Base() {}
	~Base() {}
	virtual void display() = 0;
	virtual bool deposit(double) = 0;
	virtual bool withdraw(double) = 0;
};

class BaseAccount :public Base {
protected:
	string name;
	string account;
	double balance;
public:
	BaseAccount() {}

	BaseAccount(const string &name, const string &account, double balance) : name(name), account(account),
		balance(balance) {};
	bool deposit(double m) {
		balance = balance + m;
		return true;
	}
	bool withdraw(double m) {
		if ((balance - m) >= 0) {
			balance = balance - m;
			return true;
		}
		else {
			cout << "insufficient" << endl;
			return false;
		}
	}
	void display() {
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};

class BasePlus :public BaseAccount {
protected:
	double limit;
	double limit_sum;
public:
	BasePlus(const string &name, const string &account, double balance, double limit) : BaseAccount(name, account,
		balance),
		limit(limit) {
		limit_sum = 0;
	};
	bool deposit(double m) {
		balance = balance + m;
		return true;
	}
	bool withdraw(double m) {
		if ((balance + limit - m) >= 0) {
			double blc = balance - m;
			if (blc >= 0) {
				balance = blc;
			}
			else {
				balance = 0;
				limit = limit + blc;
				limit_sum = limit_sum + (-blc);
			}
			return true;
		}
		else {
			cout << "insufficient" << endl;
			return false;
		}
	}

	void display() {
		cout << name << " " << account << " Balance:" << balance << " limit:" << limit << endl;
	}
};

int main() {
	int samples;
	cin >> samples;
	Base *pb;

	string name;
	string acc;
	double blc, lim;

	while (samples--) {

		cin >> name >> acc;
		if (acc[1] == 'A') {
			cin >> blc;
			pb = new BaseAccount(name, acc, blc);
		}
		else {
			cin >> blc;
			pb = new BasePlus(name, acc, blc, 5000);
		}

		// acc create completed;

		double a, b, c, d;
		cin >> a >> b >> c >> d;

		pb->deposit(a);
		pb->withdraw(b);
		pb->deposit(c);
		pb->withdraw(d);

		pb->display();
	}
	return 0;
}

