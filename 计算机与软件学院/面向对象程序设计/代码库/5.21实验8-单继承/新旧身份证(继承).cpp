#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<cmath>
#include<string>
#define PI 3.14
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	CDate(CDate& d) {
		year = d.year;
		month = d.month;
		day = d.day;
	}
	bool check() {
		if (month > 12 || month < 1)
			return false;
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31 || day <= 0)
				return false;
			else
				return true;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30 || day <= 0)
				return false;
			else
				return true;
		}
		else if (month == 2 && isLeap())
		{
			if (day > 29 || day <= 0)
				return false;
			else
				return true;
		}
		else if (month == 2 && !isLeap())
		{
			if (day > 28 || day <= 0)
				return false;
			else
				return true;
		}
		return true;
	}; //检验日期是否合法
	bool isLeap() {
		if ((year % 400 == 0) || (year % 4 == 0 && (year % 100 != 0)))
			return true;
		else
			return false;
	}
	int getYear() { 
		return year;
	}
	int getMonth() {
		return month; 
	}
	int getDay() { 
		return day; 
	}
	void print() {
		cout << year << "年" << month << "月" << day << "日";
	}
};

class COldID
{
protected:
	char* p_id15, * p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID(char* p_idval, char* p_nameval, CDate& day):birthday(day) {
		p_id15 = new char[16];
		p_name = new char[5];
		strcpy(p_id15, p_idval);
		strcpy(p_name, p_nameval);
	}
	bool check() {
		//检查位数长度
		if (strlen(p_id15) != 15)
			return false;
		//检查生日
		if (birthday.check() == false)
			return false;
		//检查是否全是数字
		for (int i = 0; i < 15; i++) {
			if (p_id15[i] > '9' || p_id15[i] < '0')
				return false;
			else 
				continue;
		}
		//检查生日
		int temp1, temp2;
		//日
		if (birthday.getDay() < 10) {
			temp1 = 0;
			temp2 = birthday.getDay();
		}
		else {
			temp1 = birthday.getDay() / 10;
			temp2 = birthday.getDay() % 10;
		}
		if ((p_id15[10] - '0') != temp1 || (p_id15[11] - '0') != temp2)
			return false;
		//月
		if (birthday.getMonth() < 10) {
			temp1 = 0;
			temp2 = birthday.getMonth();
		}
		else {
			temp1 = birthday.getMonth() / 10;
			temp2 = birthday.getMonth() % 10;
		}
		if ((p_id15[8] - '0') != temp1 || (p_id15[9] - '0') != temp2)
			return false;
		//年
		temp1 = birthday.getYear() / 10 % 10;
		temp2 = birthday.getYear() % 10;
		if ((p_id15[6] - '0') != temp1 || (p_id15[7] - '0') != temp2)
			return false;
		return true;
	}; //验证15位身份证是否合法
	void print() {

	}
	~COldID() {
		delete[]p_id15;
		delete[]p_name;
	}
};

class CNewID :public COldID
{
private:
	char* p_id18; //18位身份证号码
	CDate issueday;
	string validyear;
	int length;
public:
	CNewID(char* p_nameval, char* p_oldidval, char* p_newidval, CDate& bir, CDate& day,int length) :COldID(p_oldidval, p_nameval, bir),issueday(day) {
		p_id18 = new char[19];
		strcpy(p_id18, p_newidval);
		if (length == 100)
			validyear = "长期";
		else
			validyear = to_string(length) + "年";
		this->length = length;
	}

	bool check() {
		int i = 0, sum = 0;
		//检查15位是否正确
		if (COldID::check() == false)
			return false;
		//签发日期正确
		if (issueday.check() == false)
			return false;
		//temp15为正确18位扩展，对比二者
		char temp15[19];
		strcpy(temp15, p_id15);
		for (i = 0; i < 6; i++)
		{
			temp15[i] = p_id15[i];
		}
		if (birthday.getYear() >= 1900 && birthday.getYear() < 2000) {
			temp15[6] = '1';
			temp15[7] = '9';
		}
		else if (birthday.getYear() >= 2000) {
			temp15[6] = '2';
			temp15[7] = '0';
		}
		for (i = 8; i < 17; i++)
		{
			temp15[i] = p_id15[i - 2];
		}
		temp15[17] = '\0';
		sum = (temp15[0] - '0') * 7 + (temp15[1] - '0') * 9 + (temp15[2] - '0') * 10 + (temp15[3] - '0') * 5 + (temp15[4] - '0') * 8 + (temp15[5] - '0') * 4 + (temp15[6] - '0') * 2 + (temp15[7] - '0') * 1 + (temp15[8] - '0') * 6 + (temp15[9] - '0') * 3 + (temp15[10] - '0') * 7 + (temp15[11] - '0') * 9 + (temp15[12] - '0') * 10 + (temp15[13] - '0') * 5 + (temp15[14] - '0') * 8 + (temp15[15] - '0') * 4 + (temp15[16] - '0') * 2;
		sum = sum % 11;
		switch (sum)
		{
		case 0:temp15[17] = '1'; break;
		case 1:temp15[17] = '0'; break;
		case 2:temp15[17] = 'X'; break;
		case 3:temp15[17] = '9'; break;
		case 4:temp15[17] = '8'; break;
		case 5:temp15[17] = '7'; break;
		case 6:temp15[17] = '6'; break;
		case 7:temp15[17] = '5'; break;
		case 8:temp15[17] = '4'; break;
		case 9:temp15[17] = '3'; break;
		case 10:temp15[17] = '2'; break;
		}
		temp15[18] = '\0';
		if (strcmp(p_id18, temp15) != 0)
			return false;
		//有效期检查
		if (validyear != "长期") {
			int y, m, d;
			y = issueday.getYear() + length;
			m = issueday.getMonth();
			d = issueday.getDay();
			if (y < 2017)
				return false;
			else if (y == 2017 && m < 5)
				return false;
			else if (y == 2017 && m == 5 && d < 10)
				return false;
		}
		return true;
	}; //验证18位身份证是否合法
	void print() {
		cout << p_id18 << " ";
		issueday.print();
		cout << " " << validyear << endl;
	}
	void printname() {
		cout << p_name << endl;
	}
	~CNewID() {
		delete[]p_id18;
	}

};

int main() {
	int t;
	cin >> t;
	while (t--) {
		char name[5];
		char oldid[16];
		char newid[19];

		int year, month, day, year1, month1, day1, length;
		cin >> name >> year >> month >> day >> oldid >> newid >> year1 >> month1 >> day1 >> length;
		CDate birth(year, month, day), date(year1, month1, day1);
		CNewID newID(name, oldid, newid, birth, date, length);
		newID.printname();
		if (newID.check())
			newID.print();
		else
			cout << "illegal id" << endl;
	}
	return 0;
}
