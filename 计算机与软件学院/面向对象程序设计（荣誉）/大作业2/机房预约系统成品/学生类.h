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

class Student :public Identidy {
public:
	//ѧ��
	int studentID;
	//Ĭ�Ϲ���
	Student();
	//�вι��� ѧ��/����/����
	Student(int id, string name, string password);
	//�˵�����
	void Menu();
	//����ԤԼ
	void apply();
	//�鿴������ԤԼ
	void showMyApply();
	//�鿴����ʹ�����
	void showAllApply();
	//ȡ��ԤԼ
	void cancelApply();
	//������Ϣ
	vector<ComputerRoom> vecComputerRoom;
};