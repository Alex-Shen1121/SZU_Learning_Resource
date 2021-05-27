#include<iostream>
#include<queue>
using namespace std;
struct People{
	int priority;
	int num;
	bool operator<(const People p) const{
		return priority < p.priority;
	}
};

int main() {
	int t;
	while (cin >> t) {
		int num = 0;
		string opt;
		int a, priority;
		People p;
		priority_queue<People> q1;
		priority_queue<People> q2;
		priority_queue<People> q3;
		while (t--) {			
			cin >> opt;
			if (opt == "IN") {
				num++;
				cin >> a >> priority;
				p.num = num;
				p.priority = priority;
				if (a == 1)
					q1.push(p);
				else if (a == 2)
					q2.push(p);
				else if (a == 3)
					q3.push(p);
			}
			else if (opt == "OUT") {
				cin >> a;
				if (a == 1) {
					if (q1.empty())
						cout << "EMPTY" << endl;
					else {
						p = q1.top();
						cout << p.num << endl;
						q1.pop();
					}
				}
				else if (a == 2) {
					if (q2.empty())
						cout << "EMPTY" << endl;
					else {
						p = q2.top();
						cout << p.num << endl;
						q2.pop();
					}
				}
				else if (a == 3) {
					if (q3.empty())
						cout << "EMPTY" << endl;
					else {
						p = q3.top();
						cout << p.num << endl;
						q3.pop();
					}
				}
			}
		}		
	}
	return 0;
}
