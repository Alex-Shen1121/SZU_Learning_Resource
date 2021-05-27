#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	queue<string> F;
	queue<string> M;
	while (t--)	{
		string name, sex;
		cin >> name >> sex;
		if (sex == "F")
			F.push(name);
		else if (sex == "M")
			M.push(name);
	}
	while (!F.empty() && !M.empty()) {
		cout << F.front() << " " << M.front() << endl;
		F.pop();
		M.pop();
	}
	if (F.size() == 0 && M.size() == 0)
		return 0;
	if (F.size() == 0) {
		cout << "M:" << M.size() << endl;
	}
	else if (M.size() == 0) {
		cout << "F:" << F.size() << endl;
	}
	return 0;
}
