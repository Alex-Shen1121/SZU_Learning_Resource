#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<functional>
#include<numeric>
#include<queue>
#include "��ݻ���.h"
#include "����Ա��.h"
#include "��ʦ��.h"
#include "ѧ����.h"
#define StudentFile "����\\ѧ���ʺ���Ϣ.txt"
#define TeacherFile "����\\��ʦ�ʺ���Ϣ.txt"
#define AdminFile "����\\����Ա�ʺ���Ϣ.txt"
#define ComputerRoomFile "����\\������Ϣ.txt"
#define OrderStaticFile "����\\ԤԼ��Ϣ����.txt"
using namespace std;


//���˵�
void Menu1() {	
	cout << "--------------------------------------------" << endl;
	cout << "          ����ԤԼϵͳ��½����              " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. ѧ    ��                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. ��    ʦ                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. �� �� Ա                   " << endl;
	cout << "                                            " << endl;
	cout << "              0. ��    ��                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������ѡ��:" << endl;
}

//�˳�����
void ExitProgram() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	exit(-1);
}

//�����ʺ���Ϣ����֤��¼(ѧ��/��ʦ)
bool checkLogin(int type, int id, string name, string password) {
	ifstream ifs;
	int fid;
	string fname, fpassword;
	//ѧ����֤
	if (type == 1) {
		ifs.open(StudentFile, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ�������" << endl;
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
	//��ʦ��֤
	else if (type == 2) {
		ifs.open(TeacherFile, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ�������" << endl;
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

//�����ʺ���Ϣ����֤��¼(����Ա)
bool checkLogin(int type, string name, string password) {
	ifstream ifs;
	string fname, fpassword;
	ifs.open(AdminFile, ios::in);
	if (!ifs.is_open()) {
		cout << "�ʺ��ļ�������" << endl;
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

//��½����
bool Login(int type, Identidy*& p) {
	int id = 0;
	string name, password;
	switch (type)
	{
		//ѧ��
	case 1:cout << "������ѧ��:" << endl; cin >> id; break;
		//��ʦ
	case 2:cout << "������ְ����:" << endl; cin >> id; break;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> password;
	//��֤ѧ��/ְ���ţ��û����������Ƿ�ƥ��
	switch (type)
	{
		//ѧ��
	case 1:{
		if (checkLogin(1, id, name, password)) {
			cout << "ѧ���˺ŵ�½�ɹ���" << endl;
			system("pause");
			system("cls");
			p = new Student(id, name, password);
			return true;
		}
		else {
			cout << "ѧ���˺ŵ�½ʧ��" << endl;
			system("pause");
			return false;
		}
	}
		//��ʦ
	case 2:{
		if (checkLogin(2, id, name, password)) {
			cout << "��ʦ�˺ŵ�½�ɹ���" << endl;
			system("pause");
			system("cls");
			p = new Teacher(id, name, password);
			return true;
		}
		else {
			cout << "��ʦ�˺ŵ�½ʧ��" << endl;
			system("pause");
			return false;
		}
	}
		//����Ա
	case 3:{
		if (checkLogin(3, name, password)) {
			cout << "����Ա�˺ŵ�½�ɹ���" << endl;
			system("pause");
			system("cls");
			p = new Admin(name, password);
			return true;
		}
		else {
			cout << "����Ա�˺ŵ�½ʧ��" << endl;
			system("pause");
			return false;
		}
	}
	}	
	return false;
}

//ѧ�����ܽ���
void StudentFunction() {
	Identidy* p;
	//��¼ѧ���˺Ų���֤
	if (Login(1, p)) {
		//��½�ɹ�
		Student* obj = (Student*)p;
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//����ԤԼ
			if (opt == 1) {
				obj->apply();
			}
			//�鿴������ԤԼ
			else if (opt == 2) {
				obj->showMyApply();
			}
			//�鿴����ʹ�����
			else if (opt == 3) {
				obj->showAllApply();
			}
			//ȡ��ԤԼ
			else if (opt == 4) {
				obj->cancelApply();
			}
			//ע���˺�
			else if (opt == 5) {
				delete obj;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "�������������ѡ��" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else {
		return;
	}
}

//��ʦ���ܽ���
void TeacherFunction() {
	Identidy* p;
	//��¼��ʦ�˺Ų���֤
	if (Login(2, p)) {
		//��½�ɹ�
		Teacher* obj = (Teacher*)p;
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//�鿴����ʹ�����
			if (opt == 1) {
				obj->showAllApply();
			}
			//���ԤԼ
			else if (opt == 2) {
				obj->checkApply();
			}
			//ע���˺�
			else if (opt == 3) {
				delete obj;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "�������������ѡ��" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else {
		return;
	}
}

//����Ա���ܽ���
void AdminFunction() {
	Identidy* p;
	//��¼����Ա�˺Ų���֤
	if (Login(3, p)) {
		//��½�ɹ�
		Admin* obj = (Admin*)p;		
		while (true) {
			system("cls");
			obj->Menu();
			int opt;
			cin >> opt;
			//ע���˺�
			if (opt == 1) {
				obj->Register();
			}
			//�鿴�˺�
			else if (opt == 2) {
				obj->showAccount();
			}
			//�鿴����
			else if (opt == 3) {
				obj->showInfo();
			}
			//���ԤԼ
			else if (opt == 4) {
				obj->clear();
			}
			//��������
			else if (opt == 5) {
				obj->addComputerRoom();
			}
			//ע���˺�
			else if (opt == 6) {
				delete obj;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "�������������ѡ��" << endl;
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
		default:cout << "�������������ѡ��" << endl; system("pause"); break;
		}
	}
	return 0;
}
