2018192009:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;
class animal
{
protected:
    int age;
    string name;
    int weight;
public:
    animal(){}
    animal(int a,string n):age(a),name(n){}
    virtual void speak()=0;
};
class tiger:public animal
{
public:
    tiger(string n,int a):animal(a,n){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class pig:public animal
{
public:
    pig(string n,int a):animal(a,n){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class duck:public animal
{
public:
    duck(string n,int a):animal(a,n){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class dog:public animal
{
public:
    dog(string n,int a):animal(a,n){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    animal *p;
    string name,anim;
    int age;
    while(t--)
    {
        cin>>anim;
        cin>>name;
        cin>>age;
        if(anim=="Tiger")
        {
            tiger a(name,age);
            p=&a;
            p->speak();
        }
        else if(anim=="Pig")
        {
            pig a(name,age);
            p=&a;
            p->speak();
        }
        else if(anim=="Dog")
        {
            dog a(name,age);
            p=&a;
            p->speak();
        }
        else if(anim=="Duck")
        {
            duck a(name,age);
            p=&a;
            p->speak();
        }
        else
            cout<<"There is no "<<anim<<" in our Zoo."<<endl;
    }
    return 0;
}

