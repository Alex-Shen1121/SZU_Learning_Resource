#include<iostream>
#include<iomanip>
using namespace std;
int checkYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || y % 400 == 0)
		return 1;
	else
		return -1;
}
class Date
{
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int y, m, d;
		cin >> y >> m >> d;
		Date temp(y, m, d);
		temp.print();
	}
	return 0;
}

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void Date::print()
{
	cout << "Today is " << getYear() << "/" << setw(2) << setfill('0') << getMonth() << "/" << setw(2) << setfill('0') << getDay() << endl;
	addOneDay();
	cout << "Tomorrow is " << getYear() << "/" << setw(2) << setfill('0') << getMonth() << "/" << setw(2) << setfill('0') << getDay() << endl;
}

void Date::addOneDay()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if (day == 31)
		{
			day = 1;
			month++;
		}
		else
			day++;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 30)
		{
			day = 1;
			month++;
		}
		else
			day++;
	}
	else if (month == 2)
	{
		if (checkYear(year) == -1)
		{
			if (day == 28)
			{
				day = 1;
				month++;
			}
			else
				day++;
		}
		else if (checkYear(year) == 1)
		{
			if (day == 29)
			{
				day = 1;
				month++;
			}
			else
				day++;
		}
	}
	else if (month == 12)
	{
		if (day == 31)
		{
			day = 1;
			month = 1;
			year++;
		}
		else
			day++;
	}
	
}

