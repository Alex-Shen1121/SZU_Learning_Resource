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
	//Ѱ����߷�
	float max = v[0];	
	for (it = v.begin(); it != v.end(); it++) {
		if (*it > max)
			max = *it;
	}
	//�޸ķ���
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
	//�洢����
	storeVector(v);
	
	//�޸�����
	rewriteVector(v);
	//��ӡ����
	printVector(v);
	system("pause");
	return 0;
}
