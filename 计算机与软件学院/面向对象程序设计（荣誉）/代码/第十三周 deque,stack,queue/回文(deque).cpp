#include<stack>
#include<iostream>
using namespace std;

void func1() {
	int n, i;
	cin >> n;
	stack<int>s;
	int data;
	//ջ�ڴ���ǰһ������
	for (i = 0; i < n / 2; i++) {		
		cin >> data;
		s.push(data);
	}
	//�������м�Ϊ��������
	if (i != (float)n / 2)
		cin >> data;
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		if (data == s.top()) {
			s.pop();
			continue;
		}
		else {
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
	return;
}

void func2() {
	int n, i;
	cin >> n;
	stack<char>s;
	char data;
	//ջ�ڴ���ǰһ������
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		s.push(data);
	}
	//�������м�Ϊ��������
	if (i != (float)n / 2)
		cin >> data;
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		if (data == s.top()) {
			s.pop();
			continue;
		}
		else {
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
	return;
}

void func3() {
	int n, i;
	cin >> n;
	stack<string>s;
	string data;
	//ջ�ڴ���ǰһ������
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		s.push(data);
	}
	//�������м�Ϊ��������
	if (i != (float)n / 2)
		cin >> data;
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		if (data == s.top()) {
			s.pop();
			continue;
		}
		else {
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
	return;
}

void func4() {
	int n, i;
	cin >> n;
	stack<double>s;
	double data;
	//ջ�ڴ���ǰһ������
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		s.push(data);
	}
	//�������м�Ϊ��������
	if (i != (float)n / 2)
		cin >> data;
	for (i = 0; i < n / 2; i++) {
		cin >> data;
		if (data == s.top()) {
			s.pop();
			continue;
		}
		else {
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		cin >> type;
		switch (type) {
		case 'i': func1(); break;
		case 'c': func2(); break;
		case 's': func3(); break;
		case 'd': func4(); break;
		}
	}
	return 0;
}
