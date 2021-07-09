#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

class CBigInteger {
	char* num;
public:
	CBigInteger() {
		num = new char[1001];
	}
	CBigInteger(char* p) {
		num = new char[strlen(p) + 1];
		int i = 0;
		if (p[0] == '0' && p[1] != '\0')
			for (i = 0; p[i] == '0'; i++);
		strcpy(num, p + i);
	}
	friend istream& operator>>(istream& in, CBigInteger& Num);
	friend ostream& operator<<(ostream& out, CBigInteger Num);
	friend CBigInteger& operator+(const CBigInteger& lhs, const CBigInteger& rhs);
	friend CBigInteger& operator-(const CBigInteger& lhs, const CBigInteger& rhs);
	CBigInteger operator*(CBigInteger& r);
	friend bool operator>=(const CBigInteger& l, const CBigInteger& r);
	friend CBigInteger minus(CBigInteger t);
};

CBigInteger minus(CBigInteger t) {
	char p[2] = "-";
	char* data = new char[strlen(t.num) + 2];
	data[0] = '\0';
	strcat(data,p);
	strcat(data, t.num);
	CBigInteger temp(data);
	return temp;
}

char p[3] = "-1";
CBigInteger minusone(p);

int main() {
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;
	cin >> t;
	while (t--) {
		cin >> bigNum1 >> op >> bigNum2;
		cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
		if (op == '+') {
			cout << bigNum1 + bigNum2 << endl;
		}
		else if (op == '-') {
			cout << bigNum1 - bigNum2 << endl;
		}
		else if (op == '*') {
			cout << bigNum1 * bigNum2 << endl;
		}
	}
}

istream& operator>>(istream& in, CBigInteger& Num)
{
	char p[1001];
	in >> p;
	int i = 0;
	if (p[0] == '0' && p[1] != '\0')
		for (i = 0; p[i] == '0'; i++);
	strcpy(Num.num, p + i);
	return in;
}

ostream& operator<<(ostream& out, CBigInteger Num)
{
	if (Num.num[0] != '-')
		out << Num.num;
	else {
		out << '(' << Num.num << ')';
	}
	return out;
}

bool operator>=(const CBigInteger& l, const CBigInteger& r) {
	if (strlen(l.num) > strlen(r.num))
		return true;
	if (strlen(l.num) == strlen(r.num))
	{
		for (int i = 0; i < (int)strlen(l.num); i++)
			if (l.num[i] > r.num[i])
				return true;
			else if (l.num[i] < r.num[i])
				return false;
			else
				continue;
		return true;
	}
	return false;
}

CBigInteger& operator+(const CBigInteger& lhs, const CBigInteger& rhs)
{
	//正+正
	if (lhs.num[0] != '-' && rhs.num[0] != '-') {
		stack<int> a;
		stack<int> b;
		stack<int> ans;
		int i;
		for (i = 0; i < strlen(lhs.num); i++)
			a.push(lhs.num[i] - '0');
		for (i = 0; i < strlen(rhs.num); i++)
			b.push(rhs.num[i] - '0');
		while (!a.empty() && !b.empty()) {
			if (a.top() + b.top() >= 10) {				
				ans.push(a.top() + b.top() - 10);
				a.pop();				
				b.pop();
				if (!a.empty())
					a.top()++;
				else if (!b.empty())
					b.top()++;
				else
					ans.push(1);
			}
			else {
				ans.push(a.top() + b.top());
				a.pop();
				b.pop();
			}
		}
		if (a.empty()) {
			while (!b.empty()) {
				ans.push(b.top());
				b.pop();
			}			
		}
		else {
			while (!a.empty()) {
				ans.push(a.top());
				a.pop();
			}
		}
		char* answer = new char[ans.size() + 1];
		for (i = 0; !ans.empty(); i++) {
			answer[i] = ans.top() + '0';
			ans.pop();
		}
		answer[i] = '\0';
		CBigInteger temp(answer);
		return temp;
	}
	//负+负
	else if (lhs.num[0] == '-' && rhs.num[0] == '-') {
		stack<int> a;
		stack<int> b;
		stack<int> ans;
		int i;
		for (i = 1; i < strlen(lhs.num); i++)
			a.push(lhs.num[i] - '0');
		for (i = 1; i < strlen(rhs.num); i++)
			b.push(rhs.num[i] - '0');
		while (!a.empty() && !b.empty()) {
			if (a.top() + b.top() >= 10) {
				ans.push(a.top() + b.top() - 10);
				a.pop();
				b.pop();
				if (!a.empty())
					a.top()++;
				else if (!b.empty())
					b.top()++;
				else
					ans.push(1);
			}
			else {
				ans.push(a.top() + b.top());
				a.pop();
				b.pop();
			}
		}
		if (a.empty()) {
			while (!b.empty()) {
				ans.push(b.top());
				b.pop();
			}
		}
		else {
			while (!a.empty()) {
				ans.push(a.top());
				a.pop();
			}
		}
		char* answer = new char[ans.size() + 2];
		answer[0] = '-';
		for (i = 1; !ans.empty(); i++) {
			answer[i] = ans.top() + '0';
			ans.pop();
		}
		answer[i] = '\0';
		CBigInteger temp(answer);
		return temp;
	}
	//负+正
	else if (lhs.num[0] == '-' && rhs.num[0] != '-') {
		CBigInteger lhs2(lhs.num + 1);
		return rhs - lhs2;
	}
	//正+负
	else if (lhs.num[0] != '-' && rhs.num[0] == '-') {
		CBigInteger rhs2(rhs.num + 1);
		return lhs - rhs2;
	}
}

CBigInteger& operator-(const CBigInteger& lhs, const CBigInteger& rhs)
{
	//正-正
	if (lhs.num[0] != '-' && rhs.num[0] != '-') {
		if (lhs >= rhs) {
			stack<int> a;
			stack<int> b;
			stack<int> ans;
			int i;
			for (i = 0; i < strlen(lhs.num); i++)
				a.push(lhs.num[i] - '0');
			for (i = 0; i < strlen(rhs.num); i++)
				b.push(rhs.num[i] - '0');
			while (!a.empty() && !b.empty()) {
				if (a.top() - b.top() < 0) {
					ans.push(a.top() - b.top() + 10);
					a.pop();
					b.pop();
					if (!a.empty())
						a.top()--;
					else if (!b.empty())
						b.top()--;
				}
				else {
					ans.push(a.top() - b.top());
					a.pop();
					b.pop();
				}
			}
			if (a.empty()) {
				while (!b.empty()) {
					ans.push(b.top());
					b.pop();
				}
			}
			else {
				while (!a.empty()) {
					ans.push(a.top());
					a.pop();
				}
			}
			if (ans.top() == 0) {
				char answer[2] = "0";
				CBigInteger temp(answer);
				return temp;
			}
			char* answer = new char[ans.size() + 1];
			for (i = 0; !ans.empty(); i++) {
				answer[i] = ans.top() + '0';
				ans.pop();
			}
			answer[i] = '\0';
			CBigInteger temp(answer);
			return temp;
		}
		else {
			CBigInteger temp= ::minus(rhs - lhs);
			return temp;
		}
	}
	//正-负
	if (lhs.num[0] != '-' && rhs.num[0] == '-') {
		CBigInteger rhs2(rhs.num + 1);
		return lhs + rhs2;
	}
	//负-负
	if (lhs.num[0] == '-' && rhs.num[0] == '-') {
		CBigInteger rhs2(rhs.num + 1);
		return lhs + rhs2;
	}
	//负-正
	if (lhs.num[0] == '-' && rhs.num[0] != '-') {
		CBigInteger lhs2(lhs.num + 1);
		CBigInteger temp = ::minus(lhs2 + rhs);
		return temp;
	}
}

CBigInteger CBigInteger::operator*(CBigInteger& r) {
	CBigInteger res, temp1(this->num), temp2(r.num);
	char sign = '+';
	int len1 = strlen(temp1.num), len2 = strlen(temp2.num);

	if (this->num[0] == '0' || r.num[0] == '0')
	{
		res.num[0] = '0';
		res.num[1] = '\0';
		return res;
	}

	if (*this->num == '-' && *r.num == '-')//负数*负数
	{
		sign = '+';
		for (int tt = 1; tt < len1; tt++)
			temp1.num[tt - 1] = temp1.num[tt];
		temp1.num[len1 - 1] = '\0';
		for (int tt = 1; tt < len2; tt++)
			temp2.num[tt - 1] = temp2.num[tt];
		temp2.num[len2 - 1] = '\0';
		len1 = strlen(temp1.num), len2 = strlen(temp2.num);
	}
	else if (*this->num != '-' && *r.num != '-')//正数*正数
		sign = '+';
	else if (*this->num == '-' && *r.num != '-') //负数*正数
	{
		sign = '-';
		for (int tt = 1; tt < len1; tt++)
			temp1.num[tt - 1] = temp1.num[tt];
		temp1.num[len1 - 1] = '\0';
		len1 = strlen(temp1.num);
	}
	else if (*this->num != '-' && *r.num == '-')//正数*负数
	{
		sign = '-';
		for (int tt = 1; tt < len2; tt++)
			temp2.num[tt - 1] = temp2.num[tt];
		temp2.num[len2 - 1] = '\0';
		len2 = strlen(temp2.num);
	}

	int len3 = len1 + len2;
	for (int tt = 0; tt < len3; tt++)
		res.num[tt] = '0';
	res.num[len3] = '\0';
	for (int i = len1 - 1; i >= 0; i--) {
		int step = 0;
		for (int j = len2 - 1; j >= 0; j--) {
			int mul = (temp1.num[i] - '0') * (temp2.num[j] - '0');
			int sum = res.num[i + j + 1] - '0' + step + mul % 10;
			res.num[i + j + 1] = sum % 10 + '0';
			step = sum / 10 + mul / 10;
		}
		res.num[i] += step;
	}

	while (res.num[0] == '0' && len3 != 1)
	{
		for (int ii = 0; ii < len3; ii++)
			res.num[ii] = res.num[ii + 1];
		len3 = strlen(res.num);
	}

	if (sign == '-')
	{
		for (int tt = len3; tt >= 0; tt--)
			res.num[tt + 1] = res.num[tt];
		res.num[0] = sign;
	}
	return res;
}

