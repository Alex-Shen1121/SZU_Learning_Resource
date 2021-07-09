#include<iostream>
using namespace std;

class Student {
protected:
	string name; //ѧ������
	int type; //ѧ�����:1��ʾ��������2��ʾ�о���
	int courses[3]; //3�ſεĳɼ�
	string courseGrade; //�ɼ��ȼ�
public:
	Student(string n, char t, int a1, int a2, int a3);//���췽��
	virtual void calculateGrade() = 0;//����ɼ��ȼ�
	void print();//�����Ϣ
};

Student::Student(string n, char t, int a1, int a2, int a3)
{
	name = n;
	type = t;
	courses[0] = a1;
	courses[1] = a2;
	courses[2] = a3;
}

void Student::print()
{
	cout << name << ",";
	if (type == '1') {
		cout << "������,";
	}
	else if (type == '2') {
		cout << "�о���,";
	}
	cout << courseGrade << endl;
}

class Undergraduate :public Student {
public:
	Undergraduate(string n, char t, int a1, int a2, int a3) :Student(n, t, a1, a2, a3) {};
	void calculateGrade() {
		double ave = (courses[0] + courses[1] + courses[2]) / 3.0;
		if (ave < 50) {
			courseGrade = "������";
		}
		else if (ave < 60 && ave >= 50) {
			courseGrade = "����";
		}
		else if (ave < 70 && ave >= 60) {
			courseGrade = "һ��";
		}
		else if (ave < 80 && ave >= 70) {
			courseGrade = "����";
		}
		else if (ave <= 100 && ave >= 80) {
			courseGrade = "����";
		}
	}
};

class Postgraduate :public Student {
public:
	Postgraduate(string n, char t, int a1, int a2, int a3) :Student(n, t, a1, a2, a3) {};
	void calculateGrade() {
		double ave = (courses[0] + courses[1] + courses[2]) / 3.0;
		if (ave < 60) {
			courseGrade = "������";
		}
		else if (ave < 70 && ave >= 60) {
			courseGrade = "����";
		}
		else if (ave < 80 && ave >= 70) {
			courseGrade = "һ��";
		}
		else if (ave < 90 && ave >= 80) {
			courseGrade = "����";
		}
		else if (ave <= 100 && ave >= 90) {
			courseGrade = "����";
		}
	}
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		string name;
		char type;
		int a1, a2, a3;
		Student* p = NULL;
		cin >> name >> type >> a1 >> a2 >> a3;
		if (type == '1') {
			p = new Undergraduate(name, type, a1, a2, a3);
		}
		else if (type == '2') {
			p = new Postgraduate(name, type, a1, a2, a3);
		}
		p->calculateGrade();
		p->print();
	}
	return 0;
}
