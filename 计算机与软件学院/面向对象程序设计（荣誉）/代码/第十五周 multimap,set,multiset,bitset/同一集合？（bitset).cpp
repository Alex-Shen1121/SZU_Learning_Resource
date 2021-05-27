#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<bitset>
using namespace std;

int main() {
	int t;
	cin >> t;
	bitset<10000>* s = new bitset<10000>[t];
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int data;
			cin >> data;
			s[i][data] = 1;
		}
	}
	int t2;
	cin >> t2;
	while (t2--) {
		int a, b;
		int k = 0;
		cin >> a >> b;
		bitset<10000> num1, num2;
		num1[a] = 1;
		num2[b] = 1;
		for (int i = 0; i < t; i++) {
			if ((num1 & s[i]).any() && (num2 & s[i]).any()) {
				k++;
				if (k == 1) {
					cout << i + 1;
				}
				else
					cout << " " << i + 1;
			}
		}
		if (k == 0)
			cout << "no";
		cout << endl;
	}
	return 0;
}
