#include<iostream>
#include<map>
using namespace std;

template <class T>
class List {
private:
	T data[100];
	int n;
public:
	List(T* a = NULL, int b = 0) {
		n = b;
		for (int i = 0; i < 100; i++) {
			if (i < n) {
				data[i] = a[i];
			}
			else
				data[i] = -1;
		}
	}
	void Insert() {
		int pos;
		T x;
		cin >> pos >> x;
		for (int i = n; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = x;
		n++;
	};
	void Delete() {
		int pos;
		cin >> pos;
		for (int i = pos; i < n; i++) {
			data[i] = data[i + 1];
		}
		data[n - 1] = -1;
		n--;
	}
	void Print() {
		cout << data[0];
		for (int i = 1; i < n; i++)
			cout << " " << data[i];
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;
	int* data1 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data1[i];
	List<int> a(data1, n);
	a.Insert();
	a.Delete();
	a.Print();
	cin >> n;
	double* data2 = new double[n];
	for (int i = 0; i < n; i++)
		cin >> data2[i];
	List<double> b(data2, n);
	b.Insert();
	b.Delete();
	b.Print();
}

