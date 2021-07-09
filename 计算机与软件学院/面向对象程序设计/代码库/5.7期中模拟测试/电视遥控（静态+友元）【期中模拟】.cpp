#include<iostream>
using namespace std;

class TV {
    int volume, mode, channel;
    friend class Remote;
    static int num1, num2;
public:
    TV() {
        mode = 1;
        channel = 0;
        volume = 50;
    }
    int getMode() {
        return mode;
    }
    void num() {
        num1++;
    }
    void num_() {
        num2++;
    }
    void print(int i) {
        cout << "��" << i  << "�ŵ��ӻ�--";
        if (mode == 1)
            cout << "TV";
        else if (mode == 2)
            cout << "DVD";
        cout << "ģʽ--Ƶ��" << channel << "--����" << volume << endl;
    }
    int getnum1() {
        return num1;
    }
    int getnum2() {
        return num2;
    }
};

class Remote {
public:
    void fun(TV& T, int m, int c, int v) {
        T.channel = c;
        T.mode = m;
        T.volume += v;
        if (T.volume < 0)
            T.volume = 0;
        else if (T.volume > 100)
            T.volume = 100;
    }
 };

int TV::num1 = 0;
int TV::num2 = 0;

int main() {

    int n;
    cin >> n;
    TV* T = new TV[n];
    Remote R;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int id, mode, channel, volume;
        cin >> id >> mode >> channel >> volume;
        R.fun(T[id - 1], mode, channel, volume);
        T[id - 1].print(id);
    }
    for (int i = 0; i < n; i++) {
        if (T[i].getMode() == 1)
            T[i].num();
        else if(T[i].getMode() == 2)
            T[i].num_();
    }
    cout << "���ŵ��ӵĵ��ӻ�����Ϊ" << T[0].getnum1() << endl;
    cout << "����DVD�ĵ��ӻ�����Ϊ" << T[0].getnum2() << endl;
    delete[]T;
    return 0;
}
