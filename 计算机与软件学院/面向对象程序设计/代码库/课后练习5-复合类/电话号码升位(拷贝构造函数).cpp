#include<iostream>
#include<cstring>
using namespace std;
bool isLegal(char* p);
class CTelNumber {
private:
	char* num;
public:
	CTelNumber(char* n) {
		num = new char(strlen(n) + 1);
		strcpy(num, n);
	};
	CTelNumber(const CTelNumber& temp)
	{
		int l = strlen(temp.num);
		if (l != 7)
		{
			num = new char[2];
			num[0] = ' ';
		}
		else if (l == 7 && temp.num[0] >= '2' && temp.num[0] <= '8')
		{
			num = new char[9];
			if (temp.num[0] == '2' || temp.num[0] == '3' || temp.num[0] == '4')
				num[0] = '8';
			else if (temp.num[0] == '5' || temp.num[0] == '6' || temp.num[0] == '7' || temp.num[0] == '8')
				num[0] = '2';
			for (int i = 0; i < 7; i++)
				num[i + 1] = temp.num[i];
			num[8] = '\0';
		}
		else {
			num = new char[2];
			num[0] = ' ';
		}
	}
	~CTelNumber() {
		delete[]num;
	};
	void print(){
		if (::isLegal(num))
			cout << num << endl;
		else
			cout << "Illegal phone number" << endl;
	}
};

bool isLegal(char* p)
{
	if (p[0] <= '1' || p[0] >= '9')
		return false;
	int i;
	for (i = 0; i < 8 && p[i] != '\0' && p[i] >= '0' && p[i] <= '9'; i++);
	return i >= 7;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char str[1000];
		cin >> str;
		CTelNumber test(str);
		CTelNumber ans(test);
		ans.print();
	}
	return 0;
}
