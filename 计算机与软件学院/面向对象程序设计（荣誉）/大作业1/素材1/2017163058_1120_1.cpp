2017163058:Problem1120:��ȷ
#include <iostream>
#include <fstream>
using namespace std;
//ĳ������԰�ڣ����ϻ�������Ѽ�Ӻ���ȶ������԰�Ĺ���ԱΪÿ�����ﶼ����һ�����֣�����ÿ�����ﶼ�����䡢���ص���Ϣ��

//ÿ��ιʳ��ʱ�򣬲�ͬ�Ķ��ﶼ��л�(speak)��ÿ�ֶ���Ľл�������ͬ���ϻ��Ľл����ǡ�AOOO�������Ľл����ǡ�WangWang����Ѽ�ӵĽл����ǡ�GAGA������Ľл����ǡ�HENGHENG����

//����һ��Animal�Ļ��࣬Animal���к���Speak()���������ϻ�������Ѽ�Ӻ����࣬���ܷ�����ͬ�Ľл��������ı���Ϣ�����������
//
//��д�������붯�����ơ����֡����䣬�ö���԰�ڵĸ��ֶ���л���
//
//Ҫ��ֻʹ��һ������ָ�룬ָ�����ɵĶ��󲢵��÷�����
class Animal
{
protected:
    string name;
    int age;
public:
    virtual void Speak() = 0;
};
class Tiger:public Animal
{
public:
    Tiger(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string name, animal;
    int t, age;
    Animal *p;
    cin>>t;
    while(t --)
    {
        cin>>animal>>name>>age;
        if(animal == "Tiger")
        {
            Tiger tiger(name, age);
            p = &tiger;
            p->Speak();
        }
        else if(animal == "Dog")
        {
            Dog dog(name, age);
            p = &dog;
            p->Speak();
        }
        else if(animal == "Duck")
        {
            Duck duck(name, age);
            p = &duck;
            p->Speak();
        }
        else if(animal == "Pig")
        {
            Pig pig(name, age);
            p = &pig;
            p->Speak();
        }
        else
        {
            cout<<"There is no "<<animal<<" in our Zoo."<<endl;
        }

    }
    return 0;
}

