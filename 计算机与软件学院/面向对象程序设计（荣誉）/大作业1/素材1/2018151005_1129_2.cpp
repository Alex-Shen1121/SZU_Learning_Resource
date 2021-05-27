2018151005:Problem1129:��ȷ
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
/*ĳ���п���Ϊ��ͨ������ͨ������������֣�������ͨ������򵥵Ŀ����������԰������ţ�ID����������CName������Counter����
������������ʼ����initial������save����ȡ�take������ѯ��info������ͨ�������Ժͷ���˵������:
1.������һ�����֣������õ�����ĸ��ʾ�������һ���Ǹ�����
2.���������������һ�ʿ����������������������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
 3.ȡ�������������һ�ʿ������������������Ҳ��ܳ��������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
 4.��ѯ������������������Ϣ���������š�����������Ϣ֮���õ����̻�������*/
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
/*��ͨ������ͨ���������棬�������������ǽ�ͨ��Tcounter����ʹ�ý�ͨ���ܹ���������ͨʹ�ã��������ⷽ����ת�ʣ�transfer����
�����п���Ǯת�뽻ͨ����У�ע��ת�ʽ��ܳ����˻�ԭ�������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1*/
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
/*���������ͨ���������棬�����������������ö�ȣ�Credit����ʹ�ù�����ܹ�͸֧����ȡ����������Ǯ�������Ķ��ⷽ����͸֧��over����
��ִ��͸֧�����������0���������Ĳ��������ö�����ۼ���ע��͸֧�������ܳ������+���ö�ȣ����Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1*/
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
/*ʹ��c++���Ժ���̳з���ʵ���������п��Ĺ���

ע�⣬�����ύ�������ֳ��ඨ�塢��ʵ�֡��������������򣬲���ע�ͱ���
��




����


��һ������һ����ͨ�������ݣ��ֱ�������š����������
 �ڶ�������һ�Ž�ͨ�������ݣ��ֱ�������š�����������ͨ���
 ����������һ�Ź���������ݣ��ֱ�������š������������ö��
 �����������ĸ���������ʾ����ͨ����˳����ִ��2�δ�2��ȡ��
 �����������ĸ���������ʾ�Խ�ͨ����˳��ִ��1�δ�1��ȡ�2��ת��
 �����������ĸ���������ʾ�Թ������˳��ִ��1�δ�1��ȡ�2��͸֧

���


���ö�̬���������ſ�ִ�в�ѯ����ʾִ����ǰ�����в�����ĸ�������Ϣ��

��ͨ����Ϣ��ʽ������-����-���

����Ϣ��ʽ������-����-���-��ͨ���

�������Ϣ��ʽ������-����-���-͸֧���


ע�⣺��������������ֱ�ӵ������info����������ʹ�ö�̬���������á�


��������

1111 A 100
2222 B 200 0
3333 C 300 3000
49 -51 -100 50
100 150 500 55
300 200 2000 5000


�������

1111-A-99
2222-B-95-55
3333-C-0-1400


��ʾ*/
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
