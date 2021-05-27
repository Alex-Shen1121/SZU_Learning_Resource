2018151058:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    virtual void speak()=0;
};
class tiger:public Animal
{

public:
    tiger(string n,int a)
    {
        name=n;
        age=a;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;

    }
};
class duck:public Animal
{

public:
    duck(string n,int a)
    {
        name=n;
        age=a;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;

    }
};
class dog:public Animal
{

public:
    dog(string n,int a)
    {
        name=n;
        age=a;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;

    }
};
class pig:public Animal
{
public:
    pig(string n,int a)
    {
        name=n;
        age=a;
    }
    void speak()
    {
       cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;

    }
};

void print(Animal *b)
{
    b->speak();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Animal *pv;
        string type;
        cin>>type;
        string name;
        int age;
        cin>>name>>age;
        if(type=="Tiger")
        {

            pv=new tiger(name,age);
            print(pv);continue ;

        }
        if(type=="Duck")
        {

            pv=new duck(name,age);
            print(pv);continue ;
        }
        if(type=="Dog")
        {

            pv=new dog(name,age);
            print(pv);continue ;
        }
        if(type=="Pig")
        {
           pv=new pig(name,age);
            print(pv);continue ;
        }
        cout<<"There is no "<<type<<" in our Zoo."<<endl;

    }
    return 0;
}

