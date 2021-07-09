#include<iostream>
using namespace std;
class Robot {
private:
	string name, type;
	int grade, blood, damage, defence;
	static int num;
public:
	Robot() {};
	Robot(string n, string t, int g) {
		name = n;
		type = t;
		grade = g;
		if (t == "N") {
			blood = grade * 5;
			damage = grade * 5;
			defence = grade * 5;
		}
		else if (t == "A") {
			blood = grade * 5;
			damage = grade * 10;
			defence = grade * 5;
		}
		else if (t == "D") {
			blood = grade * 5;
			damage = grade * 5;
			defence = grade * 10;
		}
		else if (t == "H") {
			blood = grade * 50;
			damage = grade * 5;
			defence = grade * 5;
		}
	}
	bool changeType(string t) {
		if (t == type)
			return false;
		else if (t != type)
			return true;
	}
	void change(string t) {
		if (t == "N") {
			blood = grade * 5;
			damage = grade * 5;
			defence = grade * 5;
		}
		else if (t == "A") {
			blood = grade * 5;
			damage = grade * 10;
			defence = grade * 5;
		}
		else if (t == "D") {
			blood = grade * 5;
			damage = grade * 5;
			defence = grade * 10;
		}
		else if (t == "H") {
			blood = grade * 50;
			damage = grade * 5;
			defence = grade * 5;
		}
	}
	void printStatus() {
		cout << name << "--" << type << "--" << grade << "--" << blood << "--" << damage << "--" << defence << endl;
	}
	void printNum() {
		cout << "The number of robot transform is " << num << endl;
	}
	int getgrade() {
		return grade;
	}
	void setblood(int n) {
		blood = n;
	}
	void setdamage(int n) {
		damage = n;
	}
	void setdefence(int n) {
		defence = n;
	}
	void Num() {
		num++;
	}
	void setType(string t) {
		type = t;
	}
};
int Robot::num = 0;

void change(Robot& R, string t) {
	if (t == "N") {
		R.setblood(R.getgrade() * 5);
		R.setdamage(R.getgrade() * 5);
		R.setdefence(R.getgrade() * 5);
	}
	else if (t == "A") {
		R.setblood(R.getgrade() * 5);
		R.setdamage(R.getgrade() * 10);
		R.setdefence(R.getgrade() * 5);
	}
	else if (t == "D") {
		R.setblood(R.getgrade() * 5);
		R.setdamage(R.getgrade() * 5);
		R.setdefence(R.getgrade() * 10);
	}
	else if (t == "H") {
		R.setblood(R.getgrade() * 50);
		R.setdamage(R.getgrade() * 5);
		R.setdefence(R.getgrade() * 5);
	}
	R.setType(t);
	R.Num();
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string name, type;
		int grade;
		cin >> name >> type >> grade;
		Robot R(name, type, grade);
		string type2;
		cin >> type2;
		if (R.changeType(type2)) {
			::change(R, type2);			
		}
		R.printStatus();
		if (n == 0)
			R.printNum();
	}

	return 0;
}
