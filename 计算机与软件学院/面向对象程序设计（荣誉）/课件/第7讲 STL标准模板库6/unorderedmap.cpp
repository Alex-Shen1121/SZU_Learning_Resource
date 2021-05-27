#include <iostream>
#include <unordered_map>
using namespace std;

//输出m中各桶子信息
void display(unordered_map<int,string> m);

int main()
{
    unordered_map<int,string>  smap;
    int n,id;
    string name;

    cin>>n;
    while(n--)
    {
        cin>>id>>name;
        smap.insert(pair<int,string>(id,name));
        cout<<smap.bucket_count()<<endl;    //桶子数
    }

    cout<<"------------------------------"<<endl<<endl;
    display(smap);

    //根据键值学号查找
    cout<<"---------find-------------"<<endl<<endl;
    cin>>id;
    auto it = smap.find(id);
    if(it!=smap.end())
        cout<<"finded: "<<it->second<<endl;
    else
        cout<<"not found"<<endl;
    cout<<smap[id]<<endl;


    cin>>id;
    cout<<id<<" in "<<smap.bucket(id)<<"th bucket"<<endl;
    cin>>name;
    auto re = smap.insert(pair<int,string>(id,name));
    if(re.second==false)
        cout<<"insert failure";
    else
        display(smap);
}

//输出m中各桶子信息
void display(unordered_map<int,string> m)
{
    int i;
    for(i=0; i<(int)m.bucket_count(); i++)
    {
        //第i个桶子元素数及元素
        cout<<i<<"th bucket: "<<m.bucket_size(i)<<": ";
        for(auto it=m.begin(i); it!=m.end(i); it++)
            cout<<"->("<<it->first<<","<<it->second<<")";
        cout<<endl;
    }
}



/*
8
2001 liming
2002 wangwu
2010 zhaosi
2009 qianliu
2010 lulu
2011 xiaoming
2003 taozi
2007 yangqi
2010
2007
dingmou
*/



