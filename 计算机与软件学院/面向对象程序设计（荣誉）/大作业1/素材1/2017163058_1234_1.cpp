2017163058:Problem1234:��ȷ
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
//ĳСѧ���꼶����ѧ��ʦ�ڽ�ѧ�������Ӽ�������ʱ���֣����ϵ�ͬѧ���Էֳ����࣬
//
//��һ�������ȷ����ɼӼ�������(GroupA)��
//
//�ڶ��������ȷ����ɼӷ����㣬�����ڼ���������˵���������ǽ�λ�Ĵ���(GroupB)��
//
//�������������Ǽӷ��Ľ�λ��Ҳ�������Ǽ����Ľ�λ(GroupC)������ʾ��Сѧ���꼶��ûѧ��������
//
//������ģ�⵱��ʦ�ڿ�������ĳλͬѧʱ��ͬѧ������Ļش�
//
//ʵ��ʱ���������Ļ����ܣ�
class Group
{
public:
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
};
class GroupA:public Group
{
public:
    int add(int x, int y)
    {
        return x + y;
    }
    int sub(int x, int y)
    {
        return x - y;
    }
};
class GroupB:public Group
{
public:
    int add(int x, int y)
    {
        return x + y;
    }
    int sub(int x,int y)
    {
        stack<int> X, Y;
        int result = 0, temp;
        while(x)
        {
            X.push(x % 10);
            x /= 10;
        }
        while(y)
        {
            Y.push(y % 10);
            y /= 10;
        }
        while(X.size() > Y.size())
        {
            result = result*10 + X.top();
            X.pop();
        }
        while(!X.empty())
        {
            temp = (X.top() - Y.top());
            if(temp < 0)
            {
                temp += 10;
            }
            result = result*10 + temp;
            X.pop();
            Y.pop();
        }
        return result;
    }
};
class GroupC:public Group
{
public:
    int add(int x, int y)
    {
        stack<int> X, Y;
        int result = 0, temp = 0;
        while(x)
        {
            X.push(x % 10);
            x /= 10;
        }
        while(y)
        {
            Y.push(y % 10);
            y /= 10;
        }
        while(X.size() > Y.size())
        {
            result = result*10 + X.top();
            X.pop();
        }
        while(X.size() < Y.size())
        {
            result = result*10 + Y.top();
            Y.pop();
        }
        while(!X.empty())
        {
            temp = (X.top() + Y.top()) % 10;
            result = result*10 + temp;
            X.pop();
            Y.pop();
        }
        return result;
    }
    int sub(int x, int y)
    {
        stack<int> X, Y;
        int result = 0, temp;
        while(x)
        {
            X.push(x % 10);
            x /= 10;
        }
        while(y)
        {
            Y.push(y % 10);
            y /= 10;
        }
        while(X.size() > Y.size())
        {
            result = result*10 + X.top();
            X.pop();
        }
        while(!X.empty())
        {
            temp = (X.top() - Y.top());
            if(temp < 0)
            {
                temp += 10;
            }
            result = result*10 + temp;
            X.pop();
            Y.pop();
        }
        return result;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    int x, y, sign,t;
    char op;
    cin>>t;
    Group *p;
    while(t --)
    {
        cin>>sign>>x>>op>>y;

        switch(sign)
        {
        case 1:
            {
                GroupA student;
                p = &student;
                if(op == '+')
                {
                    cout<<p->add(x, y)<<endl;
                }
                else
                {
                    cout<<p->sub(x, y)<<endl;
                }
                break;
            }
        case 2:
            {
                GroupB student;
                p = &student;
                if(op == '+')
                {
                    cout<<p->add(x, y)<<endl;
                }
                else
                {
                    cout<<p->sub(x, y)<<endl;
                }
                break;
            }
        case 3:
            {
                GroupC student;
                p = &student;
                if(op == '+')
                {
                    cout<<p->add(x, y)<<endl;
                }
                else
                {
                    cout<<p->sub(x, y)<<endl;
                }
            }
        }
    }
}

