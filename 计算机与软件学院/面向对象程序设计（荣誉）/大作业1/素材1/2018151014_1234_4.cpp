2018151014:Problem1234:ÕıÈ·
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

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
		stringstream ssx, ssy;
		ssx << x;
		ssy << y;
		
		string x_str;
		string y_str;
		ssx >> x_str;
		ssy >> y_str;
		
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
		
		stringstream ssre;
		ssre << x_str;
		ssre >> result;
		return result;
	}
};

class GroupC : public Group {
public:
	int add(int x, int y) {
		int result;
		stringstream ssx, ssy;
		ssx << x;
		ssy << y;
		
		string x_str;
		string y_str;
		ssx >> x_str;
		ssy >> y_str;
		
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
		
		stringstream ssre;
		ssre << x_str;
		ssre >> result;
		return result;
	}
	
	int sub(int x, int y) {
		int result;
		stringstream ssx, ssy;
		ssx << x;
		ssy << y;
		
		string x_str;
		string y_str;
		ssx >> x_str;
		ssy >> y_str;
		
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
		
		stringstream ssre;
		ssre << x_str;
		ssre >> result;
		return result;
	}
	
};

int main(void) {
	
	int t;
	cin >> t;
	while (t--) {
		int x;
		string eqn;
		Group *g;
		
		cin >> x >> eqn;
		
		if (x == 1) {
			int id = eqn.find('+');
			stringstream ssx, ssy;
			int x, y;
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupA;
				cout << g->add(x, y) << endl;
			}
			
			id = eqn.find('-');
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupA;
				cout << g->sub(x, y) << endl;
			}
		}
		else if (x == 2) {
			int id = eqn.find('+');
			stringstream ssx, ssy;
			int x, y;
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupB;
				cout << g->add(x, y) << endl;
			}
			
			id = eqn.find('-');
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupB;
				cout << g->sub(x, y) << endl;
			}
		}
		else if (x == 3) {
			int id = eqn.find('+');
			stringstream ssx, ssy;
			int x, y;
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupC;
				cout << g->add(x, y) << endl;
			}
			
			id = eqn.find('-');
			if (id >= 0) {
				string x_str = "";
				for (int i = 0; i < id; i++) {
					x_str += eqn[i];
				}
				
				string y_str = "";
				for (int i = id+1; i < eqn.size(); i++) {
					y_str += eqn[i];
				}
				ssx << x_str;
				ssx >> x;
				ssy << y_str;
				ssy >> y;
				
				g = new GroupC;
				cout << g->sub(x, y) << endl;
			}
		}
		delete g;
	}
	
	return 0;
}
