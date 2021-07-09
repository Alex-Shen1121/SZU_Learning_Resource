#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

class CDate {
	int year, month, day;
public:
	CDate(int n = 0) {
		year = n / 10000;
		n -= year * 10000;
		month = n / 100;
		n -= month * 100;
		day = n;
	}
	operator int() {
		return day + month * 100 + year * 1000;
	}
	void Print() {
		cout << year << "年" << fixed << setw(2) << setfill('0') << month << "月" << day << "日" << endl;
	}
};

int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin >> t;
	while (t--)
	{
		cin >> t1 >> t2;
		C1 = t1;
		C2 = t2;
		((C1 > C2) ? C1 : C2).Print(); //日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
	}
	return 0;
}
