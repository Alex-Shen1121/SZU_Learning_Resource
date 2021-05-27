#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;


int main()
{
	vector<int> v{102,90,80,110,200,70,60,4,300};
	vector<int> rev2;

	//lambdaʵ��
	partition_copy(begin(v),end(v),ostream_iterator<int>(cout," "),back_inserter(rev2),
                [](int x)->bool { return x>=100;});

    for(auto x:rev2)
        cout<<x<<" ";
    cout<<endl;

    //����ʵ��
    partition_copy(begin(v),end(v),ostream_iterator<int>(cout," "),back_inserter(rev2),
                   bind(greater<int>(),placeholders::_1,99));

    for(auto x:rev2)
        cout<<x<<" ";
    cout<<endl;


    //����,���°��Ų���˳��_2<_1������
    /*sort(begin(v),end(v),bind(less<int>(),placeholders::_2,placeholders::_1));

    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;*/

    //ȡ����,ǰ�벿��x<100�ķ�
    rev2.clear();
    partition_copy(begin(v),end(v),ostream_iterator<int>(cout," "),back_inserter(rev2),
                   not_fn(bind(less<int>(),placeholders::_1,100)));
    for(auto x:rev2)
        cout<<x<<" ";
    cout<<endl;
	return 0;
}
