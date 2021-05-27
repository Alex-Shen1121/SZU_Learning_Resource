#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> svec;
    int score;
    int n;

    //输入n及成绩
    cin>>n;
    while(n--)
    {
        cin>>score;
        svec.push_back(score);
    }

    //降序排序
    sort(begin(svec),end(svec),greater<double>());

    //查找第一个不及格的成绩
    auto it = find_if(begin(svec),end(svec),
                      [](double s)->bool{return s<60;});

    for(; it!=end(svec); it++)
        cout<<*it<<" ";
    cout<<endl;
}
