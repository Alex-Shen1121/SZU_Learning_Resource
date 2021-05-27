2018152062:Problem1129:答案错误
#include <iostream>
using namespace std;
/*某银行卡分为普通卡、交通卡、贵宾卡三种，其中普通卡是最简单的卡，
具有属性包括卡号（ID）、户名（CName）、余额（Counter），
方法包括：初始化（initial），存款（save），取款（take）、查询（info）。
普通卡的属性和方法说明如下:
1.卡号是一串数字，户名用单个字母表示，余额是一个非负整数
2.存款操作是余额增加一笔款项，款项必须是正整数，不合法数据直接返回-1，执行成功则返回1
3.取款操作是余额减少一笔款项，款项必须是正整数且不能超过余额，不合法数据直接返回-1，执行成功则返回1
4.查询操作是输出卡的相关信息，包括卡号、户名、余额，信息之间用单个短划线连接*/

class Card
{
protected:
    string ID;
    char CName;
    int Counter;
public:
    Card(string _ID,char _CName,int _Counter):ID(_ID),CName(_CName),Counter(_Counter){}
    virtual int save(int e)
    {
        if(e>=0)
        {
            Counter+=e;
            return 1;
        }
        else
            return -1;
    }
    virtual int take(int e)
    {
        if(e<=Counter&&e>=0)
        {
            Counter-=e;
            return 1;
        }
        else
            return -1;
    }
    virtual void print()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};
/*交通卡是普通卡的升级版，包含额外属性是交通余额（Tcounter），
使得交通卡能够当作深圳通使用，包含额外方法是转帐（transfer），把银行卡的钱转入交通余额中，
注意转帐金额不能超过账户原有余额，不合法数据直接返回-1，执行成功则返回1*/
class Traffic_Card:public Card
{
protected:
    int Tcounter;
public:
    Traffic_Card(string _ID,char _CName,int _Counter,int _Tcounter):Card(_ID,_CName,_Counter),Tcounter(_Tcounter){}
    int save(int e)
    {
        if(e>=0)
        {
            Counter+=e;
            return 1;
        }
        return -1;
    }
    int transfer(int e)
    {
        if(e<0)
            return -1;
        else
        {
            if(Card::take(e))
            {
                Tcounter+=e;
                return 1;
            }
            return -1;
        }
    }
    void print()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
/*贵宾卡是普通卡的升级版，包含额外属性是信用额度（Credit），使得贵宾卡能够透支，
即取出超过余额的钱，包含的额外方法是透支（over），
当执行透支操作，余额清0，超过余额的部分用信用额度来扣减。
注意透支的最大金额不能超过余额+信用额度，不合法数据直接返回-1，执行成功则返回1
使用c++语言和类继承方法实现上述银行卡的功能*/
class VIP_Card:public Card
{
protected:
    int Credict;
public:
    VIP_Card(string _ID,char _CName,int _Counter,int _Credict):Card(_ID,_CName,_Counter),Credict(_Credict){}
    int save(int e)
    {
        if(e>=0)
        {
            Counter+=e;
            return 1;
        }
        return -1;
    }
    int take(int e)
    {
        if(e<0)
            return -1;
        else
        {
            if(e>Credict+Counter)
                return -1;
            else
            {
                if(e<Counter)
                {
                    Counter-=e;
                }
                else
                {
                    Credict-=(e-Counter);
                    Counter=0;
                }
                return 1;
            }
        }
    }
    void print()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credict<<endl;

    }
    friend void show(Card &p);
};
void show(Card &p)
{
    p.print();
}
int main()
{
    string ID;
    char name;
    int Counter,Tcounter,Credict;
    cin>>ID>>name>>Counter;
    Card u(ID,name,Counter);
    cin>>ID>>name>>Counter>>Tcounter;
    Traffic_Card v(ID,name,Counter,Tcounter);
    cin>>ID>>name>>Counter>>Credict;
    VIP_Card w(ID,name,Counter,Credict);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    u.save(a);
    u.save(b);
    u.take(c);
    u.take(d);
    cin>>a>>b>>c>>d;
    v.save(a);
    v.take(b);
    v.transfer(c);
    v.transfer(d);
    cin>>a>>b>>c>>d;
    w.save(a);
    w.take(b);
    w.take(c);
    w.take(d);
    show(u);
    show(v);
    show(w);
    return 0;
}

