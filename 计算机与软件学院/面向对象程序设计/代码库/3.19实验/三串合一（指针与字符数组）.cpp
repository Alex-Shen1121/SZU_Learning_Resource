#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int strl = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, i = 0, j = 0;
		char str1[100] = "\0", str2[100] = "\0", str3[100] = "\0";
		char* p1 = NULL, * p2 = NULL, * p3 = NULL, * str = NULL;
		cin >> str1 >> str2 >> str3;
		cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;
		strl = num2 + num4 + num6 - num1 - num3 - num5 + 3;
		p1 = &str1[num1 - 1];
		p2 = &str2[num3 - 1];
		p3 = &str3[num5 - 1];
		str = new char[strl];
		for (j = num1; j <= num2; j++)
		{
			str[i] = *p1;
			p1++;
			i++;
		}
		for (j = num3; j <= num4; j++)
		{
			str[i] = *p2;
			p2++;
			i++;
		}
		for (j = num5; j <= num6; j++)
		{
			str[i] = *p3;
			p3++;
			i++;
		}
		cout << str << endl;
		delete[]str;
	}
	return 0;
}
