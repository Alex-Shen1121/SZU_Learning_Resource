#include<iostream>
#include<string.h>
using namespace std;
int compare(char* s, char* t, int ls, int lt)
{
	int i, nums=0, numt=0;
	if (ls > lt)
		return 1;
	else if (ls < lt)
		return -1;
	else
	{
		for (i = 0; i < ls; i++)
		{
			if (*(s + i) > * (t + i))
				nums++;
			else if (*(s + i) < *(t + i))
				numt++;
		}
		if (nums > numt)
			return 1;
		else if (nums < numt)
			return -1;
		else
			return 0;
	}
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		char S[100], T[100];
		int ls = 0, lt = 0;
		cin >> S >> T;
		ls = strlen(S);
		lt = strlen(T);
		cout << compare(S, T, ls, lt) << endl;
	}
	return 0;
}
