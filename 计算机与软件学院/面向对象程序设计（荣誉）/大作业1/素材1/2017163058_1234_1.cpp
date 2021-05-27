2017163058:Problem1234:正确
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
//某小学二年级的数学老师在教学生整数加减法运算时发现：班上的同学可以分成三类，
//
//第一类可以正确地完成加减法运算(GroupA)；
//
//第二类可以正确地完成加法运算，但对于减法运算来说，总是忘记借位的处理(GroupB)；
//
//第三类总是忘记加法的进位，也总是忘记减法的借位(GroupC)。（提示：小学二年级还没学负数。）
//
//现在请模拟当老师在课堂提问某位同学时，同学会给出的回答。
//
//实现时请基于下面的基类框架：
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

