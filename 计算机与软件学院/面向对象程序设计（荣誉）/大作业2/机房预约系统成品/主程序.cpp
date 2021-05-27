#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<functional>
#include<numeric>
#include<queue>
#include "身份基类.h"
#include "管理员类.h"
#include "老师类.h"
#include "学生类.h"
#define StudentFile "数据\\学生帐号信息.txt"
#define TeacherFile "数据\\老师帐号信息.txt"
#define AdminFile "数据\\管理员帐号信息.txt"
#define ComputerRoomFile "数据\\机房信息.txt"
#define OrderStaticFile "数据\\预约信息汇总.txt"
using namespace std;


//主菜单
void Menu1() {	
	cout << "--------------------------------------------" << endl;
	cout << "          机房预约系统登陆界面              " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. 学    生                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. 老    师                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. 管 理 员                   " << endl;
	cout << "                                            " << endl;
	cout << "              0. 退    出                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入你的选择:" << endl;
}

//退出程序
void ExitProgram() {
	cout << "欢迎下次使用！" << endl;
	exit(-1);
}

//根据帐号信息，验证登录(学生/老师)
bool checkLogin(int type, int id, string name, string password) {
	ifstream ifs;
	int fid;
	string fname, fpassword;
	//学生验证
	if (type == 1) {
		ifs.open(StudentFile, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在" << endl;
			ifs.close();
			system("pause");
			return false;
		}
		while (ifs >> fid >> fname >> fpassword) {
			if (id == fid && name == fname && password == fpassword) {
				return true;
			}
		}
		return false;
	}
	//老师验证
	else if (type == 2) {
		ifs.open(TeacherFile, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在" << endl;
			ifs.close();
			system("pause");
			return false;
		}
		while (ifs >> fid >> fname >> fpassword) {
			if (id == fid && name == fname && password == fpassword) {
				return true;
			}
		}
		return false;
	}
	return false;
}

//根据帐号信息，验证登录(管理员)
bool checkLogin(int type, string name, string password) {
	ifstream ifs;
	string fname, fpassword;
	ifs.open(AdminFile, ios::in);
	if (!ifs.is_open()) {
		cout << "帐号文件不存在" << endl;
		ifs.close();
		system("pause");
		return false;
	}
	while (ifs >> fname >> fpassword) {
		if (name == fname && password == fpassword) {
			return true;
		}
	}
	return false;
}

//登陆界面
bool Login(int type, Identidy*& p) {
	int id = 0;
	string name, password;
	switch (type)
	{
		//学生
	case 1:cout << "请输入学号:" << endl; cin >> id; break;
		//老师
	case 2:cout << "请输入职工号:" << endl; cin >> id; break;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> password;
	//验证学号/职工号，用户名，密码是否匹配
	switch (type)
	{
		//学生
	case 1:{
		if (checkLogin(1, id, name, password)) {
			cout << "学生账号登陆成功！" << endl;
			system("pause");
			system("cls");
			p = new Student(id, name, password);
			return true;
		}
		else {
			cout << "学生账号登陆失败" << endl;
			system("pause");
			return false;
		}
	}
		//老师
	case 2:{
		if (checkLogin(2, id, name, password)) {
			cout << "老师账号登陆成功！" << endl;
			system("pause");
			system("cls");
			p = new Teacher(id, name, password);
			return true;
		}
		else {
			cout << "老师账号登陆失败" << endl;
			system("pause");
			return false;
		}
	}
		//管理员
	case 3:{
		if (checkLogin(3, name, password)) {
			cout << "管理员账号登陆成功！" << endl;
			system("pause");
			system("cls");
			p = new Admin(name, password);
			return true;
		}
		else {
			cout << "管理员账号登陆失败" << endl;
			system("pause");
			return false;
		}
	}
	}	
	return false;
}

//学生功能界面
void StudentFunction() {
	Identidy* p;
	//登录学生账号并验证
	if (Login(1, p)) {
		//登陆成功
		Student* obj = (Student*)p;
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//申请预约
			if (opt == 1) {
				obj->apply();
			}
			//查看已申请预约
			else if (opt == 2) {
				obj->showMyApply();
			}
			//查看机房使用情况
			else if (opt == 3) {
				obj->showAllApply();
			}
			//取消预约
			else if (opt == 4) {
				obj->cancelApply();
			}
			//注销账号
			else if (opt == 5) {
				delete obj;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "输入错误，请重新选择！" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else {
		return;
	}
}

//老师功能界面
void TeacherFunction() {
	Identidy* p;
	//登录老师账号并验证
	if (Login(2, p)) {
		//登陆成功
		Teacher* obj = (Teacher*)p;
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//查看机房使用情况
			if (opt == 1) {
				obj->showAllApply();
			}
			//审核预约
			else if (opt == 2) {
				obj->checkApply();
			}
			//注销账号
			else if (opt == 3) {
				delete obj;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "输入错误，请重新选择！" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else {
		return;
	}
}

//管理员功能界面
void AdminFunction() {
	Identidy* p;
	//登录管理员账号并验证
	if (Login(3, p)) {
		//登陆成功
		Admin* obj = (Admin*)p;		
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//注册账号
			if (opt == 1) {
				obj->Register();
			}
			//查看账号
			else if (opt == 2) {
				obj->showAccount();
			}
			//查看机房
			else if (opt == 3) {
				obj->showInfo();
			}
			//清空预约
			else if (opt == 4) {
				obj->clear();
			}
			//新增机房
			else if (opt == 5) {
				obj->addComputerRoom();
			}
			//注销账号
			else if (opt == 6) {
				delete obj;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "输入错误，请重新选择！" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else {
		return;
	}
}

int main() {
	while (true) {
		system("cls");
		Menu1();
		int opt;
		cin >> opt;
		switch (opt) {
		case 1:StudentFunction(); break;
		case 2:TeacherFunction(); break;
		case 3:AdminFunction(); break;
		case 0:ExitProgram(); break;
		default:cout << "输入错误，请重新选择！" << endl; system("pause"); break;
		}
	}
	return 0;
}
