2018152062:Problem1119:��ȷ
#include <iostream>
using namespace std;
/*ĳ���е�֧Ʊ�˻���Ϊ���࣬һ��Ϊ����֧Ʊ�˻�BaseAccount����һ��Ϊ����͸֧�������Ե�BasePlus֧Ʊ�˻���
BaseAccount֧Ʊ�˻�����Ϣ�������ͻ�����(name)���˻�(account)����ǰ����(balance)��
BaseAccount֧Ʊ�˻�����ִ�еĲ������������(deposit)��ȡ��(withdraw)����ʾ�˻���Ϣ(display)��
ע�⣺ȡ�����͸֧��������ʽ������Ϣ��insufficient����*/
class BaseAccount
{
protected:
    string name;
    string account;
    float balance;
public:
    BaseAccount(string _name,string _account,float _balance):name(_name),account(_account),balance(_balance){}
    virtual void deposit(float e)
    {
        balance+=e;
    }
    virtual void withdraw(float e)
    {
        if(e<=balance)
            balance-=e;
        else
            cout<<"insufficient"<<endl;
    }
    virtual void print()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
/*BasePlus֧Ʊ�˻�������BaseAccount��������Ϣ�⣬������������Ϣ��͸֧����(limit��Ĭ��Ϊ5000)��
��ǰ͸֧�ܶ�(limit_sum)��BasePlus֧Ʊ�˻���ִ�еĲ�����BaseAccount��ͬ��
�������ֲ�����ʵ�ֲ�ͬ��(1)����ȡ�������������͸֧���޷�Χ��͸֧����������ʾ������Ϣ��insufficient����
(2)������ʾ������������ʾBasePlus��������Ϣ��
��ʵ��BaseAccount���BasePlus�࣬����BasePlus��̳���BaseAccount�࣬
ע��BaseAccount�˻�������BA��ͷ��BasePlus�˻�������BP��ͷ��
Ҫ��ֻʹ��һ������ָ�룬ָ���������Ķ���Ȼ��ʹ��ָ��������еķ�����*/
class BasePlus:public BaseAccount
{
protected:
    float limit;
public:
    BasePlus(string _name,string _account,float _balance):BaseAccount(_name,_account,_balance)
    {
        limit=5000;
    }
    void deposit(float e)
    {
        balance+=e;
    }
    void withdraw(float e)
    {
        if(e<=limit+balance)
        {
            if(e<=balance)
                balance-=e;
            else
            {
                limit-=(e-balance);
                balance=0;
            }
        }
        else
            cout<<"insufficient"<<endl;
    }
    void print()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        BaseAccount *p;
        string name;
        char account[10];
        float balance;
        float d1,w1,d2,w2;
        cin>>name>>account>>balance>>d1>>w1>>d2>>w2;
        if(account[1]=='A')
        {
            BaseAccount u(name,account,balance);
            p=&u;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->print();
        }
        else
        {
            BasePlus v(name,account,balance);
            p=&v;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->print();
        }
    }
    return 0;
}

