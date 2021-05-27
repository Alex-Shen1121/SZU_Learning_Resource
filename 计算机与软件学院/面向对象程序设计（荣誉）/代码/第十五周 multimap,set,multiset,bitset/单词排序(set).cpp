#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool check(char c) {
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
		return true;
	else
		return false;
}

int main() {
	set<string> s;
	string str;
	while (getline(cin, str)) {
		int start = 0, end = 0;
		int start1 = 0, end1 = 0;
		while (true) {
			/*start = str.find_first_not_of(' ', start);
			end = str.find(' ', start);
			start1 = start;
			if (end == string::npos)
				end1 = str.length();
			else
				end1 = end;*/
			while (start1 <= str.length() && !check(str[start1]))
				start1++;
			if (start1 > str.length())
				break;
			end1 = start1;
			while (check(str[end1]) || end1 > str.length())
				end1++;
			string data(str.substr(start1, end1 - start1));
			transform(data.begin(), data.end(), data.begin(), ::tolower);
			s.insert(data);
			start1 = end1 + 1;			
		}
	}	
	for (auto x : s) {
		cout << x << endl;
	}
	return 0;
}
