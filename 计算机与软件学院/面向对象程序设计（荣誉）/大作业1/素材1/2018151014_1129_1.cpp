2018151014:Problem1129:ÕýÈ·
#include <iostream>

using namespace std;

class Card {
public:
	
	void initial(int id, char ch, int b) {
		ID = id;
		name = ch;
		balance = b;
	}
	
	int deposit(int s) {
		if (s <= 0) {
			return -1;
		}
		balance += s;
		return 1;
	}
	
	virtual int take(int s) {
		if (s <= 0 || s > balance) {
			return -1;
		}
		balance -= s;
		return 1;
	}
	
	virtual void info() {
		cout << ID << '-' << name << '-' << balance << endl;
	}
	
protected:
	int ID;
	char name;
	int balance;
};

class TransCard : public Card {
public:
	void initial(int id, char ch, int b, int t_b) {
		ID = id;
		name = ch;
		balance = b;
		t_balance = t_b;
	}
	
	int transfer(int s) {
		if (s > balance) {
			return -1;
		}
		
		balance -= s;
		t_balance += s;
	}
	
	void info() {
		cout << ID << '-' << name << '-' << balance << '-' << t_balance << endl;
	}
	
private:
	int t_balance;
};

class VIPCard : public Card {
public:
	void initial(int id, char ch, int b, int cre) {
		ID = id;
		name = ch;
		balance = b;
		credit = cre;
	}
	
	int take(int s) {
		if (s > balance) {
			if (s > balance + credit) {
				return -1;
			}
			else {
				int loss = s - balance;
				balance = 0;
				credit -= loss;
				return 1;
			}
		}
		else {
			balance -= s;
		}
	}
	
	void info() {
		cout << ID << '-' << name << '-' << balance << '-' << credit << endl;
	}
private:
	int credit;
};

void show(Card &obj) {
	obj.info();
}

int main(void) {
	
	int ID;
	char name;
	int balance;
	int t_balance;
	int credit;
	
	Card c1;
	TransCard c2;
	VIPCard c3;
	
	cin >> ID >> name >> balance;
	c1.initial(ID, name, balance);
	cin >> ID >> name >> balance >> t_balance;
	c2.initial(ID, name, balance, t_balance);
	cin >> ID >> name >> balance >> credit;
	c3.initial(ID, name, balance, credit);
	
	int a, b, c, d;
	// normal card
	{
		cin >> a >> b >> c >> d;
		c1.deposit(a);
		c1.deposit(b);
		c1.take(c);
		c1.take(d);
	}
	// trans card
	{
		cin >> a >> b >> c >> d;
		c2.deposit(a);
		c2.take(b);
		c2.transfer(c);
		c2.transfer(d);
	}
	// vip card
	{
		cin >> a >> b >> c >> d;
		c3.deposit(a);
		c3.take(b);
		c3.take(c);
		c3.take(d);
	}
	
	show(c1);
	show(c2);
	show(c3);
	return 0;
}
