#include "����Ա��.h"

//��ʼ����ע��ѧ����ʦ������Ϣ����
void setVecAllData(vector<Student>& v1, vector<Teacher>& v2) {
	v1.clear();
	v2.clear();
	string fileName;
	int id;
	string name;
	string password;
	ifstream ifs;
	ifstream ifs1;
	fileName = StudentFile;
	//��ѧ����Ϣ�ļ�
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(Student(id, name, password));	
	ifs.close();
	//����ʦ��Ϣ�ļ�
	fileName = TeacherFile;
	ifs1.open(fileName);
	while (ifs1 >> id >> name >> password)
		v2.push_back(Teacher(id, name, password));
	return;
}

//��ʼ��ѧ��/ְ������������
void setVecIdData(vector<int>& v1, vector<int>& v2) {
	v1.clear();
	v2.clear();
	string fileName;
	int id;
	string name;
	string password;
	ifstream ifs;
	//��ѧ����Ϣ�ļ�
	fileName = StudentFile;
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(id);
	ifs.close();
	ifstream ifs2;
	fileName = TeacherFile;
	//����ʦ��Ϣ�ļ�
	ifs2.open(fileName);
	while (ifs2 >> id >> name >> password)
		v2.push_back(id);
	ifs2.close();
	return;
}

//��ʼ����ע��ѧ����ʦ�û�������
void setVecNameData(vector<string>& v1, vector<string>& v2) {
	v1.clear();
	v2.clear();
	string fileName;
	int id;
	string name;
	string password;
	ifstream ifs;
	ifstream ifs2;
	fileName = StudentFile;
	//��ѧ����Ϣ�ļ�
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(name);
	ifs.close();
	fileName = TeacherFile;
	//����ʦ��Ϣ�ļ�
	ifs2.open(fileName);
	while (ifs2 >> id >> name >> password)
		v2.push_back(name);
	ifs2.close();
	return;
}

//��ʼ���ѿ��Ż������������
void setVecRoomNum(vector<int>& v1) {
	ifstream ifs;
	string str1, str;
	//�򿪻�����Ϣ�ļ�
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		//��ȡ�������Ϣ
		str = str1.substr(str1.find("¥") + 2, str1.find('\t') - str1.find("¥"));
		v1.push_back(stoi(str));
	}
	return;
}

//����ظ����ظ�����true�����ظ�����false
//���ID�Ƿ��ظ�
bool checkRepeat(int newID, vector<int>& v1) {
	if (find(begin(v1), end(v1), newID) != end(v1))
		return true;
	else
		return false;
}

//���� ����û����ظ�
bool checkRepeat(string newName, vector<string>& v1) {
	if (find(begin(v1), end(v1), newName) != end(v1))
		return true;
	else
		return false;
}

Admin::Admin()
{
	Name = "";
	Password = "";
}

Admin::Admin(string name, string password)
{
	Name = name;
	Password = password;
}

//�˵�����
void Admin::Menu()
{
	cout << "��ӭ����Ա" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "             ����Ա���ܽ���                 " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. ע���˺�                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. �鿴�˺�                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. �鿴������Ϣ               " << endl;
	cout << "                                            " << endl;
	cout << "              4. ���ԤԼ                   " << endl;
	cout << "                                            " << endl;
	cout << "              5. ��������                   " << endl;
	cout << "                                            " << endl;
	cout << "              6. ע����¼                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������ѡ��:" << endl;
}

//����˺�
void Admin::Register()
{
	//��ע��ѧ��/ְ�������������ڼ���Ƿ����ظ�ע��
	vector<int> ExistedStudentID;
	vector<int> ExistedTeacherID;
	vector<string> ExistedStudentName;
	vector<string> ExistedTeacherName;
	//��ʼ����������
	setVecIdData(ExistedStudentID, ExistedTeacherID);
	setVecNameData(ExistedStudentName, ExistedTeacherName);
	system("cls");
	this->Menu();
	int opt;
	string fileName;
	ofstream ofs;
	int id;
	string name, password;
	while (true) {
		cout << "������ע���˺�����:" << endl;
		cout << "1: ѧ���˺�" << endl;
		cout << "2: ��ʦ�˺�" << endl;
		cin >> opt;
		//ע��ѧ���˺�
		if (opt == 1) {
			fileName = StudentFile;
			cout << "������ѧ��:" << endl;
			cin >> id;
			//���ID�Ƿ��ظ�ע��
			if (checkRepeat(id, ExistedStudentID)) {
				cout << "��ѧ���Ѿ����ڡ�" << endl << "ע��ʧ��" << endl;
				system("pause");
				return;
			}
			break;
		}
		else if (opt == 2) {
			fileName = TeacherFile;
			cout << "������ְ����:" << endl;
			cin >> id;
			//���ID�Ƿ��ظ�ע��
			if (checkRepeat(id, ExistedTeacherID)) {
				cout << "��ְ�����Ѿ����ڡ�" << endl << "ע��ʧ��" << endl;
				system("pause");
				return;
			}
			break;
		}
		else {
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			this->Menu();
		}
	}
	//�򿪶�Ӧ�ļ�
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "�ļ�������" << endl;
		ofs.close();
		system("pause");
		return;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	//����û����Ƿ��ظ�
	if (opt == 1) {
		if (checkRepeat(name, ExistedStudentName)) {
			cout << "���û����Ѿ����ڡ�" << endl << "ע��ʧ��" << endl;
			system("pause");
			return;
		}
	}
	else if (opt == 2) {
		if (checkRepeat(name, ExistedTeacherName)) {
			cout << "���û����Ѿ����ڡ�" << endl << "ע��ʧ��" << endl;
			system("pause");
			return;
		}
	}
	cout << "����������:" << endl;
	cin >> password;
	//�����Ϣ
	ofs << id << " " << name << " " << password << endl;
	cout << "�˺�ע��ɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	return;
}

//�鿴�˺�
void Admin::showAccount()
{
	//��ע��ѧ����ʦ������Ϣ���������ڱ���
	vector<Student> ExistedStudentInfo;
	vector<Teacher> ExistedTeacherInfo;
	//��ʼ����������
	setVecAllData(ExistedStudentInfo, ExistedTeacherInfo);
	string name, password;
	int opt;
	while (true) {
		cout << "��������Ҫ�鿴���˺�����:" << endl;
		cout << "1: ѧ���˺�" << endl;
		cout << "2: ��ʦ�˺�" << endl;
		cin >> opt;
		//ע��ѧ���˺�
		if (opt == 1) {
			cout << "ѧ���ʺ���Ϣ����:" << endl;
			//��ӡѧ����Ϣ
			for_each(begin(ExistedStudentInfo), end(ExistedStudentInfo), [](Student& s) {
				cout << "ѧ��: " << setiosflags(ios::left) << setw(15) << s.studentID << "�û���: " << setw(15) << s.Name << "����: " << setw(15) << s.Password << endl;
				});
			break;
		}
		else if (opt == 2) {
			cout << "��ʦ�˺���Ϣ����:" << endl;
			//��ӡ��ʦ��Ϣ
			for_each(begin(ExistedTeacherInfo), end(ExistedTeacherInfo), [](Teacher& t) {
				cout << "ְ����: " << setiosflags(ios::left) << setw(15) << t.teacherID << "�û���: " << setw(15) << t.Name << "����: " << setw(15) << t.Password << endl;
				});
			break;
		}
		else {
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			this->Menu();
		}
	}
	system("pause");
	return;
}

//�鿴����
void Admin::showInfo()
{
	ifstream ifs;
	string str;
	//�򿪻�����Ϣ�ļ�
	ifs.open(ComputerRoomFile);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		system("pause");
		return;
	}
	cout << "������Ϣ����:" << endl;
	//��ӡ������Ϣ
	while (getline(ifs, str))
		cout << str << endl;
	system("pause");
	return;
}

//���ԤԼ
void Admin::clear()
{
	cout << "�Ƿ�ȷ�����ԤԼ��Ϣ��" << endl;
	cout << "1: ȷ��" << endl;
	cout << "2: ����" << endl;
	int opt;
	cin >> opt;
	if (opt == 1) {
		//����ԭ�ļ�����գ�
		ofstream ofs(OrderStaticFile, ios::trunc);
		ofs.close();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	return;
}

//��������
void Admin::addComputerRoom()
{
	vector<int> RoomNumVec;
	setVecRoomNum(RoomNumVec);
	int RoomNum, ComputerNum, startTime, endTime;
	cout << "��������������:" << endl;
	cin >> RoomNum;
	//��鷿����Ƿ��ظ�
	if (checkRepeat(RoomNum, RoomNumVec)) {
		cout << "�Ѿ����ڸû�����Ϣ�����ʧ��" << endl;
		system("pause");
		return;
	}
	cout << "�������������:" << endl;
	cin >> ComputerNum;
	cout << "�����뿪��ʱ��:" << endl;
	cout << "��ʼʱ�䣨��xx�ڿΣ�:";
	cin >> startTime;
	cout << "����ʱ�䣨��xx�ڿΣ�:";
	cin >> endTime;
	if (startTime < 1 || endTime>12 || endTime < startTime) {
		cout << "ʱ������������ʧ��" << endl;
		system("pause");
		return;
	}
	ofstream ofs;
	//���·���Ϣ�ļ�
	ofs.open(ComputerRoomFile, ios::out | ios::app);
	//���ں��������Ϣ
	ofs << "�������ƣ������������¥" << RoomNum << '\t' << "����������" << ComputerNum << '\t' << "����ʱ�䣺" << setw(2) << setfill('0') << startTime << '-' << setw(2) << setfill('0') << endTime << "�ڿ�" << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	return;
}
