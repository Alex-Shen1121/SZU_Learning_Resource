2016140066:Problem1120:ÕýÈ·
#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal() {}
    virtual void Speak() {};
	virtual ~Animal(){}
};

class Tiger : public Animal
{
private:
     string type, name;
     int age;

public:
    Tiger(string type_val, string name_val, int age_val)
    {
        type = type_val;
        name = name_val;
        age = age_val;
    }

    virtual void Speak()
    {
        cout << "Hello,I am " << name << ",AOOO." << endl;
    }
    ~Tiger(){}
};
class Pig : public Animal
{
private:
     string type, name;
     int age;

public:
    Pig(string type_val, string name_val, int age_val)
    {
        type = type_val;
        name = name_val;
        age = age_val;
    }
    virtual void Speak()
    {
        cout << "Hello,I am " << name << ",HENGHENG." << endl;
    }
    ~Pig(){}
};

class Dog : public Animal
{
private:
     string type, name;
     int age;

public:
    Dog(string type_val, string name_val, int age_val)
    {
        type = type_val;
        name = name_val;
        age = age_val;
    }
    virtual void Speak()
    {
        cout << "Hello,I am " << name << ",WangWang." << endl;
    }
    ~Dog(){}
};
class Duck : public Animal
{
private:
     string type, name;
     int age;

public:
    Duck(string type_val, string name_val, int age_val)
    {
        type = type_val;
        name = name_val;
        age = age_val;
    }
    virtual void Speak()
    {
        cout << "Hello,I am " << name << ",GAGA." << endl;
    }
    ~Duck(){}
};
void Speak(Animal *p)
{
    p->Speak();
}

int main()
{
    int t;
    string type, name;
    int age;
    cin >> t;
    while(t--)
    {
        cin >> type >> name >> age;
        if(type == "Tiger")
        {
            Tiger *p = new Tiger(type, name, age);
            Speak(p);
			delete p;
        }
        else if(type == "Pig")
        {
            Pig *p = new Pig(type, name, age);
            Speak(p);
			delete p;
        }
        else if(type == "Dog" )
        {
            Dog *p = new Dog(type, name, age);
            Speak(p);
			delete p;
        }
        else if(type == "Duck")
        {
            Duck *p = new Duck(type, name, age);
            Speak(p);
			delete p;
        }
        else
        {
            cout << "There is no " << type << " in our Zoo." << endl;
        }
    }
    return 0;
}
