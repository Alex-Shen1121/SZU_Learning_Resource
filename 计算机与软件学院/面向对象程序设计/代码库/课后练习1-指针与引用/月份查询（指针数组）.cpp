#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;
		if (x == 1)
			cout << "January" << endl;
		else if (x == 2)
			cout << "February" << endl;
		else if (x == 3)
			cout << "March" << endl;
		else if (x == 4)
			cout << "April" << endl;
		else if (x == 5)
			cout << "May" << endl;
		else if (x == 6)
			cout << "June" << endl;
		else if (x == 7)
			cout << "July" << endl;
		else if (x == 8)
			cout << "August" << endl;
		else if (x == 9)
			cout << "September" << endl;
		else if (x == 10)
			cout << "Octobor" << endl;
		else if (x == 11)
			cout << "November" << endl;
		else if (x == 12)
			cout << "December" << endl;
		else
			cout << "error" << endl;
	}
 	return 0;
}
