#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    array<int,10>  arr;

    arr.fill(10);   //10��10

    //�������Ԫ��
    for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});
    cout<<endl;

    arr[0] = 20;  //[]����
    for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});
    cout<<endl;

    cout<<get<3>(arr)<<endl;   //get���ʣ���3��Ԫ��

    //��arr1������vectorҲ֧��swap
    array<int,10> arr1({1,2,3,4,6,7});
    arr.swap(arr1);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;

    //�����һ��Ԫ��,data����ָ���һ��Ԫ�ص�ָ��
    cout<<*arr.data()<<endl;







}
