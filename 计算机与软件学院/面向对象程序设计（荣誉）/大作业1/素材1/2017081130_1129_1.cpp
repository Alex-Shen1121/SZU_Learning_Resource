2017081130:Problem1129:´ğ°¸´íÎó
#include <iostream>
using namespace std;
class Account
{
protected:
    string ID;
    char CName;
    int Counter;
public:
    friend void show(Account &obj);
    Account(){};
    Account(string id,char n,int c):ID(id),CName(n),Counter(c){};
    int save(int n)
    {
        if(n>0)
        {
            Counter+=n;
            return 1;
        }
        else
            return 0;

    }
    int take(int n)
    {
        if(n>0&&n<Counter)
        {
            Counter-=n;
            return 1;
        }
        else
            return 0;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};
class Traffic:virtual public Account
{
    int Tcounter;
public:
    Traffic(){};
    Traffic(string id,char n,int c,int t):Account(id,n,c),Tcounter(t){};
    int transfer(int n)
    {
        if(n<Counter)
        {
            Counter-=n;
            Tcounter+=n;
            return 1;
        }
        else
            return 0;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
class VIP:virtual public Account
{
    int Credit;
public:
    VIP(){};
    VIP(string id,char n,int c,int l):Account(id,n,c),Credit(l){};
    int over(int n)
    {
        if(n<=Counter)
        {
            Counter-=n;
            return 1;
        }
        else if(n>(Counter+Credit))
            return 0;
        else
        {
            Credit=Credit-(n-Counter);
            Counter=0;
            return 1;
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
void show(Account &obj)
{
    obj.info();
}
int main()
{
    Account *ac;
    string id1,id2,id3;
    char name1,name2,name3;
    int counter1,counter2,counter3,num1,num2,num3,num4,tcounter,credit;
    cin>>id1>>name1>>counter1;
    cin>>id2>>name2>>counter2>>tcounter;
    cin>>id3>>name3>>counter3>>credit;
    Account a(id1,name1,counter1);
    Traffic t(id2,name2,counter2,tcounter);
    VIP vip(id3,name3,counter3,credit);
    cin>>num1>>num2>>num3>>num4;
    a.save(num1);
    a.take(num2);
    a.take(num3);
    a.take(num4);
    cin>>num1>>num2>>num3>>num4;
    t.save(num1);
    t.take(num2);
    t.transfer(num3);
    t.transfer(num4);
    cin>>num1>>num2>>num3>>num4;
    vip.save(num1);
    vip.take(num2);
    vip.over(num3);
    vip.over(num4);
    show(a);
    show(t);
    show(vip);
    return 0;
}

