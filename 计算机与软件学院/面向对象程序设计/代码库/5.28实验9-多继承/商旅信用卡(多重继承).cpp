#include<iostream>
using namespace std;

class VIPcard {
protected:
	int VIPcardNum, VIPpoint;
public:
	VIPcard(int n) {
		VIPcardNum = n;
		VIPpoint = 0;
	}
	void order() {
		int m;
		cin >> m;
		VIPpoint += m;
	}
};

class Credit {
protected:
	int CreditNum, Limit, CreditPoint;
	string Name;
	float Bill;
public:
	Credit(int num, int li, string n) {
		CreditNum = num;
		Limit = li;
		CreditPoint = 0;
		Name = n;
		Bill = 0;
	}

};

class VIPandCredit :public VIPcard, public Credit {
public:
	VIPandCredit(int VIPnum, int  CreditNum, int limit, string name) :VIPcard(VIPnum), Credit(CreditNum, limit, name) {};
	void VIPorder() {
		float m;
		cin >> m;
		VIPpoint += (int)m;
		CreditPoint += (int)m;
		Bill += m;
	}
	void CreditPurchase() {
		float m;
		cin >> m;
		Bill += m;
		if (Bill > Limit) {
			Bill -= m;
			return;
		}	
		CreditPoint += (int)m;
	}
	void CreditRefund() {
		float m;
		cin >> m;
		Bill -= m;
		CreditPoint -= (int)m;
	}
	void PointExchange() {
		int n;
		cin >> n;
		CreditPoint -= n;
		VIPpoint += (n / 2);
	}
	void display() {
		cout << VIPcardNum << " " << VIPpoint << endl;
		cout << CreditNum << " " << Name << " " << Bill << " " << CreditPoint << endl;
	}
};

int main() {
	int VIPnum, CreditNum, limit;
	string name;
	cin >> VIPnum >> CreditNum >> name >> limit;
	VIPandCredit p1(VIPnum, CreditNum, limit, name);
	int t;
	cin >> t;
	while (t--) {
		char opt;
		cin >> opt;
		switch (opt) {
		case 'o':p1.VIPorder(); break;
		case 'c':p1.CreditPurchase(); break;
		case 'q':p1.CreditRefund(); break;
		case 't':p1.PointExchange(); break;
		}
	}
	p1.display();
	return 0;
}
