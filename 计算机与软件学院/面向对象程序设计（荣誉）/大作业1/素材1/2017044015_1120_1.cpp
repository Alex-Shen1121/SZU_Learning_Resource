2017044015:Problem1120:ÕýÈ·
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Animal{
protected:
    string name;
    int age;
public:
    virtual void Speak() = 0;
};

class Tiger: public Animal{
public:
    Tiger(string s, int a){
        name = s;
        age = a;
    }
    virtual void Speak(){
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class Pig: public Animal{
public:
    Pig(string s, int a){
        name = s;
        age = a;
    }
    virtual void Speak(){
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};

class Dog: public Animal{
public:
    Dog (string s, int a){
        name = s;
        age = a;
    }
    virtual void Speak(){
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class Duck : public Animal{
public:
    Duck  (string s, int a){
        name = s;
        age = a;
    }
    virtual void Speak(){
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

int main()
{
    Animal* animal;
    int t, a;
    string name, type;
    cin>>t;
    while(t--){
        cin>>type>>name>>a;
        if(type == "Tiger"){
            Tiger tiger(name, a);
            animal = &tiger;
            animal->Speak();
        }
        else if(type == "Pig"){
            Pig pig(name, a);
            animal = &pig;
            animal->Speak();
        }
        else if(type == "Duck"){
            Duck duck(name, a);
            animal = &duck;
            animal->Speak();
        }
        else if(type == "Dog"){
            Dog dog(name, a);
            animal = &dog;
            animal->Speak();
        }
        else{
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
    return 0;
}

