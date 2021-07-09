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
		cout << "��ͨ��Ա" << id << "--" << name << "--" << num << endl;
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
		cout << "�����Ա" << id << "--" << name << "--" << num << endl;
	}
};

int main()
{
	Member* pm; 
	//����һ���������ָ��
	int num, id, cost, exchange, rate1, rate2;
	string name;
	//....�����������б�д
	cin >> id >> name >> num;
	Member mm(num, id, name);
	//�������ݣ�������ͨ��Ա����mm
	//ʹ��ָ��pmִ�����²�����
	//1��pmָ����ͨ��Ա����mm
	//2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	//3��ͨ��pm���ô�ӡ�������
	pm = &mm;
	cin >> cost >> exchange;
	pm->Add(cost);
	pm->Exchange(exchange);
	pm->print();
	//�������ݣ����������Ա����vv
	cin >> id >> name >> num >> rate1 >> rate2;
	VIP vv(num, id, name, rate1, rate2);
	//ʹ��ָ��pmִ�����²�����
	//1��pmָ������Ա����vv
	//2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	//3��ͨ��pm���ô�ӡ�������
	pm = &vv;
	cin >> cost >> exchange;
	pm->Add(cost);
	pm->Exchange(exchange);
	pm->print();
	return 0;

}
