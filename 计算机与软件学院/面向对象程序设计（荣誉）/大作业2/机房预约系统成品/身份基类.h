#pragma once
#include<iostream>
using namespace std;

//��ݻ���
class Identidy {
public:
	//�û���
	string Name;
	//����
	string Password;
	virtual void Menu() = 0;
};