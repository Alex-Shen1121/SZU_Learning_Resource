#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[]不能添加数据，需有空间

int main()
{
    vector<vector<int>>   mat;
    vector<int> v(10);
    vector<int> degree;
    int n,sum,i,j,e;

    /*for(i=0; i<5; i++)
        v[i]=10;*/

    cin>>n;

    //输入矩阵值
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>e;
            v.push_back(e);
        }
        mat.push_back(v);
        v.clear();
    }


    //计算每行1的个数
    for(i=0; i<(int)mat.size(); i++)
    {
        /*sum = 0;
        for(j=0; j<(int)mat[i].size(); j++)
            sum+=mat[i][j];*/
        sum = count(begin(mat[i]),end(mat[i]),1);    //用count算法计算
        degree.push_back(sum);
    }

    //输出度
    vector<int>::iterator it;
    for(it = degree.begin(); it!=degree.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
}


/*
4
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/
