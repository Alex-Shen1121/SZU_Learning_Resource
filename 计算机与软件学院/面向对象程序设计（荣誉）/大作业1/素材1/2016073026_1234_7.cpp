2016073026:Problem1234:??ȷ
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Group{
public:
    virtual int add(int x, int y)=0;
    virtual int sub(int x, int y)=0;
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
        int result=0,i,pow;
        for(i=0,pow=1;i<min(j,k);i++,pow*=10){
            if(ar1[i]-ar2[i]<0)
                result+=(ar1[i]+10-ar2[i]) * pow;
            else
                result+=(ar1[i]-ar2[i]) * pow;
        }
        if(j>k)
            while(i<j){
                result+=ar1[i]*pow;
                i++;
                pow*=10;
            }
        if(k>j)
            while(i<k){
                result+=ar2[i]*pow;
                i++;
                pow*=10;
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
        int result=0,i,pow;
        for(i=0,pow=1;i<min(j,k);i++,pow*=10)
            result+=(ar1[i]+ar2[i])%10 * pow;
        if(j>k)
            while(i<j){
                result+=ar1[i]*pow;
                i++;
                pow*=10;
            }
        if(k>j)
            while(i<k){
                result+=ar2[i]*pow;
                i++;
                pow*=10;
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
        int result=0,i,pow;
        for(i=0,pow=1;i<min(j,k);i++,pow*=10){
            if(ar1[i]-ar2[i]<0)
                result+=(ar1[i]+10-ar2[i]) * pow;
            else
                result+=(ar1[i]-ar2[i]) * pow;
        }
        if(j>k)
            while(i<j){
                result+=ar1[i]*pow;
                i++;
                pow*=10;
            }
        if(k>j)
            while(i<k){
                result+=ar2[i]*pow;
                i++;
                pow*=10;
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

