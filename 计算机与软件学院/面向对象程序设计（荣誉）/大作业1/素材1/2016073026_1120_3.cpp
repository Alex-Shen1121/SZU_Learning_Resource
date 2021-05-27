2016073026:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;

class Animal{
public:
    virtual void Speak()=0;
};

class Tiger:public Animal{
    string name;
    int age;
public:
    Tiger(string na,int age_v):name(na),age(age_v){}
    virtual void Speak(){cout<<"Hello,I am "<<name<<",AOOO.\n";}
};

class Dog:public Animal{
    string name;
    int age;
public:
    Dog(string na,int age_v):name(na),age(age_v){}
    virtual void Speak(){cout<<"Hello,I am "<<name<<",WangWang.\n";}
};

class Duck:public Animal{
    string name;
    int age;
public:
    Duck(string na,int age_v):name(na),age(age_v){}
    virtual void Speak(){cout<<"Hello,I am "<<name<<",GAGA.\n";}
};

class Pig:public Animal{
    string name;
    int age;
public:
    Pig(string na,int age_v):name(na),age(age_v){}
    virtual void Speak(){cout<<"Hello,I am "<<name<<",HENGHENG.\n";}
};

int main()
{
    Animal *pa;
    int t;
    cin>>t;
    while(t--){
        string type,name;
        int age;
        cin>>type>>name>>age;
        if(type=="Tiger"){    pa=new Tiger(name,age);     pa->Speak();}
        else if(type=="Pig"){   pa=new Pig(name,age);     pa->Speak();}
        else if(type=="Duck"){   pa=new Duck(name,age);     pa->Speak();}
        else if(type=="Dog"){   pa=new Dog(name,age);     pa->Speak();}
        else    cout<<"There is no "<<type<<" in our Zoo.\n";
    }
    return 0;
}

