#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<cmath>
#define PI 3.14
using namespace std;

class CAccount {
protected:
	long account;
	char name[10];
	float balance;
public:
	CAccount(long ac, char* n, float b) {
		account = ac;
		strcpy(name, n);
		balance = b;
	}
	void deposit(float x) {		
		balance += x;
		cout << "saving ok!" << endl;
		check();
	}
	void withdraw(float x) {
		if (x > balance)
			cout << "sorry! over balance!" << endl;
		else {
			balance -= x;
			cout << "withdraw ok!" << endl;
		}
		check();
	}
	void check() {
		cout << "balance is " << balance << endl;
	}
};

class CCreditcard:public CAccount {
protected:
	float limit;
public:
	CCreditcard(long ac, char* n, float b, float l) :CAccount(ac, n, b) {
		limit = l;
	}
	void withdraw(float x) {
		if (x > balance + limit)
			cout << "sorry! over limit!" << endl;
		else {
			balance -= x;
			cout << "withdraw ok!" << endl;
		}
		check();
	}
};

int main() {
	long account;
	char name[10];
	float balance;
	float limit;
	float x;
	cin >> account >> name >> balance;
	CAccount Acc1(account, name, balance);
	Acc1.check();
	cin >> x;	
	Acc1.deposit(x);
	cin >> x;
	Acc1.withdraw(x);
	cin >> account >> name >> balance >> limit;
	CCreditcard Acc2(account, name, balance, limit);
	Acc2.check();
	cin >> x;
	Acc2.deposit(x);
	cin >> x;
	Acc2.withdraw(x);
	return 0;
}
