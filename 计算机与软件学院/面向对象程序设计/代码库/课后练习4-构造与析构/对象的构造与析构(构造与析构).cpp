#include<iostream>
using namespace std;
int numi=0;
class OB
{
private:
	int value;
public:
	OB()
	{
		value = numi++;
		cout << "Constructing object " << numi << endl;
	}
	~OB()
	{
		cout << "Destructing object " << numi << endl;
		numi--;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		numi = 0;
		cin >> n;
		OB* p = new OB[n];
		delete[]p;
	}
	return 0;
}
