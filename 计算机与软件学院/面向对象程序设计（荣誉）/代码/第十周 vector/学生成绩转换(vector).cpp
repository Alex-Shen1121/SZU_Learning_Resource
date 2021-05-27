#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void storeVector(vector<float>& v) {
	while (1) {
		int data;
		cin >> data;
		if (data == -1)
			break;
		v.push_back(data);
	}
}

void rewriteVector(vector<float>& v) {
	vector<float>::iterator it;
	//寻找最高分
	float max = v[0];	
	for (it = v.begin(); it != v.end(); it++) {
		if (*it > max)
			max = *it;
	}
	//修改分数
	for (it = v.begin(); it != v.end(); it++) {
		*it = *it / max * 100;
	}
}

void printVector(vector<float>& v) {
	for (vector<float>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	vector<float>v;
	//存储数据
	storeVector(v);
	
	//修改数据
	rewriteVector(v);
	//打印数据
	printVector(v);
	system("pause");
	return 0;
}
