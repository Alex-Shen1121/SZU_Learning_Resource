2018152062:Problem1120:�𰸴���
#include <iostream>
using namespace std;
/*ĳ������԰�ڣ����ϻ�������Ѽ�Ӻ���ȶ������԰�Ĺ���ԱΪÿ�����ﶼ����һ�����֣�
����ÿ�����ﶼ�����䡢���ص���Ϣ��ÿ��ιʳ��ʱ�򣬲�ͬ�Ķ��ﶼ��л�(speak)��
ÿ�ֶ���Ľл�������ͬ���ϻ��Ľл����ǡ�AOOO�������Ľл����ǡ�WangWang����
Ѽ�ӵĽл����ǡ�GAGA������Ľл����ǡ�HENGHENG����
����һ��Animal�Ļ��࣬Animal���к���Speak()���������ϻ�������Ѽ�Ӻ����࣬
���ܷ�����ͬ�Ľл��������ı���Ϣ�����������
��д�������붯�����ơ����֡����䣬�ö���԰�ڵĸ��ֶ���л���
Ҫ��ֻʹ��һ������ָ�룬ָ�����ɵĶ��󲢵��÷�����*/
class Animal
{
protected:
    string type;
public:
    Animal(string _type):type(_type){}
    virtual void speak(){};
};
class Tiger:public Animal
{
protected:
    string name;
    int age;
public:
    Tiger(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"AOOO."<<endl;
    }
};
class Dog:public Animal
{
protected:
    string name;
    int age;
public:
    Dog(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"WangWang."<<endl;
    }
};
class Duck:public Animal
{
protected:
    string name;
    int age;
public:
    Duck(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"GAGA."<<endl;
    }
};
class Pig:public Animal
{
protected:
    string name;
    int age;
public:
    Pig(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"HENGHENG."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Animal *p;
        string type;
        string name;
        int age;
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger tiger(type,name,age);
            p=&tiger;
            p->speak();
        }
        else if(type=="Duck")
        {
            Duck duck(type,name,age);
            p=&duck;
            p->speak();
        }
        else if(type=="Dog")
        {
            Dog dog(type,name,age);
            p=&dog;
            p->speak();
        }
        else if(type=="Pig")
        {
            Pig pig(type,name,age);
            p=&pig;
            p->speak();
        }
        else
            cout<<"There is no "<<name<<" in our Zoo."<<endl;
    }
    return 0;
}

