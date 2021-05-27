2017092048:Problem1129:ÕýÈ·
// May.27, 2019
// Author: Wenzhuo Dong
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;




class NCard {
protected:
    int id;
    char CName;
    int counter;
public:
    NCard();
    void initial(int i, char c, int ct);
    int save(int c);
    int take(int c);
    virtual void info();
};

// transportation card
class Tcard:public NCard{
protected:
    int Tcounter;
public:
    Tcard();
    void initial(int i, char c, int ct, int tc);
    int transfer(int c);
    void info();
};
//
// VIP card
class Vcard:public NCard{
protected:
    int credit;
public:
    Vcard();
    void initial(int i, char c, int ct, int cd);
    int over(int c);
    void info();
};

void show(NCard & obj) {
    obj.info();
}

//
//
// main function
int main() {
    int id, ct, t;
    char n;
    // initial cards
    cin >> id >> n >> ct;
    NCard nc;
    nc.initial(id, n, ct);

    cin >> id >> n >> ct >> t;
    Tcard tc;
    tc.initial(id, n, ct, t);

    cin >> id >> n >> ct >> t;
    Vcard vc;
    vc.initial(id, n, ct, t);
    // end
    // start operate
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    nc.save(a);
    nc.save(b);
    nc.take(c);
    nc.take(d);

    cin >> a >> b >> c >> d;
    tc.save(a);
    tc.take(b);
    tc.transfer(c);
    tc.transfer(d);

    cin >> a >> b >> c >> d;
    vc.save(a);
    vc.take(b);
    vc.over(c);
    vc.over(d);

    //end
    // show info
    show(nc);
    show(tc);
    show(vc);
    // end
    return 0;
}
// main function end
//
// class NCard
NCard::NCard() {
    id = 0;
    CName = '\0';
    counter = 0;
}
void NCard::initial(int i, char c, int ct) {
    id = i;
    CName = c;
    counter = ct;
}

int NCard::take(int c) {
    if ( c >= 0) {
        if ((counter-c) >= 0 ) {
            counter -= c;
            return 1;
        }
    }
    return -1;
}

int NCard::save(int c) {
    if (c >= 0) {
        counter += c;
        return 1;
    }
    return -1;
}

void NCard::info() {
    cout << id << "-" << CName << "-" << counter << endl;
}
// end NCard

// class Tcard
Tcard::Tcard():NCard(){
    Tcounter = 0;
}
void Tcard::initial(int i, char c, int ct, int tc) {
    NCard::initial(i, c, ct);
    Tcounter = tc;
}
int Tcard::transfer(int c) {
    if ( c >= 0) {
        if (counter >= c){
            counter -= c;
            Tcounter += c;
            return 1;
        }
    }
    return -1;
}

void Tcard::info() {
    cout << id << "-" << CName << "-" << counter << "-" << Tcounter << endl;
}
// end Tcard

// class Vcard
Vcard::Vcard():NCard(){
    credit = 0;
}
void Vcard::initial(int i, char c, int ct, int cd) {
    NCard::initial(i, c, ct);
    credit = cd;
}

int Vcard::over(int c) {
    if (c >= 0){
        if ( (counter + credit - c) >= 0){
            credit = credit + counter - c;
            counter = 0;
        }
    }
    return -1;
}

void Vcard::info() {
    cout << id << "-" << CName << "-" << counter << "-" << credit << endl;

}

// end Vcard
