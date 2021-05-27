2018152114:Problem1129:ÕýÈ·
#include <iostream>
#include <string>
using namespace std;

class NCard
{
protected:
	int ID;
	string CName;
	int Counter;

public:
	void initial(int id, string name, int counter);
	int save(int n);
	int take(int n);
	virtual void info();
};

class TCard : public NCard
{
protected:
	int Tcounter;

public:
	void initial(int id, string name, int counter, int tcounter);
	int transfer(int n);
	virtual void info();
};

class VCard : public NCard
{
protected:
	int Credit;

public:
	void initial(int id, string name, int counter, int credit);
	int over(int n);
	virtual void info();
};

void NCard::initial(int id, string name, int counter)
{
	ID = id;
	CName = name;
	Counter = counter;
}

int NCard::save(int n)
{
	if (n < 0)
		return -1;

	Counter += n;

	return 1;
}

int NCard::take(int n)
{
	if (n < 0 || n > Counter) 
		return -1;

	Counter -= n;

	return 1;
}

void NCard::info()
{
	cout << ID << "-" << CName << "-" << Counter;
}

void TCard::initial(int id, string name, int counter, int tcounter)
{
	Tcounter = tcounter;
	NCard::initial(id, name, counter);
}

int TCard::transfer(int n)
{
	if (n < 0 || n > Counter)
		return -1;

	Counter -= n;
	Tcounter += n;

	return 1;
}

void TCard::info()
{
	NCard::info();
	cout << "-" << Tcounter;
}

void VCard::initial(int id, string name, int counter, int credit)
{
	Credit = credit;
	NCard::initial(id, name, counter);
}

int VCard::over(int n)
{
	if (n < 0 || n > Counter + Credit)
		return -1;

	n -= Counter;
	Counter = 0;
	Credit -= n;

	return 1;
}

void VCard::info()
{
	NCard::info();
	cout << "-" << Credit;
}

void show(NCard & obj)
{
	obj.info();
	cout << endl;
}

int main()
{
	int id;
	string name;
	int balance;
	int tcounter, credit;

	NCard nc;
	TCard tc;
	VCard vc;

	cin >> id >> name >> balance;
	nc.initial(id, name, balance);

	cin >> id >> name >> balance >> tcounter;
	tc.initial(id, name, balance, tcounter);

	cin >> id >> name >> balance >> credit;
	vc.initial(id, name, balance, credit);

	int num;

	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		nc.save(num);
	}

	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		nc.take(num);
	}

	cin >> num;
	tc.save(num);

	cin >> num;
	tc.take(num);

	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		tc.transfer(num);
	}

	cin >> num;
	vc.save(num);

	cin >> num;
	vc.take(num);

	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		vc.over(num);
	}

	show(nc);
	show(tc);
	show(vc);

	return 0;
}
