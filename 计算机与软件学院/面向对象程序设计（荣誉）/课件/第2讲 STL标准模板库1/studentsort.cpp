#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct student
{
    string name;
    int age;
    bool operator<(const student &rhs)
    {
        return age>rhs.age;
    }
};

struct cmp
{
    bool operator()(const student &lhs,const student &rhs)
    {
        return lhs.age>rhs.age;
    }
};

bool compare(const student &lhs,const student &rhs)
{
    return lhs.age>rhs.age;
}


int main()
{
    student s[4] = {{"liming",20},{"wangwu",21},{"zhaosi",19},{"qianwu",20}};

    //sort(s,s+4);
    //sort(s,s+4,cmp());
    //sort(s,s+4,compare);
    sort(s,s+4,[](const student &lhs,const student &rhs)->bool{return lhs.age>rhs.age;});

    cout<<"sort result:"<<endl;
    for(auto x:s)
        cout<<x.name<<" "<<x.age<<endl;
}
