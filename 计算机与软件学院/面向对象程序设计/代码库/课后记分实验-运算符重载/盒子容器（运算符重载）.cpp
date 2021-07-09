#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

class box {
private:
	string num;
	int length;
	int width;
	int height;
public:
	box(string n = "0", int l = 0, int w = 0, int h = 0) {
		num = n;
		length = l;
		width = w;
		height = h;
	}
	int operator-(box& b2) {
		if (b2.length > length)
			return -1;
		else if (b2.width > width)
			return -1;
		if (b2.height > height)
			return b2.length * b2.width * height;
		else
			return b2.length * b2.width * b2.height;
	}
	string getnum() {
		return num;
	}
};

int main() {
	int t;
	box* Box;
	cin >> t;
	Box = new box[t];
	for (int i = 0; i < t; i++) {
		int l, w, h;
		string num;
		cin >> num >> l >> w >> h;
		Box[i] = box(num,l, w, h);
	}
	int index_a = 0, index_b = 0, volume = 0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t ; j++) {
			if (j == i)
				continue;
			if (Box[j] - Box[i] > volume) {
				index_a = i;
				index_b = j;
				volume = Box[j] - Box[i];
			}
		}
	}
	cout << Box[index_a].getnum() << "盒子放入" << Box[index_b].getnum() << "盒子溢出的水最多，为" << volume << "。" << endl;
	return 0;
}
