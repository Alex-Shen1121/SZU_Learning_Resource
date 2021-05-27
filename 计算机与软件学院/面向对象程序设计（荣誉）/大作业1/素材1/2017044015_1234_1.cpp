2017044015:Problem1234:正确
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

class Group
{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class groupA:public Group{
public:
    virtual int add(int x, int y){
        return x + y;
    }
    virtual int sub(int x, int y){
        return x - y;
    }
};

class groupB:public Group{
public:
    virtual int add(int x, int y){
        return x + y;
    }
    virtual int sub(int x, int y){
        int m = 0;
        if(x%10 < y%10)
            m += 10;
        if(x%100/10 < y%100/10)
            m += 100;
        if(x%1000/100 < y%1000/100)
            m += 1000;
        return x - y + m;
    }
};

class groupC:public Group{
public:
    virtual int add(int x, int y){
        int m = 0;
        if(x%10 + y%10 >9)
            m += 10;
        if(x%100/10 + y%100/10 > 9)
            m += 100;
        if(x%1000/100 + y%1000/100 > 9)
            m += 1000;
        return x + y - m;
    }
    virtual int sub(int x, int y){
        int m = 0;
        if(x%10 < y%10)
            m += 10;
        if(x%100/10 < y%100/10)
            m += 100;
        if(x%1000/100 < y%1000/100)
            m += 1000;
        return x - y + m;
    }
};

int main()
{
    int t, g;
    string s;
    cin>>t;
    while(t--){
        cin>>g>>s;
        char sign;
        int index;
        for(int i=0; i < s.size(); i++)
        if(s[i] == '+' || s[i] == '-'){
            sign = s[i];
            index = i;
            break;
        }
        int x, y;
        x = stoi(s.substr(0, index));
        y = stoi(s.substr(index + 1));
        Group* p;
        if(g == 1)
            p = new groupA();
        if(g == 2)
            p = new groupB();
        if(g == 3)
            p = new groupC();
        if(sign == '+')
            cout<<p->add(x, y)<<endl;
        if(sign == '-')
            cout<<p->sub(x, y)<<endl;
        delete p;
    }
    return 0;
}

