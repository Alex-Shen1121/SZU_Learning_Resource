#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class CMP {
public:
	bool operator()(const string& s1, const string& s2) const {
		return s1 > s2;
	}
};


int main() {
	int t;
	while (cin >> t) {
		map<int, vector<string>> m;
		pair<int, vector<string>> p;
		vector<string> vname;
		string name, web;
		int num = 0, i = 0;
		while (t--) {
			cin >> name >> web;
			auto it = find(begin(vname), end(vname), name);
			if (it == end(vname)) {
				vname.push_back(name);
				m[num].push_back(web);
				num++;
			}
			else {
				m[it - begin(vname)].push_back(web);
			}
		}
		for (auto x : m) {
			cout << vname[x.first];
			for (auto y : x.second) {
				cout << " " << y;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
