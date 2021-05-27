#include "��ʦ��.h"

//��ȡ�ַ���
//����
//origin��������:test_student
//��a->������ b->test_student
void mySubstr1(string& a, string& b, string& origin) {
	if (origin.find(':') != string::npos) {
		a = origin.substr(0, origin.find(':'));
		b = origin.substr(origin.find(':') + 1, origin.size() - origin.find(':') - 1);
	}
}

//��ʼ��ԤԼ��Ϣ��������
//��ֵ����x����Ϣ
//ʵֵ����Ϣ����+��Ϣ����
void setOrderStatic1(map<int, map<string, string>>& m) {
	ifstream ifs;
	ifs.open(OrderStaticFile, ios::in);
	//�������û��������ڣ���ʼʱ�䣬����ʱ�䣬��������״̬
	string applicantName, date, startTime, endTime, roomName, status;
	//��x����Ϣ
	int num = 0;
	while (ifs >> applicantName >> roomName >> date >> startTime >> endTime >> status) {
		num++;
		string key, value;
		map<string, string> temp;
		//��ȡԤԼ��Ϣ�ַ���
		mySubstr1(key, value, applicantName);
		temp.insert(pair<string, string>(key, value));
		mySubstr1(key, value, roomName);
		temp.insert(pair<string, string>(key, value));
		mySubstr1(key, value, date);
		temp.insert(pair<string, string>(key, value));
		mySubstr1(key, value, startTime);
		temp.insert(pair<string, string>(key, value));
		mySubstr1(key, value, endTime);
		temp.insert(pair<string, string>(key, value));
		mySubstr1(key, value, status);
		temp.insert(pair<string, string>(key, value));
		m.insert(make_pair(num, temp));
	}
	ifs.close();
}

//���������ļ�
void updateOrderFile1(map<int, map<string, string>>& m) {
	ofstream ofs;
	//����ļ�����
	ofs.open(OrderStaticFile, ios::out | ios::trunc);
	for (int i = 1; i <= m.size(); i++) {
		//��������������Ϣ
		ofs << "������:" << m[i]["������"] << " " << "������:" << m[i]["������"] << " " << "����:" << m[i]["����"] << " " << "��ʼʱ��:" << m[i]["��ʼʱ��"] << " " << "����ʱ��:" << m[i]["����ʱ��"] << " " << "״̬:" << m[i]["״̬"] << endl;
	}
	ofs.close();
}

Teacher::Teacher()
{
	teacherID = 0;
	Name = "";
	Password = "";
}

Teacher::Teacher(int id, string name, string password)
{
	teacherID = id;
	Name = name;
	Password = password;
}

//���˵�
void Teacher::Menu()
{
	cout << "��ӭ��ʦ" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "              ��ʦ���ܽ���                  " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. �鿴����ʹ�����           " << endl;
	cout << "                                            " << endl;
	cout << "              2. ���ԤԼ                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. ע����¼                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������ѡ��:" << endl;
}

//�鿴����ʹ�����
void Teacher::showAllApply()
{
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic1(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "����ԤԼ��¼��" << endl;
		system("pause");
		return;
	}
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		cout << i << "��" << "������:" << AllOrderStatic[i]["������"] << "\t" << "������:" << AllOrderStatic[i]["������"] << "\t" << "����:";
		//����ת��x
		string date;
		if (AllOrderStatic[i]["����"] == "1") {
			date = "��һ";
		}
		else if (AllOrderStatic[i]["����"] == "2") {
			date = "�ܶ�";
		}
		else if (AllOrderStatic[i]["����"] == "3") {
			date = "����";
		}
		else if (AllOrderStatic[i]["����"] == "4") {
			date = "����";
		}
		else if (AllOrderStatic[i]["����"] == "5") {
			date = "����";
		}
		cout << date << "\t" << "��ʼʱ��:��" << AllOrderStatic[i]["��ʼʱ��"] << "�ڿ�" << "\t" << "����ʱ��:��" << AllOrderStatic[i]["����ʱ��"] << "�ڿ�" << "\t" << "״̬:";
		//1������� 2�����ͨ�� 3�����ʧ�� 4����ȡ��
		string status;
		if (AllOrderStatic[i]["״̬"] == "1") {
			status = "�����";
		}
		else if (AllOrderStatic[i]["״̬"] == "2") {
			status = "���ͨ��";
		}
		else if (AllOrderStatic[i]["״̬"] == "3") {
			status = "���ʧ��";
		}
		else if (AllOrderStatic[i]["״̬"] == "4") {
			status = "��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	return;
}

//���ԤԼ
void Teacher::checkApply()
{
	//��ֵ����Ϣ����
	//ʵֵ����Ϣ����
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic1(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "����ԤԼ��¼��" << endl;
		system("pause");
		return;
	}
	cout << "ע������е�ԤԼ������Ա�������" << endl;	
	//��ֵ����¼���˵�n��/ʵֵ���ܹ���i���Ķ�Ӧ��ϵ
	map<int, int> recordNum;
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (AllOrderStatic[i]["״̬"] == "1") {
			n++;
			recordNum.insert(make_pair(n, i));
			cout << n << "��" << "������:" << AllOrderStatic[i]["������"] << " " << "������:" << AllOrderStatic[i]["������"] << "\t" << "����:";
			//����ת��x
			string date;
			if (AllOrderStatic[i]["����"] == "1") {
				date = "��һ";
			}
			else if (AllOrderStatic[i]["����"] == "2") {
				date = "�ܶ�";
			}
			else if (AllOrderStatic[i]["����"] == "3") {
				date = "����";
			}
			else if (AllOrderStatic[i]["����"] == "4") {
				date = "����";
			}
			else if (AllOrderStatic[i]["����"] == "5") {
				date = "����";
			}
			cout << date << "\t" << "��ʼʱ��:��" << AllOrderStatic[i]["��ʼʱ��"] << "�ڿ�" << "\t" << "����ʱ��:��" << AllOrderStatic[i]["����ʱ��"] << "�ڿ�" << "\t" << "״̬:";
			//1������� 2�����ͨ�� 3�����ʧ�� 4����ȡ��
			string status;
			if (AllOrderStatic[i]["״̬"] == "1") {
				status = "�����";
			}
			cout << status << endl;
		}
	}
	//����Ϊ��
	if (n == 0) {
		cout << "������Ҫ��˵�ԤԼ���롣" << endl;
		system("pause");
		return;
	}
	cout << "��ѡ������Ҫ��˵�ԤԼ���롣" << endl;
	int select;
	cin >> select;
	if (select < 1 || select > n) {
		cout << "ѡ�����" << endl;
		system("pause");
		return;
	}
	cout << "�������" << select << "��ԤԼ��¼����˽����" << endl;
	cout << "1: ͨ��" << endl;
	cout << "2: ��ͨ��" << endl;
	int select2;
	cin >> select2;
	if (select2 == 1) {
		//����״̬Ϊ���ͨ��
		AllOrderStatic[recordNum[select]]["״̬"] = "2";
		//���������ļ�
		updateOrderFile1(AllOrderStatic);
		cout << "���ͨ����" << endl;
		system("pause");
		return;
	}
	else if (select2 == 2) {
		//����״̬Ϊ���ʧ��
		AllOrderStatic[recordNum[select]]["״̬"] = "3";
		//���������ļ�
		updateOrderFile1(AllOrderStatic);
		cout << "��˲�ͨ����" << endl;
		system("pause");
		return;
	}
	return;
}
