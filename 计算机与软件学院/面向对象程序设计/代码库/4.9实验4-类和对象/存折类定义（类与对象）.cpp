#include<iostream>
#include<cstring>
using namespace std;
class CAccount
{
private:
	long account;
	char name[10];
	float balance;
public:
	CAccount(long a, char n[10], float b);
	void deposit(int num);
	void withdraw(int num);
	void check();
};

CAccount::CAccount(long a, char n[10], float b)
{
	account = a;
	strcpy(name, n);
	balance = b;
}

void CAccount::deposit(int num)
{
	balance += num;
	cout << "saving ok!" << endl;
}

void CAccount::withdraw(int num)
{
	if (num > balance)
		cout << "sorry! over limit!" << endl;
	else
	{
		balance -= num;
		cout << "withdraw ok!" << endl;
	}
}

void CAccount::check()
{
	cout << name << "'s balance is " << balance << endl;
}

int main()
{
	int n = 2;
	while (n--)
	{
		long a;
		char n[10];
		float b;
		int temp;
		cin >> a >> n >> b;
		CAccount People(a, n, b);
		People.check();
		cin >> temp;
		People.deposit(temp);
		People.check();
		cin >> temp;
		People.withdraw(temp);
		People.check();
	}
	return 0;
}
