#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class cmp {
public:
	bool operator()(const pair<int, int>p1, const pair<int, int>p2) const {
		return p1.second < p2.second;
	}
};

int main() {
	map<int, int> m;
	pair<int, int>p;
	int t;
	cin >> t;
	while (t--) {
		m.clear();
		int n;
		cin >> n;
		while (n--) {
			int data;
			cin >> data;
			m[data]++;
		}
		cout << max_element(m.begin(), m.end(), cmp())->first << " " << max_element(m.begin(), m.end(), cmp())->second << endl;
	}

	return 0;
}
