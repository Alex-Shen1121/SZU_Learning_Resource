#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> list1 = {5,6};
    forward_list<int> list2 = {1,2,3,4};
    forward_list<int> list3 = {7,8,9};

    list1.splice_after(list1.before_begin(),list2);  //1，2，3，4，5，6
    list1.push_front(0);  //0,1,2,3,4,5,6

    forward_list<int>::iterator it = list1.before_begin();  //0之前
    auto iter = it;

    while(++iter != end(list1))   //循环向后，it指向6
        ++it;


    //it = list1.end();    //若it指向past of the end, 最后一个元素之后插入，出错。

    list1.insert_after(it,begin(list3),end(list3));   //6之后插入7,8,9
    for(auto i:list1)    //输出所有元素
        cout<<i<<" ";
    cout<<endl;

    for(int x: list2)    //list2中的元素移到list1中
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
