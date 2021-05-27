#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)	{
		int n;
		string str1, str2;
		cin >> n;
		cin >> str1 >> str2;
		stack<char>s1, s2;
		int j = 0;
		for (int i = 0; i < str1.length(); i++)
		{
			s1.push(str1[i]);
			while (s1.top() == str2[j])
			{
				s1.pop();
				j++;
				if (s1.empty())
					break;
			}
		}
		if (j == str2.length())
			cout << "Yes" << endl;
		else
		{
			cout << "No" << endl << "FINISH" << endl;
			continue;
		}
		j = 0;
		for (int i = 0 ; i < str1.length(); i++)
		{
			s1.push(str1[i]);
			cout << "in" << endl;
			while (s1.top() == str2[j])
			{
				s1.pop();
				j++;
				cout << "out" << endl;
				if (s1.empty())
					break;
			}
		}
		cout << "FINISH" << endl;
	}
	return 0;
}
