#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class CXGraph {
	int n;
public:
	CXGraph(int a):n(a){}
	CXGraph& operator++() {
		if (n == 21)
			return *this;
		n+=2;
		return *this;
	}
	CXGraph& operator++(int) {
		if (n == 21)
			return *this;
		CXGraph temp(*this);
		n += 2;
		return temp;
	}
	CXGraph& operator--() {
		if (n == 1)
			return *this;
		n-=2;
		return *this;
	}
	CXGraph& operator--(int) {
		if (n == 1)
			return *this;
		CXGraph temp = *this;
		n-=2;
		return temp;
	}
	friend ostream& operator<<(ostream& out, CXGraph obj);
};

int main() {
	int t, n;
	string command;
	cin >> n;
	CXGraph xGraph(n);
	cin >> t;
	while (t--) {
		cin >> command;
		if (command == "show++")
			cout << xGraph++ << endl;
		else if (command == "++show")
			cout << ++xGraph << endl;
		else if (command == "show--")
			cout << xGraph-- << endl;
		else if (command == "--show")
			cout << --xGraph << endl;
		else if (command == "show")
			cout << xGraph << endl;
	}
	return 0;
}

ostream& operator<<(ostream& out, CXGraph obj)
{
	int i, k;
	for (i = obj.n, k = 0; i >= 1; i -= 2, k++) {
		for (int j = 0; j < k; j++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "X";
		}
		out << endl;
	}
	if (obj.n != 1) {
		for (i = 3, k -= 2; i <= obj.n; i += 2, k--) {
			for (int j = 0; j < k; j++) {
				cout << " ";
			}
			for (int j = 0; j < i; j++) {
				cout << "X";
			}
			out << endl;
		}
	}	
	return out;
}

