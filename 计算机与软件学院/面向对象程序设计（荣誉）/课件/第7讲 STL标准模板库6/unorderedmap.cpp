#include <iostream>
#include <unordered_map>
using namespace std;

//���m�и�Ͱ����Ϣ
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
        cout<<smap.bucket_count()<<endl;    //Ͱ����
    }

    cout<<"------------------------------"<<endl<<endl;
    display(smap);

    //���ݼ�ֵѧ�Ų���
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

//���m�и�Ͱ����Ϣ
void display(unordered_map<int,string> m)
{
    int i;
    for(i=0; i<(int)m.bucket_count(); i++)
    {
        //��i��Ͱ��Ԫ������Ԫ��
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



