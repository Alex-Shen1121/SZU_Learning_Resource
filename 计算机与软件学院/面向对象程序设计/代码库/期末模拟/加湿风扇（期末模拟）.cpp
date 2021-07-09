#include<iostream>
#include<algorithm>
using namespace std;

class Device {
protected:
	int id, power;
public:
	Device(int i = 0, int p = 0) :id(i), power(p) {};
	void print() {
		cout << "���" << id << "--����" << power << "W" << endl;
	}
};

class Fan :virtual public Device {
protected:
	int winddirection, windpower;
public:
	void wdControl(int i) {
		winddirection = i;
	}
	void wpControl(int i) {
		windpower = i;
	}
	void print() {
		if (winddirection == 0)
			cout << "����";
		else if (winddirection == 1)
			cout << "��ת";
		cout << "����--����" << windpower << "��" << endl;
	}
};

class Humidifier :virtual public Device {
protected:
	float current_water, max_water;
public:
	int Alert() {
		if (current_water >= max_water * 0.5)
			return 1;
		else if (current_water >= max_water * 0.1)
			return 2;
		else
			return 3;
	}
	void print() {
		cout << "ʵ��ˮ����" << current_water << "��--ˮ��";
		if (Alert() == 1)
			cout << "����" << endl;
		else if (Alert() == 2)
			cout << "ƫ��" << endl;
		else if (Alert() == 3)
			cout << "����" << endl;
	}
};

class Humid_Fan :public Fan, public Humidifier {
protected:
	int status;
public:
	Humid_Fan(int i, int p, int wd, int wp, float c_w, float m_w, int s) :Device(i, p) {
		winddirection = wd;
		windpower = wp;
		current_water = c_w;
		max_water = m_w;
		status = s;
	}
	void setStatus(int i) {
		status = i;
		if (i == 1) {
			winddirection = 0;
			windpower = 1;
		}
		else if (i == 2) {
			winddirection = 1;
			windpower = 2;
		}
		else if (i == 3) {
			winddirection = 1;
			windpower = 3;
		}
	}
	void print() {
		cout << "��ʪ����--��λ" << status << endl;
		Device::print();
		Fan::print();
		Humidifier::print();		
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int id, power, winddirection, windpower, status;
		float current_water, max_water;
		cin >> id >> power >> winddirection >> windpower >> current_water >> max_water >> status;
		Humid_Fan obj(id, power, winddirection, windpower, current_water, max_water, status);
		int status2;
		cin >> status2;
		obj.setStatus(status2);
		obj.print();
	}
	return 0;
}
