2018192022:Problem1120:ÕýÈ·
#include <iostream>
#include <iomanip>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    virtual void Speak()=0;
};
class Tiger:public Animal
{
protected:
public:
    Tiger(string a,int b){name=a;age=b;}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
protected:
public:
    Dog(string a,int b){name=a;age=b;}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
protected:
public:
    Duck(string a,int b){name=a;age=b;}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
protected:
public:
    Pig(string a,int b){name=a;age=b;}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    Animal *p;
    while(t--)
    {
        string n;
        cin>>n;
        if(n=="Tiger")
        {
            string name;
            int age;
            cin>>name>>age;
            p=new Tiger(name,age);
            p->Speak();
        }
        else if(n=="Pig")
        {
            string name;
            int age;
            cin>>name>>age;
            p=new Pig(name,age);
            p->Speak();
        }
        else if(n=="Duck")
        {
            string name;
            int age;
            cin>>name>>age;
            p=new Duck(name,age);
            p->Speak();
        }
        else if(n=="Dog")
        {
            string name;
            int age;
            cin>>name>>age;
            p=new Dog(name,age);
            p->Speak();
        }
        else
        {
            string name;
            int age;
            cin>>name>>age;
            cout<<"There is no "<<n<<" in our Zoo."<<endl;
        }
    }
    return 0;
}
