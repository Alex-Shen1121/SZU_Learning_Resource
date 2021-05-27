//求给定字符串中最长无重复子字符串的长度。

#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str, substring;
    int maxlength, findresult,start;

    getline(cin, str);

    findresult = string::npos;
    for (maxlength = str.length() / 2; maxlength > 1 ;maxlength--)
    {
        for (start = 0; start + 2 * maxlength <= (int)str.length(); start++)
        {
            substring = str.substr(start, maxlength);
            findresult = str.find(substring, start + maxlength);

            if (findresult != string::npos)
                break;
        }
        if (findresult != string::npos)
            break;
    }
    cout << maxlength << endl;
}
