2018152007:Problem1120:´ð°¸´íÎó
#include <iostream>

using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void speak()=0;
};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class dog:public Animal
{
public:
    dog(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class pig:public Animal
{
public:
    pig(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
int main()
{
    int time;
    cin>>time;
    while(time--)
    {
        string t,n;
        int a;
        cin>>t>>n>>a;
        Animal *b;
        if(t=="Tiger")
        {
            Tiger *t1=new Tiger(n,a);
            b=t1;
            b->speak();
        }
        else if(t=="Pig")
        {
            pig *p1=new pig(n,a);
            b=p1;
            b->speak();
        }
        else if(t=="Dog")
        {
            dog *d1=new dog(n,a);
            b=d1;
            b->speak();
        }
        else if(t=="Duck")
        {
            Duck *k1=new Duck(n,a);
            b=k1;
            b->speak();
        }
        else
        {
            cout<<"There is no Rabbit in our Zoo."<<endl;
        }
    }
    return 0;
}

