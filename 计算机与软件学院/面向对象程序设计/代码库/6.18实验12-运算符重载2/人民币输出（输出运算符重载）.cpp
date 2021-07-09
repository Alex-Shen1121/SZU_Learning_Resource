#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class money {
	double m;
public:
	money(double a = 0) {
		m = a;
	}
	friend ostream& operator<<(ostream& out, const money& obj);
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		double a;
		cin >> a;
		money m(a);
		cout << m << endl;
	}
}

ostream& operator<<(ostream& out, const money& obj)
{
	string m = to_string(obj.m);
	out << "yuan=" << m[0] << " jiao=" << m[2] << " fen=" << m[3];
	return out;
}

