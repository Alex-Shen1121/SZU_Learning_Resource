2018192010:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;
class Animal
{
protected:
    int age;
    string name;
public:
    Animal(){}
    Animal(string n,int a):name(n),age(a){}
    ~Animal(){}
    virtual void speak(){};
};
class Tiger:public Animal
{
public:
    Tiger(){}
    Tiger(string n,int a):Animal(n,a){}
    void speak()
    {
        cout << "Hello,I am " << name << ",AOOO." << endl;
    }
};
class Pig:public Animal
{
public:
    Pig(){}
    Pig(string n,int a):Animal(n,a){}
    void speak()
    {
        cout << "Hello,I am " << name << ",HENGHENG." << endl;
    }
};
class Dog:public Animal
{
public:
    Dog(){}
    Dog(string n,int a):Animal(n,a){}
    void speak()
    {
        cout << "Hello,I am " << name << ",WangWang." << endl;
    }
};
class Duck:public Animal
{
public:
    Duck(){}
    Duck(string n,int a):Animal(n,a){}
    void speak()
    {
        cout << "Hello,I am " << name << ",GAGA." << endl;
    }
};
int main()
{
    int t;
    string no,type;
    int age;
    cin >> t;
    while(t--)
    {
        Animal *pv;
        cin >> type;
        if(type=="Tiger")
        {
            cin >> no >> age;
            pv = new Tiger(no,age);
            pv->speak();
            delete pv;
        }
        else if(type=="Pig")
        {
            cin >> no >> age;
            pv = new Pig(no,age);
            pv->speak();
            delete pv;
        }
        else if(type=="Duck")
        {
            cin >> no >> age;
            pv = new Duck(no,age);
            pv->speak();
            delete pv;
        }
        else if(type=="Dog")
        {
            cin >> no >> age;
            pv = new Dog(no,age);
            pv->speak();
            delete pv;
        }
        else
        {
            cin >> no >> age;
            cout << "There is no " << type << " in our Zoo." << endl;
        }
    }
    return 0;
}

