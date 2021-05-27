2018151031:Problem1120:±‡“Î¥ÌŒÛ
#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
public:
    virtual void Speak()=0
};

class tiger:public Animal
{
public:
    tiger(char _name[20],int _age):age(_age)
    {
        strcpy(name,_name);
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
private:
    char name[20];
    int age;
};

class dog:public Animal
{
public:
    dog(char _name[20],int _age):age(_age)
    {
        strcpy(name,_name);
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
private:
    char name[20];
    int age;
};

class duck:public Animal
{
public:
    duck(char _name[20],int _age):age(_age)
    {
        strcpy(name,_name);
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
private:
    char name[20];
    int age;
};

class pig:public Animal
{
public:
    pig(char _name[20],int _age):age(_age)
    {
        strcpy(name,_name);
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
private:
    char name[20];
    int age;
};


int main()
{
	int t,age;
	char name[20],ani[20];
	cin>>t;
	Animal *p;
	while(t--)
    {
        cin>>ani>>name>>age;
        if(!strcmp(ani,"Tiger"))
        {
            tiger a(name,age);
            p=&a;
            p->Speak();
        }
        else if(!strcmp(ani,"Dog"))
        {
            dog a(name,age);
            p=&a;
            p->Speak();
        }
        else if(!strcmp(ani,"Duck"))
        {
            duck a(name,age);
            p=&a;
            p->Speak();
        }
        else if(!strcmp(ani,"Pig"))
        {
            pig a(name,age);
            p=&a;
            p->Speak();
        }
        else
            cout<<"There is no "<<ani<<" in our Zoo."<<endl;
    }
	return 0;
}
