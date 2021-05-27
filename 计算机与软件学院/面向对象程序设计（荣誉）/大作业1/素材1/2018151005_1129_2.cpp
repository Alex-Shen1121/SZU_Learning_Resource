2018151005:Problem1129:正确
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
/*某银行卡分为普通卡、交通卡、贵宾卡三种，其中普通卡是最简单的卡，具有属性包括卡号（ID）、户名（CName）、余额（Counter），
方法包括：初始化（initial），存款（save），取款（take）、查询（info）。普通卡的属性和方法说明如下:
1.卡号是一串数字，户名用单个字母表示，余额是一个非负整数
2.存款操作是余额增加一笔款项，款项必须是正整数，不合法数据直接返回-1，执行成功则返回1
 3.取款操作是余额减少一笔款项，款项必须是正整数且不能超过余额，不合法数据直接返回-1，执行成功则返回1
 4.查询操作是输出卡的相关信息，包括卡号、户名、余额，信息之间用单个短划线连接*/
class NCard
{
protected:
	int ID;
	char CName;
	int Counter;
public:
	virtual void initial(int ID0, char CName0, int Counter0)
	{
		ID = ID0;
		CName = CName0;
		Counter = Counter0;
	}
	int save(int money)
	{
		if (money > 0)
		{
			Counter += money;
			return 1;
		}
		else
			return -1;
	}
	int take(int money)
	{
		if (money > 0 && money <= Counter)
		{
			Counter -= money;
			return 1;
		}
		else
			return -1;
	}
	virtual void info()
	{
		cout << ID << "-" << CName << "-" << Counter << endl;;
	}
};
/*交通卡是普通卡的升级版，包含额外属性是交通余额（Tcounter），使得交通卡能够当作深圳通使用，包含额外方法是转帐（transfer），
把银行卡的钱转入交通余额中，注意转帐金额不能超过账户原有余额，不合法数据直接返回-1，执行成功则返回1*/
class TCard:public NCard
{
protected:
	int Tcounter;
public:
	virtual void initial(int ID0, char CName0, int Counter0, int Tcounter0)
	{
		NCard::initial(ID0, CName0, Counter0);
		Tcounter = Tcounter0;
	}
	int transfor(int money)
	{
		if (money > 0 && money <= Counter)
		{
			Counter -= money;
			Tcounter += money;
			return 1;
		}
		else
			return -1;
	}
	virtual void info()
	{
		cout << ID << "-" << CName << "-" << Counter <<"-"<< Tcounter << endl;
	}
};
/*贵宾卡是普通卡的升级版，包含额外属性是信用额度（Credit），使得贵宾卡能够透支，即取出超过余额的钱，包含的额外方法是透支（over），
当执行透支操作，余额清0，超过余额的部分用信用额度来扣减。注意透支的最大金额不能超过余额+信用额度，不合法数据直接返回-1，执行成功则返回1*/
class VIPCard:public NCard
{
protected:
	int Credit;
public:
	virtual void initial(int ID0, char CName0, int Counter0, int Credit0)
	{
		NCard::initial(ID0, CName0, Counter0);
		Credit = Credit0;
	}
	int over(int money)
	{
		if (money > 0 && money <= Counter)
		{
			Counter -= money;
			return 1;
		}
		else if (money > Counter&&money <= Credit + Counter)
		{
			Credit -= money - Counter;
			Counter = 0;
			return 1;
		}
		else
			return -1;
	}
	virtual void info()
	{
		cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;;
	}
};
void show(NCard &obj)
{
	obj.info();
}
/*使用c++语言和类继承方法实现上述银行卡的功能

注意，最终提交代码必须分成类定义、类实现、主函数三个区域，并用注释标明
：




输入


第一行输入一张普通卡的数据，分别包含卡号、户名、余额
 第二行输入一张交通卡的数据，分别包含卡号、户名、余额、交通余额
 第三行输入一张贵宾卡的数据，分别包含卡号、户名、余额、信用额度
 第四行输入四个整数，表示对普通卡按顺序先执行2次存款，2次取款
 第五行输入四个整数，表示对交通卡按顺序执行1次存款，1次取款，2次转帐
 第六行输入四个整数，表示对贵宾卡按顺序执行1次存款，1次取款，2次透支

输出


调用多态函数对三张卡执行查询，显示执行完前面所有操作后的各个卡信息。

普通卡信息格式：卡号-户名-余额

金卡信息格式：卡号-户名-余额-交通余额

贵宾卡信息格式：卡号-户名-余额-透支余额


注意：不能在主函数中直接调用类的info方法，必须使用多态函数来调用。


样例输入

1111 A 100
2222 B 200 0
3333 C 300 3000
49 -51 -100 50
100 150 500 55
300 200 2000 5000


样例输出

1111-A-99
2222-B-95-55
3333-C-0-1400


提示*/
int main()
{
	int ID;
	char CName;
	int Counter;
	int Tcounter;
	int Credit;
	cin >> ID >> CName >> Counter;
	NCard n;
	n.initial(ID, CName, Counter);
	cin >> ID >> CName >> Counter >> Tcounter;
	TCard t;
	t.initial(ID, CName, Counter, Tcounter);
	cin >> ID >> CName >> Counter >> Credit;
	VIPCard v;
	v.initial(ID, CName, Counter, Credit);
	//system("pause");
	int money;
	cin >> money;
	n.save(money);
	cin >> money;
	n.save(money);
	cin >> money;
	n.take(money);
	cin >> money;
	n.take(money);
	cin >> money;
	t.save(money);
	cin >> money;
	t.take(money);
	cin >> money;
	t.transfor(money);
	cin >> money;
	t.transfor(money);
	cin >> money;
	v.save(money);
	cin >> money;
	v.take(money);
	cin >> money;
	v.over(money);
	cin >> money;
	v.over(money);
	show(n);
	show(t);
	show(v);
	return 0;
}
