2016073026:Problem1234:时间超限
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
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y){
        int ar1[10]={0},ar2[10]={0};
        int j=0,k=0;
        while(x){
            ar1[j++]=x%10;
            x=x/10;
        }
        while(y){
            ar2[k++]=y%10;
            y=y/10;
        }
        int result=0,i;
        for(i=0;i<min(j,k);i++){
            if(ar1[i]-ar2[i]<0)
                result+=(ar1[i]+10-ar2[i]) * pow(10,i);
            else
                result+=(ar1[i]-ar2[i]) * pow(10,i);
        }
        return result;
    }
};

class GroupC:public Group{
public:
    virtual int add(int x, int y){
        int ar1[10]={0},ar2[10]={0};
        int j=0,k=0;
        while(x){
            ar1[j++]=x%10;
            x=x/10;
        }
        while(y){
            ar2[k++]=y%10;
            y=y/10;
        }
        int result=0,i;
        int minN=min(j,k);
        for(i=0;i<minN;i++)
            result+=(ar1[i]+ar2[i])%10 * pow(10,i);
        if(j>k)
            while(i<j){
                result+=ar1[i]*pow(10,i);
                i++;
            }
        if(k>j)
            while(i<k){
                result+=ar1[i]*pow(10,i);
                j++;
            }
        return result;
    }
    virtual int sub(int x, int y){
        int ar1[10]={0},ar2[10]={0};
        int j=0,k=0;
        while(x){
            ar1[j++]=x%10;
            x=x/10;
        }
        while(y){
            ar2[k++]=y%10;
            y=y/10;
        }
        int result=0,i;
        for(i=0;i<min(j,k);i++){
            if(ar1[i]-ar2[i]<0)
                result+=(ar1[i]+10-ar2[i]) * pow(10,i);
            else
                result+=(ar1[i]-ar2[i]) * pow(10,i);
        }
        return result;
    }
};

int main()
{
    Group* pg;
    int t;
    cin>>t;
    while(t--){
        int group,a,b;
        char op;
        cin>>group>>a>>op>>b;
        switch(group){
            case 1: pg=new GroupA;break;
            case 2: pg=new GroupB;break;
            case 3: pg=new GroupC;break;
        }
        if(op=='+')
            cout<<pg->add(a,b)<<endl;
        else
            cout<<pg->sub(a,b)<<endl;;
    }
    return 0;
}

