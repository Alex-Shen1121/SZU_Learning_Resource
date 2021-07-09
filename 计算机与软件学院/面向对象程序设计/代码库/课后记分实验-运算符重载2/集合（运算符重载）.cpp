#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class set {
private:
	int* data;
	int n;
public:
	set(int size = 10, int* num = NULL) {
		data = new int[size];
		n = size;
		if (num)
			for (int i = 0; i < size; i++)
				data[i] = num[i];
	}
	friend ostream& operator<<(ostream& out, set& s);
	/*set operator+(set& rhs) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.push_back(data[i]);
		}
		for (int i = 0; i < rhs.n; i++) {
			if (find(v.begin(), v.end(), rhs.data[i]) == v.end()) {
				v.push_back(rhs.data[i]);
			}
		}
		int* num = new int[v.size()];
		for (int i = 0; i < v.size(); i++) {
			num[i] = v[i];
		}
		set temp(v.size(), num);
		return temp;
	}*/
	friend set operator+(set lhs, set rhs);
	set operator*(set& rhs) {
		vector<int> v1, v;
		for (int i = 0; i < rhs.n; i++) {
			v1.push_back(rhs.data[i]);
		}
		for (int i = 0; i < n; i++) {
			if (find(v1.begin(), v1.end(), data[i]) != v1.end()) {
				v.push_back(data[i]);
			}
		}
		int* num = new int[v.size()];
		for (int i = 0; i < v.size(); i++) {
			num[i] = v[i];
		}
		set temp(v.size(), num);
		return temp;
	}
	set operator-(set& rhs) {
		vector<int> v1, v;
		for (int i = 0; i < rhs.n; i++) {
			v1.push_back(rhs.data[i]);
		}
		for (int i = 0; i < n; i++) {
			if (find(v1.begin(), v1.end(), data[i]) == v1.end()) {
				v.push_back(data[i]);
			}
		}
		int* num = new int[v.size()];
		for (int i = 0; i < v.size(); i++) {
			num[i] = v[i];
		}
		set temp(v.size(), num);
		return temp;
	}
	set& operator=(set& rightValue) {
		if (data) {
			delete[]data;
			data = NULL;
		}
		data = new int[rightValue.n];
		for (int i = 0; i < rightValue.n; i++)
			data[i] = rightValue.data[i];
		return *this;
	}
};

ostream& operator<<(ostream& out, set& s)
{
	for (int i = 0; i < s.n; i++) {
		if (i == 0)
			out << s.data[i];
		else
			out << " " << s.data[i];
	}
	return out;
}

set operator+(set lhs, set rhs)
{
	vector<int> v;
	for (int i = 0; i < lhs.n; i++) {
		v.push_back(lhs.data[i]);
	}
	for (int i = 0; i < rhs.n; i++) {
		if (find(v.begin(), v.end(), rhs.data[i]) == v.end()) {
			v.push_back(rhs.data[i]);
		}
	}
	int* num = new int[v.size()];
	for (int i = 0; i < v.size(); i++) {
		num[i] = v[i];
	}
	set temp(v.size(), num);
	return temp;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n1, n2, * data1, * data2, data;
		cin >> n1;
		data1 = new int[n1];
		for (int i = 0; i < n1; i++) {
			cin >> data;
			data1[i] = data;
		}
		set A(n1, data1);
		cin >> n2;
		data2 = new int[n2];
		for (int i = 0; i < n2; i++) {
			cin >> data;
			data2[i] = data;
		}

		set B(n2, data2);
		set s1 = A + B;
		set s2 = A * B;
		set s4 = (A - B) + (B - A);
		cout << "A:" << A << endl;
		cout << "B:" << B << endl;
		cout << "A+B:" << s1 << endl;
		cout << "A*B:" << s2 << endl;
		cout << "(A-B)+(B-A):" << s4 << endl;
		cout << endl;
	}
}



