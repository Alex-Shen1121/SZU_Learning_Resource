2018152021:Problem1129:ÕýÈ·
#include<iostream>
using namespace std;
 
class card{
    protected:
        int ID;
        char CName;
        int Counter;
    public:
        card(int a,char b,int c){
            ID=a;
            CName=b;
            Counter=c;
        }
        int save(int d){
            if(d<0)
                return -1;
            else
            {
                Counter+=d;
                return 1;
            }
        }
        int take(int e){
            if(e<0||e>Counter)
                return -1;
            else
            {
                Counter-=e;
                return 1;
            }
        }
        virtual void info(){
            cout << ID << "-" << CName << "-" << Counter << endl;
        }
         
};
class B:public card{
    protected:
        int d;
    public:
        B(int A1,char C1,int B1,int D1):card(A1,C1,B1){
            d=D1;
        }
        void info(){
            cout << ID << "-" << CName << "-" << Counter << "-" << d << endl;
        }
        int transfer(int x){
            if(x>Counter||x<0)
                return -1;
            else
            {
                Counter-=x;
                d+=x;
                return 1;
            }
        }
};
class C:public card{
    protected:
        int d;
    public:
        C(int A1,char C1,int B1,int D1):card(A1,C1,B1){
            d=D1;
        }
        void info(){
            cout << ID << "-" << CName << "-" << Counter << "-"<< d << endl;
        }
        int over(int x){
            if(x<0||x>Counter+d)
                return -1;
            else
            {
                d-=(x-Counter);
                Counter=0;
                return 1;
            }
        }
};
 
void show(card & obj)
{
    obj.info();
}
int main()
{
    int a1,c1,a2,c2,a3,c3;
    char b1,b2,b3;
    int d2,d3;
    int x;
    cin >> a1 >> b1 >> c1
        >> a2 >> b2 >> c2 >> d2
        >> a3 >> b3 >> c3 >> d3;
         
    card a(a1,b1,c1);
    B b(a2,b2,c2,d2);
    C c(a3,b3,c3,d3);
     
    cin >> x;
    a.save(x);
    cin >> x;
    a.save(x);
    cin >> x;
    a.take(x);
    cin >> x;
    a.take(x);
    cin >> x;
    b.save(x);
    cin >> x;
    b.take(x);
    cin >> x;
    b.transfer(x);
    cin >> x;
    b.transfer(x);
    cin >> x;
    c.save(x);
    cin >> x;
    c.take(x);
    cin >> x;
    c.over(x);
    cin >> x;
    c.over(x);
     
    show(a);
    show(b);
    show(c);
     
     
    return 0;
}

