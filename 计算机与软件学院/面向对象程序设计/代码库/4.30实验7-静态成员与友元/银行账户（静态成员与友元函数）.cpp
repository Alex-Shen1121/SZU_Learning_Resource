#include<iostream>
using namespace std;
class Account {
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
public:
	Account();
	Account(string accno, string name, float balance);
	~Account();
	void setAccount(string accno, string name, float balance);
	void Deposit(float amount);
	void Withdraw(float amount);
	float GetBalance();
	void Show();
	friend void Update(Account& a);
	static int GetCount();
	static float GetInterestRate();
	static void setRateAndCountnum(float rate, int num);
};

int Account::count = 0;
float Account::InterestRate = 0;

int main() {
	float rate;
	int num;
	cin >> rate >> num;
	Account::setRateAndCountnum(rate, num);
	Account* acc;
	acc = new Account[num];
	for (int i = 0; i < num; i++) {
		string accno, name;
		float balance;
		float dep, draw;
		cin >> accno >> name >> balance >> dep >> draw;
		acc[i].setAccount(accno, name, balance);
		acc[i].Deposit(dep);
		acc[i].Show();
		Update(acc[i]);
		cout << acc[i].GetBalance() << " ";
		acc[i].Withdraw(draw);
		cout << acc[i].GetBalance() << endl;
	}
	float sum = 0;
	for (int i = 0; i < num; i++) {
		sum += acc[i].GetBalance();
	}
	cout << sum << endl;
	return 0;
}

Account::Account()
{
	_accname = "";
	_accno = "";
	_balance = 0;
}

Account::Account(string accno, string name, float balance)
{
	_accname = name;
	_accno = accno;
	_balance = balance;
}

Account::~Account()
{
}

void Account::setAccount(string accno, string name, float balance)
{
	_accname = name;
	_accno = accno;
	_balance = balance;
}

void Account::Deposit(float amount)
{
	_balance += amount;
}

void Account::Withdraw(float amount)
{
	_balance -= amount;
}

float Account::GetBalance()
{
	return _balance;
}

void Account::Show()
{
	cout << _accno << " " << _accname << " " << _balance << " ";
}

int Account::GetCount()
{
	return count;
}

float Account::GetInterestRate()
{
	return InterestRate;
}

void Account::setRateAndCountnum(float rate, int num)
{
	count = num;
	InterestRate = rate;
}

void Update(Account& a)
{
	a._balance *= (1 + Account::InterestRate);
}

