2018151014:Problem1234:ÕýÈ·
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int stringToInt(const string s);
string IntToString(const int t);

class Group {
public:
	virtual int add(int x, int y) = 0;
	virtual int sub(int x, int y) = 0;
protected:
	
};

class GroupA : public Group {
public:
	int add(int x, int y) {
		return x + y;
	}
	
	int sub(int x, int y) {
		return x - y;
	}
};

class GroupB : public Group {
public:
	int add(int x, int y) {
		return x + y;
	}
	
	int sub(int x, int y) {
		int result;
		
		string x_str = IntToString(x);
		string y_str = IntToString(y);
		
		reverse(x_str.begin(), x_str.end());
		reverse(y_str.begin(), y_str.end());
		
		int max_value = max(x_str.size(), y_str.size());
		
		while (x_str.size() < max_value) {
			x_str += "0";
		}
		while (y_str.size() < max_value) {
			y_str += "0";
		}
		
		for (int i = 0; i < max_value; i++) {
			if (x_str[i] - '0' - (y_str[i] - '0') < 0) {
				x_str[i] = x_str[i] + '0' - y_str[i] + 10;
			}
			else {
				x_str[i] = x_str[i] + '0' - y_str[i];
			}
		}
		
		reverse(x_str.begin(), x_str.end());
		
		result = stringToInt(x_str);
		return result;
	}
};

class GroupC : public Group {
public:
	int add(int x, int y) {
		int result;
		
		string x_str = IntToString(x);
		string y_str = IntToString(y);
		
		reverse(x_str.begin(), x_str.end());
		reverse(y_str.begin(), y_str.end());
		
		int max_value = max(x_str.size(), y_str.size());
		
		while (x_str.size() < max_value) {
			x_str += "0";
		}
		while (y_str.size() < max_value) {
			y_str += "0";
		}
		
		
		for (int i = 0; i < max_value; i++) {
			if (x_str[i] - '0' + y_str[i] - '0' >= 10) {
				x_str[i] = x_str[i] - '0' + y_str[i] - 10;
			}
			else {
				x_str[i] = x_str[i] - '0' + y_str[i];
			}
		}
		
		reverse(x_str.begin(), x_str.end());
		
		result = stringToInt(x_str);
		return result;
	}
	
	int sub(int x, int y) {
		int result;
		
		string x_str = IntToString(x);
		string y_str = IntToString(y);
		
		reverse(x_str.begin(), x_str.end());
		reverse(y_str.begin(), y_str.end());
		
		int max_value = max(x_str.size(), y_str.size());
		
		while (x_str.size() < max_value) {
			x_str += "0";
		}
		while (y_str.size() < max_value) {
			y_str += "0";
		}
		
		for (int i = 0; i < max_value; i++) {
			if (x_str[i] - '0' - (y_str[i] - '0') < 0) {
				x_str[i] = x_str[i] + '0' - y_str[i] + 10;
			}
			else {
				x_str[i] = x_str[i] + '0' - y_str[i];
			}
		}
		
		reverse(x_str.begin(), x_str.end());
		
		result = stringToInt(x_str);
		return result;
	}
	
};

int stringToInt(const string s) {
	stringstream ss;
	int result;
	ss << s;
	ss >> result;
	
	return result;
}

string IntToString(const int t) {
	stringstream ss;
	string result;
	ss << t;
	ss >> result;
	
	return result;
}

int main(void) {
	
	int t;
	cin >> t;
	while (t--) {
		int who;
		string eqn;
		Group *g;
		
		int x;
		int y;
		char op;
		
		cin >> who >> x >> op >> y;
		if (who == 1) {
			g = new GroupA;
			switch (op) {
				case '+': cout << g->add(x, y) << endl; break;
				case '-': cout << g->sub(x, y) << endl; break;
			}
			delete g;
		}
		else if (who == 2) {
			g = new GroupB;
			switch (op) {
				case '+': cout << g->add(x, y) << endl; break;
				case '-': cout << g->sub(x, y) << endl; break;
			}
			delete g;
		}
		
		else if (who == 3) {
			g = new GroupC;
			switch (op) {
				case '+': cout << g->add(x, y) << endl; break;
				case '-': cout << g->sub(x, y) << endl; break;
			}
			delete g;
		}
	}
	
	return 0;
}
