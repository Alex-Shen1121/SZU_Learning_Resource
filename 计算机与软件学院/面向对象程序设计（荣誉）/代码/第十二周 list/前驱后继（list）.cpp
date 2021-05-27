#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	list<int>L1;
	while (n--) {
		int data;
		cin >> data;
		L1.push_back(data);
	}
	while (m--) {
		int n;
		cin >> n;
		auto it = find(begin(L1), end(L1), n);
		if (n == L1.front())
			cout << *(++it) << endl;
		else if (n == L1.back())
			cout << *(--it) << endl;
		else {
			cout << *(--it) << " ";
			cout << *(++(++it)) << endl;
		}
	}
	return 0;
}
