2018152044:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class animal
{
protected:
    string name;
    int age;
    int weight;
public:
    animal(string n,int a)
    {
        name=n;
        age=a;
    }
    ~animal()
    {
    }
    virtual void speak()=0;
};
class tiger:public animal
{
public:
    tiger(string n,int a):animal(n,a)
    {
    }
    void virtual speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class dog:public animal
{
public:
    dog(string n,int a):animal(n,a)
    {
    }
    ~dog()
    {
    }
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class duck:public animal
{
public:
    duck(string n,int a):animal(n,a)
    {
    }
    ~duck()
    {
    }
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class pig:public animal
{
public:
    pig(string n,int a):animal(n,a)
    {
    }
    ~pig()
    {
    }
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int T,age;
    animal *s;
    string type,name;
    cin>>T;
    while(T--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            tiger t(name,age);
            s=&t;
            s->speak();
        }
        else if(type=="Pig")
        {
            pig t(name,age);
            s=&t;
            s->speak();
        }
        else if(type=="Duck")
        {
            duck t(name,age);
            s=&t;
            s->speak();
        }
        else if(type=="Dog")
        {
            dog t(name,age);
            s=&t;
            s->speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
}
