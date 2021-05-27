2017081130:Problem1120:ÕýÈ·
#include <iostream>
#include<cstring>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(){};
    Animal(string n,int a):name(n),age(a){};
    virtual void speak(){};
};
class Tiger:virtual public Animal
{
public:
    Tiger(){};
    Tiger(string n,int a):Animal(n,a){};
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Pig:virtual public Animal
{
public:
    Pig(){};
    Pig(string n,int a):Animal(n,a){};
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class Dog:virtual public Animal
{
public:
    Dog(){};
    Dog(string n,int a):Animal(n,a){};
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:virtual public Animal
{
public:
    Duck(){};
    Duck(string n,int a):Animal(n,a){};
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
int main()
{
    int t,age;
    char annimal[20];
    string name;
    cin>>t;
    Animal *p_animal;
    while(t--)
    {
        cin>>annimal>>name>>age;
        if(strcmp(annimal,"Tiger")==0)
        {
            Tiger tiger(name,age);
            p_animal=&tiger;
            p_animal->speak();
        }
        else if(strcmp(annimal,"Pig")==0)
        {
            Pig pig(name,age);
            p_animal=&pig;
            p_animal->speak();
        }
        else if(strcmp(annimal,"Dog")==0)
        {
            Dog dog(name,age);
            p_animal=&dog;
            p_animal->speak();
        }
        else if(strcmp(annimal,"Duck")==0)
        {
            Duck duck(name,age);
            p_animal=&duck;
            p_animal->speak();
        }
        else
        {
            cout<<"There is no "<<annimal<<" in our Zoo."<<endl;
        }
    }
}

