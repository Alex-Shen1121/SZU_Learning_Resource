#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include "身份基类.h"
#include "学生类.h"
#include "老师类.h"
#define StudentFile "数据\\学生帐号信息.txt"
#define TeacherFile "数据\\老师帐号信息.txt"
#define AdminFile "数据\\管理员帐号信息.txt"
#define ComputerRoomFile "数据\\机房信息.txt"
#define OrderStaticFile "数据\\预约信息汇总.txt"
using namespace std;

class Admin :public Identidy {
public:
	//学号
	string studentID;
	//默认构造
	Admin();
	//有参构造 学号/姓名/密码
	Admin(string name, string password);
	//菜单界面
	void Menu();
	//注册帐号
	void Register();
	//查看帐号
	void showAccount();
	//查看机房信息
	void showInfo();
	//清空预约信息 
	void clear();
	//新增机房
	void addComputerRoom();
};