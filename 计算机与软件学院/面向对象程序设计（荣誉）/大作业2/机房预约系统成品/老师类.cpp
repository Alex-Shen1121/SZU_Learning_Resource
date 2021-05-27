#include "老师类.h"

//截取字符串
//例：
//origin：申请人:test_student
//则a->申请人 b->test_student
void mySubstr1(string& a, string& b, string& origin) {
	if (origin.find(':') != string::npos) {
		a = origin.substr(0, origin.find(':'));
		b = origin.substr(origin.find(':') + 1, origin.size() - origin.find(':') - 1);
	}
}

//初始化预约信息汇总容器
//键值：第x条信息
//实值：信息标题+信息内容
void setOrderStatic1(map<int, map<string, string>>& m) {
	ifstream ifs;
	ifs.open(OrderStaticFile, ios::in);
	//申请人用户名，日期，开始时间，结束时间，房间名，状态
	string applicantName, date, startTime, endTime, roomName, status;
	//第x条信息
	int num = 0;
	while (ifs >> applicantName >> roomName >> date >> startTime >> endTime >> status) {
		num++;
		string key, value;
		map<string, string> temp;
		//获取预约信息字符串
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

//更新数据文件
void updateOrderFile1(map<int, map<string, string>>& m) {
	ofstream ofs;
	//清空文件内容
	ofs.open(OrderStaticFile, ios::out | ios::trunc);
	for (int i = 1; i <= m.size(); i++) {
		//依次输入容器信息
		ofs << "申请人:" << m[i]["申请人"] << " " << "机房名:" << m[i]["机房名"] << " " << "日期:" << m[i]["日期"] << " " << "开始时间:" << m[i]["开始时间"] << " " << "结束时间:" << m[i]["结束时间"] << " " << "状态:" << m[i]["状态"] << endl;
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

//主菜单
void Teacher::Menu()
{
	cout << "欢迎老师" << this->Name << "!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "              老师功能界面                  " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << endl;
	cout << "              1. 查看机房使用情况           " << endl;
	cout << "                                            " << endl;
	cout << "              2. 审核预约                   " << endl;
	cout << "                                            " << endl;
	cout << "              3. 注销登录                   " << endl;
	cout << "                                            " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入你的选择:" << endl;
}

//查看机房使用情况
void Teacher::showAllApply()
{
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic1(AllOrderStatic);
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

//审核预约
void Teacher::checkApply()
{
	//键值：信息标题
	//实值：信息内容
	map<int, map<string, string>> AllOrderStatic;
	setOrderStatic1(AllOrderStatic);
	if (AllOrderStatic.size() == 0) {
		cout << "暂无预约记录。" << endl;
		system("pause");
		return;
	}
	cout << "注：审核中的预约申请可以被操作。" << endl;	
	//键值：记录个人第n条/实值：总共第i条的对应关系
	map<int, int> recordNum;
	int n = 0;
	for (int i = 1; i <= AllOrderStatic.size(); i++) {
		if (AllOrderStatic[i]["状态"] == "1") {
			n++;
			recordNum.insert(make_pair(n, i));
			cout << n << "、" << "申请人:" << AllOrderStatic[i]["申请人"] << " " << "机房名:" << AllOrderStatic[i]["机房名"] << "\t" << "日期:";
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
			cout << status << endl;
		}
	}
	//总数为零
	if (n == 0) {
		cout << "暂无需要审核的预约申请。" << endl;
		system("pause");
		return;
	}
	cout << "请选择你需要审核的预约申请。" << endl;
	int select;
	cin >> select;
	if (select < 1 || select > n) {
		cout << "选择错误！" << endl;
		system("pause");
		return;
	}
	cout << "请输入第" << select << "条预约记录的审核结果。" << endl;
	cout << "1: 通过" << endl;
	cout << "2: 不通过" << endl;
	int select2;
	cin >> select2;
	if (select2 == 1) {
		//更新状态为审核通过
		AllOrderStatic[recordNum[select]]["状态"] = "2";
		//更新数据文件
		updateOrderFile1(AllOrderStatic);
		cout << "审核通过！" << endl;
		system("pause");
		return;
	}
	else if (select2 == 2) {
		//更新状态为审核失败
		AllOrderStatic[recordNum[select]]["状态"] = "3";
		//更新数据文件
		updateOrderFile1(AllOrderStatic);
		cout << "审核不通过！" << endl;
		system("pause");
		return;
	}
	return;
}
