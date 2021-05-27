#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Problem2 {
	string problemID;
	//��¼�ǵڼ����ύ�Ĵ���
	int submitNum;
	void operator=(Problem2& p2) {
		problemID = p2.problemID;
		submitNum = p2.submitNum;
	}
};

class Student {
public:
	//ͬѧѧ��
	string studentID;
	//��ͬѧ��ȷ��ż��ϣ�������ύ��
	vector<string> correctProblemID;
	//��ͬѧ������ż��ϣ�������ύ��
	vector<string> wrongProblemID;
	vector<Problem2> correctProblemID2;
	vector<Problem2> wrongProblemID2;
	int problemNum;
	//������Ϣ�У���ͬѧÿ����Ϣ����
	Student(string studentID, string problemID, string correctORwrong) {
		this->studentID = studentID;
		Problem2 temp{ problemID,getProblemNum() + 1 };
		if (correctORwrong == "��ȷ")
			correctProblemID2.push_back(temp);
		else
			wrongProblemID2.push_back(temp);
		if (correctORwrong == "��ȷ")
			correctProblemID.push_back(studentID);
		else
			wrongProblemID.push_back(studentID);
	}
	//���ѧ���ش���Ϣ
	void addProblem(string problemID, string correctORwrong) {
		Problem2 temp{ problemID,getProblemNum() };
		if (correctORwrong == "��ȷ")
			correctProblemID2.push_back(temp);
		else
			wrongProblemID2.push_back(temp);
	}
	//���ظ�ѧ���ܴ�����
	int getProblemNum() {
		return correctProblemID2.size() + wrongProblemID2.size();
	}
	//����ĳһ����ύ������
	int sameProblemNum(string id) {
		int sum = 0;
		for_each(begin(correctProblemID2), end(correctProblemID2), [id, &sum](Problem2 a) {if (a.problemID == id)	sum++; });
		for_each(begin(wrongProblemID2), end(wrongProblemID2), [id, &sum](Problem2 a) {if (a.problemID == id)	sum++; });
		return sum;
	}
};

class Problem {
public:
	string problemID;
	//����Ŀ���ͬѧID���ϣ�������ύ��
	vector<string> correctStudentID;
	//����Ŀ���ͬѧID���ϣ�������ύ��
	vector<string> wrongStudentID;
	//������Ϣ�У�����Ŀ��Ӧ��Ϣ����
	Problem(string studentID, string problemID, string correctORwrong) {
		this->problemID = problemID;
		if (correctORwrong == "��ȷ")
			correctStudentID.push_back(studentID);
		else
			wrongStudentID.push_back(studentID);
	}
	//��Ӹ����Ӧ��ѧ����Ϣ
	void addStudent(string studentID, string correctORwrong) {
		if (correctORwrong == "��ȷ")
			correctStudentID.push_back(studentID);
		else
			wrongStudentID.push_back(studentID);
	}
	//���ػش�����ѧ������
	int getStudentNum() {
		return correctStudentID.size() + wrongStudentID.size();
	}

};

//��������ͬѧ����Ϣ
vector<Student> studentVec;
//����������Ŀ����Ϣ
vector<Problem> problemVec;
//���ڲ���ļ����ļ���
string FileBeingSplit;
//���ļ�����
int FileSum = 0;

void Menu1() {
	cout << "------------------------------------" << endl;
	cout << "1.����ļ�                          " << endl;
	cout << "2.ͳ������                          " << endl;
	cout << "3.���׼��                          " << endl;
	cout << "4.�˳�����                          " << endl;
	cout << "������1/2/3/4��ѡ����             " << endl;
	cout << "------------------------------------" << endl;
}

void Menu2() {
	cout << "------------------------------------" << endl;
	cout << "1.����ͳ�ƽ��                      " << endl;
	cout << "2.ѧ����Ϣ��ѯ                      " << endl;
	cout << "3.��Ŀ��Ϣ��ѯ                      " << endl;
	cout << "4.�����ϼ�ҳ��                      " << endl;
	cout << "������1/2/3/4��ѡ����             " << endl;
	cout << "------------------------------------" << endl;
}

void SplitFiles() {
	ofstream ofs;
	ifstream ifs;
	string filename;
	string str;
	string openFileName;
	string targetFolder;
	studentVec.clear();
	problemVec.clear();
	FileSum = 0;
	system("CLS");
	cout << "------------------------------------" << endl;
	cout << "����������Ҫ��ֲ��������ļ�����    " << endl;
	cout << "ע��1.�ļ���������logs-1005.txt     " << endl;
	cout << "    2.ȷ��������ļ���ͬһ�ļ�����  " << endl;
	cout << "    3.����ʱ�����ļ���Ŀ¼��ѡ�����޸�ԭ�루��Ϊ����д��" << endl;
	cout << "    4.txt�ļ������ʽΪANSI����ֹ�������룩" << endl;
	cout << "------------------------------------" << endl;
	cin >> openFileName;
	FileBeingSplit = openFileName;
	int filenum = 0;
	int linenum = -1;
	//linenum��Ǹ��ļ��м��� ���ļ���������Ϊ-1��
	ifs.open(openFileName, ios::in);
	//����ļ��Ƿ��ʧ��
	if (ifs.is_open() == 0) {
		cout << "������ļ�������" << endl;
		system("pause");
		return;
	}
	cout << "���ڲ���ļ�������" << endl;
	while (getline(ifs, str)) {
		//linenumΪ-1˵����һ���ļ���������Ҫ���������ļ�
		//��һ��Ϊÿһ�ݴ������Ϣ
		if (linenum == -1) {
			FileSum++;
			string studentID = str.substr(0, str.find(":"));
			string problemID = str.substr(str.find("m") + 1, 4);
			//correctORwrong---��ȷ/����
			string correctORwrong = str.substr(str.find("m") + 6, 4);
			vector<Student>::iterator it = find_if(studentVec.begin(), studentVec.end(), [studentID](Student s) ->bool {return s.studentID == studentID; });
			//δ����ѧ��
			if (it == studentVec.end()) {
				Student temp(studentID, problemID, correctORwrong);
				studentVec.push_back(temp);
			}
			//�Ѵ���ѧ��
			else {
				it->addProblem(problemID, correctORwrong);
			}

			vector<Problem>::iterator it2 = find_if(problemVec.begin(), problemVec.end(), [problemID](Problem s) ->bool {return s.problemID == problemID; });
			//δ��������
			if (it2 == problemVec.end()) {
				Problem temp2(studentID, problemID, correctORwrong);
				problemVec.push_back(temp2);
			}
			//�Ѵ�������
			else {
				it2->addStudent(studentID, correctORwrong);
			}

			it = find_if(studentVec.begin(), studentVec.end(), [studentID](Student s) ->bool {return s.studentID == studentID; });
			int num = it->sameProblemNum(problemID);
			filename = "E:\\��ѧ\\�γ�\\������������ƣ�������\\����ҵ1\\�ز�1\\" + studentID + "_" + problemID + "_" + to_string(num) + ".cpp";
			linenum = 1;
			ofs.open(filename, ios::out);
		}
		if (str == "------------------------------------------------------") {
			linenum = -1;
			//˵����ǰ�ļ�����
			ofs.close();
		}
		else {
			ofs << str << endl;
			linenum++;
		}

	}
	ifs.close();
	//�����ռ�������Ϣ������������
	//����ѧ��ID��С��С����
	sort(studentVec.begin(), studentVec.end(), [](Student a, Student b)->bool {return a.studentID < b.studentID; });
	//������ĿID��С��С����
	sort(problemVec.begin(), problemVec.end(), [](Problem a, Problem b)->bool {return a.problemID < b.problemID; });
	cout << "�ļ������ϡ�" << endl;
	system("pause");
	return;
}

void overallData() {
	system("CLS");
	cout << "��ǰ���ڷ������ļ����ǣ�" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "1.���ļ�����" << FileSum << endl;
	cout << "2.����Ŀ����" << problemVec.size() << endl;
	cout << "3.��ѧ������" << studentVec.size() << endl;
	cout << "------------------------------------" << endl;
	system("pause");
	return;
	
}

void studentData() {
	system("CLS");
	cout << "��ǰ���ڷ������ļ����ǣ�" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "�Ƿ���ʾ���β���ʵ���ͬѧID��" << endl;
	cout << "1:��         2����" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "����ʵ���ͬѧID���£�" << endl;
		for_each(studentVec.begin(), studentVec.end(), [](Student s) {cout << s.studentID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "��������Ҫ��ѯ��ͬѧ��ID��������-1�˳���ѯ��" << endl;
	cout << "------------------------------------" << endl;
	string id;
	cin >> id;
	while (id != "-1") {
		//��studentvec��Ѱ��ѧ��id��ͬ����itָ��Student����
		auto it = find_if(studentVec.begin(), studentVec.end(), [id](Student s)->bool {return s.studentID == id; });
		if (it == studentVec.end()) {
			cout << "δ�ҵ���ѧ��" << endl;
		}
		else {
			cout << "------------------------------------" << endl;
			cout << it->studentID << "ͬѧ�ܹ��ύ" << it->getProblemNum() << "�Ρ�" << endl;
			cout << "������ȷ������" << it->correctProblemID2.size() << endl;
			cout << "    ���������" << it->wrongProblemID2.size() << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "��������Ҫ��ѯ��ͬѧ��ID��������-1�˳���ѯ��" << endl;
		cout << "------------------------------------" << endl;
		cin >> id;
	}	
}

void problemData() {
	system("CLS");
	cout << "��ǰ���ڷ������ļ����ǣ�" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "�Ƿ���ʾ����������ĿID��" << endl;
	cout << "1:��         2����" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "����������ĿID���£�" << endl;
		for_each(problemVec.begin(), problemVec.end(), [](Problem p) {cout << p.problemID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "��������Ҫ��ѯ����Ŀ��ID��������-1�˳���ѯ��" << endl;
	cout << "------------------------------------" << endl;
	string id;
	cin >> id;
	//Copy1�������д�Ը����ͬѧ��ID�����ظ���
	vector<string> Copy1;	
	//Copy2�������в��뿼�Ե�ͬѧ��ID�����ظ���
	vector<string> Copy2;
	//Temp����Copy2-Copy1��ͬѧID��������δ���⣩
	vector<string> Temp;
	//ֱ������id=-1����
	while (id != "-1") {
		Copy1.clear();
		Copy2.clear();
		Temp.clear();
		////��problemvec��Ѱ��ѧ��id��ͬ����itָ��Problem����
		auto it = find_if(problemVec.begin(), problemVec.end(), [id](Problem p)->bool {return p.problemID == id; });
		if (it == problemVec.end()) {
			cout << "δ�ҵ�����Ŀ" << endl;
		}
		else {
			Copy1.resize(it->correctStudentID.size());
			//Copy1��ʼ��
			copy(it->correctStudentID.begin(), it->correctStudentID.end(), Copy1.begin());
			//����
			sort(Copy1.begin(), Copy1.end());
			//ɾ���ظ���ֵ
			Copy1.erase(unique(Copy1.begin(), Copy1.end()), Copy1.end());
			//Copy2��ʼ��
			for_each(studentVec.begin(), studentVec.end(), [&Copy2](Student s) {Copy2.push_back(s.studentID); });
			//Copy3��ʼ��
			set_symmetric_difference(begin(Copy1), end(Copy1), begin(Copy2), end(Copy2), back_inserter(Temp));
			
			cout << "------------------------------------" << endl;
			cout << "���"<<it->problemID << "�ܹ��ύ" << it->getStudentNum() << "�˴Ρ�" << endl;
			cout << "������ȷ������" << it->correctStudentID.size() << endl;
			cout << "    ���������" << it->wrongStudentID.size() << endl << endl;
			cout << "���ͬѧID��" << endl;
			if (Copy1.size() == 0)
				cout <<"    "<< "��" << endl;
			for (auto it2 = Copy1.begin(); it2 != Copy1.end(); it2++)
				cout << "    " << *it2 << endl;
			cout << "����δ�ύ��ͬѧID��" << endl;
			if (Temp.size() == 0)
				cout << "    " << "��" << endl;
			for (auto it2 = Temp.begin(); it2 != Temp.end(); it2++)
				cout << "    " << *it2 << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "��������Ҫ��ѯ����Ŀ��ID��������-1�˳���ѯ��" << endl;
		cout << "------------------------------------" << endl;
		cin >> id;
	}
}

void wrongInput() {
	cout << "����������������롣" << endl;
	system("pause");
	return;
}

void calData() {
	//�����ǰ���ļ������
	if (studentVec.size() == 0 || problemVec.size() == 0) {
		cout << "------------------------------------" << endl;
		cout << "��δ����ļ�,����ʧ��" << endl;
		cout << "------------------------------------" << endl;
		system("pause");
		return;
	}
	//������ǰ���ڲ���ļ�
	int opt;
	while (true) {
		system("CLS");
		cout << "��ǰ���ڷ������ļ����ǣ�" << FileBeingSplit << endl;
		Menu2();
		cin >> opt;
		switch (opt) {
		case 1:overallData(); break;
		case 2:studentData(); break;
		case 3:problemData(); break;
		case 4:return; break;
		default:wrongInput(); break;
		}
	}
}

int checkFile(string toBeOpenFileName1, string toBeOpenFileName2, string name1, string name2, string toBeCheckID) {
	ifstream ifs1, ifs2;
	string trash, str1, str2;
	//check=0,��ͬ��check=1 ��ȫ��ͬ
	int check = 0;
	ifs1.open(toBeOpenFileName1, ios::in);
	ifs2.open(toBeOpenFileName2, ios::in);
	//��һ��Ϊ��Ϣ�У���Ч��Ϣ
	getline(ifs1, trash);
	getline(ifs2, trash);
	while (!ifs1.eof() && !ifs2.eof()) {
		//�ڶ��п�ʼΪ��������
		getline(ifs1, str1);
		getline(ifs2, str2);
		if (str1 == str2)
			check = 1;
		else {
			check = 0;
			break;
		}
	}
	if (check == 0)
		return 0;
	else if (check == 1) {
		cout << name1 << "��" << name2 << "����Ŀ" << toBeCheckID << "��ȫ��ͬ" << endl;
		return 1;
	}
	ifs1.close();
	ifs2.close();
	return 0;
}

void checkCheat() {
	//�����ǰ���ļ������
	if (studentVec.size() == 0 || problemVec.size() == 0) {
		cout << "------------------------------------" << endl;
		cout << "��δ����ļ�,����ʧ��" << endl;
		cout << "------------------------------------" << endl;
		system("pause");
		return;
	}
	system("CLS");
	cout << "��ǰ���ڷ������ļ����ǣ�" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "�Ƿ���ʾ����������ĿID��" << endl;
	cout << "1:��         2����" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "����������ĿID���£�" << endl;
		for_each(problemVec.begin(), problemVec.end(), [](Problem p) {cout << p.problemID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "����������Ҫ�������׼�����ĿID��������-1�˳���ѯ��" << endl;
	cout << "------------------------------------" << endl;
	string toBeCheckID;
	cin >> toBeCheckID;
	while (toBeCheckID != "-1") {
		//��problemvec��Ѱ��ѧ��id��ͬ����itָ��Problem����
		////ֻҪ��һ�������ף�ifCheat=1
		int ifCheat = 0;
		auto it = find_if(problemVec.begin(), problemVec.end(), [toBeCheckID](Problem p)->bool {return p.problemID == toBeCheckID; });
		if (it == problemVec.end()) {
			cout << "δ�ҵ�����Ŀ" << endl;
		}
		else {
			string toBeOpenFileName1, toBeOpenFileName2;
			string name1, name2;
			int submitTime1,submitTime2;
			//Copy1�������д�Ը����ͬѧ��ID�����ظ���
			vector<string> Copy1;
			Copy1.resize(it->correctStudentID.size());
			//Copy1��ʼ��
			copy(it->correctStudentID.begin(), it->correctStudentID.end(), Copy1.begin());
			//����
			sort(Copy1.begin(), Copy1.end());
			//ɾ���ظ���ֵ
			Copy1.erase(unique(Copy1.begin(), Copy1.end()), Copy1.end());
			cout << "------------------------------------" << endl;
			cout << "���ڽ������׶Աȷ���������" << endl;
			for (auto check1 = Copy1.begin(); check1 != Copy1.end() - 1; check1++) {
				auto check2 = check1 + 1;
				while (check2 != Copy1.end()) {
					name1 = *check1;
					name2 = *check2;
					//�������̡���ʦ�Ĵ���
					if (name1 == "szuzy" || name1 == "zj07" || name2 == "szuzy" || name2 == "zj07") {
						check2++;
						continue;
					}
					//��studentvec��Ѱ��ѧ��id��ͬ����itָ��Student����
					auto checkIT1 = find_if(studentVec.begin(), studentVec.end(), [name1](Student s)->bool {return s.studentID == name1; });
					submitTime1 = checkIT1->sameProblemNum(toBeCheckID);
					//��studentvec��Ѱ��ѧ��id��ͬ����itָ��Student����
					auto checkIT2 = find_if(studentVec.begin(), studentVec.end(), [name2](Student s)->bool {return s.studentID == name2; });
					submitTime2 = checkIT2->sameProblemNum(toBeCheckID);
					toBeOpenFileName1 = "E:\\��ѧ\\�γ�\\������������ƣ�������\\����ҵ1\\�ز�1\\" + name1 + "_" + toBeCheckID + "_" + to_string(submitTime1) + ".cpp";
					toBeOpenFileName2 = "E:\\��ѧ\\�γ�\\������������ƣ�������\\����ҵ1\\�ز�1\\" + name2 + "_" + toBeCheckID + "_" + to_string(submitTime2) + ".cpp";
					int temp = checkFile(toBeOpenFileName1, toBeOpenFileName2, name1, name2, toBeCheckID);
					//ֻҪ��һ�������ף�ifCheat=1
					if (temp == 1)
						ifCheat = 1;
					//�Ա���һλ
					check2++;
				}
			}
			if (ifCheat != 1)
				cout << "����û�������ס�" << endl;
			cout << "���׶Աȷ������" << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "��������Ҫ��ѯ����Ŀ��ID��������-1�˳���ѯ��" << endl;
		cout << "------------------------------------" << endl;
		cin >> toBeCheckID;
	}
}

void exitProgram() {
	cout << "��лʹ�ã�" << endl;
	exit(-1);
}

int main() {
 	while (true) {
		system("CLS");
		Menu1();
		int opt;
		cin >> opt;
		switch (opt) {
		case 1:SplitFiles(); break;
		case 2:calData(); break;
		case 3:checkCheat(); break;
		case 4:exitProgram(); break;
		default: wrongInput(); break;
		}
	}
}
