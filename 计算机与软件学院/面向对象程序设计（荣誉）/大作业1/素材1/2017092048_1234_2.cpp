2017092048:Problem1234:ÕýÈ·
// May.27, 2019
// Author: Wenzhuo Dong
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

class Group {
public:
	virtual int add(int x, int y) = 0;
	virtual int sub(int x, int y) = 0;
};

class GroupA :public Group {
public:
	GroupA() {};
	int add(int x, int y) {
		return x + y;
	}
	int sub(int x, int y) {
		return x - y;
	}
};

class GroupB :public Group {
public:
	GroupB() {};
	int add(int x, int y) {
		return x + y;
	}
	int sub(int x, int y) {
		int res = 0;
		stack<int> stk;
		int a, b;
		while (x != 0) {
			a = x % 10 + 10;
			b = y % 10;
			stk.push((a - b) % 10);
			x /= 10;
			y /= 10;
		}
		while (!stk.empty()) {
			res = res * 10;
			res += stk.top();
			stk.pop();
		}
		return res;
	}

};

class GroupC :public Group {
public:
	GroupC() {};
	int add(int x, int y) {
		int res = 0;
		stack<int> stk;
		int a, b;
		while (x != 0 || y != 0) {
			a = x % 10;
			b = y % 10;
			stk.push((a + b) % 10);
			x /= 10;
			y /= 10;
		}
		while (!stk.empty()) {
			res = res * 10;
			res += stk.top();
			stk.pop();
		}
		return res;
	}
	int sub(int x, int y) {
		int res = 0;
		stack<int> stk;
		int a, b;
		while (x != 0) {
			a = x % 10 + 10;
			b = y % 10;
			stk.push((a - b) % 10);
			x /= 10;
			y /= 10;
		}
		while (!stk.empty()) {
			res = res * 10;
			res += stk.top();
			stk.pop();
		}
		return res;
	}

};
int main() {
	int samples;
	cin >> samples;

	Group *pg;
	int type;
	string input;
	while (samples--) {
		cin >> type >> input;
		switch (type) {
		case 1:
			pg = new GroupA;
			break;
		case 2:
			pg = new GroupB;
			break;
		case 3:
			pg = new GroupC;
			break;
		default:
			pg = new GroupA;
		}

		// get number and opt from input
		int n1, n2;
		n1 = n2 = 0;
		char opt;
		int i = 0;
		for (i = 0; input[i] != '+' && input[i] != '-'; ++i) {
			n1 = n1 * 10;
			n1 += input[i] - '0';
		}
		opt = input[i];
		for (i = i + 1; i < input.length(); ++i) {
			n2 = n2 * 10;
			n2 += input[i] - '0';
		}
		// end
		// calculate
		int res = 0;
		if (opt == '+')
			res = pg->add(n1, n2);
		else
			res = pg->sub(n1, n2);

		cout << res << endl;
	}

	return 0;
}

