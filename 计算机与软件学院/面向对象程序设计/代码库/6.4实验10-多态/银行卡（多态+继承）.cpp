#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

class NCard {
protected:
	string ID, CName;
	int Counter;
public:
	NCard() {
		ID = "0";
		CName = "0";
		Counter = 0;
	}
	void initial(string id, string name, int counter) {
		ID = id;
		CName = name;
		Counter = counter;
	}
	int save(int m) {
		if (m < 0)
			return -1;
		Counter += m;
		return 1;
	}
	int take(int m) {
		if (m < 0 || m > Counter) {
			return -1;
		}
		Counter -= m;
		return 1;
	}
	virtual void info() {
		cout << ID << "-" << CName << "-" << Counter << endl;
	}
};

class TransCard :public NCard {
	int Tcounter;
public:
	void initial(string id, string name, int counter,int tcounter) {
		ID = id;
		CName = name;
		Counter = counter;
		Tcounter = tcounter;
	}
	int transfer(int m) {
		if (m < 0 || m > Counter) {
			return -1;
		}
		Counter -= m;
		Tcounter += m;
		return 1;
	}
	virtual void info() {
		cout << ID << "-" << CName << "-" << Counter << "-" << Tcounter << endl;
	}
};

class VIPcard :public NCard {
	int Credit;
public:
	void initial(string id, string name, int counter, int credit) {
		ID = id;
		CName = name;
		Counter = counter;
		Credit = credit;
	}
	int over(int m) {
		if (m < 0 || m > Counter + Credit) {
			return -1;
		}
		if (m > Counter) {
			m -= Counter;
			Counter = 0;
			Credit -= m;
		}
		else
			Counter -= m;
		return 1;
	}
	virtual void info() {
		cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;
	}
};

void show(NCard& obj) {
	obj.info();
}

int main() {
	string ID, CName;
	int Counter, Tcounter, Credit;
	NCard c1;
	TransCard c2;
	VIPcard c3;
	cin >> ID >> CName >> Counter;
	c1.initial(ID, CName, Counter);
	cin >> ID >> CName >> Counter >> Tcounter;
	c2.initial(ID, CName, Counter, Tcounter);
	cin >> ID >> CName >> Counter >> Credit;
	c3.initial(ID, CName, Counter, Credit);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c1.save(a);
	c1.save(b);
	c1.take(c);
	c1.take(d);
	show(c1);
	cin >> a >> b >> c >> d;
	c2.save(a);
	c2.take(b);
	c2.transfer(c);
	c2.transfer(d);
	show(c2);
	cin >> a >> b >> c >> d;
	c3.save(a);
	c3.take(b);
	c3.over(c);
	c3.over(d);
	show(c3);
	return 0;
}
