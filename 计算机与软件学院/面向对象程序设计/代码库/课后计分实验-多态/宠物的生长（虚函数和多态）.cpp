#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

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

class Pet {
protected:
	string name;//姓名
	double length;//身长
	double weight;//体重
	CDate current;//开始记录时间
public:
	virtual void display(CDate day) = 0;//输出目标日期时宠物的身长和体重
};

class Dog :public Pet {
public:
	Dog(string n, double l, double w, CDate date) {
		name = n;
		length = l;
		weight = w;
		current.setDate(date.getYear(), date.getMonth(), date.getDay());
	}
	void display(CDate day) {
		int i = getDays(day) - getDays(current);
		if (i < 0 || day.getYear() < this->current.getYear()) {
			cout << "error" << endl;
		}
		else {
			weight += 0.1 * i;
			length += 0.2 * i;
			cout << name << " after " << i << fixed << setprecision(2) << " day: length=" << length << ",weight=" << weight << endl;
		}		
	}
};

class Cat :public Pet {
public:
	Cat(string n, double l, double w, CDate date) {
		name = n;
		length = l;
		weight = w;
		current.setDate(date.getYear(), date.getMonth(), date.getDay());;
	}
	void display(CDate day) {
		int i = getDays(day) - getDays(current);
		if (i < 0 || day.getYear() < this->current.getYear()) {
			cout << "error" << endl;
		}
		else {
			weight += 0.2 * i;
			length += 0.1 * i;
			cout << name << " after " << i << fixed << setprecision(2) << " day: length=" << length << ",weight=" << weight << endl;
		}
	}
};

int main() {
	int t;
	cin >> t;
	int y, m, d;
	cin >> y >> m >> d;
	CDate startDay(y, m, d);
	while (t--) {
		int type;
		cin >> type;
		Pet* pt;
		string name;//姓名
		double length;//身长
		double weight;//体重
		switch (type) {
		case 1: {
			cin >> name >> length >> weight >> y >> m >> d;
			CDate lastDay(y, m, d);
			Cat obj(name, length, weight, startDay);
			pt = &obj;
			pt->display(lastDay);
			break;
		}
		case 2: {
			cin >> name >> length >> weight >> y >> m >> d;
			CDate lastDay(y, m, d);
			Dog obj(name, length, weight, startDay);
			pt = &obj;
			pt->display(lastDay);
			break;
		}
		}
		pt = NULL;
	}
	return 0;
}

int distanceofday(CDate d1, CDate d2)
{
	return abs(getDays(d1) - getDays(d2));
}

