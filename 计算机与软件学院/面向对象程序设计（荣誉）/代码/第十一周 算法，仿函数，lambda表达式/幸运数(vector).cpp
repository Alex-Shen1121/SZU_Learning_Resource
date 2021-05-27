#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int min_val, max_val;
	cin >> min_val >> max_val;
	vector<int> v;
	for (int i = 1; i < max_val; i++)
		v.push_back(i);
	int round = 1;
	int lucknumber = 2;
	while (lucknumber <= v.size()) {		
		int i = 0;
		auto it = remove_if(begin(v), end(v), [&i, lucknumber](int x)->bool {i++; return i % lucknumber == 0; });
		v.erase(it, end(v));
		round++;
		lucknumber = v[round - 1];
	}
	cout << count_if(begin(v), end(v), [min_val, max_val](int x)->bool {return x > min_val && x < max_val; }) << endl;
	return 0;
}
