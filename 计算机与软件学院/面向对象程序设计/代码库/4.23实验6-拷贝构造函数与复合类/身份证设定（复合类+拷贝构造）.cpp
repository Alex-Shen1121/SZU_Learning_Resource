#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Date {
private:
	int year, month, day;
public:
	Date(int y, int m, int d) :year(y), month(m), day(d) {};
	Date() {};
	void set(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

};
class PID {
private:
	int type;
	char* num;
	Date birth;
public:
	PID(int t, char* n, int y, int m, int d) {
		type = t;
		num = new char[strlen(n) + 1];
		strcpy(num, n);
		birth.set(y, m, d);
	}
	PID(const PID& temp) {
		type = 2;
		birth = temp.birth;
		int i, sum = 0;
		num = new char[19];
		for (i = 0; i < 6; i++)
		{
			num[i] = temp.num[i];
		}

		if (birth.getYear() >= 1900 && birth.getYear() < 2000) {
			num[6] = '1';
			num[7] = '9';
		}
		else if (birth.getYear() >= 2000) {
			num[6] = '2';
			num[7] = '0';
		}

		for (i = 8; i < 17; i++)
		{
			num[i] = temp.num[i - 2];
		}

		for (i = 0; i < 17; i++) {
			sum += num[i] - '0';
		}
		if (sum % 10 == 0)
			num[17] = 'X';
		else
			num[17] = sum % 10 + '0';
		num[18] = '\0';
	}
	~PID() {
		if (num != NULL)
			delete num;
	}
	void print()
	{
		cout << "type=" << type << " birth=" << setfill('0') << setw(2) << birth.getYear() << "." << setfill('0') << setw(2) << birth.getMonth()  << "." << setfill('0') << setw(2) << birth.getDay() << endl;
		cout << "ID=" << num << endl;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int type, y, m, d;
		char num[19];
		cin >> type >> num >> y >> m >> d;
		PID p1(type, num, y, m, d);
		if (type == 1)
		{
			PID p2(p1);
			p2.print();
		}
		else p1.print();
	}
	return 0;
}
