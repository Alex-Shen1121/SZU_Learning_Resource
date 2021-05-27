#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	set<int> s;
	int t1, t2;
	while (cin >> t1 >> t2) {
		s.clear();
		while (t1--) {
			int data;
			cin >> data;
			s.insert(data);
		}
		while (t2--) {
			int data;
			cin >> data;
			s.insert(data);
		}
		for (auto x : s) {
			if (x == *s.begin())
				cout << x;
			else
				cout << " " << x;
		}
		cout << endl;
	}

	
	return 0;
}
