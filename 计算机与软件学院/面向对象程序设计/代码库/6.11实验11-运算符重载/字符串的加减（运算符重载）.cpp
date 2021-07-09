#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class Str {
	int length;
	char* p;
public:
	Str();
	Str(char* s);
	Str(const Str& obj);
	friend Str operator+(const Str& s1, const Str& s2);
	friend Str operator-(const Str& s1, const Str& s2);
	void operator=(const Str& obj);
	void show() {
		cout << "length=" << length << " " << p << endl;
	}
};

int main()
{
	char* p1 = new char[50], * p2 = new char[50];
	cin.getline(p1, 50);
	cin.getline(p2, 50);
	Str s1(p1), s2(p2), s3;
	s3 = s1 + s2;
	s3.show();
	s3 = s1 - s2;
	s3.show();
	return 0;
}

Str::Str()
{
	length = 0;
	p = NULL;
}

Str::Str(char* s)
{
	length = strlen(s);
	p = new char[length + 1];
	strcpy(p, s);
}

Str::Str(const Str& obj)
{
	length = strlen(obj.p);
	p = new char[length + 1];
	strcpy(p, obj.p);
}

void Str::operator=(const Str& obj)
{
	length = strlen(obj.p);
	p = new char[length + 1];
	strcpy(p, obj.p);
}

Str operator+(const Str& s1, const Str& s2)
{
	Str temp;
	temp.length = strlen(s1.p) + strlen(s2.p);
	temp.p = new char[temp.length + 1];
	temp.p[0] = '\0';
	strcat(temp.p, s1.p);
	strcat(temp.p, s2.p);
	return temp;
}

Str operator-(const Str& s1, const Str& s2)
{
	Str s1_(s1), s2_(s2);
	int start = -1 , check = 0;
	int j;
	for (int i = 0; i < strlen(s1_.p); i++) {
		//ÕÒµ½¿ªÍ·
		if (s1_.p[i] == s2_.p[0]) {
			int _i = i + 1;
			for (j = 1; j < strlen(s2_.p); j++) {
				if (s1_.p[_i] == s2_.p[j]) {
					check = 1;
					_i++;
				}
				else {
					check = -1;
					break;
				}
			}
			if (j == strlen(s2_.p)) {
				start=i;
				break;
			}
		}
	}
	if (start != -1) {
		int i;
		for (i = start; i < strlen(s1_.p); i++) {
			s1_.p[i] = s1_.p[i + strlen(s2_.p)];
		}
		s1_.p[i] = '\0';
	}	
	Str temp(s1_.p);
	return temp;
}

//Str operator-(const Str& s1, const Str& s2)
//{
//	string s11(s1.p);
//	string s22(s2.p);
//	if (s11.find(s22) != string::npos)
//		s11.erase(s11.find(s22), s22.size());
//	Str temp;
//	temp.length = s11.size();
//	temp.p = new char[temp.length + 1];
//	strcpy(temp.p, s11.c_str());
//	return temp;
//}
