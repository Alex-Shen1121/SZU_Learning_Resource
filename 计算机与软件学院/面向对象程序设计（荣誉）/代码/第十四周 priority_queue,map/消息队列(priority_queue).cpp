#include<iostream>
#include<queue>
using namespace std;
struct Event{
	int priority;
	string event, parameter;
	bool operator<(const Event p) const{
		return priority > p.priority;
	}
};

int main() {
	string opt;
	priority_queue<Event> q1;
	while (cin >> opt) {
		int priority;
		string event, parameter;
		Event p;
		if (opt == "PUT") {
			cin >> event >> parameter >> priority;
			p.event = event;
			p.parameter = parameter;
			p.priority = priority;
			q1.push(p);
		}
		else if (opt == "GET") {
			if (q1.empty())
				cout << "EMPTY" << endl;
			else {
				p = q1.top();
				cout << p.event << " " << p.parameter << endl;
				q1.pop();
			}
		}
	}
	return 0;
}
