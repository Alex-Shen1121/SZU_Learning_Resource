#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class myMatrix {
	int n;
	int** p;
public:
	myMatrix() {
		n = 0;
		p = NULL;
	}
	myMatrix(int n, int** data) {
		this->n = n;
		p = new int* [n];
		for (int i = 0; i < n; i++)
			p[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = data[i][j];
	}
	myMatrix(int n) {
		this->n = n;
		p = new int* [n];
		for (int i = 0; i < n; i++)
			p[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = 0;
	}
	myMatrix(const myMatrix& m) {
		n = m.n;
		p = new int* [n];
		for (int i = 0; i < n; i++)
			p[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = m.p[i][j];
	}
	void operator=(const myMatrix& m) {
		n = m.n;
		if (p) {
			for (int i = 0; i < n; i++)
				delete[]p[i];
			delete[] p;
		}
		p = new int* [n];
		for (int i = 0; i < n; i++)
			p[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = m.p[i][j];
	}
	myMatrix operator*(const myMatrix& m) {
		myMatrix temp(m.n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					temp.p[i][j] += p[i][k] * m.p[k][j];
		return temp;
	}
	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << p[i][j] << " ";
			cout << endl;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	myMatrix* m;
	m = new myMatrix[n];
	int N;
	cin >> N;
	for (int I = 0; I < n; I++) {
		int** data;
		data = new int* [N];
		for (int i = 0; i < N; i++)
			data[i] = new int[N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> data[i][j];
		m[I] = myMatrix(N, data);
	}
	myMatrix temp(m[0]);
	for (int I = 1; I < n; I++) {
		temp = temp * m[I];
	}
	temp.show();
	return 0;
}


