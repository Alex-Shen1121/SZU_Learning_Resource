#pragma once
#include<iostream>
using namespace std;

//身份基类
class Identidy {
public:
	//用户名
	string Name;
	//密码
	string Password;
	virtual void Menu() = 0;
};