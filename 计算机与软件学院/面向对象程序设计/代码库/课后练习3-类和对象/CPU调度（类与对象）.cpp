#include<iostream>
using namespace std;
//类定义
class Process
{
private:
	char Name;
	int time_wait, time_run, level;
public:
	Process(char ch, int x, int y);
	void display();
	int getlevel();
};

//类实现

Process::Process(char ch, int x, int y)
{
	Name = ch;
	time_wait = x;
	time_run = y;
}

void Process::display()
{
	cout << Name << ' ' << time_wait << ' ' << time_run << ' ' << getlevel() << endl;
}

int Process::getlevel()
{
	return time_wait / time_run;
}

//主函数

int main()
{
	int wait, run, max, maxi;
	char name;
	cin >> name >> wait >> run;
	Process p1(name, wait, run);
	cin >> name >> wait >> run;
	Process p2(name, wait, run);
	cin >> name >> wait >> run;
	Process p3(name, wait, run);
	max = p1.getlevel();
	maxi = 1;
	if (p2.getlevel() > max)
	{
		max = p2.getlevel();
		maxi = 2;
	}
	if (p3.getlevel() > max)
	{
		maxi = 3;
		max = p3.getlevel();
	}
	if (maxi == 1)
		p1.display();
	else if (maxi == 2)
		p2.display();
	else if (maxi == 3)
		p3.display();

	return 0;

}
