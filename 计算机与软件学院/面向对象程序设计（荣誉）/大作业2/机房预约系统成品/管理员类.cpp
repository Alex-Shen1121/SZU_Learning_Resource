#include "管理员类.h"

//初始化已注册学生老师所有信息容器
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
	//打开学生信息文件
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(Student(id, name, password));	
	ifs.close();
	//打开老师信息文件
	fileName = TeacherFile;
	ifs1.open(fileName);
	while (ifs1 >> id >> name >> password)
		v2.push_back(Teacher(id, name, password));
	return;
}

//初始化学号/职工号容器内容
void setVecIdData(vector<int>& v1, vector<int>& v2) {
	v1.clear();
	v2.clear();
	string fileName;
	int id;
	string name;
	string password;
	ifstream ifs;
	//打开学生信息文件
	fileName = StudentFile;
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(id);
	ifs.close();
	ifstream ifs2;
	fileName = TeacherFile;
	//打开老师信息文件
	ifs2.open(fileName);
	while (ifs2 >> id >> name >> password)
		v2.push_back(id);
	ifs2.close();
	return;
}

//初始化已注册学生老师用户名容器
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
	//打开学生信息文件
	ifs.open(fileName);
	while (ifs >> id >> name >> password)
		v1.push_back(name);
	ifs.close();
	fileName = TeacherFile;
	//打开老师信息文件
	ifs2.open(fileName);
	while (ifs2 >> id >> name >> password)
		v2.push_back(name);
	ifs2.close();
	return;
}

//初始化已开放机房房间号容器
void setVecRoomNum(vector<int>& v1) {
	ifstream ifs;
	string str1, str;
	//打开机房信息文件
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		//截取房间号信息
		str = str1.substr(str1.find("楼") + 2, str1.find('\t') - str1.find("楼"));
		v1.push_back(stoi(str));
	}
	return;
}

//检查重复，重复返回true，无重复返回false
//检查ID是否重复
bool checkRepeat(int newID, vector<int>& v1) {
	if (find(begin(v1), end(v1), newID) != end(v1))
		return true;
	else
		return false;
}

//重载 检查用户名重复
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

//菜单界面
void Admin::Menu()
{
	cout << "欢迎管理员" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "             管理员功能界面                 " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. 注册账号                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. 查看账号                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. 查看机房信息               " << endl;
	cout << "                                            " << endl;
	cout << "              4. 清空预约                   " << endl;
	cout << "                                            " << endl;
	cout << "              5. 新增机房                   " << endl;
	cout << "                                            " << endl;
	cout << "              6. 注销登录                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入你的选择:" << endl;
}

//添加账号
void Admin::Register()
{
	//已注册学号/职工号容器，用于检测是否有重复注册
	vector<int> ExistedStudentID;
	vector<int> ExistedTeacherID;
	vector<string> ExistedStudentName;
	vector<string> ExistedTeacherName;
	//初始化容器内容
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
		cout << "请输入注册账号类型:" << endl;
		cout << "1: 学生账号" << endl;
		cout << "2: 老师账号" << endl;
		cin >> opt;
		//注册学生账号
		if (opt == 1) {
			fileName = StudentFile;
			cout << "请输入学号:" << endl;
			cin >> id;
			//检查ID是否重复注册
			if (checkRepeat(id, ExistedStudentID)) {
				cout << "该学号已经存在。" << endl << "注册失败" << endl;
				system("pause");
				return;
			}
			break;
		}
		else if (opt == 2) {
			fileName = TeacherFile;
			cout << "请输入职工号:" << endl;
			cin >> id;
			//检查ID是否重复注册
			if (checkRepeat(id, ExistedTeacherID)) {
				cout << "该职工号已经存在。" << endl << "注册失败" << endl;
				system("pause");
				return;
			}
			break;
		}
		else {
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			this->Menu();
		}
	}
	//打开对应文件
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "文件不存在" << endl;
		ofs.close();
		system("pause");
		return;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	//检查用户名是否重复
	if (opt == 1) {
		if (checkRepeat(name, ExistedStudentName)) {
			cout << "该用户名已经存在。" << endl << "注册失败" << endl;
			system("pause");
			return;
		}
	}
	else if (opt == 2) {
		if (checkRepeat(name, ExistedTeacherName)) {
			cout << "该用户名已经存在。" << endl << "注册失败" << endl;
			system("pause");
			return;
		}
	}
	cout << "请输入密码:" << endl;
	cin >> password;
	//添加信息
	ofs << id << " " << name << " " << password << endl;
	cout << "账号注册成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	return;
}

//查看账号
void Admin::showAccount()
{
	//已注册学生老师所有信息容器，用于遍历
	vector<Student> ExistedStudentInfo;
	vector<Teacher> ExistedTeacherInfo;
	//初始化容器内容
	setVecAllData(ExistedStudentInfo, ExistedTeacherInfo);
	string name, password;
	int opt;
	while (true) {
		cout << "请输入需要查看的账号类型:" << endl;
		cout << "1: 学生账号" << endl;
		cout << "2: 老师账号" << endl;
		cin >> opt;
		//注册学生账号
		if (opt == 1) {
			cout << "学生帐号信息如下:" << endl;
			//打印学生信息
			for_each(begin(ExistedStudentInfo), end(ExistedStudentInfo), [](Student& s) {
				cout << "学号: " << setiosflags(ios::left) << setw(15) << s.studentID << "用户名: " << setw(15) << s.Name << "密码: " << setw(15) << s.Password << endl;
				});
			break;
		}
		else if (opt == 2) {
			cout << "老师账号信息如下:" << endl;
			//打印老师信息
			for_each(begin(ExistedTeacherInfo), end(ExistedTeacherInfo), [](Teacher& t) {
				cout << "职工号: " << setiosflags(ios::left) << setw(15) << t.teacherID << "用户名: " << setw(15) << t.Name << "密码: " << setw(15) << t.Password << endl;
				});
			break;
		}
		else {
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			this->Menu();
		}
	}
	system("pause");
	return;
}

//查看机房
void Admin::showInfo()
{
	ifstream ifs;
	string str;
	//打开机房信息文件
	ifs.open(ComputerRoomFile);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		system("pause");
		return;
	}
	cout << "机房信息如下:" << endl;
	//打印机房信息
	while (getline(ifs, str))
		cout << str << endl;
	system("pause");
	return;
}

//清空预约
void Admin::clear()
{
	cout << "是否确认清空预约信息？" << endl;
	cout << "1: 确认" << endl;
	cout << "2: 返回" << endl;
	int opt;
	cin >> opt;
	if (opt == 1) {
		//覆盖原文件（清空）
		ofstream ofs(OrderStaticFile, ios::trunc);
		ofs.close();
		cout << "清空成功！" << endl;
	}
	system("pause");
	return;
}

//新增机房
void Admin::addComputerRoom()
{
	vector<int> RoomNumVec;
	setVecRoomNum(RoomNumVec);
	int RoomNum, ComputerNum, startTime, endTime;
	cout << "请输入机房房间号:" << endl;
	cin >> RoomNum;
	//检查房间号是否重复
	if (checkRepeat(RoomNum, RoomNumVec)) {
		cout << "已经存在该机房信息。添加失败" << endl;
		system("pause");
		return;
	}
	cout << "请输入电脑数量:" << endl;
	cin >> ComputerNum;
	cout << "请输入开放时间:" << endl;
	cout << "开始时间（第xx节课）:";
	cin >> startTime;
	cout << "结束时间（第xx节课）:";
	cin >> endTime;
	if (startTime < 1 || endTime>12 || endTime < startTime) {
		cout << "时间输入错误。添加失败" << endl;
		system("pause");
		return;
	}
	ofstream ofs;
	//打开新房信息文件
	ofs.open(ComputerRoomFile, ios::out | ios::app);
	//接在后面添加信息
	ofs << "机房名称：南区计算机大楼" << RoomNum << '\t' << "电脑数量：" << ComputerNum << '\t' << "开放时间：" << setw(2) << setfill('0') << startTime << '-' << setw(2) << setfill('0') << endTime << "节课" << endl;
	cout << "添加成功！" << endl;
	system("pause");
	return;
}
