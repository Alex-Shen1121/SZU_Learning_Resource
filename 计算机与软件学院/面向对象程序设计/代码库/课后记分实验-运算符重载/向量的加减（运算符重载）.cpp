#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Vector {
	int vec[5];
public:
	Vector(int v[]) {
		vec[0] = v[0];
		vec[1] = v[1];
		vec[2] = v[2];
		vec[3] = v[3];
		vec[4] = v[4];
	}
	Vector() {
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
		vec[3] = 0;
		vec[4] = 0;
	}
	Vector(const Vector& obj) {
		vec[0] = obj.vec[0];
		vec[1] = obj.vec[1];
		vec[2] = obj.vec[2];
		vec[3] = obj.vec[3];
		vec[4] = obj.vec[4];
	}
	Vector operator +(const Vector& obj) {	
		Vector temp;
		temp.vec[0] = vec[0] + obj.vec[0];
		temp.vec[1] = vec[1] + obj.vec[1];
		temp.vec[2] = vec[2] + obj.vec[2];
		temp.vec[3] = vec[3] + obj.vec[3];
		temp.vec[4] = vec[4] + obj.vec[4];
		return temp;
	}
	Vector operator -(const Vector& obj){
		Vector temp;
		temp.vec[0] = vec[0] - obj.vec[0];
		temp.vec[1] = vec[1] - obj.vec[1];
		temp.vec[2] = vec[2] - obj.vec[2];
		temp.vec[3] = vec[3] - obj.vec[3];
		temp.vec[4] = vec[4] - obj.vec[4];
		return temp;
	}
	void print() {
		cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << " " << vec[4] << " " << endl;
	}
};

int main() {
	int data[5];
	for (int i = 0; i < 5; i++) {
		cin >> data[i];
	}
	Vector v1(data);
	for (int i = 0; i < 5; i++) {
		cin >> data[i];
	}
	Vector v2(data);
	Vector v3;
	v3 = v1 + v2;
	v3.print();
	v3 = v1 - v2;
	v3.print();
}
