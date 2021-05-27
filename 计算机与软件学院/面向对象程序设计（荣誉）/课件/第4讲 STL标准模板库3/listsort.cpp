#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(const int &lhs,const int &rhs)
    {
        return lhs*lhs>rhs*rhs;
    }
}cmp;


int main()
{
    list<int>  l;
    int n,e;


    cin>>n;
    while(n--)
    {
        cin>>e;
        l.push_back(e);
    }

    //l.sort(cmp());
    l.sort(cmp);

    for_each(begin(l),end(l),[](int x){cout<<x<<" ";});
    cout<<endl;
}
