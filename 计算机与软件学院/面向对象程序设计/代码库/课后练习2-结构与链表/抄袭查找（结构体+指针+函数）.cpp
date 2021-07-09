#include<iostream>
#include<string.h>
using namespace std;
struct Paper
{
	char num[100];
	char ans1[100];
	char ans2[100];
	char ans3[100];
};
Paper getPaper()
{
	Paper temp;
	cin >> temp.num >> temp.ans1 >> temp.ans2 >> temp.ans3;
	return temp;
}
int check(Paper* man1, Paper* man2)			//·µ»Ø³­Ï®ÌâºÅ£¬ÎÞ³­Ï®·µ»Ø-1
{
	float l1, l2, l3, l1_, l2_, l3_;
	int temp, temp2 = 0;
	l1_ = strlen(man1->ans1);
	l2_ = strlen(man1->ans2);
	l3_ = strlen(man1->ans3);
	l1 = strlen(man1->ans1) * 0.9;
	l2 = strlen(man1->ans2) * 0.9;
	l3 = strlen(man1->ans3) * 0.9;
	temp = 0;
	for (int i = 0; i < l1_; i++)
	{
		if (man1->ans1[i] == man2->ans1[i])
			temp++;
	}
	if (temp >= l1)
	{
		temp2 = 1;
		return 1;
	}
	temp = 0;
	for (int i = 0; i < l2_; i++)
	{
		if (man1->ans2[i] == man2->ans2[i])
			temp++;
	}
	if (temp >= l2)
	{
		temp2 = 1;
		return 2;
	}
	temp = 0;
	for (int i = 0; i < l3_; i++)
	{
		if (man1->ans3[i] == man2->ans3[i])
			temp++;
	}
	if (temp >= l3)
	{
		temp2 = 1;
		return 3;
	}
	if (temp2 == 0)	return -1;
}
int main()
{
	int i, j, t, temp;
	cin >> t;
	Paper* People = new Paper[t];
	for (i = 0; i < t; i++)
		People[i] = getPaper();
	for (i = 0; i < t; i++)
		for (j = i + 1; j < t; j++)
		{
			temp = check(&People[i], &People[j]);
			if (temp != -1)
				cout << People[i].num << ' ' << People[j].num << ' ' << temp << endl;
			else continue;
		}
 	return 0;
}
