#include <bitset>
#include <iostream>
using namespace std;

#define N 3001

int main()
{
    bitset<N>  prime;
    int i,j;

    prime.set();

    prime.flip(1);
    prime.flip(0);
    for(i=2; i<=N/2; i++)
    {
        if(prime[i])
        {
            for(j=i+1; j<=N-1; j++)
                if(!(j%i))
                    prime.set(j,0);
        }
    }

    for(i=2; i<=N-1; i++)
        if(prime.test(i))
            cout<<i<<" ";
    cout<<endl;
}
