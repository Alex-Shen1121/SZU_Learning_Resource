#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    //int score[] = {99,100,78,80,85,60,50};
    int score[]={62,41,30,28,16,22,13,19,17,15};
    vector<int> v(score,score+10);

    make_heap(v.begin(),v.end());
    //sort_heap(v.begin(),v.end(),greater<int>());
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;


    //循环排序
    for(auto it=begin(v),itend=end(v); itend!=it; itend--)
    {
        pop_heap(it,itend);   //最大值放到itend-1,下溯调整[it,itend-1)为堆
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
    }
    v.push_back(1000);   //尾端插入1000
    push_heap(begin(v),end(v));  //上溯调整为堆
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;





}

