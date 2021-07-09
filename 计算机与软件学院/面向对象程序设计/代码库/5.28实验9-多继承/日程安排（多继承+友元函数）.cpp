#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
};

class Time {
protected:
	int hour, minute, second;
public:
	Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
};

class Schedule :public Time, public Date {
protected:
	int ID;
public:
	Schedule(int ID, int y, int m, int d, int h, int m1, int s) :Date(y, m, d), Time(h, m1, s) {
		this->ID = ID;
	}
	friend bool before(const Schedule& s,const Schedule& s2);
	void display() {
		cout << ID << ": " << year << "/" << fixed << setw(2) << setfill('0') << month << "/" << day << " ";
		cout << fixed << setw(2) << setfill('0') << hour << ":" << fixed << setw(2) << setfill('0') << minute << ":" << fixed << setw(2) << setfill('0') << second << endl;
	}
};

bool before(const Schedule& s, const Schedule& s2)
{
	if (s.year != s2.year)
		return s.year < s2.year;
	else if (s.month != s2.month)
		return s.month < s2.month;
	else if (s.day != s2.day)
		return s.day < s2.day;
	else if (s.hour != s2.hour)
		return s.hour < s2.hour;
	else if (s.minute < s2.minute)
		return s.minute < s2.minute;
	else if (s.second < s2.second)
		return s.second < s2.second;
	return false;
}

int main() {
	vector<Schedule> v;
	while (true) {
		int ID;
		cin >> ID;
		if (ID == 0)
			break;
		int year, month, day, hour, minute, second;
		cin >> year >> month >> day >> hour >> minute >> second;
		Schedule Temp(ID, year, month, day, hour, minute, second);
		v.push_back(Temp);
	}
	sort(v.begin(), v.end(), before);
	cout << "The urgent schedule is No.";
	v[0].display();
	return 0;
}

