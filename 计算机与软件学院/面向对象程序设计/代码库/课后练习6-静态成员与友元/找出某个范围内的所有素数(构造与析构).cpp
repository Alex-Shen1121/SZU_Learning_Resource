#include<iostream>
#include<cmath>
using namespace std;
class CSieve
{
private:
    char* p_sieve;
    unsigned long num;                //numÊÇ×î´ó·¶Î§
public:
    CSieve(unsigned long n);
    void printPrime();
    ~CSieve();
};

CSieve::CSieve(unsigned long n)
{
    p_sieve = new char[n+1];
    for (int i = 1; i < n; i++)
        p_sieve[i] = 1;
    num = n;
}

void CSieve::printPrime()
{
    int i, j, q;
    for (i = 2; i < sqrt(num); i++)
    {
        if (p_sieve[i] == 0)
            continue;
        else if (p_sieve[i] == 1) {
            j = num / i;
            for (q = 2; q <= j; q++)
                p_sieve[q * i] = 0;
        }
    }
    for (int i=2; i < num; i++)
    {
        if (p_sieve[i] == 0)
            continue;
        else if (p_sieve[i] == 1)
        {
            if (i == 2)
                cout << i;
            else
                cout << " " << i;
        }            
    }
    cout << endl;
}

CSieve::~CSieve()
{
    delete[]p_sieve;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int nummax;
        cin >> nummax;
        CSieve C1(nummax);
        C1.printPrime();
    }
    return 0;
}
