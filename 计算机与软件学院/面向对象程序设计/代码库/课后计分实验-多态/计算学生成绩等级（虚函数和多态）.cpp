#include<iostream>
using namespace std;

class Student {
protected:
	string name; //学生姓名
	int type; //学生类别:1表示本科生，2表示研究生
	int courses[3]; //3门课的成绩
	string courseGrade; //成绩等级
public:
	Student(string n, char t, int a1, int a2, int a3);//构造方法
	virtual void calculateGrade() = 0;//计算成绩等级
	void print();//输出信息
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
		cout << "本科生,";
	}
	else if (type == '2') {
		cout << "研究生,";
	}
	cout << courseGrade << endl;
}

class Undergraduate :public Student {
public:
	Undergraduate(string n, char t, int a1, int a2, int a3) :Student(n, t, a1, a2, a3) {};
	void calculateGrade() {
		double ave = (courses[0] + courses[1] + courses[2]) / 3.0;
		if (ave < 50) {
			courseGrade = "不及格";
		}
		else if (ave < 60 && ave >= 50) {
			courseGrade = "及格";
		}
		else if (ave < 70 && ave >= 60) {
			courseGrade = "一般";
		}
		else if (ave < 80 && ave >= 70) {
			courseGrade = "良好";
		}
		else if (ave <= 100 && ave >= 80) {
			courseGrade = "优秀";
		}
	}
};

class Postgraduate :public Student {
public:
	Postgraduate(string n, char t, int a1, int a2, int a3) :Student(n, t, a1, a2, a3) {};
	void calculateGrade() {
		double ave = (courses[0] + courses[1] + courses[2]) / 3.0;
		if (ave < 60) {
			courseGrade = "不及格";
		}
		else if (ave < 70 && ave >= 60) {
			courseGrade = "及格";
		}
		else if (ave < 80 && ave >= 70) {
			courseGrade = "一般";
		}
		else if (ave < 90 && ave >= 80) {
			courseGrade = "良好";
		}
		else if (ave <= 100 && ave >= 90) {
			courseGrade = "优秀";
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
