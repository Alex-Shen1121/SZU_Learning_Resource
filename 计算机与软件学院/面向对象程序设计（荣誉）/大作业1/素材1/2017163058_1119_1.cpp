2017163058:Problem1119:��ȷ
#include <iostream>
#include <fstream>
using namespace std;
//ĳ���е�֧Ʊ�˻���Ϊ���࣬һ��Ϊ����֧Ʊ�˻�BaseAccount����һ��Ϊ����͸֧�������Ե�BasePlus֧Ʊ�˻���
//
//BaseAccount֧Ʊ�˻�����Ϣ�������ͻ�����(name)���˻�(account)����ǰ����(balance)
//
//BaseAccount֧Ʊ�˻�����ִ�еĲ������������(deposit)��ȡ��(withdraw)����ʾ�˻���Ϣ(display)��ע�⣺ȡ�����͸֧��������ʽ������Ϣ��insufficient����
//
//BasePlus֧Ʊ�˻�������BaseAccount��������Ϣ�⣬������������Ϣ��
//
//��ʵ��BaseAccount���BasePlus�࣬����BasePlus��̳���BaseAccount�࣬ע��BaseAccount�˻�������BA��ͷ��BasePlus�˻�������BP��ͷ��
class BaseAccount
{
protected:
    string name, account;
    int balance;
public:
    BaseAccount(string n, string a, int b):name(n), account(a), balance(b){}
    void deposit(int money)
    {
        balance += money;
    }
    virtual void withdraw(int money)
    {
        if(balance < money)
        {
            cout<<"insufficient"<<endl;
        }
        else
        {
            balance -= money;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
//͸֧����(limit��Ĭ��Ϊ5000)����ǰ͸֧�ܶ�(limit_sum)��BasePlus֧Ʊ�˻���ִ�еĲ�����BaseAccount��ͬ���������ֲ�����ʵ�ֲ�ͬ��
//
//(1)����ȡ�������������͸֧���޷�Χ��͸֧����������ʾ������Ϣ��insufficient����
//
//(2)������ʾ������������ʾBasePlus��������Ϣ��
class BasePlus:public BaseAccount
{
private:
    int limit, limits_sum;
public:
    BasePlus(string name, string account, int balance):BaseAccount(name, account, balance), limit(5000), limits_sum(0){}
    void withdraw(int money)
    {
        if(money <= balance)
        {
            balance -= money;
        }
        else if(balance > 0 && money < balance + limit)
        {
            limits_sum += (money-balance);
            balance = 0;
        }
        else if(money + limits_sum < limit)
        {
            limits_sum += money;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limits_sum<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string name, account;
    int balance, money, t;
    cin>>t;
    BaseAccount *p;
    while(t --)
    {
        cin>>name>>account>>balance;
        if(account[1] == 'A')
        {
            BaseAccount baseAccount(name, account, balance);
            p = &baseAccount;
            for(int i=0;i<2;i++)
            {
                cin>>money;
                p->deposit(money);
                cin>>money;
                p->withdraw(money);
            }
            p->display();
        }
        else
        {
            BasePlus basePlus(name, account, balance);
            p = &basePlus;
            for(int i=0;i<2;i++)
            {
                cin>>money;
                p->deposit(money);
                cin>>money;
                p->withdraw(money);
            }
            p->display();
        }
    }
    return 0;
}

