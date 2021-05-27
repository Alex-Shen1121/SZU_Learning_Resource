#include <iostream>
#include <vector>

#include <list>
using namespace std;

template <class T>
class cstack
{
    vector<T> c;
public:
    bool empty()
    {
        return c.empty();
    }
    void push(const T &e)
    {
        c.push_back(e);
    }
    T &top()
    {
        return c.back();
    }
    void pop()
    {
        c.pop_back();
    }

    int size() const {return c.size();}
};

template <class T>
bool operator==(const cstack<T> &x,const cstack<T> &y)
{
    return x.c == y.c;
}

template <class T>
bool operator<(const cstack<T> &x,const cstack<T> &y)
{
    return x.c<y.c;
}

int main()
{
    cstack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;

}

