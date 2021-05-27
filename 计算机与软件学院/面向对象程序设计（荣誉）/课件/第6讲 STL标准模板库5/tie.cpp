#include <tuple>
#include <functional>
#include <iostream>
using namespace std;

/*int main()
{
    int i;
    string s;
    double d;

    i=20,s="ok",d=10.5;
    cout<<i<<" "<<s<<" "<<d<<endl;
    tuple<int,string,double> t1(10,"Test",3.14);
    tie(i,s,d) = t1;   //分解t1
    cout<<i<<" "<<s<<" "<<d<<endl;

    i++;
    s+="ok";
    d+=10;
    t1 = tie(i,s,d);   //打包
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl;

    string s1="test";
    tie(i,ignore,d) = t1;   //分解,忽略第2项
    cout<<i<<" "<<s1<<" "<<d<<endl;


    return 0;
}*/

struct student
{
    string name;
    int id;
    double score;
};
int main()
{
    student s{"liming",2019150000,90.5};

    auto [name,id,score] = s;
    cout<<name<<" "<<id<<" "<<score<<endl;
    return 0;


}

