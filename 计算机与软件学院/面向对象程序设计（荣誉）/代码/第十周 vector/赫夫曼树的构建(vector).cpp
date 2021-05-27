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
	//������Ԫ�ظ���Ϊ1�������ܷ���
	if (v.size() == 1) {
		return sum = v[0];
	}
	while (true) {
		if (v.size() == 1)//������Ԫ�ظ���Ϊ1��ѭ������
			break;
		int min1 = v[0], min2 = v[1];//��Сֵ��Ϊǰ������
		int mini1 = 0, mini2 = 1;//��Сֵ���±���Ϊǰ������
		j = 2;
		for (vector<int>::iterator it = v.begin() + 2; it != v.end(); it++, j++) {//Ѱ����Сֵ
			//���*it�ȵ�ǰ��Сֵ��С���滻����ǰ�ϴ����Сֵ
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
		//ɾ��min1��min2�������min1+min2
		v.erase(v.begin() + max(mini1, mini2));
		v.erase(v.begin() + min(mini1, mini2));
		v.push_back(min1 + min2);
		//�����ܷ���
		sum += min1 + min2;
	}
	return sum;
}

int main() {
	vector<int>pi;
	//д������
	setVector(pi);
	//����Huffman����������
	cout << func(pi) << endl;
	return 0;
}
