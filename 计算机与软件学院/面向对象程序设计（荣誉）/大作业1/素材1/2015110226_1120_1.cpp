2015110226:Problem1120:ÕýÈ·
#include <bits/stdc++.h>
using namespace std;

class Animal{
protected:
    string name;
    int age;
public:
    Animal(string a,int b):name(a),age(b){}
    virtual void speak()=0;
};
class Tiger:public Animal{
public:
    Tiger(string a,int b):Animal(a,b){}
    void speak(){cout<<"Hello,I am "<<name<<",AOOO."<<endl;}
private:
};
class Dog:public Animal{
public:
    Dog(string a,int b):Animal(a,b){}
    void speak(){cout<<"Hello,I am "<<name<<",WangWang."<<endl;}
private:
};
class Duck:public Animal{
public:
    Duck(string a,int b):Animal(a,b){}
    void speak(){cout<<"Hello,I am "<<name<<",GAGA."<<endl;}
private:
};
class Pig:public Animal{
public:
    Pig(string a,int b):Animal(a,b){}
    void speak(){cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;}
private:
};
int main(){
    int time;
    cin>>time;
    while(time--){
        string a,b;
        int c;
        cin>>a>>b>>c;
        Animal *p;
        if(a=="Tiger"){
            p = new Tiger(b,c);
            p->speak();
        }
        else if(a=="Dog"){
            p = new Dog(b,c);
            p->speak();
        }
        else if(a=="Duck"){
            p = new Duck(b,c);
            p->speak();
        }
        else if(a=="Pig"){
            p = new Pig(b,c);
            p->speak();
        }else{
            cout<<"There is no "<<a<<" in our Zoo."<<endl;
        }
    }
    return 0;
}


