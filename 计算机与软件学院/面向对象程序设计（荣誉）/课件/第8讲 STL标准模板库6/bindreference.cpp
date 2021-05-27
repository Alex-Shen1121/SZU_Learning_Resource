#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

void increment(int &index)
{
    cout<<&index<<endl;
    index++;
}


int main()
{
	int index = 0;

	cout<<&index<<endl;
	cout<<index<<endl;
	increment(index);
	cout<<"after increment: "<<index<<endl;

    cout<<endl<<"------bind-------"<<endl;

	auto f1 = bind(increment,index);
	f1(index);
	cout<<"after bind: "<<index<<endl;

    cout<<endl<<"------bind ref-------"<<endl;
    auto f2 = bind(increment,ref(index));
	f2(index);
	cout<<"after bind(ref): "<<index<<endl;

	//cout<<endl<<"------bind cref------"<<endl;
    /*auto f3 = bind(increment,cref(index));        //wrong
	f3(index);
	cout<<"after bind(ref): "<<index<<endl;*/
	return 1;
}
