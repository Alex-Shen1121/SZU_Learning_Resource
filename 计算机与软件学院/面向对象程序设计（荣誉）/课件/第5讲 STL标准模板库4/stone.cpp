#include <iostream>
#include <queue>
using namespace std;

#define f(i,l,r) for(i=(l);i<=(r);i++)
#define ff(i,r,l) for(i=(r);i>=(l);i--)

int main()
{
    priority_queue<int>  q(greater<int>);
    int n,e,num1,num2;

    cin>>n;
    while(n--)
    {
        cin>>e;
        q.push(e);
    }

    int sum=0;
    while(q.size()>1)
    {
        num1 = q.top();
        q.pop();
        num2 = q.top();
        q.pop();
        q.push(num1+num2);
        sum += num1+num2;
    }
    cout<<sum<<endl;
}
