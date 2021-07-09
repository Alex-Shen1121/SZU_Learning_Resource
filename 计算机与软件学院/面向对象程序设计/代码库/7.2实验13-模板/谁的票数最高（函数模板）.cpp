#include<iostream>
#include<map>
using namespace std;


template<class T>
void func(T* data, int n) {
	map<T, int> m;
	for (int i = 0; i < n; i++) {
		m[data[i]] += 1;
	}
	int max = m.begin()->second;
	T x = m.begin()->first;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			x = it->first;
		}
	}
	cout << x << " " << max << endl;
	return;
}

int main() {
	int n;
	char ch;
	int t;
	cin >> t;
	while (t--) {
		cin >> ch;
		cin >> n;
		if (ch == 'I') {
			int* data = new int[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			func(data, n);
		}
		else if (ch == 'C') {
			char* data = new char[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			func(data, n);
		}
		else if (ch == 'S') {
			string* data = new string[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			func(data, n);
		}
	}
	return 0;
}
