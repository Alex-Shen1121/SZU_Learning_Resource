// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


int main()
{
    //auto list1 { 1,2,3 };   //编译错误,少=
    auto list2 = { 1,2,3 };   //

    for (auto x : list2)
        cout << x << " ";

    cout << typeid(list2).name() << endl;
    cout << endl;

    //去除const限定符
    const int num1 = 10;
    cout << typeid(num1).name() << num1<<endl;
    auto num2 = num1;
    num2 = 20;
    cout << typeid(num2).name() << " " << num2 << endl;

    //去除reference限定符
    const int& rnum1 = num1;
    auto rnum2 = rnum1;
    rnum2 = 20;
    cout << typeid(rnum1).name() << " " << rnum1 << endl;
    cout << typeid(rnum2).name() << " " << rnum2 << endl;

    //限定const,reference
    const auto num3 = num1;
    auto& rnum3 = num1;
    //num3 = 20;   //编译错误，常量
    //rnum3 = 20;  //编译错误，不能给常量赋值 
    cout << typeid(num3).name() << " " << num3 << endl;
    cout << typeid(rnum3).name() << " " << rnum3 << endl;

    //decltype未去除const和referecnce
    decltype(num1)  x=20;
    //x = 30;   编译错误，常量
    cout << typeid(x).name() << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
