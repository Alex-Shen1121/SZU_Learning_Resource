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
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] <= 'Z' && str1[i] >= 'A' || str1[i] <= 'z' && str1[i] >= 'a')
				k++;
		}
		cout << k << endl;
	}
	return 0;
}
