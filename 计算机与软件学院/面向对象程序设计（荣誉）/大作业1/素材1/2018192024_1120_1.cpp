2018192024:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;

class Animal
{
protected:
    string name;
public:
    Animal(){}
    Animal(string n):name(n){}
    virtual void speak()=0;
};
class Tiger:public Animal
{
public:
    Tiger(string n):Animal(n){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string n):Animal(n){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string n):Animal(n){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string n):Animal(n){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};



int main()
{
    int t;
    cin>>t;
    Animal *p_animal;
    while(t--)
    {
        string type,n;
        int age;
        cin>>type>>n>>age;
        if(type=="Tiger")
        {
            Tiger t(n);
            p_animal=&t;
            p_animal->speak();
        }
        else if(type=="Dog")
        {
            Dog d(n);
            p_animal=&d;
            p_animal->speak();
        }
        else if(type=="Duck")
        {
            Duck du(n);
            p_animal=&du;
            p_animal->speak();
        }
        else if(type=="Pig")
        {
            Pig p(n);
            p_animal=&p;
            p_animal->speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
    return 0;
}

