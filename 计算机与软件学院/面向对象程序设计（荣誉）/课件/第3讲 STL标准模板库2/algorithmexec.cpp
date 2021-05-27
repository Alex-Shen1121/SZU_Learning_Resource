             //max_element,min_element,count,find_if等用法
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct cmp
{
    bool operator()(int lhs,int rhs)
    {
        return abs(lhs)<abs(rhs);
    }
};

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

    int sum,result;
    sum = accumulate(begin(vec)+1,end(vec),0);   //计算vec[1]之后的所有数字和
    result = accumulate(begin(vec),end(vec),0,[](int re,int y){return re+y*y;});  //计算所有数字的平方和
    cout<<sum<<" "<<result<<endl;
    result = accumulate(begin(vec),end(vec),1,multiplies<int>());   //计算所有数的乘积
    cout<<result<<endl;

    cout<<*max_element(vec.begin(),vec.end())<<endl;   //最大值,max_element返回指向最大值的迭代器
    cout<<*min_element(begin(vec),end(vec),cmp())<<endl;   //绝对值最小，返回同上，迭代器

    cout<<count(begin(vec),end(vec),10)<<endl;   //统计10出现次数
    cout<<count_if(begin(vec),end(vec),[](int x){return !(x%2);})<<endl;   //统计偶数出现次数

    remove_if(begin(vec),end(vec),[](int x)->bool{return x%2;});    //删除vec中所有的奇数
    for(auto x:vec)
        cout<<x<<" ";
    cout<<endl;

    vector<string> s;
    s.push_back("shen");
    s.push_back("zhen");
    s.push_back("university");

    auto str = accumulate(begin(s),end(s),string(""),[](string re,string l){return re +" "+l;});
    cout<<str<<endl;   //48


}


/*
5
-1 -2 2 3 4
*/
