#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	vector<int>a;
	while (cin >> n >> m) {
		a.clear();
		for (int i = 0; i < 2 * n; i++) {
			a.push_back(i);
		}//初始化容器
		
		int badpos = 0;
		for (int i = 0; i < n; i++) {
			badpos = (ba dpos + m - 1) % a.size();
			a.erase(a.begin() + badpos);
		}//删除坏人位置，留下好人位置
		vector<int>::iterator it = a.begin();
		for (int i = 0; i < 2 * n; i++) {
			//*it为下一个好人位号码
			if (i == *it) {
				cout << "G";
				if (it != a.end() - 1)
					it++;
			}
			else
				cout << "B";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
