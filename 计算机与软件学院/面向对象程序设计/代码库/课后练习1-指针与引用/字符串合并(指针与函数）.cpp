#include<iostream>
using namespace std;
char* strAdd(char* s1, char* s2)
{
	int i = 0, p = 0;
	char s3[2000];
	while (*(s1 + i) != '\0')
	{
		*(s3 + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + p) != '\0')
	{
		*(s3 + i + p) = *(s2 + p);
		p++;
	}
	*(s3 + p + i) = '\0';
	return s3;
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		char s1[1000], s2[1000];
		char* p = NULL;
		int i = 0;
		cin >> s1 >> s2;
		p = strAdd(s1, s2);
		cout << s1 << ' ' << s2 << ' ';
		while (*(p + i) != '\0')
		{
			cout << *(p + i);
			i++;
		}
		cout << endl;
	}
 	return 0;
}
