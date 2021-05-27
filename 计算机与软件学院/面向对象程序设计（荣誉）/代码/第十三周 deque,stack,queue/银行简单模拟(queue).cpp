#include<iostream>
#include<queue>
using namespace std;

int main() {
	int t;
	queue<int> a;
	queue<int> b;
	cin >> t;
	while (t--) {
		int data;
		cin >> data;
		if (data % 2 == 0)
			b.push(data);
		else
			a.push(data);
	}
	while (a.size() != 0 && b.size() != 0) {
		cout << a.front() << " ";
		a.pop();
		cout << a.front() << " ";
		a.pop();
		cout << b.front() << " ";
		b.pop();
	}
	if (a.empty()) {
		while (!b.empty()) {
			cout << b.front() << " ";
			b.pop();
		}
	}
	else if (b.empty()) {
		while (!a.empty()) {
			cout << a.front() << " ";
			a.pop();
		}
	}
	return 0;
}
