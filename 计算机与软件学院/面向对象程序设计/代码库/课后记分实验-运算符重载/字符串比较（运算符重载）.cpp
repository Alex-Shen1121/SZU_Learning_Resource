#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

class str {
	char* p;
public:
	str() {
		p = NULL;
	}
	str(char* s) {
		p = new char[strlen(s) + 1];
		strcpy(p, s);
	}
	friend bool operator>(str& s1, str& s2);
	friend bool operator<(str& s1, str& s2);
	friend bool operator==(str& s1, str& s2);
	void show() {
		cout << p << endl;
	}
};

bool operator>(str& s1, str& s2)
{
	if (strcmp(s1.p, s2.p) > 0)
		return true;
	else
		return false;
}

bool operator<(str& s1, str& s2)
{
	if (strcmp(s1.p, s2.p) < 0)
		return true;
	else
		return false;
}

bool operator==(str& s1, str& s2)
{
	if (strcmp(s1.p, s2.p) == 0)
		return true;
	else
		return false;
}

int main() {
	char p[3][50];
	cin.getline(p[0], 50);
	cin.getline(p[1],50);
	cin.getline(p[2], 50);
	str A(p[0]), B(p[1]), C(p[2]);
	if (A > B)
		A.show();
	else
		B.show();
	if (A < C)
		A.show();
	else
		C.show();
	if (B == C)
		B.show();
	else
		C.show();
}

//int main() {
//	string A, B, C;
//	getline(cin, A);
//	getline(cin, B);
//	getline(cin, C);
//	if (A > B)
//		cout << A << endl;
//	else
//		cout << B << endl;
//	if (A < C)
//		cout << A << endl;
//	else
//		cout << C << endl;
//	if (B == C)
//		cout << B << endl;
//	else
//		cout << C << endl;
//}
