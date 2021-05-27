#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


int main()
{
	vector<int> v{ 1,2,3};
	int count = 0;

    do{
		copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));  //Á÷µü´úÆ÷
		cout << endl;
		count++;
	}while (next_permutation(v.begin(), v.end()));

	cout <<count<<endl;

	return 0;
}
