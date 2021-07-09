#include<iostream>
using namespace std;

class Remote;

class TV {
	int state, volume, maxchannel, channel, mode, input;
	friend class Remote;
public:
	TV(int state, int volume, int channel, int mode, int input);
	void onoff();
	bool ison()const;
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode();
	void set_input();
	void settings();
};

class Remote {
	int mode;
public:
	Remote(int m) :mode(m) {}
	bool volup(TV& t) {
		return t.volup();
	}
	bool voldown(TV& t) {
		return t.voldown();
	}
	void onoff(TV& t) {
		t.onoff();
	}
	void chanup(TV& t) {
		t.chanup();
	}
	void chandown(TV& t) {
		t.chandown();
	}
	void set_chan(TV& t, int c) {
		t.channel = c;
	}
	void set_mode(TV& t) {
		t.set_mode();
	}
	void set_input(TV& t) {
		t.set_input();
	}
};

TV::TV(int state1, int volume1, int channel1, int mode1, int input1)
{
	state = state1;
	volume = volume1;
	channel = channel1;
	input = input1;
	maxchannel = 100;
	mode = mode1;
}

void TV::onoff()
{
	if (state == 1)
		state = 0;
	else if (state == 0)
		state = 1;
}

bool TV::ison() const
{
	return state;
}

bool TV::volup()
{
	if (ison() && volume < 20)
		volume++;
	return 1;
}

bool TV::voldown()
{
	if (ison() && volume < 20)
		volume--;
	return 1;
}

void TV::chanup()
{
	if (channel < 100 && ison())
		channel++;
}

void TV::chandown()
{
	if (channel < 100 && ison())
		channel--;
}

void TV::set_mode()
{
	if (ison()) {
		if (mode == 1)
			mode = 2;
		else if (mode == 2)
			mode = 1;
	}
	
}

void TV::set_input()
{
	if (ison()) {
		if (input == 1)
			input = 2;
		else if (input == 2)
			input = 1;
	}
}

void TV::settings()
{
	if (ison())
		cout << "on "; 
	else 
		cout << "off ";
	cout << volume << ' ' << channel << ' ';
	if (mode == 1)
		cout << "Cable ";
	else if (mode == 2)
		cout << "Antenna ";
	if (input == 1)
		cout << "VCR" << endl;
	else if (input == 2)
		cout << "TV" << endl;
}

int main()
{
	
	string _state, _mode, _input;
	int state, volume, channel, mode, input;
	cin >> _state >> volume >> channel >> _mode >> _input;
	if (_state == "off") {
		state = 0;
	}
	else if (_state == "on")
		state = 1;
	if (_mode == "Cable") {
		mode = 1;
	}
	else if(_mode == "Antenna")
		mode = 2;
	if (_input == "VCR") {
		input = 1;
	}
	else if(_input == "TV")
		input = 2;
	TV T(state, volume, channel, mode, input);	
	string function[5];
	int i;
	for (i = 0; i < 5; i++)
		cin >> function[i];
	Remote RemoteControl(mode);
	for (int i = 0; i < 5; i++) {
		if (function[i] == "onoff")
			RemoteControl.onoff(T);
		else if (function[i] == "chanup")
			RemoteControl.chanup(T);
		else if (function[i] == "chandown")
			RemoteControl.chandown(T);
		else if (function[i] == "set_mode")
			RemoteControl.set_mode(T);
		else if (function[i] == "set_input")
			RemoteControl.set_input(T);
		else if (function[i] == "set_input")
			RemoteControl.set_input(T);
		else if (function[i] == "volup")
			RemoteControl.volup(T);
		else if (function[i] == "voldown")
			RemoteControl.voldown(T);
	}
	T.settings();
	return 0;
}
