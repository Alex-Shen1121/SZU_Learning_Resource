#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Vector {
	int vec[10];
public:
	Vector(int v[]) {
		for (int i = 0; i < 10; i++)
			vec[i] = v[i];
	}
	Vector() {
		for (int i = 0; i < 10; i++)
			vec[i] = 0;
	}
	Vector(const Vector& obj) {
		for (int i = 0; i < 10; i++)
			vec[i] = obj.vec[i];
	}
	Vector operator +(const Vector& obj) {
		Vector temp;
		for (int i = 0; i < 10; i++)
			temp.vec[i] = vec[i] + obj.vec[i];
		return temp;
	}
	Vector operator -(const Vector& obj) {
		Vector temp;
		for (int i = 0; i < 10; i++)
			temp.vec[i] = vec[i] - obj.vec[i];
		return temp;
	}
	friend ostream& operator<<(ostream& out, Vector& obj);
};

ostream& operator<<(ostream& out, Vector& obj) {
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			out << obj.vec[i];
			continue;
		}
		else {
			out << " " << obj.vec[i];
		}
	}
	return out;
}

int main() {
	int data[10];
	for (int i = 0; i < 10; i++) {
		cin >> data[i];
	}
	Vector v1(data);
	for (int i = 0; i < 10; i++) {
		cin >> data[i];
	}
	Vector v2(data);
	Vector v3;
	v3 = v1 + v2;
	cout << v3 << endl;
	v3 = v1 - v2;
	cout << v3 << endl;
}
