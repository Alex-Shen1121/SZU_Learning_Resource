#include<iostream>
#include<algorithm>
using namespace std;

class Fraction {
	int numerator, denominator;
	int common_divisor();
	void contracted();
public:
	Fraction(int a, int b);
	Fraction(Fraction&);
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	void Set(int = 0, int = 1);
	void disp() {
		cout << "fraction=" << numerator << "/" << denominator << endl;
	}
};

int Fraction::common_divisor()
{
	int max = 1;
	for (int i = 2; i <= min(numerator, denominator); i++) {
		if (numerator % i == 0 && denominator % i == 0) {
			max = i;
		}
	}
	return max;
}

void Fraction::contracted()
{
	numerator /= common_divisor();
	denominator /= common_divisor();
}

Fraction::Fraction(int a = 0, int b = 1) {
	numerator = a;
	denominator = b;
}

Fraction::Fraction(Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}

Fraction Fraction::operator+(Fraction f)
{
	Fraction t(numerator * f.denominator + denominator * f.numerator, denominator * f.denominator);
	return t;
}

Fraction Fraction::operator-(Fraction f)
{
	Fraction t(numerator * f.denominator - denominator * f.numerator, denominator * f.denominator);
	return t;
}

Fraction Fraction::operator*(Fraction f)
{
	Fraction t(numerator * f.numerator, denominator * f.denominator);
	return t;
}

Fraction Fraction::operator/(Fraction f)
{
	Fraction t(numerator * f.denominator, denominator * f.numerator);
	return t;
}

void Fraction::Set(int a, int b)
{
	numerator = a;
	denominator = b;
}

int main() {
	int a, b;
	cin >> a >> b;
	Fraction f1(a, b);
	cin >> a >> b;
	Fraction f2(a, b);
	Fraction f3;
	f3 = f1 + f2;
	f3.disp();
	f3 = f1 - f2;
	f3.disp();
	f3 = f1 * f2;
	f3.disp();
	f3 = f1 / f2;
	f3.disp();
}
