#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

class Group {
public:
	virtual int add(int x, int y) = 0;//输出加法的运算结果
	virtual int sub(int x, int y) = 0;//输出减法的运算结果
};

class GroupA :public Group {
public:
	int add(int x, int y) {
		return x + y;
	}
	int sub(int x, int y) {
		return x - y;
	}
};

class GroupB :public Group {
public:
	int add(int x, int y) {
		return x + y;
	}
	int sub(int x, int y) {
		int x1 = x, y1 = y;
		int sum = 0;
		int j = 0;
		while (y1 != 0) {
			int temp;
			temp = x1 % 10 - y1 % 10;
			if (temp < 0)
				temp += 10;
			x1 = (x1 - x1 % 10) / 10;
			y1 = (y1 - y1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		while (x1 != 0) {
			int temp;
			temp = x1 % 10;
			x1 = (x1 - x1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		return sum;
	}
};

class GroupC :public Group {
public:
	int add(int x, int y) {
		int x1 = x, y1 = y;
		int sum = 0;
		int j = 0;
		while (y1 != 0) {
			int temp;
			temp = x1 % 10 + y1 % 10;
			if (temp > 10)
				temp -= 10;
			x1 = (x1 - x1 % 10) / 10;
			y1 = (y1 - y1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		while (x1 != 0) {
			int temp;
			temp = x1 % 10;
			x1 = (x1 - x1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		return sum;
	}
	int sub(int x, int y) {
		int x1 = x, y1 = y;
		int sum = 0;
		int j = 0;
		while (y1 != 0) {
			int temp;
			temp = x1 % 10 - y1 % 10;
			if (temp < 0)
				temp += 10;
			x1 = (x1 - x1 % 10) / 10;
			y1 = (y1 - y1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		while (x1 != 0) {
			int temp;
			temp = x1 % 10;
			x1 = (x1 - x1 % 10) / 10;
			sum += pow(10, j) * temp;
			j++;
		}
		return sum;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Group* p;
		int type;
		char c;
		int x, y;
		cin >> type >> x >> c >> y;
		switch (type) {
		case 1: {
			GroupA obj;
			p = &obj;
			if (c == '+')
				cout << p->add(x, y) << endl;
			else if (c == '-')
				cout << p->sub(x, y) << endl;
			break;
		}
		case 2: {
			GroupB obj;
			p = &obj;
			if (c == '+')
				cout << p->add(x, y) << endl;
			else if (c == '-')
				cout << p->sub(x, y) << endl;
			break;
		}
		case 3: {
			GroupC obj;
			p = &obj;
			if (c == '+')
				cout << p->add(x, y) << endl;
			else if (c == '-')
				cout << p->sub(x, y) << endl;
			break;
		}
		}
	}	
	return 0;
}
