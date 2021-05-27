2018151020:Problem1120:ÕýÈ·
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string na,int ag):name(na),age(ag){}
    virtual void Speak()=0;
    virtual ~Animal(){}
};
class Tiger:public Animal
{
protected:

public:
    Tiger(string na,int ag):Animal(na,ag){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<","<<"AOOO."<<endl;
    }
    ~Tiger(){}
};
class Dog:public Animal
{
protected:

public:
    Dog(string na,int ag):Animal(na,ag){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<","<<"WangWang."<<endl;
    }
    ~Dog(){}
};
class Duck:public Animal
{
protected:

public:
    Duck(string na,int ag):Animal(na,ag){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<","<<"GAGA."<<endl;
    }
    ~Duck(){}
};
class Pig:public Animal
{
protected:

public:
    Pig(string na,int ag):Animal(na,ag){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<","<<"HENGHENG."<<endl;
    }
    ~Pig(){}
};
int main()
{
    int t;
    cin>>t;
    string type,na;
    int ag;
    while(t--)
    {
        Animal *K;
        cin>>type>>na>>ag;
        if(type=="Tiger")
        {
            Tiger *T = new Tiger(na,ag);
            K = T;
        }
        else if(type=="Dog")
        {
            Dog *Do = new Dog(na,ag);
            K = Do;
        }
        else if(type == "Pig")
        {
            Pig *P = new Pig(na,ag);
            K = P;
        }
        else if(type=="Duck")
        {
            Duck *Du = new Duck(na,ag);
            K = Du;
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
            K = NULL;
        }
        if(K)
        {
            K->Speak();
            delete K;
        }


    }
    return 0;
}

