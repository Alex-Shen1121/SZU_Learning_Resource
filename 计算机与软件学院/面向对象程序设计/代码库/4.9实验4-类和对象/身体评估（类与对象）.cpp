#include<iostream>
#include<iomanip>
using namespace std;
class BMI
{
	
	float height, weight, waist;
public:
	string name;
	BMI(string n, float h, float w, float wa);
	int calBMI();
	float calBFR();
};

BMI::BMI(string n, float h, float w, float wa)
{
	name = n;
	height = h;
	weight = w;
	waist = wa;
}

int BMI::calBMI()
{
	float a = weight / height / height;
	int i = a + 0.5;
	return i;
}

float BMI::calBFR()
{
	float a, b, c;
	a = waist * 0.74;
	b = weight * 0.082 + 34.89;
	c = a - b;
	return c/weight;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string n; 
		float h, w, wa;
		cin >> n >> h >> w >> wa;
		BMI People(n, h, w, wa);
		cout << People.name << setprecision(0) << "的BMI指数为" << People.calBMI() << "--体脂率为" << setprecision(2) << People.calBFR() << endl;
	}
	return 0;
}
