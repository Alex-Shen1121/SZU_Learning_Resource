#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student
{
public:
	Student(string n, int a, int g) {
		name = n;
		age = a;
		grade = g;
	}
	string name;
	int age;
	int grade;
};

bool cmp(const Student& a, const Student& b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else if (a.name != b.name)
		return a.name < b.name;
	else
		return a.age < b.age;
}

void print(Student s) {
	cout << s.name << " " << s.age << " " << s.grade << endl;
}

int main() {
	int n;
	cin >> n;
	vector<Student>vec;
	while (n--) {
		string name;
		int age, grade;
		cin >> name >> age >> grade;
		Student temp(name, age, grade);
		vec.push_back(temp);
	}
	sort(begin(vec), end(vec), cmp);
	for_each(begin(vec), end(vec), print);
	return 0;
}
