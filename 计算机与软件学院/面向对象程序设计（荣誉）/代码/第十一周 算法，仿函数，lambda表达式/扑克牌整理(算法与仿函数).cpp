#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Card {
public:
	int val;
	string color;
	Card() {
		color = "";
		val = 0;
	}
	Card(string str, int v) {
		color = str;
		val = v;
	}
};

class mySort {
public:
	bool operator()(const Card& a, const Card& b) {
		return a.val < b.val;
	}
};

class myPrint {
public:
	void operator()(const Card& a) {
		cout << a.color << " " << a.val << endl;
	}
};

int main() {
	int t;
	vector<Card> v;
	vector<Card> v2;
	while (cin >> t) {
		v.clear();	
		while (t--) {
			string color;
			int val;
			cin >> color >> val;
			Card temp(color, val);
			v.push_back(temp);
		}
		int n;
		cin >> n;
		while (n--) {
			string color;
			int val;
			cin >> color >> val;
			int count = 0;
			for (vector<Card>::iterator it = begin(v); it != end(v); it++) {
				if (it->color == color && it->val >= val) {
					count++;
					v2.push_back(*it);
				}
			}
			if (count != 0) {
				sort(begin(v2), end(v2), mySort());
				for_each(begin(v2), end(v2), myPrint());
			}			
			cout << count << endl;

			v2.clear();
		}
	}
	return 0;
}
