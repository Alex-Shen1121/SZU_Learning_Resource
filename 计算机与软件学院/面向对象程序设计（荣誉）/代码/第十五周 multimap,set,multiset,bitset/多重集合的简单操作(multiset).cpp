#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	multiset<int> s;
	int t, opt, data;
	cin >> t;
	while (t--) {
		cin >> opt;
		switch (opt) {
		case 1: {
			cin >> data;
			s.insert(data);
			break;
		}
		case 2: {
			if (!s.empty())
				s.erase(s.begin());
			break;
		}
		case 3: {
			if (!s.empty())
				cout << *s.rbegin() << endl;
			break;
		}
		}
	}
	return 0;
}
