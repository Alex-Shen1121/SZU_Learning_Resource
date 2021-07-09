#include <iostream>
using namespace std;

class Complex {
	float Real, Image;
public:
	Complex(float x = 0, float y = 0) {
		Real = x;
		Image = y;
	}
	friend Complex operator+(Complex&, Complex&);
	friend Complex operator-(Complex&, Complex&);
	friend Complex operator*(Complex&, Complex&);
	void show() {
		cout << "Real=" << Real << " " << "Image=" << Image << endl;
	}
};

int main()
{
	int r, i;
	cin >> r >> i;
	Complex c1(r, i);
	cin >> r >> i;
	Complex c2(r, i);
	Complex c3;
	c3 = c1 + c2;
	c3.show();
	c3 = c1 - c2;
	c3.show();
	c3 = c1 * c2;
	c3.show();
	return 0;
}

Complex operator+(Complex& a, Complex& b)
{	
	return Complex(a.Real + b.Real, a.Image + b.Image);
}

Complex operator-(Complex& a, Complex& b)
{
	return Complex(a.Real - b.Real, a.Image - b.Image);
}

Complex operator*(Complex& a, Complex& b)
{
	return Complex(a.Real*b.Real -a.Image*b.Image, a.Image * b.Real + a.Real * b.Image);
}

