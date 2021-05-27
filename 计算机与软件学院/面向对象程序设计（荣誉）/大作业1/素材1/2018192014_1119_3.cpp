2018192014:Problem1119:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
class BaseAccount{
protected:
    string name,account;
    double balance;
public:
    BaseAccount(string n,string a,double b):
        name(n),account(a),balance(b){
        }
    virtual void deposit(double b)
    {
        balance+=b;
    }
    virtual void withdraw(double b)
    {
        if(balance<b)
        {
            cout<<"insufficient"<<endl;
            return ;
        }
        else
        {
            balance-=b;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
    virtual ~BaseAccount()
    {
	}
};
class BasePlus:virtual public BaseAccount{
protected:
    double limit,limit_sum;
public:
    BasePlus(string n,string a,double b,double l=5000,double ls=0):
    BaseAccount(n,a,b),limit(l),limit_sum(ls){
         
    }
    virtual void deposit(double b)
    {
        balance+=b;
    }
    virtual void withdraw(double b)
    {
        double m=limit-limit_sum;
        if(balance+m<b)
        {
            cout<<"insufficient"<<endl;
            return ;
        }
        else
        {
            if(balance<b)
            {
                m=b-balance;
                limit-=m;
                limit_sum+=m;
                balance=0;
            }
            else
            {
                balance-=b;
            }
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
	virtual ~BasePlus()
    {
	}   
};
int main ()
{
    BaseAccount *ba;
    int t;
    cin>>t;
    while(t--)
    {
        string n,a;
        double b;
        cin>>n>>a>>b;
        if(a[1]=='A')
        {
            ba=new BaseAccount(n,a,b);
             
        }
        else
        {
            ba=new BasePlus(n,a,b);
        }
        cin>>b;
        ba->deposit(b);
        cin>>b;
        ba->withdraw(b);
        cin>>b;
        ba->deposit(b);
        cin>>b;
        ba->withdraw(b);
        ba->display();
        delete ba;
    }
    return 0;
}
