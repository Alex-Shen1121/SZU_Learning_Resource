2018151005:Problem1119:�𰸴���
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*ĳ���е�֧Ʊ�˻���Ϊ���࣬һ��Ϊ����֧Ʊ�˻�BaseAccount����һ��Ϊ����͸֧�������Ե�BasePlus֧Ʊ�˻���


BaseAccount֧Ʊ�˻�����Ϣ�������ͻ�����(name)���˻�(account)����ǰ����(balance)��BaseAccount֧Ʊ�˻���
��ִ�еĲ������������(deposit)��ȡ��(withdraw)����ʾ�˻���Ϣ(display)��ע�⣺ȡ�����͸֧��������
ʽ������Ϣ��insufficient����*/

class BaseAccount
{
protected:
    string name;
    char account[8];
    float balance;
public:
    BaseAccount(){}
    BaseAccount(string name0,char* account0,float balance0):name(name0),balance(balance0)
    {
        strcpy(account,account0);
    }
    virtual void deposit(float money)
    {
        balance+=money;
    }
    virtual void withdraw(float money)
    {
        if(balance>=money)
        {
            balance-=money;
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
/*BasePlus֧Ʊ�˻�������BaseAccount��������Ϣ�⣬������������Ϣ��͸֧����(limit��Ĭ��Ϊ5000)����ǰ͸֧��
��(limit_sum)��BasePlus֧Ʊ�˻���ִ�еĲ�����BaseAccount��ͬ���������ֲ�����ʵ�ֲ�ͬ��(1)����ȡ�������
������͸֧���޷�Χ��͸֧����������ʾ������Ϣ��insufficient����(2)��
����ʾ������������ʾBasePlus��������Ϣ��*/


class BasePlus:public BaseAccount
{
private:
    float limit;
    float limit_sum;
public:
    BasePlus():limit(5000),limit_sum(0){}
    BasePlus(string name0,char* account0,float balance0):BaseAccount(name0,account0,balance0),
        limit(5000),limit_sum(0){}
    virtual void deposit(float money)
    {
        int balance_real=balance-limit_sum+money;
        if(balance_real>=0)
        {
            balance=balance_real;
            limit_sum=0;
        }
        else
        {
            balance=0;
            limit_sum=-balance_real;
        }
    }
    virtual void withdraw(float money)
    {
        int balance_real=balance-limit_sum-money;
        if(balance_real>=0)
        {
            balance=balance_real;
            limit_sum=0;
        }
        else if(balance_real<0&&balance_real>=-limit)
        {
            balance=0;
            limit_sum=-balance_real;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};
/*��ʵ��BaseAccount���BasePlus�࣬����BasePlus��̳���BaseAccount�࣬ע��BaseAccount�˻�������BA��ͷ��
BasePlus�˻�������BP��ͷ��

Ҫ��ֻʹ��һ������ָ�룬ָ���������Ķ���Ȼ��ʹ��ָ��������еķ�����*/
int main()
{
    int t;
    cin>>t;
    BaseAccount* pa;
    while(t--)
    {
        string name;
        char account[8];
        float balance;
        cin>>name>>account>>balance;
        char type[3];
        type[0]=account[0];
        type[1]=account[1];
        type[2]='\0';
        if(strcmp(type,"BA")==0)
        {
            BaseAccount a(name,account,balance);
            pa=&a;
        }
        else if(strcmp(type,"BP")==0)
        {
            BasePlus a(name,account,balance);
            pa=&a;
        }
        float m1,m2,m3,m4;
        cin>>m1>>m2>>m3>>m4;
        pa->deposit(m1);
        pa->withdraw(m2);
        pa->deposit(m3);
        pa->withdraw(m4);
        pa->display();
    }
}

