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
	CVector(const CVector& C) {
		n = C.n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = C.data[i];
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
	friend CVector Add(const CVector V1, const CVector V2);
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		int* data = new int[t];
		for (int i = 0; i < t; i++)
			cin >> data[i];
		CVector C1(t, data);
		for (int i = 0; i < t; i++)
			cin >> data[i];
		CVector C2(t, data);
		C1.print();
		C2.print();
		CVector Sum(Add(C1, C2));
		Sum.print();
	}
	return 0;
}

CVector Add(const CVector V1, const CVector V2)
{
	int n = V1.n;
	int* data = new int[n];
	for (int i = 0; i < n; i++)
		data[i] = V1.data[i] + V2.data[i];
	CVector TempV(n,data);
	return TempV;
}

