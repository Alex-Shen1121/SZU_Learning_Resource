2018152062:Problem1129:�𰸴���
#include <iostream>
using namespace std;
/*ĳ���п���Ϊ��ͨ������ͨ������������֣�������ͨ������򵥵Ŀ���
�������԰������ţ�ID����������CName������Counter����
������������ʼ����initial������save����ȡ�take������ѯ��info����
��ͨ�������Ժͷ���˵������:
1.������һ�����֣������õ�����ĸ��ʾ�������һ���Ǹ�����
2.���������������һ�ʿ����������������������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
3.ȡ�������������һ�ʿ������������������Ҳ��ܳ��������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
4.��ѯ������������������Ϣ���������š�����������Ϣ֮���õ����̻�������*/

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
/*��ͨ������ͨ���������棬�������������ǽ�ͨ��Tcounter����
ʹ�ý�ͨ���ܹ���������ͨʹ�ã��������ⷽ����ת�ʣ�transfer���������п���Ǯת�뽻ͨ����У�
ע��ת�ʽ��ܳ����˻�ԭ�������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1*/
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
/*���������ͨ���������棬�����������������ö�ȣ�Credit����ʹ�ù�����ܹ�͸֧��
��ȡ����������Ǯ�������Ķ��ⷽ����͸֧��over����
��ִ��͸֧�����������0���������Ĳ��������ö�����ۼ���
ע��͸֧�������ܳ������+���ö�ȣ����Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
ʹ��c++���Ժ���̳з���ʵ���������п��Ĺ���*/
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

