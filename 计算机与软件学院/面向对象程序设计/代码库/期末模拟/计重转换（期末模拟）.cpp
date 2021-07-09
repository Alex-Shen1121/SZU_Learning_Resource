#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

class CN; //提前声明

class EN; //提前声明

class Weight { //抽象类
protected:
	char kind[20]; //计重类型
	int gram; //克
public:
	Weight(char tk[], int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void Print(ostream& out) = 0; //输出不同类型的计重信息
};
class CN : public Weight { //中国计重
	int a1, a2, a3, a4;
public:
	CN(int a, int b, int c, int d, char tk[]) :a1(a), a2(b), a3(c), a4(d), Weight(tk) {};
	CN() :Weight("中国计重", 0) {
		a1 = a2 = a3 = a4 = 0;
	}
	void Convert(int tw) {
		a1 = tw / 500;
		tw -= a1 * 500;
		a2 = tw / 50;
		tw -= a2 * 50;
		a3 = tw / 5;
		tw -= a3 * 5;
		a4 = tw;
	}
	void Print(ostream& out) {
		out << "中国计重:" << a1<<"斤" << a2 << "两" << a3 << "钱" << a4 << "克" << endl;
	}
	friend ostream& operator<<(ostream& out, CN& obj);
};

class EN : public Weight { //英国计重
	int a1, a2, a3, a4;
public:
	EN(int a, int b, int c, int d, char tk[]) :a1(a), a2(b), a3(c), a4(d), Weight(tk) {};
	void Convert(int tw) {
		a1 = tw / 512;
		tw -= a1 * 512;
		a2 = tw / 32;
		tw -= a2 * 32;
		a3 = tw / 2;
		tw -= a3 * 2;
		a4 = tw;
	}
	void Print(ostream& out) {
		out << "英国计重:" << a1 << "磅" << a2 << "盎司" << a3 << "打兰" << a4 << "克" << endl;
	}
	friend ostream& operator<<(ostream& out, EN& obj);
	operator CN() {
		CN temp;
		int a;
		a = 512 * a1 + 32 * a2 + 2 * a3 + a4;
		temp.Convert(a);
		return temp;
	}
};

//以全局函数方式重载输出运算符，代码3-5行....自行编写
ostream& operator<<(ostream& out, CN& obj)
{
	obj.Print(out);
}
ostream& operator<<(ostream& out, EN& obj)
{
	obj.Print(out);
}


//重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
//重载函数必须调用参数Weight对象的Print方法
int main()//主函数
{
	int tw;
	//创建一个中国计重类对象cn
	//构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); //把输入的克数转成中国计重
	cout << cn;

	//创建英国计重类对象en
	//构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); //把输入的克数转成英国计重
	cout << en;
	cn = en; //把英国计重转成中国计重
	cout << cn;
	return 0;
}


