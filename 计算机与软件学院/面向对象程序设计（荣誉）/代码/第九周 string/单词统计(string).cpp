#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string str1;
		int k = 0;
		getline(cin, str1);
		int start = 0, end = 0;
		while(true)
		{
			start = str1.find_first_not_of(' ', start);
			end = str1.find(' ', start);
			if (start != string::npos)
				k++;
			if (end == string::npos)
				break;
			start = end + 1;
		}
		cout << k << endl;
	}
	return 0;
}
