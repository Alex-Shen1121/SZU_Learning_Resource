#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str1, str2, str3;
		cin.ignore();
		getline(cin, str1);
		getline(cin, str2);
		getline(cin, str3);
		while (true) {
			if (str1.find(str2) != str1.npos) {
				str1.replace(str1.find(str2), str2.length(), str3);					
			}
			else
				break;
		}
		cout << str1 << endl;
	}
	return 0;
}
