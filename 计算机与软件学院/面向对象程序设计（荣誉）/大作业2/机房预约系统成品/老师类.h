#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<iomanip>
#include<string>
#include "��ݻ���.h"
#include "������.h"
#define StudentFile "����\\ѧ���ʺ���Ϣ.txt"
#define TeacherFile "����\\��ʦ�ʺ���Ϣ.txt"
#define AdminFile "����\\����Ա�ʺ���Ϣ.txt"
#define ComputerRoomFile "����\\������Ϣ.txt"
#define OrderStaticFile "����\\ԤԼ��Ϣ����.txt"
using namespace std;

class Teacher :public Identidy {
public:
	//ְ����
	int teacherID;
	//Ĭ�Ϲ���
	Teacher();
	//�вι��� ѧ��/����/����
	Teacher(int id, string name, string password);
	//�˵�����
	void Menu();
	//�鿴����ʹ�����
	void showAllApply();
	//���ԤԼ
	void checkApply();
};