2017133026:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;
class Animal{
protected:
    string name;
    int age,weight;
public:
    Animal(string n,int a){
        name=n;
        age=a;
    }
    virtual void speak(){

    };
};
class Tiger:public Animal{
public:
    Tiger(string n,int a):Animal(n,a){

    }
    void speak(){
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Pig:public Animal{
public:
    Pig(string n,int a):Animal(n,a){

    }
    void speak(){
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};

class Duck:public Animal{
public:
    Duck(string n,int a):Animal(n,a){

    }
    void speak(){
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Dog:public Animal{
public:
    Dog(string n,int a):Animal(n,a){

    }
    void speak(){
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    string type,name;
    int age;
    Animal *a;
    while(t--){
        cin>>type>>name>>age;
        if(type=="Tiger"){
            Tiger t1(name,age);
            a=&t1;
            a->speak();
        }else if(type=="Pig"){
            Pig p(name,age);
            a=&p;
            a->speak();
        }else if(type=="Duck"){
            Duck d(name,age);
            a=&d;
            a->speak();
        }else if(type=="Dog"){
            Dog d1(name,age);
            a=&d1;
            a->speak();
        }else{
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
    return 0;
}

