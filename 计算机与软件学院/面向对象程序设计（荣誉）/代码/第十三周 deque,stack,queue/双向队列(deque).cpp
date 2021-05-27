#include<stack>
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
	int t;
	deque<int> q;
	vector<int> wrongOPT;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string opt;
		int data;
		cin >> opt;
		if (opt == "LIN") {
			cin >> data;
			q.push_front(data);
		}
		else if (opt == "RIN") {
			cin >> data;
			q.push_back(data);
		}
		else if (opt == "LOUT") {
			if (q.empty())
				wrongOPT.push_back(i);
			else
				q.pop_front();
		}
		else if (opt == "ROUT") {
			if (q.empty())
				wrongOPT.push_back(i);
			else
				q.pop_back();
		}
	}
	if (q.empty()) {
		cout << "EMPTY" << endl;
	}
	else {
		for (auto it = q.begin(); it != q.end(); it++)
			cout << *it << " ";
		cout << endl;
	}	
	for (auto it = wrongOPT.begin(); it != wrongOPT.end(); it++)
		cout << *it << " ERROR" << endl;
	return 0;
}
