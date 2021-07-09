#include<iostream>
#include<iomanip>
using namespace std;

class CVector {
	int* data;
	int n;
	static int sum;
public:
	CVector() {
		n = 5;
		data = new int[n];
		data[0] = 0;
		data[1] = 1;
		data[2] = 2;
		data[3] = 3;
		data[4] = 4;
		sum += 10;
	}
	CVector(int n, int* p) {
		this->n = n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = p[i];
			sum += data[i];
		}
	}
	CVector(const CVector& C) {
		n = C.n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = C.data[i];
			sum += data[i];
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
	}
	float Average() {
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum / n;
	}
	friend CVector Add(const CVector V1, const CVector V2);
	static void printSum() {
		cout << sum << endl;
	}
	static void clearSum() {
		sum = 0;
	}
};

class CStudent {
	string name; 
	CVector score; 
public:
	CStudent(string name1,int n1,int* a1):name(name1),score(n1,a1) {
	}
	void print() {
		cout << name << " ";
		score.print();
		cout << " " << fixed << setprecision(2) << score.Average() << endl;

	}
};

int CVector::sum = 0;

int main() {
	string name;
	while (cin>>name) {
		int t;
		cin >> t;
		int* data = new int[t];
		for (int i = 0; i < t; i++)
			cin >> data[i];
		CStudent STU(name, t, data);
		STU.print();
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

