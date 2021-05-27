#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	multimap<string,string> m;
	string name;
	string phonenum;
	int t, opt;
	cin >> t;
	while (t--) {
		cin >> name >> phonenum;
		m.insert(pair<string, string>(name, phonenum));
	}
	cin >> t;
	while (t--) {
		cin >> opt;
		switch (opt) {
		case 1: {
			cin >> name;
			cout << m.count(name) << endl;
			break;
		}
		case 2: {
			cin >> name;
			if (m.find(name) != m.end()) {
				for (auto it = m.lower_bound(name); it != m.upper_bound(name); it++) {
					cout << it->second << endl;
				}
			}
			else
				cout << "None" << endl;
			break;
		}
		}
	}
	return 0;
}
