#include <iostream>
#include <list>
#include<functional>
using namespace std;

void print(list<int>& L) {
	cout << L.size();
	for (auto it = L.begin(); it != L.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
	return;
}

void Insert(list<int>*& L,int n) {
	int i, loc, e;
	cin >> i >> loc >> e;
	if (loc > L[i - 1].size() + 1 || loc < 1 || i < 1 || i > n) {
		print(L[i - 1]);
		return;
	}
	auto it = L[i - 1].begin();
	int n_ = loc - 1;
	while (n_--)
		it++;
	L[i - 1].insert(it, e);
	print(L[i - 1]);
	return;
}

void Delete(list<int>*& L, int n) {
	int i, loc;
	cin >> i >> loc;
	if (loc > L[i - 1].size() || loc < 1 || i < 1 || i > n) {
		print(L[i - 1]);
		return;
	}
	auto it = L[i - 1].begin();
	int n_ = loc - 1;
	while (n_--)
		it++;
	L[i - 1].erase(it);
	print(L[i - 1]);
	return;
}

void Merge(list<int>*& L, int n) {
	int i, j;
	cin >> i >> j; 
	if (j < 1 || j > n || i < 1 || i > n) {
		print(L[i - 1]);
		return;
	}
	L[i - 1].sort();
	L[j - 1].sort();
	L[i - 1].merge(L[j - 1]);
	print(L[i - 1]);
	return;
}

void Unique(list<int>*& L, int n) {
	int i;
	cin >> i;
	if (i < 1 || i > n) {
		print(L[i - 1]);
		return;
	}
	L[i - 1].sort(greater<int>());
	L[i - 1].unique();	
	print(L[i - 1]);
	return;
}

void Display(list<int>*& L, int n) {
	int i;
	cin >> i;
	if (i < 1 || i > n) {
		print(L[i - 1]);
		return;
	}
	cout << L[i - 1].size();
	for (auto it = L[i - 1].begin(); it != L[i - 1].end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
	return;
}

int main()
{
	int m;
	cin >> m;
	list<int>* L = new list<int>[m];
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		while (n--) {
			int data;
			cin >> data;
			L[i].push_back(data);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		string opt;
		cin >> opt;
		if (opt == "insert")
			Insert(L, m);
		else if (opt == "delete")
			Delete(L, m);
		else if (opt == "merge")
			Merge(L, m);
		else if (opt == "unique")
			Unique(L, m);
		else if (opt == "display")
			Display(L, m);
		else
			break;
	}
	return 0;
}
