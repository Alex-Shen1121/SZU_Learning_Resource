#include "ѧ����.h"

//��ȡ�ַ���
//����
//origin��������:test_student
//��a->������ b->test_student
void mySubstr(string& a, string& b, string& origin) {
	if (origin.find(':') != string::npos) {
		a = origin.substr(0, origin.find(':'));
		b = origin.substr(origin.find(':') + 1, origin.size() - origin.find(':') - 1);
	}
}
	

//��ʼ��ԤԼ��Ϣ��������
//��ֵ����x����Ϣ
//ʵֵ����Ϣ����+��Ϣ����
void setOrderStatic(map<int, map<string, string>>& m) {
	ifstream ifs;
	ifs.open(OrderStaticFile, ios::in);
	//�������û��������ڣ���ʼʱ�䣬����ʱ�䣬��������״̬
	string applicantName, date, startTime, endTime, roomName, status;
	//��x����Ϣ
	int num = 0;
	while (ifs >> applicantName>> roomName >> date >> startTime >> endTime >> status) {
		num++;
		string key, value;
		map<string, string> temp;
		//��ȡԤԼ��Ϣ�ַ���
		mySubstr(key, value, applicantName);
		temp.insert(pair<string, string>(key, value));
		mySubstr(key, value, roomName);
		temp.insert(pair<string, string>(key, value));
		mySubstr(key, value, date);
		temp.insert(pair<string, string>(key, value));
		mySubstr(key, value, startTime);
		temp.insert(pair<string, string>(key, value));
		mySubstr(key, value, endTime);
		temp.insert(pair<string, string>(key, value));
		mySubstr(key, value, status);
		temp.insert(pair<string, string>(key, value));
		m.insert(make_pair(num, temp));
	}
	ifs.close();
}

//����ԤԼ��Ϣ���������ļ�
void updateOrderFile(map<int, map<string, string>>& m) {
	ofstream ofs;
	//����ļ�����
	ofs.open(OrderStaticFile, ios::out | ios::trunc);
	for (int i = 1; i <= m.size(); i++) {
		//��������������Ϣ
		ofs << "������:" << m[i]["������"] << " " << "������:" << m[i]["������"] << " " << "����:" << m[i]["����"] << " " << "��ʼʱ��:" << m[i]["��ʼʱ��"] << " " << "����ʱ��:" << m[i]["����ʱ��"] << " " << "״̬:" << m[i]["״̬"] << endl;
	}
	ofs.close();
}

Student::Student()
{
	studentID = 0;
	Name = "";
	Password = "";
	//��ʼ��������Ϣ
	string RoomName;
	int RoomNum;
	int ComputerNum;
	int StartTime;
	int EndTime;
	ifstream ifs;
	string str1, str;
	//��ʼ��������Ϣ
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		RoomName = str1.substr(str1.find("��"), str1.find('\t') - str1.find("��"));
		RoomNum = stoi(str1.substr(str1.find("¥") + 2, str1.find('\t') - str1.find("¥")));
		ComputerNum = stoi(str1.substr(str1.find("��") + 4, str1.find("��") - 5 - str1.find("��")));
		StartTime = stoi(str1.substr(str1.find("��") + 4, str1.find("-") - str1.find("��") - 4));
		EndTime = stoi(str1.substr(str1.find("-") + 1, str1.length() - str1.find("-") - 5));
		vecComputerRoom.push_back(ComputerRoom(RoomName, RoomNum, ComputerNum, StartTime, EndTime));
	}
	ifs.close();
}

Student::Student(int id, string name, string password)
{
	studentID = id;
	Name = name;
	Password = password;
	//��ʼ��������Ϣ
	string RoomName;
	int RoomNum;
	int ComputerNum;
	int StartTime;
	int EndTime;
	ifstream ifs;
	string str1, str;
	//��ʼ��������Ϣ
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		RoomName = str1.substr(str1.find("��"), str1.find('\t') - str1.find("��"));
		RoomNum = stoi(str1.substr(str1.find("¥") + 2, str1.find('\t') - str1.find("¥")));
		ComputerNum = stoi(str1.substr(str1.find("��") + 4, str1.find("��") - 5 - str1.find("��")));
		StartTime = stoi(str1.substr(str1.find("��") + 4, str1.find("-") - str1.find("��") - 4));		
		EndTime = stoi(str1.substr(str1.find("-") + 1, str1.length() - str1.find("-") - 5));
		vecComputerRoom.push_back(ComputerRoom(RoomName, RoomNum, ComputerNum, StartTime, EndTime));
	}
	ifs.close();
}

//���˵�
void Student::Menu()
{
	cout << "��ӭѧ��" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "               ѧ�����ܽ���                 " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. ����ԤԼ                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. �鿴������ԤԼ             " << endl;
	cout << "                                            " << endl;
	cout << "              3. �鿴����ʹ�����           " << endl;
	cout << "                                            " << endl;
	cout << "              4. ȡ��ԤԼ                   " << endl;
	cout << "                                            " << endl;
	cout << "              5. ע����¼                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������ѡ��:" << endl;
}

//����ԤԼ
void Student::apply()
{
	int date, startTime, endTime, roomNum;
	string roomName;
	cout << "--------------------------------------------" << endl;
	if (vecComputerRoom.size() == 0) {
		cout << "���޿��ŵĻ�����" << endl;
		system("pause");
		return;
	}
	cout << "�����»������ţ�" << endl;
	//��ʾ���������
	for (int i = 1; i <= vecComputerRoom.size(); i++) {
		cout<<i<<"��"<<vecComputerRoom[i-1].RoomName<<'\t'<<"����������"<< vecComputerRoom[i - 1].ComputerNum << '\t' << "����ʱ�䣺" << setw(2) << setfill('0') << vecComputerRoom[i - 1].StartTime << '-' << setw(2) << setfill('0') << vecComputerRoom[i - 1].EndTime << "�ڿ�" << endl;
	}	
	//ѡ�����
	while (true) {
		cout << "��ѡ����ҪԤԼ�Ļ������룺" << endl;
		cin >> roomNum;
		if (roomNum >= 1 && roomNum <= vecComputerRoom.size()) {
			roomName = vecComputerRoom[roomNum - 1].RoomName;
			break;
		}
		cout << "�����������������롣" << endl;
	}
	//ѡ��ʱ��
	cout << "--------------------------------------------" << endl;
	cout << "��������ʱ��Ϊ��һ�����塣" << endl;
	cout << "1. ��һ" << endl;
	cout << "2. �ܶ�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "5. ����" << endl;
	while (true) {
		cout << "����������ԤԼ��ʱ�䣺" << endl;
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "�����������������롣" << endl;
	}
	//ѡ��ʱ��2
	cout << "--------------------------------------------" << endl;
	cout << "��������ʱ��Ϊ��" << vecComputerRoom[roomNum - 1].StartTime << "�ڿ�����" << vecComputerRoom[roomNum - 1].EndTime << "�ڿΡ�" << endl;
	while (true) {
		cout << "����������ԤԼ��ʱ��Σ�" << endl;
		cout << "��ʼʱ�䣨��xx�ڿΣ�:";
		cin >> startTime;
		cout << "����ʱ�䣨��xx�ڿΣ�:";
		cin >> endTime;
		//���ʱ��2�Ƿ����
		if (startTime >= 1 && endTime <= 12 && endTime >= startTime && (startTime >= vecComputerRoom[roomNum - 1].StartTime && endTime <= vecComputerRoom[roomNum - 1].EndTime)) {
			break;
		}
		else if (startTime < 1 || endTime > 12 || endTime < startTime) {
			cout << "�����������������롣" << endl;
			continue;
		}
		else if (!(startTime >= vecComputerRoom[roomNum - 1].StartTime && endTime <= vecComputerRoom[roomNum - 1].EndTime)) {
			cout << "���ڿ���ʱ�䡣ԤԼʧ�ܡ�" << endl;
			system("pause");
			return;
		}			
	}
	cout << "--------------------------------------------" << endl;
	cout << "ԤԼ�ɹ�����ȴ���ˡ�" << endl;
	ofstream ofs;
	//��ԤԼ��Ϣ�ļ�����׷��ԤԼ��¼
	ofs.open(OrderStaticFile, ios::app);
	ofs << "������:" << this->Name << " " << "������:" << roomName << " " << "����:" << date << " " << "��ʼʱ��:" << startTime << " " << "����ʱ��:" << endTime << " " << "״̬:" << 1 << endl;
	ofs.close();
	system("pause");
	return;
}

//�鿴������ԤԼ
void Student::showMyApply()
{
	//��ȡ����ԤԼ��Ϣ��
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "����ԤԼ��¼��" << endl;
		system("pause");
		return;
	}
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (this->Name == AllOrderStatic[i]["������"]) {
			n++;
			cout << n << "��" << "������:" << AllOrderStatic[i]["������"] << "\t" << "����:";
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
	}
	if (n == 0) {
		cout << "����ԤԼ��Ϣ��" << endl;
	}
	system("pause");
	return;
}

//�鿴����ʹ�����
void Student::showAllApply()
{
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
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

//ȡ��ԤԼ
void Student::cancelApply()
{
	//��ȡԤԼ��¼
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "����ԤԼ��¼��" << endl;
		system("pause");
		return;
	}
	cout << "ע������л����ͨ����ԤԼ��¼���Ա�ȡ����" << endl;
	//��ֵ����¼���˵�n��/ʵֵ���ܹ���i���Ķ�Ӧ��ϵ
	map<int, int> recordNum;
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (this->Name == AllOrderStatic[i]["������"] && (AllOrderStatic[i]["״̬"] == "1" || AllOrderStatic[i]["״̬"] == "2")) {
			n++;
			recordNum.insert(make_pair(n, i));
			cout << n << "��" << "������:" << AllOrderStatic[i]["������"] << "\t" << "����:";
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
			cout << status << endl;
		}
	}
	if (n == 0) {
		cout << "���޿��Ա�ȡ����ԤԼ���롣" << endl;
		system("pause");
		return;
	}
	cout << "��ѡ������Ҫȡ��ԤԼ��¼��" << endl;
	int select;
	cin >> select;
	if (select < 1 || select > n) {
		cout << "ѡ�����" << endl;
		system("pause");
		return;
	}
	cout << "�Ƿ�ȷ��ȡ����" << select << "��ԤԼ��" << endl;
	cout << "1: ȷ��" << endl;
	cout << "2: ȡ��" << endl;
	int select2;
	cin >> select2;
	if (select2 == 1) {
		//����״̬Ϊ��ȡ��
		AllOrderStatic[recordNum[select]]["״̬"] = "4";
		//���������ļ�
		updateOrderFile(AllOrderStatic);
		cout << "ȡ���ɹ���" << endl;
		system("pause");
		return;
	}
	else {
		cout << "ȡ��ʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	return;
}
