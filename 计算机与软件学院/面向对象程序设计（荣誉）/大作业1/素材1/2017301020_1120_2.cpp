2017301020:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;

class Animal{
protected:
    string name;
    int year;
public:
    Animal(string name1,int year1):name(name1),year(year1){}
    virtual void Speak()=0;
};

class Tiger:public Animal{
public:
    Tiger(string name1,int year1):Animal(name1,year1){}
    virtual void Speak();
};

void Tiger::Speak(){
    cout<<"Hello,I am "<<name<<",AOOO."<<endl;
}

class Dog:public Animal{
public:
    Dog(string name1,int year1):Animal(name1,year1){}
    virtual void Speak();
};

void Dog::Speak(){
    cout<<"Hello,I am "<<name<<",WangWang."<<endl;
}

class Duck:public Animal{
public:
    Duck(string name1,int year1):Animal(name1,year1){}
    virtual void Speak();
};

void Duck::Speak(){
    cout<<"Hello,I am "<<name<<",GAGA."<<endl;
}

class Pig:public Animal{
public:
    Pig(string name1,int year1):Animal(name1,year1){}
    virtual void Speak();
};

void Pig::Speak(){
    cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
}

int main()
{
    Animal *pv;
    int t,year;
    string name,type;
    cin>>t;
    while(t--){
        cin>>type>>name>>year;
        if(type=="Tiger"){
            Tiger a(name, year);
            pv=&a;
            pv->Speak();
        }

        else if(type=="Dog"){
            Dog a(name, year);
            pv=&a;
            pv->Speak();
        }
        else if(type=="Duck"){
            Duck a(name, year);
            pv=&a;
            pv->Speak();
        }
        else if(type=="Pig"){
            Pig a(name, year);
            pv=&a;
            pv->Speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
    return 0;
}

