2017133026:Problem1234:正确
#include <iostream>

using namespace std;
class Group
{
public:
    Group(){}
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group{
public:
    virtual int add(int x,int y){
        return x+y;
    }
    virtual int sub(int x,int y){
        return x-y;
    }
};

class GroupB:public Group{
public:
    virtual int add(int x,int y){
        return x+y;
    }
    virtual int sub(int x,int y){
        int sum=0;
        int base=1;
        while(x!=0 || y!=0){
            if(x%10<y%10){
                sum+=((x%10+10-y%10)%10)*base;
            }else{
                sum+=((x%10-y%10)%10)*base;
            }
            base*=10;
            x/=10;
            y/=10;
        }
        sum=sum+x+y;
        return sum;
    }
};

class GroupC:public Group{
public:
    virtual int add(int x,int y){
        int sum=0;
        int base=1;
        while(x!=0 || y!=0){
            sum+=((x%10+y%10)%10)*base;
            base*=10;
            x/=10;
            y/=10;
        }
        sum=sum+x+y;
        return sum;
    }
    virtual int sub(int x,int y){
        int sum=0;
        int base=1;
        while(x!=0 || y!=0){
            if(x%10<y%10){
                sum+=((x%10+10-y%10)%10)*base;
            }else{
                sum+=((x%10-y%10)%10)*base;
            }
            base*=10;
            x/=10;
            y/=10;
        }
        sum=sum+x+y;
        return sum;
    }
};
int main()
{
    int t,x,y;
    cin>>t;
    int type;
    Group *g;
    char op;
    while(t--){
        cin>>type;
        cin>>x>>op>>y;
        if(type==1){
            GroupA a;
            g=&a;
        }else if(type==2){
            GroupB b;
            g=&b;
        }else if(type==3){
            GroupC c;
            g=&c;
        }
        if(op=='+'){
            cout<<g->add(x,y)<<endl;
        }else if(op=='-'){
            cout<<g->sub(x,y)<<endl;
        }
    }
    return 0;
}

