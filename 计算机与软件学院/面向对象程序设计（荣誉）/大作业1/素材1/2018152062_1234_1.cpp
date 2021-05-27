2018152062:Problem1234:�𰸴���
#include <iostream>
using namespace std;
/*ĳСѧ���꼶����ѧ��ʦ�ڽ�ѧ�������Ӽ�������ʱ���֣����ϵ�ͬѧ���Էֳ����࣬
��һ�������ȷ����ɼӼ�������(GroupA)���ڶ��������ȷ����ɼӷ����㣬
�����ڼ���������˵���������ǽ�λ�Ĵ���(GroupB)���������������Ǽӷ��Ľ�λ��
Ҳ�������Ǽ����Ľ�λ(GroupC)������ʾ��Сѧ���꼶��ûѧ��������
������ģ�⵱��ʦ�ڿ�������ĳλͬѧʱ��ͬѧ������Ļش�
ʵ��ʱ���������Ļ����ܣ�*/

class Group
{
public:
    virtual int add(int x, int y)=0;//����ӷ���������
    virtual int sub(int x, int y)=0;//���������������
};
/*������GroupA, GroupB��GroupC�����ɳ���:
����д��������Ҫ������������һ������Groupָ�룬ͨ����ָ��ͳһ�ؽ���add��sub����*/
class GroupA:public Group
{
public:
    GroupA(){}
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }
};
class GroupB:public Group
{
public:
    GroupB(){}
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        if(x-y<100)
           return x-y+10;
        else
           return x-y+100+10;
    }
};
class GroupC:public Group
{
public:
    GroupC(){}
    int add(int x,int y)
    {
        if(x+y<100)
            return x+y-10;
        else
            return x+y-10-100;
    }
    int sub(int x,int y)
    {
        if(x-y<100)
           return x-y+10;
        else
           return x-y+100+10;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Group *p;
        int cnt;
        int x,y;
        char ch;
        cin>>cnt>>x>>ch>>y;
        if(cnt==1)
        {
            GroupA u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(cnt==2)
        {
            GroupB u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else
        {
            GroupC u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
    }
    return 0;
}

