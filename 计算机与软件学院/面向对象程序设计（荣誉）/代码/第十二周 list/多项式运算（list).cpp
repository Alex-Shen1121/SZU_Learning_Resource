#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
struct node
{
	//系数
	int coef;
	//指数
	int expn;
};
 
list<node> add(const list<node>& p1, const list<node>& p2) {
	list<node> ans;
	node data;
	auto it1 = begin(p1), it2 = begin(p2);
	while (it1 != end(p1) && it2 != end(p2)) {
		if (it1->expn < it2->expn) {
			data.expn = it1->expn;
			data.coef = it1->coef;
			it1++;
			if (data.coef != 0)
				ans.push_back(data);
		}
		else if (it1->expn > it2->expn) {
			data.expn = it2->expn;
			data.coef = it2->coef;
			it2++;
			if (data.coef != 0)
				ans.push_back(data);
		}
		else {
			data.expn = it1->expn;
			data.coef = it1->coef + it2->coef;
			it1++;
			it2++;
			if (data.coef != 0)
				ans.push_back(data);
		}
	}
	if (it1 == end(p1)) {
		for (; it2 != end(p2); it2++)
			ans.push_back(*it2);
	}
	else if (it2 == end(p2)) {
		for (; it1 != end(p1); it1++)
			ans.push_back(*it1);
	}
	return ans;
}

list<node> minus(const list<node>& p1, const list<node>& p2) {
	list<node> _p2 = p2;
	auto it = p2.begin();
	for_each(begin(_p2), end(_p2), [&it](node& p) {
		p.coef = -1 * it->coef;
		p.expn = it->expn;
		it++;
		});
	return add(p1, _p2);
}

list<node> multiply(const list<node>& p1, const list<node>& p2) {
	list<node> temp1;
	list<node> ans;
	for (auto it = p2.begin(); it != p2.end(); it++) {
		node temp;
		temp1.clear();
		for (auto it2 = p1.begin(); it2 != p1.end(); it2++) {
			temp.coef = it->coef * it2->coef;
			temp.expn = it->expn + it2->expn;
			temp1.push_back(temp);
		}
		ans = add(ans, temp1);
	}
	return ans;
}

void print(const list<node>& p1) {
	if (p1.size() == 0) {
		cout << "0" << endl;
		return;
	}
	for (auto it = p1.begin(); it != p1.end(); it++) {
		if (it == p1.begin()) {
			if (it->expn != 0 && it->expn != 1) {
				if (it->coef == 1) {
					cout << "x" << "^" << it->expn;
				}
				else if (it->coef == -1) {
					cout << "-" << "x" << "^" << it->expn;
				}
				else if (it->coef > 0) {
					cout << it->coef << "x" << "^" << it->expn;
				}
				else if (it->coef < 0) {
					cout << it->coef << "x" << "^" << it->expn;
				}
			}
			else if (it->expn == 0) {
				cout << it->coef;
			}
			else if (it->expn == 1) {
				if (it->coef > 0) {
					if (it->coef == 1) {
						cout << "x";
					}
					else
						cout << it->coef << "x";
				}
				else if (it->coef < 0) {
					if (it->coef == -1) {
						cout << "-" << "x";
					}
					else
						cout << it->coef << "x";
				}
			}
		}
		else {
			if (it->expn != 0 && it->expn != 1) {
				if (it->coef == 1) {
					cout << "+" << "x" << "^" << it->expn;
				}
				else if (it->coef == -1) {
					cout << "-" << "x" << "^" << it->expn;
				}
				else if (it->coef > 0) {
					cout << "+" << it->coef << "x" << "^" << it->expn;
				}
				else if (it->coef < 0) {
					cout << it->coef << "x" << "^" << it->expn;
				}
			}
			else if (it->expn == 0) {
				if (it->coef > 0)
					cout << "+" << it->coef;
				else
					cout << it->coef;
			}
			else if (it->expn == 1) {
				if (it->coef > 0) {
					if (it->coef == 1) {
						cout << "+" << "x";
					}
					else
						cout << "+" << it->coef << "x";
				}
				else if (it->coef < 0) {
					if (it->coef == -1) {
						cout << "-" << "x";
					}
					else
						cout << it->coef << "x";
				}
			}
		}
	}
	cout << endl;
}

int main() {
	list<node> poly1;
	list<node> poly2;
	list<node> ans;
	int n;
	cin >> n;
	while (n--) {
		poly1.clear();
		poly2.clear();
		int t;
		cin >> t;
		while (t--) {
			int ceof, expn;
			cin >> ceof >> expn;
			node data{ ceof,expn };
			poly1.push_back(data);
		}
		cin >> t;
		while (t--) {
			int ceof, expn;
			cin >> ceof >> expn;
			node data{ ceof,expn };
			poly2.push_back(data);
		}
		ans = ::add(poly1, poly2);	
		print(ans);
		ans = ::minus(poly1, poly2);
		print(ans);
		ans = ::multiply(poly1, poly2);
		print(ans);
	}
	return 0;
}
