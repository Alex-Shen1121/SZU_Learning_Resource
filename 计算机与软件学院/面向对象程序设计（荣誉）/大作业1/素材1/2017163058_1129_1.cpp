2017163058:Problem1129:��ȷ
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
//ĳ���п���Ϊ��ͨ������ͨ������������֣�������ͨ������򵥵Ŀ����������԰������ţ�ID����������CName������Counter����������������ʼ����initial������save����ȡ�take������ѯ��info������ͨ�������Ժͷ���˵������:
//1.������һ�����֣������õ�����ĸ��ʾ�������һ���Ǹ�����
//2.���������������һ�ʿ����������������������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
//3.ȡ�������������һ�ʿ������������������Ҳ��ܳ��������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
//4.��ѯ������������������Ϣ���������š�����������Ϣ֮���õ����̻�������

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















