#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int getvalue2(char ch);
struct Poker
{
	char card[100];
};
int getvalue(char* temp)
{
	int l;
	l = strlen(temp);
	if (l == 6)//10�����
	{
		if (strstr(temp,"����") != NULL)
			return 7;
		else if (strstr(temp, "����") != NULL)
			return 20;
		else if (strstr(temp, "÷��") != NULL)
			return 33;
		else if (strstr(temp, "����") != NULL)
			return 46;
	}
	else
	{
		if (strstr(temp, "����") != NULL)
			return 2 + getvalue2(temp[4]);
		else if (strstr(temp, "����") != NULL)
			return 15 + getvalue2(temp[4]);
		else if (strstr(temp, "÷��") != NULL)
			return 28 + getvalue2(temp[4]);
		else if (strstr(temp, "����") != NULL)
			return 41 + getvalue2(temp[4]);
	}

}
int getvalue2(char ch)
{
	if (ch == 'A')	return 1;
	else if (ch == 'K')	return 2;
	else if (ch == 'Q')	return 3;
	else if (ch == 'J')	return 4;
	else if (ch == '9')	return 6;
	else if (ch == '8')	return 7;
	else if (ch == '7')	return 8;
	else if (ch == '6')	return 9;
	else if (ch == '5')	return 10;
	else if (ch == '4')	return 11;
	else if (ch == '3')	return 12;
	else if (ch == '2')	return 13;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, temp, i, j;
		cin >> n;
		Poker tempDeck;
		Poker* deck = new Poker[n];
		int* value = new int[n];
		Poker* sortdeck = new Poker[n];
		for (int i = 0; i < n; i++)
			cin >> deck[i].card;
		for (int i = 0; i < n; i++)//Ϊÿ���Ƹ�ֵ��1��� 52��С//value[i]��deck[i]һһ��Ӧ
		{
			if (strcmp(deck[i].card, "����") == 0)
			{
				value[i] = 1;
			}
			else if (strcmp(deck[i].card, "С��") == 0)
			{
				value[i] = 2;
			}
			else
			{
				value[i] = getvalue(deck[i].card);
			}
		}
		for (i = 1; i < n; i++)//��С����ð������
			for (j = 0; j < n - i; j++)
			{
				if (value[j] > value[j + 1])
				{
					temp = value[j];
					value[j] = value[j + 1];
					value[j + 1] = temp;
					tempDeck = deck[j];
					deck[j] = deck[j + 1];
					deck[j + 1] = tempDeck;
				}
			}
		for (i = 0; i < n; i++)
		{
			if (i == 0)
				cout << deck[i].card;
			else if (i != 0)
				cout << ' ' << deck[i].card;
		}
		cout << endl;
	}
	return 0;
}
