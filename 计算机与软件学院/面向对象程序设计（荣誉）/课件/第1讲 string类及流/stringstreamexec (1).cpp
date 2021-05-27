#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool alldigit(string s)
{
    for (auto x : s)
        if (x < '0' || x > '9')
            return false;
    return true;
}

int main()
{
    string str1, str2;
    stringstream ss;
    int  num1, num2;

    //如果都是数字完成数字加，否则字符串链接
    cin >> str1 >> str2;

    if (alldigit(str1) && alldigit(str2))
    {
        /*ss << str1 << " " << str2;
        ss >> num1 >> num2;*/
        num1 = stoi(str1);    //两种方法
        num2 = stoi(str2);
        cout<<num1+num2<<endl;
    }
    else
        cout<<str1 + str2<<endl;

    return 0;
}
