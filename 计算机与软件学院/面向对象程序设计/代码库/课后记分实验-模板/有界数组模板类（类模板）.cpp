#include<iostream>
#include<algorithm>
#include<map>
using namespace std;


template<class T>
void func(T* data, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
	T x;
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (data[i] == x) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
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
		else if (ch == 'D') {
			double* data = new double[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			func(data, n);
		}
	}
	return 0;
}
