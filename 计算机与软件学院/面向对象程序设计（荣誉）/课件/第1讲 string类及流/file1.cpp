#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    string id,phonenumber;

    file.open("c:\\temp\\data.txt",ios::out|ios::in);


    if(!file.is_open())
    {
        cout<<"file open error!"<<endl;
        return 0;
    }

    while(file)
    {
        file>>id;

        if(id=="2019150340")
        {
            file.seekp(file.tellg());
            file<<" 13633322211";
            break;
        }
        file>>phonenumber;
    }

}
