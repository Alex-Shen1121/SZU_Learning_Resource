#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

class CN; //��ǰ����

class EN; //��ǰ����

class Weight { //������
protected:
	char kind[20]; //��������
	int gram; //��
public:
	Weight(char tk[], int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void Print(ostream& out) = 0; //�����ͬ���͵ļ�����Ϣ
};
class CN : public Weight { //�й�����
	int a1, a2, a3, a4;
public:
	CN(int a, int b, int c, int d, char tk[]) :a1(a), a2(b), a3(c), a4(d), Weight(tk) {};
	CN() :Weight("�й�����", 0) {
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
		out << "�й�����:" << a1<<"��" << a2 << "��" << a3 << "Ǯ" << a4 << "��" << endl;
	}
	friend ostream& operator<<(ostream& out, CN& obj);
};

class EN : public Weight { //Ӣ������
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
		out << "Ӣ������:" << a1 << "��" << a2 << "��˾" << a3 << "����" << a4 << "��" << endl;
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

//��ȫ�ֺ�����ʽ������������������3-5��....���б�д
ostream& operator<<(ostream& out, CN& obj)
{
	obj.Print(out);
}
ostream& operator<<(ostream& out, EN& obj)
{
	obj.Print(out);
}


//���غ�����������������ostream������Weight����󣬲��������Ƕ�����������
//���غ���������ò���Weight�����Print����
int main()//������
{
	int tw;
	//����һ���й����������cn
	//���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	CN cn(0, 0, 0, 0, "�й�����");
	cin >> tw;
	cn.Convert(tw); //������Ŀ���ת���й�����
	cout << cn;

	//����Ӣ�����������en
	//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	EN en(0, 0, 0, 0, "Ӣ������");
	cin >> tw;
	en.Convert(tw); //������Ŀ���ת��Ӣ������
	cout << en;
	cn = en; //��Ӣ������ת���й�����
	cout << cn;
	return 0;
}


