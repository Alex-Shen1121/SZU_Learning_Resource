#include<iostream>
using namespace std;
class Account {
	int num;
	float balance;
	string type;
	float rate;
public:
	Account() {};
	Account(int n, string t, int b) {
		num = n;
		type = t;
		balance = b;
		rate = 0.5 / 100;
	}
	Account(const Account& Acc) {
		num = Acc.num + 50000000;
		type = Acc.type;
		balance = Acc.balance;
		rate = 1.5 / 100;
	}
	void fun1() {
		balance = balance * (1 + rate);
		cout << "Account=" << num << "--sum=" << balance << endl;
	}
	void fun2() {
		cout << "Account=" << num << "--" << gettype() << "--sum=" << balance << "--rate=" << rate << endl;
	}
	string gettype() {
		if (type == "P")
			return "Person";
		else if (type == "E")
			return "Enterprise";
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		float balance;
		string type;
		cin >> num >> type >> balance;
		Account ACC1(num, type, balance);
		Account ACC2(ACC1);
		string temp;
		cin >> temp;
		if (temp == "C")
			ACC1.fun1();
		else if (temp == "P")
			ACC1.fun2();
		cin >> temp;
		if (temp == "C")
			ACC2.fun1();
		else if (temp == "P")
			ACC2.fun2();
	}
	return 0;
}
