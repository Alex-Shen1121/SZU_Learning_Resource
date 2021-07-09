#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<string.h>
using namespace std;

class CPeople {
protected:
    char* id;
    char* name;
public:
    CPeople() {
        this->id = new char[1];
        id[0] = '\0';
        this->name = new char[1];
        name[0] = '\0';
    }
    CPeople(char* name, char* id) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void setCPeople(char* name, char* id) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
};

class CInternetUser :virtual public CPeople {
protected:
    char* password;
public:
    CInternetUser():CPeople() {
        this->password = new char[1];
        password[0] = '\0';
    }
    void registerUser(char* name, char* id, char* password) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->password = new char[strlen(password) + 1];
        strcpy(this->password, password);
    }
    bool login(char* id, char* password) {
        if ((strcmp(this->password, password) != 0) || (strcmp(this->id, id) != 0))
            return false;
        return true;
    }
};

class CBankCustomer :virtual public CPeople {
protected:
    double b_balance;
public:
    void openAccount(char* name, char* id) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        b_balance = 0;
    }
    void deposit(double money) {
        b_balance += money;
    }
    bool withdraw(double money) {
        if (money > b_balance)
            return false;
        else
            b_balance -= money;
        return true;
    }
};

class CInternetBankCustomer :public CBankCustomer, public CInternetUser {
    double ib_balance, yesterday_ib_balance, today_profit, today_interest;
public:
    CInternetBankCustomer():CBankCustomer(),CInternetUser() {
        ib_balance = 0;
        yesterday_ib_balance = 0;
        today_profit = 0;
        today_interest = 0;
    }
    bool login(char* p, char* i) {
        if (CInternetUser::login(p, i) == false)
            return false;
        if (strcmp(CInternetUser::id, CBankCustomer::id) != 0 && strcmp(CInternetUser::name, CBankCustomer::name) != 0)
            return false;
        return true;
    }
    bool deposit(double money) {
        yesterday_ib_balance = ib_balance;
        if (money > b_balance)
            return false;
        b_balance -= money;
        yesterday_ib_balance += money;
        ib_balance = yesterday_ib_balance;
        return true;
    }
    bool withdraw(double money) {
        yesterday_ib_balance = ib_balance;
        if (money > ib_balance)
            return false;
        yesterday_ib_balance -= money;
        ib_balance = yesterday_ib_balance;
        b_balance += money;
        return true;
    }
    void setInterest(double interest) {
        today_interest = interest;
    }
    void calculateProfit() {
        if (ib_balance != yesterday_ib_balance)
            yesterday_ib_balance = ib_balance;
        ib_balance += ib_balance / 10000 * today_interest;
    }
    void print() {
        cout << "Name: " << name << " ID: " << id << endl;
        cout << "Bank balance: " << b_balance << endl;
        cout << "Internet bank balance: " << yesterday_ib_balance << endl << endl;
    }
};

int main()
{
    int t, no_of_days, i;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;

    //输入测试案例数t
    cin >> t;
    while (t--)
    {
        //输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        //输入银行开户用户名,id
        cin >> b_xm >> b_id;

        //输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        //输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            //输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
                if (ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T':  //从互联网金融转入银行帐户
            case 't':
                if (ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D':  //直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W':  //直接从银行帐户取款
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            //输出用户名,id 
            //输出银行余额
            //输出互联网金融账户余额
            ib_user.print();
        }
    }
    return 0;
}

