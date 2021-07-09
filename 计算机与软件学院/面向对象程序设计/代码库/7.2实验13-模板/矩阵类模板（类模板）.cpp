#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

template <class T>
class Matrix {
private:
	T matrix[100][100];
	int a, b;
public:
	Matrix(T** d, int A, int B) {
		a = A;
		b = B;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				matrix[i][j] = d[i][j];
	}
	void transport() {
		T temp[100][100];
		for (int i = 0; i < b; i++)
			for (int j = 0; j < a; j++)
				temp[i][j] = matrix[j][i];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				matrix[i][j] = temp[i][j];
		swap(a, b);
	}
	void Print() {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}			
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		if (ch == 'I') {
			int** data;
			data = new int* [a];
			for (int i = 0; i < a; i++)
				data[i] = new int[b];
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					cin >> data[i][j];
			Matrix<int> m(data, a, b);
			m.transport();
			m.Print();
		}
		else if (ch == 'D') {
			double** data;
			data = new double* [a];
			for (int i = 0; i < a; i++)
				data[i] = new double[b];
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					cin >> data[i][j];
			Matrix<double> m(data, a, b);
			m.transport();
			m.Print();
		}
		else if (ch == 'C') {
			char** data;
			data = new char* [a];
			for (int i = 0; i < a; i++)
				data[i] = new char[b];
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					cin >> data[i][j];
			Matrix<char> m(data, a, b);
			m.transport();
			m.Print();
		}
	}
}

