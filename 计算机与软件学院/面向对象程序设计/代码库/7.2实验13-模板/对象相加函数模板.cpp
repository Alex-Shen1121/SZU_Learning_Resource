#include<iostream>
#include<map>
using namespace std;

class CRmb {
private:
	int yuan, jiao, fen;
public:
	CRmb(int a = 0, int b = 0, int c = 0) :yuan(a), jiao(b), fen(c) {};
	int get3() {
		return yuan;
	}
	int get2() {
		return jiao;
	}
	int get1() {
		return fen;
	}
	friend ostream& operator<<(ostream& out, const CRmb& obj);
};

class CClock {
	int h, m, s;
public:
	CClock(int h = 0, int m = 0, int s = 0) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	int get3() {
		return h;
	}
	int get2() {
		return m;
	}
	int get1() {
		return s;
	}
	friend ostream& operator<<(ostream& out, const CClock& obj);
};

template <class T>
T add(T obj1, T obj2, int index) {
	int a = 0, b = 0, c = 0;
	if (obj1.get1() + obj2.get1() >= index) {
		c = obj1.get1() + obj2.get1() - index;
		b++;
	}
	else {
		c = obj1.get1() + obj2.get1();
	}
	if (b + obj1.get2() + obj2.get2() >= index) {
		b += obj1.get2() + obj2.get2() - index;
		a++;
	}
	else {
		b += obj1.get2() + obj2.get2();
	}
	a += obj1.get3() + obj2.get3();
	T obj(a, b, c);
	return obj;
}

int main() {
	int a, b, c_, d, e, f;
	cin >> a >> b >> c_ >> d >> e >> f;
	CClock c1(a, b, c_), c2(d, e, f), c;
	c = add(c1, c2, 60);
	cout << c << endl;
	cin >> a >> b >> c_ >> d >> e >> f;
	CRmb r1(a, b, c_), r2(d, e, f), r;
	r = add(r1, r2, 10);
	cout << r << endl;
	return 0;
}

ostream& operator<<(ostream& out, const CRmb& obj)
{
	out << obj.yuan << " " << obj.jiao << " " << obj.fen;
	return out;
}

ostream& operator<<(ostream& out, const CClock& obj)
{
	out << obj.h << " " << obj.m << " " << obj.s;
	return out;
}

