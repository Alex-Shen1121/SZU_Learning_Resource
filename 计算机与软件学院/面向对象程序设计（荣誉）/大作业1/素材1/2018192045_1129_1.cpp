2018192045:Problem1129:��ȷ
#include<iostream>
using namespace std;
#include<cstring>

class comcard;
class Tcard;
class Vcard;
void show(comcard &p);
void show(Tcard &p);
void show(Vcard &p);
class comcard
{
protected:
    string ID;
    char name;
    int  Counter;
public:
    void initial(string ID1,char name1,int Counter1)
    {
        ID=ID1;
        name=name1;
        Counter=Counter1;
    }
    int save(int m)
    {
        if(m<=0)
            return -1;
        Counter+=m;
        return 1;
    }
    int take(int m)
    {
        if(m<=0||m>Counter)
            return -1;
        Counter-=m;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<name<<'-'<<Counter<<endl;
    }
};
class Tcard:public comcard
{
    int Tcounter;
public:
    void initial(string ID1,char name1,int Counter1,int Tcounter1)
    {
        ID=ID1;
        name=name1;
        Counter=Counter1;
        Tcounter=Tcounter1;
    }
    int transfer(int m)
    {
        if(m>Counter)
            return -1;
        Counter-=m;
        Tcounter+=m;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<name<<'-'<<Counter<<'-'<<Tcounter<<endl;
    }
};
class Vcard:public comcard
{
    int Credit;
public:
    void initial(string ID1,char name1,int Counter1,int Credit1)
    {
        ID=ID1;
        name=name1;
        Counter=Counter1;
        Credit=Credit1;

    }
    int over(int m)
    {
        if(m>Counter+Credit)
            return -1;
        Credit-=(m-Counter);
        Counter=0;
        return 1;

    }
    void info()
    {
        cout<<ID<<"-"<<name<<'-'<<Counter<<'-'<<Credit<<endl;
    }
};
int main()
{
    string ID;
    char name;
    int m1,m2,m3,m4;
    int Counter,Tcounter,Credit;//����һϵ�б��������������
    comcard C;
    cin>>ID>>name>>Counter;
    C.initial(ID,name,Counter);
    Tcard T;
    cin>>ID>>name>>Counter>>Tcounter;
    T.initial(ID,name,Counter,Tcounter);
    Vcard V;
    cin>>ID>>name>>Counter>>Credit;
    V.initial(ID,name,Counter,Credit);//�������ݲ���ʼ������initial����
    cin>>m1>>m2>>m3>>m4;//�������ݲ���˳����в���
    C.save(m1);
    C.save(m2);
    C.take(m3);
    C.take(m4);//��ͨ�����δ������ȡ�� ��save/take
    cin>>m1>>m2>>m3>>m4;
    T.save(m1);
    T.take(m2);
    T.transfer(m3);
    T.transfer(m4);//��1�δ��һ��ȡ��2��ת�ˣ�save/take/over
    cin>>m1>>m2>>m3>>m4;
    V.save(m1);
    V.take(m2);
    V.over(m3);
    V.over(m4);//�����һ�δ��һ��ȡ������͸֧
    show(C);
    show(T);
    show(V);//���ö�̬����show������ſ���״̬��
    return 0;
}
void show(comcard &p)
{
    p.info();
}
void show(Tcard &p)
{
    p.info();
}
void show(Vcard &p)
{
    p.info();
}

