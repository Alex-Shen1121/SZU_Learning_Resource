#include<iostream>
using namespace std;
void swap(int& a, int& b, int& c)
{
    int temp;
    if (a <= b)
    {
        temp = b;
        b = a;
        a = temp;
    }
    if (b <= c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (a <= b)
    {
        temp = b;
        b = a;
        a = temp;
    }
    cout << a << ' ' << b << ' ' << c << endl;
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        swap(x, y, z);
    }
    return 0;
} 
