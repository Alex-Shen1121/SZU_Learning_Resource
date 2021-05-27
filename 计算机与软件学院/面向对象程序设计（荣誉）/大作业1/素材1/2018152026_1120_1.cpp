2018152026:Problem1120:´ð°¸´íÎó
#include <iostream>
#include <string.h>
using namespace std;

class Animal
{
public:
    char animal[10];
    char name[10];
};

class Tiger:public Animal
{
public:
    void speak1(char name[10]);
};

class Dog:public Animal
{
public:
    void speak2(char name[10]);
};

class Duck:public Animal
{
public:
    void speak3(char name[10]);
};

class Pig:public Animal
{
public:
    void speak4(char name[10]);
};

void Tiger::speak1(char name[10])
{
    cout<<"Hello,I am "<<name<<",AOOO."<<endl;
}

void Dog::speak2(char name[10])
{
    cout<<"Hello,I am "<<name<<",WANGWANG."<<endl;
}

void Duck::speak3(char name[10])
{
    cout<<"Hello,I am "<<name<<",GAGA."<<endl;
}

void Pig::speak4(char name[10])
{
    cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     int age;
     Animal a;
     Tiger b;
     Dog c;
     Duck d;
     Pig e;
     cin>>a.animal>>a.name>>age;

     if(strcmp(a.animal,"Tiger")==0)
     {
        b.speak1(a.name);
     }
     else if(strcmp(a.animal,"Dog")==0)
     {
         c.speak2(a.name);
     }
     else if(strcmp(a.animal,"Duck")==0)
     {
         d.speak3(a.name);
     }
     else if(strcmp(a.animal,"Pig")==0)
     {
         e.speak4(a.name);
     }
     else
     {
         cout<<"There is no "<<a.animal<<" in our Zoo."<<endl;
     }
    }
    return 0;
}

