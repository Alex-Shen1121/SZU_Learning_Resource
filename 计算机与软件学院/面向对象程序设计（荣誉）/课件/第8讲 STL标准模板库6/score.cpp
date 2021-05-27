#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> svec;
    int score;
    int n;

    //����n���ɼ�
    cin>>n;
    while(n--)
    {
        cin>>score;
        svec.push_back(score);
    }

    //��������
    sort(begin(svec),end(svec),greater<double>());

    //���ҵ�һ��������ĳɼ�
    auto it = find_if(begin(svec),end(svec),
                      [](double s)->bool{return s<60;});

    for(; it!=end(svec); it++)
        cout<<*it<<" ";
    cout<<endl;
}
