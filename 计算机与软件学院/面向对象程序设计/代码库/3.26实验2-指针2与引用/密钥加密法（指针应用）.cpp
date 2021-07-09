#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		char ch[1000], num[1000],ans[1000];
		int password[1000],i;
		char* p, * s;
		int* q;
		cin >> ch >> num;
		for (i = 0; i < strlen(num);i++)
			*(password + i) = *(num + i) - '0';
		p = ch;
		q = password;
		s = ans;
		for (i = 0; i < strlen(ch); i++)
		{
			if (*(p + i) <= 'Z' && *(p + i) >= 'A')
				*(s + i) = (*(p + i) + *(q + i % strlen(num)) - 'A') % 26 + 'A';
			else if (*(p + i) <= 'z' && *(p + i) >= 'a')
				*(s + i) = (*(p + i) + *(q + i % strlen(num)) - 'a') % 26 + 'a';
		}
		cout << ans << endl;
	}
	return 0;
}
