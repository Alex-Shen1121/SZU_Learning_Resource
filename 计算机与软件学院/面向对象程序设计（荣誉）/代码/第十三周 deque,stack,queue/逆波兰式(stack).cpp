#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>
using namespace std;
//0     1     2      3
//#  <  (  <  +-  <  */
int comparePriority(string s1, string s2) {
	int s1_val = 0, s2_val = 0;
	if (s1 == "#") {
		s1_val = 0;
	}
	else if (s1 == "+") {
		s1_val = 2;
	}
	else if (s1 == "-") {
		s1_val = 2;
	}
	else if (s1 == "*") {
		s1_val = 3;
	}
	else if (s1 == "/") {
		s1_val = 3;
	}
	else if (s1 == "(") {
		s1_val = 1;
	}
	if (s2 == "+") {
		s2_val = 2;
	}
	else if (s2 == "-") {
		s2_val = 2;
	}
	else if (s2 == "*") {
		s2_val = 3;
	}
	else if (s2 == "/") {
		s2_val = 3;
	}
	if (s2_val > s1_val)
		return 1;
	else if (s2_val == s1_val)
		return 0;
	else if (s2_val < s1_val)
		return -1;
}

void print(stack<string> s) {
	stack<string> s_;
	while (!s.empty()) {
		s_.push(s.top());
		s.pop();
	}
	while (!s_.empty()) {
		cout << s_.top() << " ";
		s_.pop();
	}
	cout << endl;
}

void Reverse(stack<string>& s) {
	stack<string> s_;
	while (!s.empty()) {
		s_.push(s.top());
		s.pop();
	}
	s = s_;
}

int main() {
	int N;
	cin >> N; 
	cin.ignore();
	while (N--) {
		string str;
		stack<string> s1;
		stack<string> s2;
		vector<string> v;
		getline(cin, str);
		int start = 0, end = 0;
		int k = 0;
		while (true)
		{
			start = str.find_first_not_of(' ', start);
			end = str.find(' ', start);
			if (end == string::npos ) {
				string str1(str.substr(start, str.size() - start));
				v.push_back(str1);
				break;
			}
			string str1(str.substr(start, end - start));
			v.push_back(str1);
			start = end + 1;
		}
		s1.push("#");
		for (auto it = begin(v); it != v.end(); it++) {
			if (*it == "+" || *it == "-" || *it == "*" || *it == "/" || *it == "(" || *it == ")") {
				if (*it == "(") {
					s1.push(*it);
					continue;
				}
				else if (*it == ")") {
					while (s1.top() != "(") {
						s2.push(s1.top());
						if (!s1.empty())
							s1.pop();
					}
					if (!s1.empty())
						s1.pop();
					continue;
				}
				else {
					if (s1.top() == "(") {
						s1.push(*it);
						continue;
					}
					else {
						if (comparePriority(s1.top(), *it) == 1) {
							s1.push(*it);
							continue;
						}
						else if (comparePriority(s1.top(), *it) == -1 || comparePriority(s1.top(), *it) == 0) {	
							while ((comparePriority(s1.top(), *it) == -1 || comparePriority(s1.top(), *it) == 0) && s1.top() != "(") {
								s2.push(s1.top());
								if (!s1.empty())
									s1.pop();
							}
							s1.push(*it);
						}
					}
				}				
			}
			else {
				s2.push(*it);
			}
		}
		if (s1.size() != 1) {
			while (s1.size() != 1) {
				s2.push(s1.top());
				if (!s1.empty())
					s1.pop();
			}
		}
		print(s2);
		Reverse(s2);
		stack<float> num;
		float num1, num2;
		float ans = 0;
		while (!s2.empty()) {
			if (s2.top() == "+" || s2.top() == "-" || s2.top() == "*" || s2.top() == "/" ) {
				if (s2.top() == "+") {
					if (!s2.empty())
						s2.pop();
					num2 = num.top();
					if (!num.empty())
						num.pop();
					num1 = num.top();
					if (!num.empty())
						num.pop();
					ans = num1 + num2;
					char str_[10];
					_gcvt(ans, 10, str_);
					string str1(str_);
					s2.push(str1);
				}
				else if (s2.top() == "-") {
					if (!s2.empty())
						s2.pop();
					num2 = num.top();
					if (!num.empty())
						num.pop();
					num1 = num.top();
					if (!num.empty())
						num.pop();
					ans = num1 - num2;
					char str_[10];
					_gcvt(ans, 10, str_);
					string str1(str_);
					s2.push(str1);
				}
				else if (s2.top() == "*") {
					if (!s2.empty())
						s2.pop();
					num2 = num.top();
					if (!num.empty())
						num.pop();
					num1 = num.top();
					if (!num.empty())
						num.pop();
					ans = num1 * num2;
					char str_[10];
					_gcvt(ans, 10, str_);
					string str1(str_);
					s2.push(str1);
				}
				else if (s2.top() == "/") {
					if (!s2.empty())
						s2.pop();
					num2 = num.top();
					if (!num.empty())
						num.pop();
					num1 = num.top();
					if (!num.empty())
						num.pop();
					ans = num1 / num2;
					char str_[10];
					_gcvt(ans, 10, str_);
					string str1(str_);
					s2.push(str1);
				}
			}
			else {
				num.push(stof(s2.top()));
				if (!s2.empty())
					s2.pop();
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
