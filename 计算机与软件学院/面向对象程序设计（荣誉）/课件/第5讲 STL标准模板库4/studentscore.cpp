#include <queue>
#include <iostream>
using namespace std;

struct student
{
    string name;
    int score;
    bool operator<(const student &rhs) const
    {
        return score>rhs.score;    //´ó¶¥¶Ñ£¬ÉýÐò
    }


};

/*struct studentcmp
{
    bool operator()(const student &lhs,const student &rhs)
    {
        return lhs.score<rhs.score;   //Ð¡¶¥¶Ñ£¬½µÐò
    }
};*/

int main()
{
    priority_queue<student> q;
    string name;
    int n,score;
    student s;


    cin>>n;
    while(n--)
    {
        cin>>name>>score;
        q.push(student{name,score});
    }

    while(!q.empty())
    {
        s = q.top();
        q.pop();
        cout<<s.name<<" "<<s.score<<endl;
    }
}

/*
3
liming 97
wangwu 95
zhaoliang 100
*/
