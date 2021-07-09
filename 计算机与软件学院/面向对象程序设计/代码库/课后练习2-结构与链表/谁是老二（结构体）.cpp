#include<iostream>
using namespace std;
struct Person
{
	int year;
	int month;
	int day;
};
Person getPerson()
{
	Person temp;
	cin >> temp.year >> temp.month >> temp.day;
	return temp;
}
void output(Person* p)
{
	cout << p->year << '-' << p->month << '-' << p->day << endl;
}
int main()
{
	int t, i, j;
	Person temp = {0,0,0};
	cin >> t;
	Person* man = new Person[t];
	for (i = 0; i < t; i++)
		man[i] = getPerson();
	for(i=1;i<t;i++)
		for (j = 0; j < t - i; j++)
		{
			if ((man[j].year > man[j + 1].year) || (man[j].year == man[j + 1].year && man[j].month > man[j + 1].month) || (man[j].year == man[j + 1].year && man[j].month == man[j + 1].month && man[j].day > man[j + 1].day))
			{
				temp = man[j];
				man[j] = man[j + 1];
				man[j + 1] = temp;
			}
		}
	cout << man[1].year << '-' << man[1].month << '-' << man[1].day;
	return 0;
}
