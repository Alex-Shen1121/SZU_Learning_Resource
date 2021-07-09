#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//class stack {
//public:
//	int* sp, top, max;
//	void inflate(int lenth);
//private:
//	stack(int size = 10);
//	int pop();
//	void push(int value);
//	stack& operator=(stack& rightValue);
//	void show();
//};

int main() {
	stack<int> a, b, c, d, e;
	int t1, t2, data;
	cin >> t1 >> t2;
	while (t1--) {
		cin >> data;
		a.push(data);
	}
	while (t2--) {
		cin >> data;
		b.push(data);
	}
	b.pop();
	c = b;
	while (!c.empty()) {
		d.push(c.top());
		c.pop();
	}
	while (!d.empty()) {
		cout << d.top();
		d.pop();
	}
	cout << endl;
	swap(a, b);
	c = b;
	while (!c.empty()) {
		e.push(c.top());
		c.pop();
	}
	while (!e.empty()) {
		cout << e.top();
		e.pop();
	}
	cout << endl;
}
