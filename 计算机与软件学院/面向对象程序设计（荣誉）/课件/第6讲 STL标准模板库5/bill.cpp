#include <set>
#include <iostream>
using namespace std;

int main()
{
    multiset<int> billset;
    int t,n,e;

    cin>>t;

    while(t--)
    {
        cin>>n;

        while(n--)
        {
            cin>>e;
            billset.insert(e);
        }
        if(t>0)
        {
            cout<<*billset.begin()<<" "<<*(--billset.end())<<endl;
            billset.erase(billset.begin());
            billset.erase(--billset.end());
        }
        else
        {
            for(auto x:billset)
                cout<<x<<" ";
            cout<<endl;

        }
    }
}

