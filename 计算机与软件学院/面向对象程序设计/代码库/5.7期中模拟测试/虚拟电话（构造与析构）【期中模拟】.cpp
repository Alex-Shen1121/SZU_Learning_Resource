#include<iostream>
using namespace std;
class Phone {
private:
	int number;
	char type;
public:
	Phone() {};
	Phone(int n, char t) {
		number = n;
		type = t;
		cout << number << " constructed." << endl;
	}
	~Phone() {
		cout << number << " destructed." << endl;
	}
	void setPhone(int n, char t) {
		number = n;
		type = t;
		cout << number << " constructed." << endl;
	}
	int getNum() {
		return number;
	}
	char getType() {
		return type;
	}
};

class Tel {
private:
	Phone ph;
	int state;
	string owner;
public:
	Tel() {};
	Tel(int n, char t, int s, string o) :ph(n, t) {
		state = s;
		owner = o;
	}
	void setTel(int n, char t, int s, string o){
		ph.setPhone(n, t);
		state = s;
		owner = o;
	}
	int getNum() {
		return ph.getNum();
	}
	string getState() {
		if (state == 1)
			return "use";
		else if (state == 0)
			return "unuse";
	}
	void print() {
		cout << "Phone=" << ph.getNum() << "--Type=" << ph.getType() << "--State=" << getState() << "--Owner=" << owner << endl;
	}
};

int check(Tel* temp, int n,int num) {
	int i;
	for (i = 0; i < n; i++) {
		if (temp[i].getNum() == num) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n = 3, i;
	Tel T[3];
	for (i = 0; i < n; i++) {
		int num;
		char type;
		int state;
		string owner;
		cin >> num >> type >> state >> owner;
		T[i].setTel(num, type, state, owner);
	}
	cin >> n;
	for (i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		int tempi = check(T, 3, temp);
		if (tempi == -1) {
			cout << "wrong number." << endl;
		}
		else
			T[tempi].print();
	}
	return 0;
}
