#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> list1 = {5,6};
    forward_list<int> list2 = {1,2,3,4};
    forward_list<int> list3 = {7,8,9};

    list1.splice_after(list1.before_begin(),list2);  //1��2��3��4��5��6
    list1.push_front(0);  //0,1,2,3,4,5,6

    forward_list<int>::iterator it = list1.before_begin();  //0֮ǰ
    auto iter = it;

    while(++iter != end(list1))   //ѭ�����itָ��6
        ++it;


    //it = list1.end();    //��itָ��past of the end, ���һ��Ԫ��֮����룬����

    list1.insert_after(it,begin(list3),end(list3));   //6֮�����7,8,9
    for(auto i:list1)    //�������Ԫ��
        cout<<i<<" ";
    cout<<endl;

    for(int x: list2)    //list2�е�Ԫ���Ƶ�list1��
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
