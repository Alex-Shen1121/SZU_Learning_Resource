#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include "��ݻ���.h"
#include "ѧ����.h"
#include "��ʦ��.h"
#define StudentFile "����\\ѧ���ʺ���Ϣ.txt"
#define TeacherFile "����\\��ʦ�ʺ���Ϣ.txt"
#define AdminFile "����\\����Ա�ʺ���Ϣ.txt"
#define ComputerRoomFile "����\\������Ϣ.txt"
#define OrderStaticFile "����\\ԤԼ��Ϣ����.txt"
using namespace std;

class Admin :public Identidy {
public:
	//ѧ��
	string studentID;
	//Ĭ�Ϲ���
	Admin();
	//�вι��� ѧ��/����/����
	Admin(string name, string password);
	//�˵�����
	void Menu();
	//ע���ʺ�
	void Register();
	//�鿴�ʺ�
	void showAccount();
	//�鿴������Ϣ
	void showInfo();
	//���ԤԼ��Ϣ 
	void clear();
	//��������
	void addComputerRoom();
};