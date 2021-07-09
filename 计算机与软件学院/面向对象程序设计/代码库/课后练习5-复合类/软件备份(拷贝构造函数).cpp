#include<iostream>
#include<string.h>
using namespace std;
class CDate
{
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    CDate() {};
    void set(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear()         //计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear())
            for (i = 0; i < month; i++)   sum += b[i];
        else
            for (i = 0; i < month; i++)   sum += a[i];

        return sum;
    }
};
class Software {
private:
    char* name;
    char type;
    CDate day;
    char media;
public:
    Software(char* n, char t, char m, int y, int mo, int d)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        type = t;
        media = m;
        day.set(y, mo, d);
    };
    void print() {
        cout << "name:" << name << endl;
        if (type == 'O')
            cout << "type:original" << endl;
        else if (type == 'T')
            cout << "type:trial" << endl;
        else if (type == 'B')
            cout << "type:backup" << endl;
        
        if (media == 'D')
            cout << "media:optical disk" << endl;
        else if (media == 'H')
            cout << "media:hard disk" << endl;
        else if (media == 'U')
            cout << "media:USB disk" << endl;

        if (day.getDay() == 0 && day.getMonth() == 0 && day.getYear() == 0)
            cout << "this software has unlimited use" << endl;
        else if ((day.getDay() >= 7 && day.getMonth() >= 4 && day.getYear() >= 2015)||(day.getMonth() >= 5 && day.getYear() >= 2015))
        {
            int sum = 0, temp = 2015;
            while (temp < day.getYear())
            {
                if ((temp % 4 == 0 && temp % 100 != 0) || temp % 400 == 0)
                    sum += 366;
                else
                    sum += 365;
                temp++;
            }
            sum += day.getDayofYear();
            cout << "this software is going to be expired in " << sum - 97 << " days" << endl;
        }
        else
            cout << "this software has expired" << endl;
    }
    Software(Software& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        type = 'B';
        media = 'H';
        day = s.day;
    }
    ~Software() {
        delete name;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int y, d, m;
        char name[1000];
        char type, media;
        cin >> name >> type >> media >> y >> m >> d;
        Software s1(name, type, media, y, m, d);
        s1.print();
        cout << '\n';
        Software s2(s1);
        s2.print();
        cout << '\n';
    }
}
