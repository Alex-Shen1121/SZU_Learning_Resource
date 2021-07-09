#include<iostream>
#include<algorithm>
#include<map>
using namespace std;


template<class T>
void func(T* data, T* data2, int n) {
	for (int i = 0; i < n; i++) {
		cout << data2[i];
	}
	for (int i = 0; i < n; i++) {
		cout << data[i];
	}
	cout << endl;
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
			int* data2 = new int[n];
			for (int i = 0; i < n; i++)
				cin >> data2[i];
			func(data, data2, n);
		}
		else if (ch == 'C') {
			char* data = new char[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			char* data2 = new char[n];
			for (int i = 0; i < n; i++)
				cin >> data2[i];
			func(data, data2, n);
		}
		else if (ch == 'D') {
			double* data = new double[n];
			for (int i = 0; i < n; i++)
				cin >> data[i];
			double* data2 = new double[n];
			for (int i = 0; i < n; i++)
				cin >> data2[i];
			func(data, data2, n);
		}
	}
	return 0;
}
