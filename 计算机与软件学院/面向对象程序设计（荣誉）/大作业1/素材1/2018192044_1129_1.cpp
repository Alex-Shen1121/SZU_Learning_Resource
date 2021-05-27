2018192044:Problem1129:ÕýÈ·
#include<iostream>
using namespace std;
class commoncard
{
protected:
    string ID;
    char CName;
    int Counter;
public:
    commoncard(){}
    void initial(string i,char n,int c)
    {
        ID=i;
        CName=n;
        Counter=c;
    }
    bool save(int i)
    {
        if(i<0)
            return false;
        else
        {
            Counter+=i;
            return true;
        }
    }
    bool take(int i)
    {
        if(i<0||i>Counter)
            return false;
        else
        {
            Counter-=i;
            return true;
        }
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};
class trafficcard:public commoncard
{
    int Tcounter;
public:
    trafficcard(){}
    void initial(string i,char n,int b,int t)
    {
        ID=i;
        CName=n;
        Counter=b;
        Tcounter=t;
    }
    bool transfer(int i)
    {
        if(i>Counter)
            return false;
        else
        {
            Counter-=i;
            Tcounter+=i;
            return true;
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
class supercard:public commoncard
{
    int Credit;
public:
    supercard(){}
    void initial(string i,char n,int b,int c)
    {
        ID=i;
        CName=n;
        Counter=b;
        Credit=c;
    }
    bool over(int i)
    {
        if(i>Counter)
        {
            if(i>(Counter)+Credit)
                return false;
            else
            {
                Counter-=i;
                Credit+=Counter;
                Counter=0;
                return true;
            }
        }
    }
    void info()
    {
         cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
void show(commoncard &obj)
{
    obj.info();
}
int main()
{
    string id;
    char name;
    int balance,a;
    cin>>id>>name>>balance;
    commoncard A;
    A.initial(id,name,balance);
    cin>>id>>name>>balance>>a;
    trafficcard B;
    B.initial(id,name,balance,a);
    cin>>id>>name>>balance>>a;
    supercard C;
    C.initial(id,name,balance,a);
    cin>>a;
    A.save(a);
    cin>>a;
    A.save(a);
    cin>>a;
    A.take(a);
    cin>>a;
    A.take(a);
    cin>>a;
    B.save(a);
    cin>>a;
    B.take(a);
    cin>>a;
    B.transfer(a);
    cin>>a;
    B.transfer(a);
    cin>>a;
    C.save(a);
    cin>>a;
    C.take(a);
    cin>>a;
    C.over(a);
    cin>>a;
    C.over(a);
    show(A);
    show(B);
    show(C);
}

