2016071031:Problem1234:正确
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Group

{

public:

virtual int add(int x, int y)=0;//输出加法的运算结果

virtual int sub(int x, int y)=0;//输出减法的运算结果

};

class GroupA: public Group{
public:
    int add(int x, int y) { return x + y; }
    int sub(int x, int y) { return x - y; }
};

class GroupB: public Group{
public:
    int add(int x, int y) { return x + y; }
    int sub(int x, int y) {
         int carry = 0, res = 0;
         while(x && y) {
            int x_b = x % 10;
            int y_b = y % 10;
            res += (x_b > y_b ? x_b - y_b : x_b + 10 - y_b) * pow(10, carry) ;
            carry++;
            x /= 10;
            y /= 10;
         }

         if (x){
            res += x * pow(10, carry);
         }
         if (y){
            res += y * pow(10, carry);
         }
         return res;
    }
};

class GroupC: public Group{
public:
    int add(int x, int y) {
        int carry = 0, res = 0;
        while (x && y) {
            int x_b = x % 10;
            int y_b = y % 10;
            res += (x_b + y_b >= 10? x_b + y_b - 10 : x_b + y_b) * pow(10, carry) ;
            carry++;
            x /= 10;
            y /= 10;
        }

        if (x){
            res += x * pow(10, carry);
         }
         if (y){
            res += y * pow(10, carry);
         }

         return res;
    }
    int sub(int x, int y) {
         int carry = 0, res = 0;
         while(x && y) {
            int x_b = x % 10;
            int y_b = y % 10;
            res += (x_b > y_b ? x_b - y_b : x_b + 10 - y_b) * pow(10, carry) ;
            carry++;
            x /= 10;
            y /= 10;
         }

         if (x){
            res += x * pow(10, carry);
         }
         if (y){
            res += y * pow(10, carry);
         }
         return res;
    }
};


int main() {
//	freopen("ojdata.txt", "r", stdin);
    int t, type, x, y;
    char oper;
    Group * g;

    cin>>t;
    while (t--) {
        cin>>type;
        if(type == 1) {
            g = new GroupA();
            cin>>x>>oper>>y;
            if (oper == '+') {
                cout<< g->add(x, y) <<endl;
            } else {
                cout<< g->sub(x, y) <<endl;
            }
        } else if (type == 2) {
            g = new GroupB();
            cin>>x>>oper>>y;
            if (oper == '+') {
                cout<< g->add(x, y) <<endl;
            } else {
                cout<< g->sub(x, y) <<endl;
            }
        } else {
            g = new GroupC();
            cin>>x>>oper>>y;
            if (oper == '+') {
                cout<< g->add(x, y) <<endl;
            } else {
                cout<< g->sub(x, y) <<endl;
            }
        }
    }

    return 0;
}


