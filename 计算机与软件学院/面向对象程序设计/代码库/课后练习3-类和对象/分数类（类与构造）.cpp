#include<iostream>
using namespace std;
class CFraction
{
private:
    int fz, fm;
public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    void set(int x, int y);
    int getGCD();   // 求对象的分子和分母的最大公约数
    void print();
};

CFraction::CFraction(int fz_val, int fm_val)
{
    fz = fz_val;
    fm = fm_val;
}

CFraction CFraction::add(const CFraction& r)
{  
    fz = fz * r.fm + fm * r.fz;
    fm = fm * r.fm;
    return r;
}

CFraction CFraction::sub(const CFraction& r)
{
    fz = fz * r.fm - fm * r.fz;
    fm = fm * r.fm;
    return r;
}

CFraction CFraction::mul(const CFraction& r)
{
    fz = fz * r.fz;
    fm = fm * r.fm;
    return r;
}

CFraction CFraction::div(const CFraction& r)
{
    fz = fz * r.fm;
    fm = fm * r.fz;
    return r;
}

void CFraction::set(int x, int y)
{
    fz = x;
    fm = y;
}

int CFraction::getGCD()
{
    int temp1 = fz, temp2 = fm;
    int i;
    if (temp1 < temp2)
    {
        i = temp2;
        temp2 = temp1;
        temp1 = i;
    }
    int r = temp1 % temp2;
    while (r != 0) {
        temp1 = temp2;
        temp2 = r;
        r = temp1 % temp2;
    }
    return abs(temp2);
}

void CFraction::print()
{
    cout << fz/getGCD() 
        << '/' 
        << fm/getGCD() 
        << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int fz1, fm1, fz2, fm2;
        char temp;
        cin >> fz1 >> temp >> fm1;
        CFraction x(fz1, fm1);
        cin >> fz2 >> temp >> fm2;
        CFraction y(fz2, fm2);
        x.add(y);
        x.print();
        x.set(fz1, fm1);
        y.set(fz2, fm2);
        x.sub(y);
        x.print();
        x.set(fz1, fm1);
        y.set(fz2, fm2);
        x.mul(y);
        x.print();
        x.set(fz1, fm1);
        y.set(fz2, fm2);
        x.div(y);
        x.print();
        cout << '\n';
    }
    return 0;
}
