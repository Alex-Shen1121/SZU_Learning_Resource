2016073026:Problem1234:答案错误
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Group{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group{
public:
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y){return x-y;}
};
class GroupB:public Group{
public:
    virtual int add(int x, int y){
        int ar1[10]={0},ar2[10]={0};
        int j=0,k=0;
        while(x%10!=x){
            ar1[j++]=x%10;
        }
        while(y%10!=y){
            ar2[k++]=y%10;
        }
        int result,i;
        for(i=0;i<min(j,k);i++)
            result+=(ar1[i]+ar2[i])%10 * pow(10,i);
        if(j>k)
            while(i<j)
                result+=ar1[i]*pow(10,i);
        if(k>j)
            while(i<k)
                result+=ar1[i]*pow(10,i);
        return result;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int group;
        
    }
    return 0;
}

