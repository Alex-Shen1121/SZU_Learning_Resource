//for_each用法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fun(int &x)
{
    x *= 2;
}

struct funobject
{
    void operator()(int &x)
    {
        x *= 2;
    }
}deffunobject;

int main()
{
    vector<int>  vec;
    int   n,e;

    cin>>n;

    while(n--)
    {
        cin>>e;
        vec.push_back(e);
    }

    for_each(begin(vec),end(vec),fun);     //调用fun,vec中每个元素乘2
    for_each(begin(vec),end(vec),deffunobject);  //函数对象, 元素乘2
    for_each(begin(vec),end(vec),funobject());   //函数对象，元素乘2
    for_each(begin(vec),end(vec),[](int &x){x*=2;});    //lambda表达式，元素乘2


    for(auto x:vec)
        cout<<x<<" ";
    cout<<endl;
}


/*
4 10 20 30 40
5
0 15
1 15
2 55
7 100
10 14
3
15
30
40
2 3
*/

