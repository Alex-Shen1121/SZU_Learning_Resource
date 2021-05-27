#include <regex>
#include <iostream>
using namespace std;

int main()
{
    regex r2("([0-9a-zA-Z]{1,20})@([0-9a-zA-Z]{1,20})\\.([[:alnum:].]{1,20})");
    
    while (true)
    {
        cout << "enter email: (q=quit):";
        string str;

        if (!getline(cin, str) || str == "q")
            break;

        smatch m;
        if (regex_match(str, m, r2))
        {
            cout << " valid data." << endl;
            cout << m.size() << endl;
            if (m.size() != 0)
            {
                for (auto i = 0; i < (int)m.size(); i++)
                    cout << m[i] << endl;
            }
        }
        else
            cout << " Invalid data." << endl;
    }
    return 0;
}

