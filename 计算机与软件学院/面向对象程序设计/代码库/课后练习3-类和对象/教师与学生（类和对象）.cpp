#include<iostream>
using namespace std;
class Course
{
	int  num;
	string name;
public:
	void setCourse(int n, string str);
	void dohomework();
	string courseName();
};
int main()
{
	int t;
	Course C[50];
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int x;
		string str;
		cin >> x >> str;
		C[i].setCourse(x, str);
	}
	int n;
	cin >> n;
	string str[50];
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < t; j++)
		{
			if (C[j].courseName() == str)
				C[j].dohomework();
			else
				continue;
		}
	}
	return 0;
}

void Course::setCourse(int n, string str)
{
	num = n;
	name = str;
}

void Course::dohomework()
{
	if (num * num > 60)
		cout << "88" << endl;
	else
		cout << "44" << endl;
}

string Course::courseName()
{
	return name;
}
