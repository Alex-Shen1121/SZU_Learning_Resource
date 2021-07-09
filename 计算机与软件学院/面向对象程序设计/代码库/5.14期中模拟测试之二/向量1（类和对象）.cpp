#include <iostream>
using namespace std;

class CVector {
	int* data;
	int n;
public:
	CVector() {
		n = 5;
		data = new int[n];
		data[0] = 0;
		data[1] = 1;
		data[2] = 2;
		data[3] = 3;
		data[4] = 4;
	}
	CVector(int n, int* p) {
		this->n = n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = p[i];
		}
	}
	~CVector() {
		delete[]data;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			if (i == 0)
				cout << data[i];
			else
				cout << " " << data[i];
		}
		cout << endl;
	}
};

int main() {
	CVector C1;
	C1.print();
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	CVector C2(n, data);
	C2.print();
	return 0;
}
