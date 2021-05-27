#include <iostream>
#include <map>
#include <string>
using namespace std;

//输出
void output(map<int,string,greater<int>> mapv)
{
    /*for(auto x:mapv)
        cout<<x.first<<" "<<x.second<<endl;*/

    //支持迭代器++,--
    for(auto it=mapv.begin(); it!=mapv.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
    /*auto it = mapv.end();
    cout<<it->first<<" "<<it->second<<endl;
    it--;
    cout<<it->first<<" "<<it->second<<endl;*/

}
int main()
{
    //定义并初始化，默认键值升序
    /*map<int,string> mapStud{{2019155002,"liming"},
                                         {2019155001,"wangwu"},
                                         {2019155005,"zhaoliu"}};  */

    //定义map对象，键值降序
    map<int,string,greater<int>> mapStud;

    int m,n,no;
    string name,op;

    cin>>n;
    for(auto i=0; i<n; i++)
    {
        cin>>no>>name;
        mapStud[no] = name;
    }

    output(mapStud);

    //根据key,访问value
    cin>>no;
    cout<<mapStud[no]<<endl;
    auto it = mapStud.find(no);
    if(it!=mapStud.end())
        cout<<it->second<<endl;

    //lower_bound,upper_bound;
    it = mapStud.lower_bound(no);
    cout<<it->first<<" "<<it->second<<endl;
    it = mapStud.upper_bound(no);
    cout<<it->first<<" "<<it->second<<endl;


    cin>>m;
    for(int i=0; i<m; i++)
    {
       cin>>op;
       if(op=="insert")   //插入
       {
           cin>>no>>name;
           if(mapStud.insert(pair<int,string>(no,name)).second==false)  //插入不成功
                cout<<"insert error"<<endl;
           else
           {
                cout<<"insert success"<<endl;
                output(mapStud);
           }
       }
       else if(op=="delete")  //删除
       {
           cin>>no;
           if(mapStud.erase(no)>0)  //删除成功
           {
               cout<<"deleted success"<<endl;
               output(mapStud);
           }
           else
           {
                cout<<"delete success"<<endl;
           }
       }
       else if(op == "find")
       {
           cin>>no;
           auto reit = mapStud.equal_range(no);
           if(reit.first == reit.second)   //未找到
           {
               cout<<"find range error"<<endl;
               cout<<reit.first->first<<" "<<reit.first->second<<endl;
               cout<<reit.second->first<<" "<<reit.second->second<<endl;
           }
           else
           {
               cout<<"finded"<<endl;
               cout<<reit.first->first<<" "<<reit.first->second<<endl;
               cout<<reit.second->first<<" "<<reit.second->second<<endl;
           }

       }
    }
/*
3
2019155002 liming
2019155001 wangwu
2019155005 zhaoliu
2019155002
5
insert 2019155000 qianliu
insert 2019155010 lisi
delete 2019155000
find 2019155003
find 2019155002
*/


}

