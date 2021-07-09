#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
using namespace std;

string cal(int n) {
	if (n == 0)
		return "0";
	stack<int>s;
	string s1;
	while (n != 0) {
		s.push(n % 4);
		n /= 4;
	}
	while (!s.empty()) {
		s1.push_back(s.top() + '0');
		s.pop();
	}
	return s1;
}

class FourNum {
	string num;
	int value;
public:
	FourNum() {
		num = "0";
		value = 0;
	}
	FourNum(string n) {
		num = n;
		value = 0;
		for (int i = 0; i < n.length(); i++) {
			value += (n[n.length() - i - 1 ] - '0')* pow(4, i);
		}
	}
	FourNum operator+(FourNum& n) {
		FourNum temp;
		temp.value = value + n.value;
		temp.num = cal(temp.value);
		return temp;
	}
	string printNum() {
		return num;
	}
};

int main()
{
	int n;
	cin >> n;
	FourNum* f = new FourNum[n];
	string num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		f[i] = FourNum(num);
	}
	FourNum ans;
	for (int i = 0; i < n; i++) {
		ans = ans + f[i];
	}
	cout << ans.printNum() << endl;
	return 0;
}


