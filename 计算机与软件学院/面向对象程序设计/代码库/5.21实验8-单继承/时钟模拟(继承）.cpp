#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<cmath>
#define PI 3.14
using namespace std;

class Counter {
protected:
	int value;
public:
	Counter(int n) {
		value = n;
	}
	int increment() {
		value++;
		return value;
	}
	int getvalue() {
		return value;
	}
};

class cirCounter :public Counter {
protected:
	int min_value, max_value;
public:
	cirCounter(int v, int min, int max) :Counter(v) {
		min_value = min;
		max_value = max;
	}
	int increment() {
		value++;
		if (value > max_value)
			value = value - (max_value - min_value) - 1;
		return value;
	}
};

class Time {
	cirCounter hour, minute, second;
public:
	Time(int h, int m, int s) :hour(h, 0, 23), minute(m, 0, 59), second(s, 0, 59) {};
	void time(int s) {
		while (s--)
		{
			if (second.increment() == 0)
			{
				if (minute.increment() == 0)
					hour.increment();
			}
		}
	}
	void display() {
		cout << hour.getvalue() << ":" << minute.getvalue() << ":" << second.getvalue() << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int h, m, s;
		int passtime;
		cin >> h >> m >> s;
		Time T(h, m, s);
		cin >> passtime;
		T.time(passtime);
		T.display();
	}
	return 0;
}
