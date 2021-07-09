#include<iostream>
using namespace std;
struct FS {
	int fz, fm;
};
int getGCD(int a, int b)
{
	int i;
	if (a < b)
	{
		i = b;
		b = a;
		a = i;
	}
	int r = a % b;
	while (r!=0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
void Simplify(FS& num)
{
	int temp;
	temp = getGCD(num.fm, num.fz);
	num.fz = num.fz / temp;
	num.fm = num.fm / temp;
}
void print(FS& num)
{
	cout << num.fz << '/' << num.fm << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		FS num[3];
		char temp;
		cin >> num[0].fz >> temp >> num[0].fm
			>> num[1].fz >> temp >> num[1].fm;
		//加法
		num[2].fz = num[0].fz * num[1].fm + num[0].fm * num[1].fz;
		num[2].fm = num[0].fm * num[1].fm;
		Simplify(num[2]);
		print(num[2]);
		//减法
		num[2].fz = num[0].fz * num[1].fm - num[0].fm * num[1].fz;
		num[2].fm = num[0].fm * num[1].fm;
		if (num[2].fz < 0)
		{
			num[2].fz = -num[2].fz;
			Simplify(num[2]);
			cout << '-';
			print(num[2]);
		}
		else
		{
			Simplify(num[2]);
			print(num[2]);
		}
		//乘法
		num[2].fz = num[0].fz * num[1].fz;
		num[2].fm = num[0].fm * num[1].fm;
		Simplify(num[2]);
		print(num[2]);
		//除法
		num[2].fz = num[0].fz * num[1].fm;
		num[2].fm = num[0].fm * num[1].fz;
		Simplify(num[2]);
		print(num[2]);
		//
		cout << endl;
	}
	return 0;
}
