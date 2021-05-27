             //max_element,min_element,count,find_if���÷�
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
    sum = accumulate(begin(vec)+1,end(vec),0);   //����vec[1]֮����������ֺ�
    result = accumulate(begin(vec),end(vec),0,[](int re,int y){return re+y*y;});  //�����������ֵ�ƽ����
    cout<<sum<<" "<<result<<endl;
    result = accumulate(begin(vec),end(vec),1,multiplies<int>());   //�����������ĳ˻�
    cout<<result<<endl;

    cout<<*max_element(vec.begin(),vec.end())<<endl;   //���ֵ,max_element����ָ�����ֵ�ĵ�����
    cout<<*min_element(begin(vec),end(vec),cmp())<<endl;   //����ֵ��С������ͬ�ϣ�������

    cout<<count(begin(vec),end(vec),10)<<endl;   //ͳ��10���ִ���
    cout<<count_if(begin(vec),end(vec),[](int x){return !(x%2);})<<endl;   //ͳ��ż�����ִ���

    remove_if(begin(vec),end(vec),[](int x)->bool{return x%2;});    //ɾ��vec�����е�����
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
