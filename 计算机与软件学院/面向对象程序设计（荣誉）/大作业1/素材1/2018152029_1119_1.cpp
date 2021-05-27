2018152029:Problem1119:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;

class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string n, string a, int b) :name(n), account(a), balance(b) {}
	void deposit(int m)
	{
		balance += m;
	}
	virtual void withdraw(int m)
	{
		if (balance >= m)
			balance -= m;
		else
			cout << "insufficient" << endl;
	}
	virtual void display()
	{
		cout << name << " " << account << " " << "Balance:" << balance << endl;
	}
};

class BasePlus :public BaseAccount
{
	int limit = 5000, limit_sum = 0;
public:
	BasePlus(string n, string a, int b) :BaseAccount(n, a, b) {}
	void deposit(int m)
	{
		if (limit != 5000)
		{
			limit += m;
			if (limit > 5000)
				m = limit - 5000, limit = 5000;
			else m = 0;
		}
		balance += m;
	}
	void withdraw(int m)
	{
		if (balance + limit < m)
		{
			cout << "insufficient" << endl;
			return ;
		}
		if (balance>=m)
		{
			balance -= m;
		}
		else
		{
			m -= balance;
			balance = 0;
			limit -= m;
		}
	}
	void display()
	{
		cout << name << " " << account << " " << "Balance:" << balance << " limit:" << limit - limit_sum << endl;
	}
};
int main()
{
	int T;
	cin >> T;
	BaseAccount *p;
	while (T--)
	{
		string name, account;
		int balance, money;
		cin >> name >> account >> balance;
		if (account.substr(0, 2) == "BA")
			p = new BaseAccount(name, account, balance);
		else
			p = new BasePlus(name, account, balance);
		cin >> money;
		p->deposit(money);
		cin >> money;
		p->withdraw(money);
		cin >> money;
		p->deposit(money);
		cin >> money;
		p->withdraw(money);
		p->display();
		delete p;
	}
	//system("pause");
	return 0;
}

