#include <iostream>
using namespace std;

class Clock {
	int h, m, s;
public:
	Clock(int _h, int _m, int _s) :h(_h), m(_m), s(_s) {};
	Clock& operator++() {
		if (s == 59) {
			s = 0;
			m++;
		}
		else {
			s++;
		}
		if (m == 60) {
			m = 0;
			h++;
		}
		if (h == 12) {
			h = 0;
		}
		return *this;
	}
	Clock& operator--() {
		if (s == 0) {
			s = 59;
			m--;
		}
		else {
			s--;
		}
		if (m == -1) {
			m = 59;
			h--;
		}
		if (h == -1) {
			h = 11;
		}
		return *this;
	}
	void print() {
		cout << h << ":" << m << ":" << s << endl;
	}
};

int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	Clock c(h, m, s);
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x < 0) {
			x = -x;
			while (x--)
				--c;
		}
		else {
			while (x--)
				++c;
		}
		c.print();

	}
	return 0;
}

