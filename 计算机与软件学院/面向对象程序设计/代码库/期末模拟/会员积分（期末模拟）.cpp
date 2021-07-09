#include<iostream>
using namespace std;

class Member {
protected:
	int num, id;
	string name;
public:
	Member(int n, int i, string na) :num(n), id(i), name(na) {};
	virtual void Add(int m) {
		num += m;
	}
	virtual void Exchange(int m) {
		int temp;
		temp = m / 100 * 100;
		num -= temp;
	}
	virtual void print() {
		cout << "普通会员" << id << "--" << name << "--" << num << endl;
	}
};


class VIP:public Member { 
private:
	int rate1, rate2;
public:
	VIP(int n, int i, string na, int r1, int r2) :Member(n, i, na), rate1(r1), rate2(r2) {};
	virtual void Add(int m) {
		num += rate1 * m;
	}
	virtual void Exchange(int m) {
		int temp;
		temp = m / rate2 * rate2;
		num -= temp;
	}
	virtual void print() {
		cout << "贵宾会员" << id << "--" << name << "--" << num << endl;
	}
};

int main()
{
	Member* pm; 
	//创建一个基类对象指针
	int num, id, cost, exchange, rate1, rate2;
	string name;
	//....其他变量自行编写
	cin >> id >> name >> num;
	Member mm(num, id, name);
	//输入数据，创建普通会员对象mm
	//使用指针pm执行以下操作：
	//1、pm指向普通会员对象mm
	//2、输入数据，通过pm执行积分累加和积分兑换
	//3、通过pm调用打印方法输出
	pm = &mm;
	cin >> cost >> exchange;
	pm->Add(cost);
	pm->Exchange(exchange);
	pm->print();
	//输入数据，创建贵宾会员对象vv
	cin >> id >> name >> num >> rate1 >> rate2;
	VIP vv(num, id, name, rate1, rate2);
	//使用指针pm执行以下操作：
	//1、pm指向贵宾会员对象vv
	//2、输入数据，通过pm执行积分累加和积分兑换
	//3、通过pm调用打印方法输出
	pm = &vv;
	cin >> cost >> exchange;
	pm->Add(cost);
	pm->Exchange(exchange);
	pm->print();
	return 0;

}
