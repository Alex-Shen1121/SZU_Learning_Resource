2018152102:Problem1234:正确
#include <iostream>
#include <iomanip>

using namespace std;
class Group{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group {
public:
    int add(int x,int y) {
        return x+y;
    }
    int sub(int x,int y) {
        return x-y;
    }
};
class GroupB:public Group {
public:
   int add(int x,int y) {
        return x+y;
    }
    int sub(int x,int y) {
        int sum = 0;
        int a,b;
        int bit = 1;
        while(1) {
            a = x%10;
            b = y%10;
            x = x/10;
            y = y/10;
            sum = sum + (a-b+10)%10*bit;
            bit = bit * 10;
            if(x==0 && y==0) break;
        }
        return sum;
    }
};
class GroupC:public Group {
public:
    int add(int x,int y) {
        int sum = 0;
        int a,b;
        int bit = 1;
        while(1) {
            a = x%10;
            b = y%10;
            x = x/10;
            y = y/10;
            sum = sum + (a+b)%10*bit;
            bit = bit * 10;
            if(x==0 && y==0) break;
        }
        return sum;
    }
    int sub(int x,int y) {
        int sum = 0;
        int a,b;
        int bit = 1;
        while(1) {
            a = x%10;
            b = y%10;
            x = x/10;
            y = y/10;
            sum = sum + (a-b+10)%10*bit;
            bit = bit * 10;
            if(x==0 && y==0) break;
        }
        return sum;
    }
};
int main() {
    int t;

    cin>>t;
    while(t--) {
        int num;
        int x,y;
        char type;
        Group * p;

        cin>>num;
        cin>>x>>type>>y;
        if(num == 1) {
            p = new GroupA;
        }else if(num == 2) {
            p = new GroupB;
        }else {
            p = new GroupC;
        }

        if(type == '+') {
            cout<<p->add(x,y)<<endl;
        }else {
            cout<<p->sub(x,y)<<endl;
        }

        delete p;
    }

    return 0;
}

