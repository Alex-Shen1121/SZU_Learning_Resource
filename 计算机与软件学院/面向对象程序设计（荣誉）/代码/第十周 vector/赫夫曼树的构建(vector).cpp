#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int max(int& a, int& b) {
	return a > b ? a : b;
}

int min(int& a, int& b) {
	return a < b ? a : b;
}

void setVector(vector<int>& v) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		v.push_back(data);
	}
}

int func(vector<int>& v) {
	int sum = 0;
	int j;
	//当容器元素个数为1，返回总费用
	if (v.size() == 1) {
		return sum = v[0];
	}
	while (true) {
		if (v.size() == 1)//当容器元素个数为1，循环结束
			break;
		int min1 = v[0], min2 = v[1];//最小值设为前两个数
		int mini1 = 0, mini2 = 1;//最小值的下标设为前两个数
		j = 2;
		for (vector<int>::iterator it = v.begin() + 2; it != v.end(); it++, j++) {//寻找最小值
			//如果*it比当前最小值都小，替换掉当前较大的最小值
			if (*it < min1 || *it < min2) {
				if (min1 > min2) {
					min1 = *it;
					mini1 = j;
				}
				else if (min1 < min2) {
					min2 = *it;
					mini2 = j;
				}
			}
		}
		//删除min1，min2，并添加min1+min2
		v.erase(v.begin() + max(mini1, mini2));
		v.erase(v.begin() + min(mini1, mini2));
		v.push_back(min1 + min2);
		//计算总费用
		sum += min1 + min2;
	}
	return sum;
}

int main() {
	vector<int>pi;
	//写入数据
	setVector(pi);
	//构造Huffman树并输出结果
	cout << func(pi) << endl;
	return 0;
}
