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

class Student :public Identidy {
public:
	//学号
	int studentID;
	//默认构造
	Student();
	//有参构造 学号/姓名/密码
	Student(int id, string name, string password);
	//菜单界面
	void Menu();
	//申请预约
	void apply();
	//查看已申请预约
	void showMyApply();
	//查看机房使用情况
	void showAllApply();
	//取消预约
	void cancelApply();
	//机房信息
	vector<ComputerRoom> vecComputerRoom;
};