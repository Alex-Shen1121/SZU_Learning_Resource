#include "学生类.h"

//截取字符串
//例：
//origin：申请人:test_student
//则a->申请人 b->test_student
void mySubstr(string& a, string& b, string& origin) {
	if (origin.find(':') != string::npos) {
		a = origin.substr(0, origin.find(':'));
		b = origin.substr(origin.find(':') + 1, origin.size() - origin.find(':') - 1);
	}
}
	

//初始化预约信息汇总容器
//键值：第x条信息
//实值：信息标题+信息内容
void setOrderStatic(map<int, map<string, string>>& m) {
	ifstream ifs;
	ifs.open(OrderStaticFile, ios::in);
	//申请人用户名，日期，开始时间，结束时间，房间名，状态
	string applicantName, date, startTime, endTime, roomName, status;
	//第x条信息
	int num = 0;
	while (ifs >> applicantName>> roomName >> date >> startTime >> endTime >> status) {
		num++;
		string key, value;
		map<string, string> temp;
		//获取预约信息字符串
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

//更新预约信息汇总数据文件
void updateOrderFile(map<int, map<string, string>>& m) {
	ofstream ofs;
	//清空文件内容
	ofs.open(OrderStaticFile, ios::out | ios::trunc);
	for (int i = 1; i <= m.size(); i++) {
		//依次输入容器信息
		ofs << "申请人:" << m[i]["申请人"] << " " << "机房名:" << m[i]["机房名"] << " " << "日期:" << m[i]["日期"] << " " << "开始时间:" << m[i]["开始时间"] << " " << "结束时间:" << m[i]["结束时间"] << " " << "状态:" << m[i]["状态"] << endl;
	}
	ofs.close();
}

Student::Student()
{
	studentID = 0;
	Name = "";
	Password = "";
	//初始化机房信息
	string RoomName;
	int RoomNum;
	int ComputerNum;
	int StartTime;
	int EndTime;
	ifstream ifs;
	string str1, str;
	//初始化机房信息
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		RoomName = str1.substr(str1.find("南"), str1.find('\t') - str1.find("南"));
		RoomNum = stoi(str1.substr(str1.find("楼") + 2, str1.find('\t') - str1.find("楼")));
		ComputerNum = stoi(str1.substr(str1.find("量") + 4, str1.find("开") - 5 - str1.find("量")));
		StartTime = stoi(str1.substr(str1.find("间") + 4, str1.find("-") - str1.find("间") - 4));
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
	//初始化机房信息
	string RoomName;
	int RoomNum;
	int ComputerNum;
	int StartTime;
	int EndTime;
	ifstream ifs;
	string str1, str;
	//初始化机房信息
	ifs.open(ComputerRoomFile);
	while (getline(ifs, str1)) {
		RoomName = str1.substr(str1.find("南"), str1.find('\t') - str1.find("南"));
		RoomNum = stoi(str1.substr(str1.find("楼") + 2, str1.find('\t') - str1.find("楼")));
		ComputerNum = stoi(str1.substr(str1.find("量") + 4, str1.find("开") - 5 - str1.find("量")));
		StartTime = stoi(str1.substr(str1.find("间") + 4, str1.find("-") - str1.find("间") - 4));		
		EndTime = stoi(str1.substr(str1.find("-") + 1, str1.length() - str1.find("-") - 5));
		vecComputerRoom.push_back(ComputerRoom(RoomName, RoomNum, ComputerNum, StartTime, EndTime));
	}
	ifs.close();
}

//主菜单
void Student::Menu()
{
	cout << "欢迎学生" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "               学生功能界面                 " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. 申请预约                   " << endl;
	cout << "                                            " << endl;
	cout << "              2. 查看已申请预约             " << endl;
	cout << "                                            " << endl;
	cout << "              3. 查看机房使用情况           " << endl;
	cout << "                                            " << endl;
	cout << "              4. 取消预约                   " << endl;
	cout << "                                            " << endl;
	cout << "              5. 注销登录                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入你的选择:" << endl;
}

//申请预约
void Student::apply()
{
	int date, startTime, endTime, roomNum;
	string roomName;
	cout << "--------------------------------------------" << endl;
	if (vecComputerRoom.size() == 0) {
		cout << "暂无开放的机房。" << endl;
		system("pause");
		return;
	}
	cout << "有以下机房开放：" << endl;
	//显示可申请机房
	for (int i = 1; i <= vecComputerRoom.size(); i++) {
		cout<<i<<"、"<<vecComputerRoom[i-1].RoomName<<'\t'<<"电脑数量："<< vecComputerRoom[i - 1].ComputerNum << '\t' << "开放时间：" << setw(2) << setfill('0') << vecComputerRoom[i - 1].StartTime << '-' << setw(2) << setfill('0') << vecComputerRoom[i - 1].EndTime << "节课" << endl;
	}	
	//选择机房
	while (true) {
		cout << "请选择你要预约的机房号码：" << endl;
		cin >> roomNum;
		if (roomNum >= 1 && roomNum <= vecComputerRoom.size()) {
			roomName = vecComputerRoom[roomNum - 1].RoomName;
			break;
		}
		cout << "输入有误，请重新输入。" << endl;
	}
	//选择时间
	cout << "--------------------------------------------" << endl;
	cout << "机房开放时间为周一至周五。" << endl;
	cout << "1. 周一" << endl;
	cout << "2. 周二" << endl;
	cout << "3. 周三" << endl;
	cout << "4. 周四" << endl;
	cout << "5. 周五" << endl;
	while (true) {
		cout << "请输入申请预约的时间：" << endl;
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "输入有误，请重新输入。" << endl;
	}
	//选择时间2
	cout << "--------------------------------------------" << endl;
	cout << "机房开放时间为第" << vecComputerRoom[roomNum - 1].StartTime << "节课至第" << vecComputerRoom[roomNum - 1].EndTime << "节课。" << endl;
	while (true) {
		cout << "请输入申请预约的时间段：" << endl;
		cout << "开始时间（第xx节课）:";
		cin >> startTime;
		cout << "结束时间（第xx节课）:";
		cin >> endTime;
		//检测时间2是否符合
		if (startTime >= 1 && endTime <= 12 && endTime >= startTime && (startTime >= vecComputerRoom[roomNum - 1].StartTime && endTime <= vecComputerRoom[roomNum - 1].EndTime)) {
			break;
		}
		else if (startTime < 1 || endTime > 12 || endTime < startTime) {
			cout << "输入有误，请重新输入。" << endl;
			continue;
		}
		else if (!(startTime >= vecComputerRoom[roomNum - 1].StartTime && endTime <= vecComputerRoom[roomNum - 1].EndTime)) {
			cout << "不在开放时间。预约失败。" << endl;
			system("pause");
			return;
		}			
	}
	cout << "--------------------------------------------" << endl;
	cout << "预约成功！请等待审核。" << endl;
	ofstream ofs;
	//打开预约信息文件，并追加预约记录
	ofs.open(OrderStaticFile, ios::app);
	ofs << "申请人:" << this->Name << " " << "机房名:" << roomName << " " << "日期:" << date << " " << "开始时间:" << startTime << " " << "结束时间:" << endTime << " " << "状态:" << 1 << endl;
	ofs.close();
	system("pause");
	return;
}

//查看已申请预约
void Student::showMyApply()
{
	//获取所有预约信息；
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "暂无预约记录。" << endl;
		system("pause");
		return;
	}
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (this->Name == AllOrderStatic[i]["申请人"]) {
			n++;
			cout << n << "、" << "机房名:" << AllOrderStatic[i]["机房名"] << "\t" << "日期:";
			//数字转周x
			string date;
			if (AllOrderStatic[i]["日期"] == "1") {
				date = "周一";
			}
			else if (AllOrderStatic[i]["日期"] == "2") {
				date = "周二";
			}
			else if (AllOrderStatic[i]["日期"] == "3") {
				date = "周三";
			}
			else if (AllOrderStatic[i]["日期"] == "4") {
				date = "周四";
			}
			else if (AllOrderStatic[i]["日期"] == "5") {
				date = "周五";
			}
			cout << date << "\t" << "开始时间:第" << AllOrderStatic[i]["开始时间"] << "节课" << "\t" << "结束时间:第" << AllOrderStatic[i]["结束时间"] << "节课" << "\t" << "状态:";
			//1：审核中 2：审核通过 3：审核失败 4：已取消
			string status;
			if (AllOrderStatic[i]["状态"] == "1") {
				status = "审核中";
			}
			else if (AllOrderStatic[i]["状态"] == "2") {
				status = "审核通过";
			}
			else if (AllOrderStatic[i]["状态"] == "3") {
				status = "审核失败";
			}
			else if (AllOrderStatic[i]["状态"] == "4") {
				status = "已取消";
			}
			cout << status << endl;
		}		
	}
	if (n == 0) {
		cout << "暂无预约信息。" << endl;
	}
	system("pause");
	return;
}

//查看机房使用情况
void Student::showAllApply()
{
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "暂无预约记录。" << endl;
		system("pause");
		return;
	}
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		cout << i << "、" << "申请人:" << AllOrderStatic[i]["申请人"] << "\t" << "机房名:" << AllOrderStatic[i]["机房名"] << "\t" << "日期:";
		//数字转周x
		string date;
		if (AllOrderStatic[i]["日期"] == "1") {
			date = "周一";
		}
		else if (AllOrderStatic[i]["日期"] == "2") {
			date = "周二";
		}
		else if (AllOrderStatic[i]["日期"] == "3") {
			date = "周三";
		}
		else if (AllOrderStatic[i]["日期"] == "4") {
			date = "周四";
		}
		else if (AllOrderStatic[i]["日期"] == "5") {
			date = "周五";
		}
		cout << date << "\t" << "开始时间:第" << AllOrderStatic[i]["开始时间"] << "节课" << "\t" << "结束时间:第" << AllOrderStatic[i]["结束时间"] << "节课" << "\t" << "状态:";
		//1：审核中 2：审核通过 3：审核失败 4：已取消
		string status;
		if (AllOrderStatic[i]["状态"] == "1") {
			status = "审核中";
		}
		else if (AllOrderStatic[i]["状态"] == "2") {
			status = "审核通过";
		}
		else if (AllOrderStatic[i]["状态"] == "3") {
			status = "审核失败";
		}
		else if (AllOrderStatic[i]["状态"] == "4") {
			status = "已取消";
		}
		cout << status << endl;
	}
	system("pause");
	return;
}

//取消预约
void Student::cancelApply()
{
	//获取预约记录
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "暂无预约记录。" << endl;
		system("pause");
		return;
	}
	cout << "注：审核中或审核通过的预约记录可以被取消。" << endl;
	//键值：记录个人第n条/实值：总共第i条的对应关系
	map<int, int> recordNum;
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (this->Name == AllOrderStatic[i]["申请人"] && (AllOrderStatic[i]["状态"] == "1" || AllOrderStatic[i]["状态"] == "2")) {
			n++;
			recordNum.insert(make_pair(n, i));
			cout << n << "、" << "机房名:" << AllOrderStatic[i]["机房名"] << "\t" << "日期:";
			//数字转周x
			string date;
			if (AllOrderStatic[i]["日期"] == "1") {
				date = "周一";
			}
			else if (AllOrderStatic[i]["日期"] == "2") {
				date = "周二";
			}
			else if (AllOrderStatic[i]["日期"] == "3") {
				date = "周三";
			}
			else if (AllOrderStatic[i]["日期"] == "4") {
				date = "周四";
			}
			else if (AllOrderStatic[i]["日期"] == "5") {
				date = "周五";
			}
			cout << date << "\t" << "开始时间:第" << AllOrderStatic[i]["开始时间"] << "节课" << "\t" << "结束时间:第" << AllOrderStatic[i]["结束时间"] << "节课" << "\t" << "状态:";
			//1：审核中 2：审核通过 3：审核失败 4：已取消
			string status;
			if (AllOrderStatic[i]["状态"] == "1") {
				status = "审核中";
			}
			else if (AllOrderStatic[i]["状态"] == "2") {
				status = "审核通过";
			}
			cout << status << endl;
		}
	}
	if (n == 0) {
		cout << "暂无可以被取消的预约申请。" << endl;
		system("pause");
		return;
	}
	cout << "请选择你需要取消预约记录。" << endl;
	int select;
	cin >> select;
	if (select < 1 || select > n) {
		cout << "选择错误！" << endl;
		system("pause");
		return;
	}
	cout << "是否确认取消第" << select << "条预约？" << endl;
	cout << "1: 确认" << endl;
	cout << "2: 取消" << endl;
	int select2;
	cin >> select2;
	if (select2 == 1) {
		//更新状态为已取消
		AllOrderStatic[recordNum[select]]["状态"] = "4";
		//更新数据文件
		updateOrderFile(AllOrderStatic);
		cout << "取消成功！" << endl;
		system("pause");
		return;
	}
	else {
		cout << "取消失败！" << endl;
		system("pause");
		return;
	}
	return;
}
