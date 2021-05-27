2018152026:Problem1120:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
class animal
{
protected:
    string name;
    int age;
public:
    animal(string n,int a):name(n),age(a)
    {}
    ~animal() {}
    virtual void speak()=0;
};
class tiger:public animal
{
public:
    tiger(string n,int a):animal(n,a) {}
    void virtual speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class dog:public animal
{
public:
    dog(string n,int a):animal(n,a) {}
    ~dog() {}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class duck:public animal
{
public:
    duck(string n,int a):animal(n,a) {}
    ~duck() {}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class pig:public animal
{
public:
    pig(string n,int a):animal(n,a ) {}
    ~pig() {}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int t,age;
    animal *a;
    string type,name;
    cin>>t;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            tiger b(name,age);
            a=&b;
            a->speak();
        }
        else if(type=="Pig")
        {
            pig b(name,age);
            a=&b;
            a->speak();
        }
        else if(type=="Duck")
        {
            duck b(name,age);
            a=&b;
            a->speak();
        }
        else if(type=="Dog")
        {
            dog b(name,age);
            a=&b;
            a->speak();
        }
        else
            cout<<"There is no "<<type
            <<" in our Zoo."<<endl;
    }
}
