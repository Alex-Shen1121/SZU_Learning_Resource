#include <iostream>
#include <map>
#include <string>
using namespace std;

//���
void output(multimap<int,string,greater<int>> mapv)
{
    /*for(auto x:mapv)
        cout<<x.first<<" "<<x.second<<endl;*/

    //֧�ֵ�����++,--
    for(auto it=mapv.begin(); it!=mapv.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
    /*auto it = mapv.end();
    cout<<it->first<<" "<<it->second<<endl;
    it--;
    cout<<it->first<<" "<<it->second<<endl;*/

}
int main()
{
    //����multimap���󣬼�ֵ����
    multimap<int,string,greater<int>> mapStud;

    int m,n,no;
    string name,op;

    cin>>n;
    for(auto i=0; i<n; i++)
    {
        cin>>no>>name;
        mapStud.insert(pair<int,string>(no,name));
    }

    output(mapStud);

    //����key,����value
    auto it = mapStud.find(no);
    if(it!=mapStud.end())
        cout<<it->second<<endl;

    //lower_bound,upper_bound;
    it = mapStud.lower_bound(no);
    if(it!=mapStud.end())
        cout<<it->first<<" "<<it->second<<endl;
    it = mapStud.upper_bound(no);
    if(it!=mapStud.end())
        cout<<it->first<<" "<<it->second<<endl;


    cin>>m;
    for(int i=0; i<m; i++)
    {
       cin>>op;
       if(op=="insert")   //����
       {
           cin>>no>>name;
           mapStud.insert(pair<int,string>(no,name));
           output(mapStud);

       }
       else if(op=="delete")  //ɾ��
       {
           cin>>no;
           if(mapStud.erase(no)>0)  //ɾ���ɹ�
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
           if(reit.first == reit.second)   //δ�ҵ�
           {
               cout<<"find range error"<<endl;
               cout<<reit.first->first<<" "<<reit.first->second<<endl;
               cout<<reit.second->first<<" "<<reit.second->second<<endl;
           }
           else
           {
               cout<<"finded"<<endl;
               for(it = reit.first; it!=reit.second; it++)
                cout<<it->first<<" "<<it->second<<endl;
           }

       }
    }
/*
3
3 liming
3 wangwu
2 zhaoliu
2
5
insert 2 qianliu
insert 1 lisi
delete 1
find 2
*/


}

