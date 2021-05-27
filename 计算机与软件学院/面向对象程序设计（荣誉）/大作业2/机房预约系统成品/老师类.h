#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<iomanip>
#include<string>
#include "身份基类.h"
#include "机房类.h"
#define StudentFile "数据\\学生帐号信息.txt"
#define TeacherFile "数据\\老师帐号信息.txt"
#define AdminFile "数据\\管理员帐号信息.txt"
#define ComputerRoomFile "数据\\机房信息.txt"
#define OrderStaticFile "数据\\预约信息汇总.txt"
using namespace std;

class Teacher :public Identidy {
public:
	//职工号
	int teacherID;
	//默认构造
	Teacher();
	//有参构造 学号/姓名/密码
	Teacher(int id, string name, string password);
	//菜单界面
	void Menu();
	//查看机房使用情况
	void showAllApply();
	//审核预约
	void checkApply();
};