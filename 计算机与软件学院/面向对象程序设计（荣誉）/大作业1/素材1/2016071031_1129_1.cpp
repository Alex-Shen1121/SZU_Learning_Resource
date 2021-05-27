2016071031:Problem1129:答案错误
//#include <iostream>
//#include <fstream>
#include <bits/stdc++.h>
using namespace std;

class Card {
protected:
    int ID;
    string name;
    int counter;
public:
    Card() { counter = 0;}
    Card(int ID_, string name_, int counter_)
            :ID(ID_), name(name_), counter(counter_) {}
    ~Card(){}

    int save(int amount) {
        if (amount > 0) {
            counter += amount;
            return 1;
        } else {
            return -1;
        }
    }

    int take(int amount) {
        if (amount > 0 && amount <= counter) {
            counter -= amount;
            return 1;
        } else {
            return -1;
        }
    }

    virtual void info() {
        cout<< ID << "-" << name << "-" << counter <<endl;
    }
};

class Traffic: public Card {
    int tcounter;
public:
    Traffic(): Card() { tcounter = 0; }
    Traffic(int ID_, string name_, int counter_, int tcounter_)
            : Card(ID_, name_, counter_), tcounter(tcounter_) {}
    ~Traffic() {}

    int transfer(int amount) {
        if (amount <= counter && amount) {
            tcounter += amount;
            return 1;
        } else {
            return -1;
        }
    }

    void info() override {
        cout<< ID << "-" << name << "-" << counter << "-" << tcounter <<endl;
    }
};

class VIP: public Card {
    int credit;
public:
    VIP(): Card() { credit = 0; }
    VIP(int ID_, string name_, int counter_, int credit_)
            : Card(ID_, name_, counter_), credit(credit_) {}
    ~VIP() {}

    int over (int amount) {
        if (amount && amount <= credit + counter) {
            credit -= amount - counter;
            counter = 0;
            return 1;
        } else {
            return -1;
        }
    }

    void info() override {
        cout<< ID << "-" << name << "-" << counter << "-" << credit <<endl;
    }
};

void show(Card & obj) {
    obj.info();
}

int main() {

//    第四行输入四个整数，表示对普通卡按顺序先执行2次存款，2次取款
//    第五行输入四个整数，表示对交通卡按顺序执行1次存款，1次取款，2次转帐
//    第六行输入四个整数，表示对贵宾卡按顺序执行1次存款，1次取款，2次透支

//    freopen("ojdata.txt", "r", stdin);
    int ID, counter, tcounter, credit;
    string name;
    int o1, o2, o3, o4;

    cin>> ID >> name >> counter;
    Card c(ID, name, counter);

    cin>> ID >> name >> counter >> tcounter;
    Traffic t(ID, name, counter, tcounter);

    cin>> ID >> name >> counter >> credit;
    VIP v(ID, name, counter, credit);

    cin>> o1 >> o2 >> o3 >> o4;
    c.save(o1);
    c.save(o2);
    c.take(o3);
    c.take(o4);
    show(c);


    cin>> o1 >> o2 >> o3 >> o4;
    t.save(o1);
    t.take(o2);
    t.transfer(o3);
    t.transfer(o4);
    show(t);


    cin>> o1 >> o2 >> o3 >> o4;
    v.save(o1);
    v.take(o2);
    v.over(o3);
    v.over(o4);
    show(v);


    return 0;
}

