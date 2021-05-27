2018152100:Problem1120:ÕýÈ·
#include <iostream>
#include <string>
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

class Tiger:virtual public Animal
{
    string type;
public:
    Tiger(string n,int a,string t="Tiger"):Animal(n,a),type(t){}
    void speak(){cout << "Hello,I am " << name << ",AOOO."<<endl;}
};

class Pig:virtual public Animal
{
    string type;
public:
    Pig(string n,int a,string t="Pig"):Animal(n,a),type(t){}
    void speak(){cout << "Hello,I am " << name << ",HENGHENG."<<endl;}
};

class Duck:virtual public Animal
{
    string type;
public:
    Duck(string n,int a,string t="Duck"):Animal(n,a),type(t){}
    void speak(){cout << "Hello,I am " << name << ",GAGA."<<endl;}
};

class Dog:virtual public Animal
{
    string type;
public:
    Dog(string n,int a,string t="Dog"):Animal(n,a),type(t){}
    void speak(){cout << "Hello,I am " << name << ",WangWang."<<endl;}
};

int main()
{
    int t,age;
    string n,type;
    cin >> t;
    Animal *pa;
    while (t--)
    {
        cin >> type;
        if (type=="Tiger")
        {
            cin >> n >> age;
            Tiger t(n,age);
            pa=&t;
            pa->speak();
        }

        else if (type=="Pig")
        {
            cin >> n >> age;
            Pig p(n,age);
            pa=&p;
            pa->speak();
        }

        else if (type=="Dog")
        {
            cin >> n >> age;
            Dog d(n,age);
            pa=&d;
            pa->speak();
        }

        else if (type=="Duck")
        {
            cin >> n >> age;
            Duck d(n,age);
            pa=&d;
            pa->speak();
        }
        else
        {
            cin >> n >> age;
            cout << "There is no "<< type << " in our Zoo." << endl;
        }
    }
    return 0;
}

