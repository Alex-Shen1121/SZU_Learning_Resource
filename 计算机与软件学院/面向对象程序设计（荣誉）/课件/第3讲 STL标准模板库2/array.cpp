#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    array<int,10>  arr;

    arr.fill(10);   //10个10

    //输出所有元素
    for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});
    cout<<endl;

    arr[0] = 20;  //[]访问
    for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});
    cout<<endl;

    cout<<get<3>(arr)<<endl;   //get访问，第3个元素

    //与arr1交换。vector也支持swap
    array<int,10> arr1({1,2,3,4,6,7});
    arr.swap(arr1);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;

    //输出第一个元素,data返回指向第一个元素的指针
    cout<<*arr.data()<<endl;







}
