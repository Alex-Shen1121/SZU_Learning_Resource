2017301020:Problem1234:答案错误
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Group{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果

};

class GroupA:public Group{
public:
    virtual int add(int x, int y);
    virtual int sub(int x, int y);

};

int GroupA::add(int x, int y){
    cout<<x+y<<endl;
    return x+y;
}

int GroupA::sub(int x, int y){
    cout<<x-y<<endl;
    return x-y;
}

class GroupB:public Group{
public:
    virtual int add(int x, int y);
    virtual int sub(int x, int y);
};

int GroupB::add(int x, int y){
    cout<<x+y<<endl;
    return x+y;
}

int GroupB::sub(int x, int y){
    int a[10];
    int b[10];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));
    int i,j,k;
    for(i=0;i<10;i++){
        a[i]=x%10;
        x=x/10;
        if(x==0)
            break;
    }
    for(j=0;j<10;j++){
        b[j]=y%10;
        y=y/10;
        if(y==0)
            break;
    }
    for(k=0;k<=j;k++){
        a[k]=a[k]-b[k];
        if(a[k]<0)
            a[k]=a[k]+10;
    }
    for(j=i;j>=0;j--)
        cout<<a[j];
    cout<<endl;
}

class GroupC:public Group{
public:
    virtual int add(int x, int y);
    virtual int sub(int x, int y);
};

int GroupC::add(int x,int y){
    int a[10];
    int b[10];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));
    int i,j,k;
    for(i=0;i<10;i++){
        a[i]=x%10;
        x=x/10;
        if(x==0)
            break;
    }
    for(j=0;j<10;j++){
        b[j]=y%10;
        y=y/10;
        if(y==0)
            break;
    }
    for(k=0;k<=j;k++){
        a[k]=a[k]+b[k];
        if(a[k]>=10)
            a[k]=a[k]-10;
    }
    for(j=i;j>=0;j--)
        cout<<a[j];
    cout<<endl;
    return 1;
}

int GroupC::sub(int x, int y){
    int a[10];
    int b[10];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));
    int i,j,k;
    for(i=0;i<10;i++){
        a[i]=x%10;
        x=x/10;
        if(x==0)
            break;
    }
    for(j=0;j<10;j++){
        b[j]=y%10;
        y=y/10;
        if(y==0)
            break;
    }
    for(k=0;k<=j;k++){
        a[k]=a[k]-b[k];
        if(a[k]<0)
            a[k]=a[k]+10;
    }
    for(j=i;j>=0;j--)
        cout<<a[j];
    cout<<endl;
}


int main(){
    Group *pv;
    char ope;
    int t,type,a,b;
    cin>>t;
    while(t--){
        cin>>type>>a>>ope>>b;
        if(type==1){
            GroupA g;
            pv=&g;
            if(ope=='+')
                pv->add(a,b);
            else
                pv->sub(a,b);
        }
        else if(type==2){
            GroupB g;
            pv=&g;
            if(ope=='+')
                pv->add(a,b);
            else
                pv->sub(a,b);
        }
        else{
            GroupC g;
            pv=&g;
            if(ope=='+')
                pv->add(a,b);
            else
                pv->sub(a,b);
        }
    }
    return 0;
}

