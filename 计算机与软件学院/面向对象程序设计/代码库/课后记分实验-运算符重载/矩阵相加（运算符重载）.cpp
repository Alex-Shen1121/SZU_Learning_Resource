#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class CMatrix {
	int** matrix;
	int m, n;
public:
	CMatrix() { m = n = 0; matrix = NULL; }
	CMatrix(int a, int b) :m(a), n(b) {
		matrix = new int* [m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0;
	}
	CMatrix(int a, int b, int** array) :m(a), n(b) {
		matrix = new int* [m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = array[i][j];
	}
	CMatrix(const CMatrix& obj) :m(obj.m), n(obj.n) {
		matrix = new int* [m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = obj.matrix[i][j];
	}
	~CMatrix() {
		if (matrix) {
			for (int i = 0; i < m; i++)
				delete[] matrix[i];
			delete[]matrix;
		}
	}
	CMatrix& operator =(const CMatrix& obj) {
		if (matrix) {
			for (int i = 0; i < m; i++)
				delete[] matrix[i];
			delete[]matrix;
		}
		m = obj.m; n = obj.n;
		matrix = new int* [m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = obj.matrix[i][j];
		return *this;
	}
	int* operator [] (int index) {
		return matrix[index];
	}
	CMatrix operator +(const CMatrix& obj) {
		CMatrix temp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
		return temp;
	}
	CMatrix operator -(const CMatrix& obj) {
		CMatrix temp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				temp.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
		return temp;
	}
	CMatrix operator *(const CMatrix& obj) {
		CMatrix temp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					temp.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
		return temp;
	}
	void print() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		int** array;
		array = new int* [m];
		for (int i = 0; i < m; i++) {
			array[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> array[i][j];
		CMatrix obj1(m, n, array);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> array[i][j];
		CMatrix obj2(m, n, array);
		CMatrix obj3 = obj1;
		obj3 = obj1 + obj2;
		obj3.print();
	}	
}
