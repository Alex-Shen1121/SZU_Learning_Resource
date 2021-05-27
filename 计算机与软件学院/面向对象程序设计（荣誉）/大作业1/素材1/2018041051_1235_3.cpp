2018041051:Problem1235:‘À––¥ÌŒÛ
#include<iostream>
#include<string>
#include<cstring>
 
using namespace std;
 
class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(){}
    BaseAccount(string name1,string account1,int balance1):name(name1),account(account1),balance(balance1){}
    void deposit(int num)
    {
        balance+=num;
    }
    virtual void withdraw(int num)
    {
        if((balance-num)>=0)
        {
            balance-=num;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
 
class BasePlus:public BaseAccount
{
protected:
    int limit;
public:
    BasePlus()
    {
        limit=5000;
    }
    BasePlus(string name1,string account1,int balance1):BaseAccount(name1,account1,balance1)
    {
        limit=5000;
    }
    virtual void withdraw(int num)
    {
        if((balance-num+limit)>=0)
        {
            balance-=num;
            if(balance<0)
            {
                limit+=balance;
                balance=0;
            }
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
 
 
 
int main()
{
    BaseAccount *BA;
 
    int t;
    cin>>t;
    while(t--)
    {
        int balance;
        string name,account;
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            BA=new BaseAccount(name,account,balance);
            for(int i=1;i<=4;i++)
            {
                int num;
                cin>>num;
                if(i%2==1)
                {
                    BA->deposit(num);
                }
                else
                {
                    BA->withdraw(num);
                }
            }
            BA->display();
        }
        else
        {
            BA= new BasePlus(name,account,balance);
            for(int i=1;i<=4;i++)
            {
                int num;
                cin>>num;
                if(i%2==1)
                {
                    BA->deposit(num);
                }
                else
                {
                    BA->withdraw(num);
                }
            }
            BA->display();
        }
    }
 	
 	delete []BA;
 	
    return 0;
}
