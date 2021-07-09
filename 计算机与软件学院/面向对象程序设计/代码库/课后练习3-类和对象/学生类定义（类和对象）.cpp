#include<iostream>
using namespace std;
class Student
{
public:
	string name, number, major1, major2, gender, dom, phone;
};
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		Student People;
		cin >> People.name >> People.number >> People.major1 >> People.major2 >> People.gender >> People.dom >> People.phone;
		cout << People.name << ' ' << People.number << ' ' << People.major1 << ' ' << People.major2 << ' ' << People.gender << ' ' << People.dom << ' ' << People.phone << endl;
	}
	return 0;
}
