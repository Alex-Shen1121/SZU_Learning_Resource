#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<string.h>
using namespace std;

int isLeap(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || y % 400 == 0)
		return 1;
	else
		return 0;
}

class CDate
{
	int year, month, day;
public:
	CDate() {
		year = 0;
		month = 0;
		day = 0;
	};
	CDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void setDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	};
	int getYear();
	int getMonth();
	int getDay();
	bool operator!=(CDate d) {
		if (year == d.year && month == d.month && day == d.day)
			return false;
		else
			return true;
	}
	friend int distanceofday(CDate d1, CDate d2);
};

int getDays(CDate d)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap(d.getYear()))
		m[2]++;
	int result = 0;
	for (int i = 1; i < d.getYear(); i++)
	{
		result += 365;
		if (isLeap(i))
			result++;
	}
	for (int i = 1; i < d.getMonth(); i++)
	{
		result += m[i];
	}
	result += d.getDay();
	return result;
}


int CDate::getYear()
{
	return year;
}

int CDate::getMonth()
{
	return month;
}

int CDate::getDay()
{
	return day;
}

int distanceofday(CDate d1, CDate d2)
{
	return abs(getDays(d1) - getDays(d2));
}

class Student {
	string name;
	CDate birth;
public:
	Student() :birth() {};
	Student(string name, int y, int m, int d) :birth(y, m, d) {
		this->name = name;
	}
	int operator-(const Student& s) {
		return distanceofday(birth, s.birth);
	}
	string getname() {
		return name;
	}
};

int main()
{
	int n;
	cin >> n;
	Student* s = new Student[n];
	string name;
	int y, m, d;	
	for (int i = 0; i < n; i++) {
		cin >> name >> y >> m >> d;
		s[i] = Student(name, y, m, d);
	}
	int max = 0, i_index = 0, j_index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp;
			temp = s[i] - s[j];
			if (temp > max) {
				max = temp;
				i_index = i;
				j_index = j;
			}
		}
	}
	cout << s[i_index].getname() << "和" << s[j_index].getname() << "年龄相差最大，为" << max << "天。" << endl;
	return 0;
}


