#include<iostream>
using namespace std;

class CPeople {
protected:
	string name;
	char sex;
	int age;
public:
	CPeople(string name, char sex, int age) {
		this->name = name;
		this->sex = sex;
		this->age = age;
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "Sex: " << sex << endl;
		cout << "Age: " << age << endl;
	}
};

class CStudent :virtual public CPeople {
protected:
	int number;
	float grade;
public:
	CStudent(string name, char sex, int age, int number, float grade) :CPeople(name, sex, age) {
		this->number = number;
		this->grade = grade;
	}
	void print() {
		CPeople::print();
		cout << "No.: " << number << endl;
		cout << "Score: " << grade << endl;
	}
};

class CTeacher :virtual public CPeople {
protected:
	string position, department;
public:
	CTeacher(string name, char sex, int age, string position, string department) :CPeople(name, sex, age) {
		this->position = position;
		this->department = department;
	}
	void print() {
		CPeople::print();
		cout << "Position:  " << position << endl;
		cout << "Department:  " << department << endl;
	}
};

class CGradOnWork :public CStudent, public CTeacher {
protected:
	string direction, Tutor;
public:
	CGradOnWork(string name, char sex, int age, int number, float grade, string position, string department, string direction, string Tutor) :CStudent(name, sex, age, number, grade), CPeople(name, sex, age), CTeacher(name, sex, age, position, department) {
		this->direction = direction;
		this->Tutor = Tutor;
	}
	void print() {
		CPeople::print();
		cout << "No.: " << number << endl;
		cout << "Score: " << grade << endl;
		cout << "Position:  " << position << endl;
		cout << "Department:  " << department << endl;
		cout << "Position:  " << position << endl;
		cout << "Department:  " << department << endl;
	}
};

int main() {
	string name;
	char sex;
	int age;
	int number;
	float grade;
	string position, department;
	string direction, Tutor;
	cin >> name >> sex >> age >> number >> grade >> position >> department >> direction >> Tutor;
	CGradOnWork C(name, sex, age, number, grade, position, department, direction, Tutor);
	cout << "People:" << endl;
	C.CPeople::print();
	cout << endl;
	cout << "Student:" << endl;
	C.CStudent::print();
	cout << endl;
	cout << "Teacher:" << endl;
	C.CTeacher::print();
	cout << endl;
	cout << "GradOnWork:" << endl;
	C.CGradOnWork::print();
	return 0;
}
