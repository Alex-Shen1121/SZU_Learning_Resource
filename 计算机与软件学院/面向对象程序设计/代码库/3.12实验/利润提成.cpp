#include<iostream>
using namespace std;
int main()
{
	float LiRun,JiangJin;
	int LiRun2;
	cin >> LiRun;
	LiRun2 = LiRun / 100000;
	switch (LiRun2)
	{
		case 0:JiangJin = LiRun * 0.1;break; 
		case 1:JiangJin = 100000 * 0.1+(LiRun-100000)*0.075;break;
		case 2:
		case 3:JiangJin = 100000 * 0.1 + 100000 * 0.075 + (LiRun - 200000) * 0.05;break;
		case 4:
		case 5:JiangJin = 100000 * 0.1 + 100000 * 0.075 + 200000* 0.005+(LiRun - 400000) * 0.03;break;
		case 6:
		case 7:
		case 8:
		case 9:JiangJin = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.005 + 200000 * 0.03 + (LiRun - 600000) * 0.015;break;
		default:JiangJin = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.005 + 200000 * 0.03 + 400000 * 0.015 + (LiRun - 1000000) * 0.01;break;
	}
	cout << JiangJin;
	return 0;
}

