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
	void setVector(int n, int* p) {
		this->n = n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = p[i];
		}
	}
	friend CVector Add(const CVector V1, const CVector V2);
	static void printSum() {
		cout << sum << endl;
	}
	static void clearSum() {
		sum = 0;
	}
	friend class CMatrix;
};

class CMatrix {
	int n;
	CVector* V;
public:
	CMatrix(int n1, int* data) {
		int i = 0;
		n = n1;
		int* temp = new int[n];
		V = new CVector[n];
		for (i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				temp[j] = data[i * n + j];
			V[i].setVector(n, temp);
		}
	}
	CVector Multi(const CVector& V1) {
		int* data = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += V[i].data[j] * V1.data[j];
			}			
			data[i] = sum;
		}
		CVector temp(n, data);
		return temp;
	}
	bool check(const CVector& V1) {
		if (n == V1.n)
			return true;
		else
			return false;
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
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		int* data1 = new int[t * t];
		for (int i = 0; i < t * t; i++)
			cin >> data1[i];
		CMatrix M1(t, data1);
		cin >> t;
		int* data2 = new int[t];
		for (int i = 0; i < t; i++)
			cin >> data2[i];
		CVector V1(t, data2);
		if (M1.check(V1)) {
			CVector Result(M1.Multi(V1));
			Result.print();
		}
		else
			cout << "error" << endl;
		
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

