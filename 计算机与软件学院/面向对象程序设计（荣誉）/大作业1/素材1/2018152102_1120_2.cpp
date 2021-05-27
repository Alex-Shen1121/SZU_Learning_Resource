2018152102:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;

class Animal {
protected:
    int year;
    int weight;
    string name;
public:
    virtual void speak() = 0;
    Animal(int ye,string na):year(ye),name(na) {}
};

class Tiger:public Animal {
public:
    Tiger(int ye,string na):Animal(ye,na) {}
    void speak() {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Pig:public Animal {
public:
    Pig(int ye,string na):Animal(ye,na) {}
    void speak() {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class Duck :public Animal {
public:
    Duck(int ye,string na):Animal(ye,na) {}
    void speak() {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Dog:public Animal{
public:
    void speak(){
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    Dog(int ye,string na):Animal(ye,na) {}
};
int main() {
    int t;

    cin>>t;
    while(t--) {
        string kind;
        string name;
        int year;
        cin>>kind;
        cin>>name>>year;
        if(kind == "Tiger") {
            Tiger ti(year,name);
            ti.speak();
        }else if(kind == "Pig") {
            Pig pi(year,name);
            pi.speak();
        }else if(kind == "Duck") {
            Duck du(year,name);
            du.speak();
        }else if(kind == "Dog" ) {
            Dog dog(year,name);
            dog.speak();
        }else {
            cout<<"There is no "<<kind<<" in our Zoo."<<endl;
        }

    }

    return 0;
}

