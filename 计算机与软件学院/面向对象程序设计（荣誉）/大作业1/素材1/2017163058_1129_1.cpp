2017163058:Problem1129:正确
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
//某银行卡分为普通卡、交通卡、贵宾卡三种，其中普通卡是最简单的卡，具有属性包括卡号（ID）、户名（CName）、余额（Counter），方法包括：初始化（initial），存款（save），取款（take）、查询（info）。普通卡的属性和方法说明如下:
//1.卡号是一串数字，户名用单个字母表示，余额是一个非负整数
//2.存款操作是余额增加一笔款项，款项必须是正整数，不合法数据直接返回-1，执行成功则返回1
//3.取款操作是余额减少一笔款项，款项必须是正整数且不能超过余额，不合法数据直接返回-1，执行成功则返回1
//4.查询操作是输出卡的相关信息，包括卡号、户名、余额，信息之间用单个短划线连接

class RegularCard
{
protected:
    string ID;
    char name;
    int balance;
public:
    virtual void initial(string id, char n, int b)
    {
        ID = id;
        name = n;
        balance = b;
    }
    int save(int money)
    {
        if(money < 0)
        {
            return -1;
        }
        balance += money;
        return 1;
    }
    int take(int money)
    {
        if(money < 0 || money > balance)
        {
            return -1;
        }
        balance -= money;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<name<<"-"<<balance<<endl;
    }

};
class TrafficCard:public RegularCard
{
private:
    int Tbalance;
public:
    void initial(string id, char n, unsigned int b, int Tb)
    {
        ID = id;
        name = n;
        balance = b;
        Tbalance = Tb;
    }
    int transfer(int money)
    {
       if(money > balance)
       {
           return -1;
       }
       Tbalance += money;
       balance -= money;
       return 1;
    }
    void info()
    {
         cout<<ID<<"-"<<name<<"-"<<balance<<"-"<<Tbalance<<endl;
    }
};
class VIPCard:public RegularCard
{
private:
    int Credit;
public:
    void initial(string id, char n, unsigned int b, int c)
    {
        ID = id;
        name = n;
        balance = b;
        Credit = c;
    }
    int over(int money)
    {
        if(money > balance + Credit)
        {
            return -1;
        }
        Credit -= (money-balance);
        balance = 0;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<name<<"-"<<balance<<"-"<<Credit<<endl;
    }
};
void show(RegularCard &card)
{
    card.info();
}
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string ID;
    char name;
    int balance, Tbalance, Credit, money;

    RegularCard regularCard;
    TrafficCard trafficCard;
    VIPCard vipCard;
    cin>>ID>>name>>balance;
    regularCard.initial(ID, name, balance);
    cin>>ID>>name>>balance>>Tbalance;
    trafficCard.initial(ID, name, balance, Tbalance);
    cin>>ID>>name>>balance>>Credit;
    vipCard.initial(ID, name, balance, Credit);

    for(int i=0; i<2; i++)
    {
        cin>>money;
        regularCard.save(money);
    }
    for(int i=0; i<2; i++)
    {
        cin>>money;
        regularCard.take(money);
    }
    show(regularCard);

    cin>>money;
    trafficCard.save(money);
    cin>>money;
    trafficCard.take(money);
    for(int i=0;i<2;i++)
    {
        cin>>money;
        trafficCard.transfer(money);
    }
    show(trafficCard);

    cin>>money;
    vipCard.save(money);
    cin>>money;
    vipCard.take(money);
    for(int i=0;i<2;i++)
    {
        cin>>money;
        vipCard.over(money);
    }
    show(vipCard);
}















