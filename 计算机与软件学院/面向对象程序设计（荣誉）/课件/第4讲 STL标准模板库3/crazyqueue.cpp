#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int maxcrazy(vector<int> v,deque<int> q);

int main()
{
    vector<int> vec;
    deque<int> que;
    int n,e;


    cin>>n;
    while(n--)
    {
        cin>>e;
        vec.push_back(e);
    }
    sort(begin(vec),end(vec));

    cout<<maxcrazy(vec,que)<<endl;
}

int maxcrazy(vector<int> v,deque<int> q)
{
    int sum = 0,maxvalue;
    q.push_back(v.back());
    v.erase(v.end()-1);

    while(!v.empty())
    {
        maxvalue = 0xc0c0c0c0;
        maxvalue = max(maxvalue,abs(v.front()-q.back()));
        maxvalue = max(maxvalue,abs(v.front()-q.front()));
        maxvalue = max(maxvalue,abs(v.back()-q.back()));
        maxvalue = max(maxvalue,abs(v.back()-q.front()));

        if(maxvalue == abs(v.front()-q.back()))
        {
            q.push_back(v.front());
            v.erase(begin(v));
        }
        else if(maxvalue == abs(v.front()-q.front()))
        {
            q.push_front(v.front());
            v.erase(begin(v));
        }
        else if(maxvalue == abs(v.back()-q.back()))
        {
           q.push_back(v.back());
           v.erase(end(v)-1);
        }
        else if(maxvalue == abs(v.back()-q.front()))
        {
            q.push_front(v.back());
            v.erase(end(v)-1);
        }
        sum+=maxvalue;
    }
    return sum;
}
