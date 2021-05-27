#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Rec {
public:
	int id, length, width;
	Rec(int i, int l, int w) {
		id = i;
		length = max(l, w);
		width = min(l, w);
	}
	bool operator==(const Rec r) {
		if (id == r.id && length == r.length && width == r.width)
			return true;
		else
			return false;
	}

};

class mySort {
public:
	bool operator()(const Rec& a, const Rec& b) {
		if (a.id != b.id)
			return a.id < b.id;
		else if (a.id == b.id && a.length != b.length)
			return a.length < b.length;
		else if (a.id == b.id && a.length == b.length && a.width != b.width)
			return a.width < b.width;
	}
};


int main() {
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		vector<Rec> v;
		while (m--) {
			int id, length, width;
			cin >> id >> length >> width;
			Rec temp(id, length, width);
			v.push_back(temp);
		}
		//É¾³ýÖØ¸´ÔªËØ
		for (vector<Rec>::iterator it = begin(v); it != end(v);)
		{
			vector<Rec>::iterator it1 = find(it + 1, end(v), *it);
			if (it1 == end(v))
				it++;
			else
				v.erase(it1);
		}
		//ÅÅÐò
		sort(begin(v), end(v), mySort());
		//´òÓ¡
		for_each(begin(v), end(v), [](Rec r) {cout << r.id << " " << r.length << " " << r.width << endl; });
	}
	return 0;
}
