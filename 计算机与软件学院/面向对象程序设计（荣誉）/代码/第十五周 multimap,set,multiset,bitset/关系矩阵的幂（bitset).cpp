#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<bitset>
using namespace std;
void printMulti(bitset<50>*& a, bitset<50>*& b, bitset<50>*& ans, int t) {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if ((a[i] & b[j]).any())
				ans[i].set(j, 1);
			else
				ans[i].set(j, 0);
		}
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}

void show(int t) {
	for (int i = 0; i < t; i++)
		cout << "-";
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		int t;
		cin >> t;
		//ÐÐ´¢´æ
		auto s1 = new bitset<50>[t];
		//ÁÐ´¢´æ
		auto s2 = new bitset<50>[t];
		//´ð°¸
		auto ans1 = new bitset<50>[t];
		auto ans2 = new bitset<50>[t];
		auto ans3 = new bitset<50>[t];
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				int data;
				cin >> data;
				s1[i].set(j, data);
				s2[j].set(i, data);
			}
		}
		printMulti(s1, s2, ans1, t);
		show(t);
		printMulti(ans1, s2, ans2, t);
		show(t);
		printMulti(ans2, s2, ans3, t);
		cout << endl;
	}

	return 0;
}
