#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<string>
using namespace std;

class  Ccomplex
{
private:
	int image, real;
public:
	friend void func(Ccomplex& data);
	friend istream& operator>>(istream& in, Ccomplex& obj);
};

istream& operator>>(istream& cin, Ccomplex& obj) {
	cin >> obj.real >> obj.image;
	return cin;
}

void func(Ccomplex& data) {
	cout << data.image;
	if (data.real > 0)
		cout << '+' << data.real << endl;
	else
		cout << data.real << endl;
}

template<class T>
void func(T x) {
	ostringstream os;
	string s, s2;
	os << x;
	s = os.str();
	auto pos = s.find(' ');
	if (s[0] == '-') {
		reverse(s.begin() + 1, s.end());
		auto it = s.begin() + 1;
		while (*it == '0') {
			s.erase(it);
		}
		cout << s << endl;
	}
	else {
		reverse(s.begin(), s.end());
		auto it = s.begin();
		while (*it == '0') {
			s.erase(it);
		}
		cout << s << endl;
	}
}

int main() {
	char ch;
	int t;
	cin >> t;
	while (t--) {
		cin >> ch;
		if (ch == 'I') {
			int n;
			cin >> n;
			func(n);
		}
		else if (ch == 'S') {
			string n;
			cin >> n;
			func(n);
		}
		else if (ch == 'D') {
			double n;
			cin >> n;
			func(n);
		}
		else if (ch == 'C') {
			Ccomplex n;
			cin >> n;
			func(n);
		}
	}
	return 0;
}
