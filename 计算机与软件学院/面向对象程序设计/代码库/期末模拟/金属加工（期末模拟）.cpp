#include<iostream>
using namespace std;

class Metal {
private:
	int hardness, weight, volume;
public:
	Metal(int h = 0, int w = 0, int v = 0) :hardness(h), weight(w), volume(v) {};
	Metal operator +(const Metal& obj) {
		Metal temp = *this;
		temp.hardness = hardness + obj.hardness;
		temp.weight = weight + obj.weight;
		temp.volume = volume + obj.volume;
		return temp;
	}
	Metal operator *(const int n) {
		Metal temp = *this;
		temp.volume = volume * n;
		return temp;
	}
	void operator ++() {
		hardness += 1;
		weight *= 1.1;
		volume *= 1.1;
	}
	void operator --(int) {
		hardness -= 1;
		weight *= 0.9;
		volume *= 0.9;
	}
	void print() {
		cout << "硬度" << hardness << "--重量" << weight << "--体积" << volume << endl;
	}
};

int main() {
	int hardness, weight, volume, n;
	cin >> hardness >> weight >> volume;
	Metal m1(hardness, weight, volume);
	cin >> hardness >> weight >> volume;
	Metal m2(hardness, weight, volume);
	Metal m3;
	cin >> n;
	m3 = m1 + m2;
	m3.print();
	m3 = m1;
	m3 = m3 * n;
	m3.print();
	++m1;
	m1.print();
	m2--;
	m2.print();
	return 0;
}
