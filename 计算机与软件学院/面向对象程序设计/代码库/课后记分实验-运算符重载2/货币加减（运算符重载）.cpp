#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class Money {
private:
	int yuan, jiao, fen;
public:
	Money(int a = 0, int b = 0, int c = 0) :yuan(a), jiao(b), fen(c) {};
	Money operator+=(Money& obj) {
		fen += obj.fen;
		if (fen >= 10) {
			fen -= 10;
			jiao++;
		}
		jiao += obj.jiao;
		if (jiao >= 10) {
			jiao -= 10;
			yuan++;
		}
		yuan += obj.yuan;
		return *this;
	}
	Money operator-=(Money& obj) {
		fen -= obj.fen;
		if (fen < 0) {
			fen += 10;
			jiao--;
		}
		jiao -= obj.jiao;
		if (jiao < 0) {
			jiao += 10;
			yuan--;
		}
		yuan -= obj.yuan;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Money& obj) {
		out << obj.yuan << "Ôª" << obj.jiao << "½Ç" << obj.fen<<"·Ö";
		return out;
	}
	friend istream& operator>>(istream& in, Money& obj) {
		in >> obj.yuan >> obj.jiao >> obj.fen;
		return in;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Money obj;
		cin >> obj;
		string opt;
		cin >> opt;
		while (opt != "stop") {
			if (opt == "add") {
				Money temp;
				cin >> temp;
				obj += temp;
			}
			else if (opt == "minus") {
				Money temp;
				cin >> temp;
				obj -= temp;
			}
			cin >> opt;
		}
		cout << obj << endl;
	}
	return 0;
}



