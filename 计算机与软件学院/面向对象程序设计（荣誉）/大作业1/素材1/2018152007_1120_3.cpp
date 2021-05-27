2018152007:Problem1120:ÕýÈ·
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
    virtual ~Animal(){}
};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
    ~Tiger(){}
};
class dog:public Animal
{
public:
    dog(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    ~dog(){}
};
class pig:public Animal
{
public:
    pig(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
    ~pig(){}
};
class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
    ~Duck(){}
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
            delete t1;
        }
        else if(t=="Pig")
        {
            pig *p1=new pig(n,a);
            b=p1;
            b->speak();
            delete p1;
        }
        else if(t=="Dog")
        {
            dog *d1=new dog(n,a);
            b=d1;
            b->speak();
            delete d1;
        }
        else if(t=="Duck")
        {
            Duck *k1=new Duck(n,a);
            b=k1;
            b->speak();
            delete k1;
        }
        else
        {
            cout<<"There is no "<<t<<" in our Zoo."<<endl;
        }
    }
    return 0;
}

