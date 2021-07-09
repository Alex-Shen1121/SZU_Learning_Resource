#include<iostream>
using namespace std;
class CA {
private:
	int data;
public:
	CA() {
		data = 0;
		cout << "Constructed by default, value = " << data << endl;
	};
	CA(int i) {
		data = i;
		cout << "Constructed using one argument constructor, value = " << data << endl;
	};
	CA(const CA& temp) {
		data = temp.data;
		cout << "Constructed using copy constructor, value = " << data << endl;
	};
	~CA(){};
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, k;
		cin >> i;
		if (i == 0)
		{
			CA test;
		}
		else if (i == 1)
		{
			cin >> k;
			CA test(k);
		}
		else if (i == 2)
		{
			cin >> k;
			CA test1(k);
			CA test2(test1);
		}
	}

	return 0;
}
