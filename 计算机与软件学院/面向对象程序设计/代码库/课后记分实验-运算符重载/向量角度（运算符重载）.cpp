#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Vector {
	int x, y;
public:
	Vector(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	int operator/(Vector v2) {
		float n;
		n = (x * v2.x + y * v2.y) / sqrt(x * x + y * y) / sqrt(v2.x * v2.x + v2.y * v2.y);
		return (int)(acos(n) / 3.1415926 * 180);
	}
};

int main() {
	int x, y;
	int t;
	cin >> t;
	Vector* v;
	v = new Vector[t];
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		v[i] = Vector(x, y);
	}
	int max = 0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if (j == i)
				continue;
			if (v[i]/v[j] > max) {
				max = v[i] / v[j];
			}
		}
	}
	cout << "角度相差最大为" << max << "度。" << endl;
	return 0;
}
