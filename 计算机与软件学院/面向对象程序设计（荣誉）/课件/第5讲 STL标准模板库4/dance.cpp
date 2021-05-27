#include <iostream>
#include <queue>
using namespace std;

#define f(i,l,r) for(i=(l);i<=(r);i++)
#define ff(i,r,l) for(i=(r);i>=(l);i--)

int main()
{
    queue<int> mq,fq;
    int m,n,i,k;

    cin>>m>>n;

    f(i,1,m)
    {
        mq.push(i);
    }
    f(i,1,n)
    {
        fq.push(i);
    }

    cin>>k;
    f(i,1,k)
    {
        cout<<mq.front()<<" "<<fq.front()<<endl;
        mq.push(mq.front());
        fq.push(fq.front());
        mq.pop();
        fq.pop();
    }



}
