#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Problem2 {
	string problemID;
	//记录是第几份提交的代码
	int submitNum;
	void operator=(Problem2& p2) {
		problemID = p2.problemID;
		submitNum = p2.submitNum;
	}
};

class Student {
public:
	//同学学号
	string studentID;
	//该同学正确题号集合（含多次提交）
	vector<string> correctProblemID;
	//该同学错误题号集合（含多次提交）
	vector<string> wrongProblemID;
	vector<Problem2> correctProblemID2;
	vector<Problem2> wrongProblemID2;
	int problemNum;
	//根据信息行，将同学每题信息填入
	Student(string studentID, string problemID, string correctORwrong) {
		this->studentID = studentID;
		Problem2 temp{ problemID,getProblemNum() + 1 };
		if (correctORwrong == "正确")
			correctProblemID2.push_back(temp);
		else
			wrongProblemID2.push_back(temp);
		if (correctORwrong == "正确")
			correctProblemID.push_back(studentID);
		else
			wrongProblemID.push_back(studentID);
	}
	//添加学生回答信息
	void addProblem(string problemID, string correctORwrong) {
		Problem2 temp{ problemID,getProblemNum() };
		if (correctORwrong == "正确")
			correctProblemID2.push_back(temp);
		else
			wrongProblemID2.push_back(temp);
	}
	//返回该学生总答题数
	int getProblemNum() {
		return correctProblemID2.size() + wrongProblemID2.size();
	}
	//返回某一题号提交过几次
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
	//该题目答对同学ID集合（含多次提交）
	vector<string> correctStudentID;
	//该题目答错同学ID集合（含多次提交）
	vector<string> wrongStudentID;
	//根据信息行，将题目对应信息填入
	Problem(string studentID, string problemID, string correctORwrong) {
		this->problemID = problemID;
		if (correctORwrong == "正确")
			correctStudentID.push_back(studentID);
		else
			wrongStudentID.push_back(studentID);
	}
	//添加该题对应的学生信息
	void addStudent(string studentID, string correctORwrong) {
		if (correctORwrong == "正确")
			correctStudentID.push_back(studentID);
		else
			wrongStudentID.push_back(studentID);
	}
	//返回回答该题的学生人数
	int getStudentNum() {
		return correctStudentID.size() + wrongStudentID.size();
	}

};

//储存所有同学的信息
vector<Student> studentVec;
//储存所有题目的信息
vector<Problem> problemVec;
//正在拆分文件的文件名
string FileBeingSplit;
//总文件数量
int FileSum = 0;

void Menu1() {
	cout << "------------------------------------" << endl;
	cout << "1.拆分文件                          " << endl;
	cout << "2.统计数据                          " << endl;
	cout << "3.作弊检查                          " << endl;
	cout << "4.退出程序                          " << endl;
	cout << "请输入1/2/3/4，选择功能             " << endl;
	cout << "------------------------------------" << endl;
}

void Menu2() {
	cout << "------------------------------------" << endl;
	cout << "1.整体统计结果                      " << endl;
	cout << "2.学生信息查询                      " << endl;
	cout << "3.题目信息查询                      " << endl;
	cout << "4.返回上级页面                      " << endl;
	cout << "请输入1/2/3/4，选择功能             " << endl;
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
	cout << "请输入你需要拆分并分析的文件名：    " << endl;
	cout << "注：1.文件名举例：logs-1005.txt     " << endl;
	cout << "    2.确保待拆分文件在同一文件夹下  " << endl;
	cout << "    3.测试时对于文件夹目录的选择，请修改原码（因为不会写）" << endl;
	cout << "    4.txt文件编码格式为ANSI（防止出现乱码）" << endl;
	cout << "------------------------------------" << endl;
	cin >> openFileName;
	FileBeingSplit = openFileName;
	int filenum = 0;
	int linenum = -1;
	//linenum标记该文件有几行 若文件结束设置为-1；
	ifs.open(openFileName, ios::in);
	//检查文件是否打开失败
	if (ifs.is_open() == 0) {
		cout << "待拆分文件不存在" << endl;
		system("pause");
		return;
	}
	cout << "正在拆分文件。。。" << endl;
	while (getline(ifs, str)) {
		//linenum为-1说明上一个文件结束，需要重新命名文件
		//第一行为每一份代码的信息
		if (linenum == -1) {
			FileSum++;
			string studentID = str.substr(0, str.find(":"));
			string problemID = str.substr(str.find("m") + 1, 4);
			//correctORwrong---正确/错误
			string correctORwrong = str.substr(str.find("m") + 6, 4);
			vector<Student>::iterator it = find_if(studentVec.begin(), studentVec.end(), [studentID](Student s) ->bool {return s.studentID == studentID; });
			//未创建学生
			if (it == studentVec.end()) {
				Student temp(studentID, problemID, correctORwrong);
				studentVec.push_back(temp);
			}
			//已创建学生
			else {
				it->addProblem(problemID, correctORwrong);
			}

			vector<Problem>::iterator it2 = find_if(problemVec.begin(), problemVec.end(), [problemID](Problem s) ->bool {return s.problemID == problemID; });
			//未创建问题
			if (it2 == problemVec.end()) {
				Problem temp2(studentID, problemID, correctORwrong);
				problemVec.push_back(temp2);
			}
			//已创建问题
			else {
				it2->addStudent(studentID, correctORwrong);
			}

			it = find_if(studentVec.begin(), studentVec.end(), [studentID](Student s) ->bool {return s.studentID == studentID; });
			int num = it->sameProblemNum(problemID);
			filename = "E:\\大学\\课程\\面向对象程序设计（荣誉）\\大作业1\\素材1\\" + studentID + "_" + problemID + "_" + to_string(num) + ".cpp";
			linenum = 1;
			ofs.open(filename, ios::out);
		}
		if (str == "------------------------------------------------------") {
			linenum = -1;
			//说明当前文件结束
			ofs.close();
		}
		else {
			ofs << str << endl;
			linenum++;
		}

	}
	ifs.close();
	//整理收集到的信息，并进行排序
	//按照学生ID大小从小到大
	sort(studentVec.begin(), studentVec.end(), [](Student a, Student b)->bool {return a.studentID < b.studentID; });
	//按照题目ID大小从小到大
	sort(problemVec.begin(), problemVec.end(), [](Problem a, Problem b)->bool {return a.problemID < b.problemID; });
	cout << "文件拆分完毕。" << endl;
	system("pause");
	return;
}

void overallData() {
	system("CLS");
	cout << "当前正在分析的文件的是：" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "1.总文件数：" << FileSum << endl;
	cout << "2.总题目数：" << problemVec.size() << endl;
	cout << "3.总学生数：" << studentVec.size() << endl;
	cout << "------------------------------------" << endl;
	system("pause");
	return;
	
}

void studentData() {
	system("CLS");
	cout << "当前正在分析的文件的是：" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "是否显示本次参与实验的同学ID？" << endl;
	cout << "1:是         2：否" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "参与实验的同学ID如下：" << endl;
		for_each(studentVec.begin(), studentVec.end(), [](Student s) {cout << s.studentID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "请输入你要查询的同学的ID：（输入-1退出查询）" << endl;
	cout << "------------------------------------" << endl;
	string id;
	cin >> id;
	while (id != "-1") {
		//在studentvec中寻找学生id相同对象，it指向Student对象
		auto it = find_if(studentVec.begin(), studentVec.end(), [id](Student s)->bool {return s.studentID == id; });
		if (it == studentVec.end()) {
			cout << "未找到该学生" << endl;
		}
		else {
			cout << "------------------------------------" << endl;
			cout << it->studentID << "同学总共提交" << it->getProblemNum() << "次。" << endl;
			cout << "其中正确次数：" << it->correctProblemID2.size() << endl;
			cout << "    错误次数：" << it->wrongProblemID2.size() << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "请输入你要查询的同学的ID：（输入-1退出查询）" << endl;
		cout << "------------------------------------" << endl;
		cin >> id;
	}	
}

void problemData() {
	system("CLS");
	cout << "当前正在分析的文件的是：" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "是否显示本次所有题目ID？" << endl;
	cout << "1:是         2：否" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "本次所有题目ID如下：" << endl;
		for_each(problemVec.begin(), problemVec.end(), [](Problem p) {cout << p.problemID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "请输入你要查询的题目的ID：（输入-1退出查询）" << endl;
	cout << "------------------------------------" << endl;
	string id;
	cin >> id;
	//Copy1包含所有答对该题的同学的ID（不重复）
	vector<string> Copy1;	
	//Copy2包含所有参与考试的同学的ID（不重复）
	vector<string> Copy2;
	//Temp包含Copy2-Copy1的同学ID（即答错或未答题）
	vector<string> Temp;
	//直到输入id=-1结束
	while (id != "-1") {
		Copy1.clear();
		Copy2.clear();
		Temp.clear();
		////在problemvec中寻找学生id相同对象，it指向Problem对象
		auto it = find_if(problemVec.begin(), problemVec.end(), [id](Problem p)->bool {return p.problemID == id; });
		if (it == problemVec.end()) {
			cout << "未找到该题目" << endl;
		}
		else {
			Copy1.resize(it->correctStudentID.size());
			//Copy1初始化
			copy(it->correctStudentID.begin(), it->correctStudentID.end(), Copy1.begin());
			//排序
			sort(Copy1.begin(), Copy1.end());
			//删除重复的值
			Copy1.erase(unique(Copy1.begin(), Copy1.end()), Copy1.end());
			//Copy2初始化
			for_each(studentVec.begin(), studentVec.end(), [&Copy2](Student s) {Copy2.push_back(s.studentID); });
			//Copy3初始化
			set_symmetric_difference(begin(Copy1), end(Copy1), begin(Copy2), end(Copy2), back_inserter(Temp));
			
			cout << "------------------------------------" << endl;
			cout << "题号"<<it->problemID << "总共提交" << it->getStudentNum() << "人次。" << endl;
			cout << "其中正确次数：" << it->correctStudentID.size() << endl;
			cout << "    错误次数：" << it->wrongStudentID.size() << endl << endl;
			cout << "答对同学ID：" << endl;
			if (Copy1.size() == 0)
				cout <<"    "<< "无" << endl;
			for (auto it2 = Copy1.begin(); it2 != Copy1.end(); it2++)
				cout << "    " << *it2 << endl;
			cout << "答错或未提交答案同学ID：" << endl;
			if (Temp.size() == 0)
				cout << "    " << "无" << endl;
			for (auto it2 = Temp.begin(); it2 != Temp.end(); it2++)
				cout << "    " << *it2 << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "请输入你要查询的题目的ID：（输入-1退出查询）" << endl;
		cout << "------------------------------------" << endl;
		cin >> id;
	}
}

void wrongInput() {
	cout << "输入错误请重新输入。" << endl;
	system("pause");
	return;
}

void calData() {
	//如果当前无文件被拆分
	if (studentVec.size() == 0 || problemVec.size() == 0) {
		cout << "------------------------------------" << endl;
		cout << "尚未拆分文件,操作失败" << endl;
		cout << "------------------------------------" << endl;
		system("pause");
		return;
	}
	//分析当前正在拆分文件
	int opt;
	while (true) {
		system("CLS");
		cout << "当前正在分析的文件的是：" << FileBeingSplit << endl;
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
	//check=0,不同；check=1 完全相同
	int check = 0;
	ifs1.open(toBeOpenFileName1, ios::in);
	ifs2.open(toBeOpenFileName2, ios::in);
	//第一行为信息行，无效信息
	getline(ifs1, trash);
	getline(ifs2, trash);
	while (!ifs1.eof() && !ifs2.eof()) {
		//第二行开始为代码区域
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
		cout << name1 << "与" << name2 << "的题目" << toBeCheckID << "完全相同" << endl;
		return 1;
	}
	ifs1.close();
	ifs2.close();
	return 0;
}

void checkCheat() {
	//如果当前无文件被拆分
	if (studentVec.size() == 0 || problemVec.size() == 0) {
		cout << "------------------------------------" << endl;
		cout << "尚未拆分文件,操作失败" << endl;
		cout << "------------------------------------" << endl;
		system("pause");
		return;
	}
	system("CLS");
	cout << "当前正在分析的文件的是：" << FileBeingSplit << endl;
	cout << "------------------------------------" << endl;
	cout << "是否显示本次所有题目ID？" << endl;
	cout << "1:是         2：否" << endl;
	cout << "------------------------------------" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "------------------------------------" << endl;
		cout << "本次所有题目ID如下：" << endl;
		for_each(problemVec.begin(), problemVec.end(), [](Problem p) {cout << p.problemID << endl; });
		cout << "------------------------------------" << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "请输入你需要进行作弊检查的题目ID：（输入-1退出查询）" << endl;
	cout << "------------------------------------" << endl;
	string toBeCheckID;
	cin >> toBeCheckID;
	while (toBeCheckID != "-1") {
		//在problemvec中寻找学生id相同对象，it指向Problem对象
		////只要有一对人作弊，ifCheat=1
		int ifCheat = 0;
		auto it = find_if(problemVec.begin(), problemVec.end(), [toBeCheckID](Problem p)->bool {return p.problemID == toBeCheckID; });
		if (it == problemVec.end()) {
			cout << "未找到该题目" << endl;
		}
		else {
			string toBeOpenFileName1, toBeOpenFileName2;
			string name1, name2;
			int submitTime1,submitTime2;
			//Copy1包含所有答对该题的同学的ID（不重复）
			vector<string> Copy1;
			Copy1.resize(it->correctStudentID.size());
			//Copy1初始化
			copy(it->correctStudentID.begin(), it->correctStudentID.end(), Copy1.begin());
			//排序
			sort(Copy1.begin(), Copy1.end());
			//删除重复的值
			Copy1.erase(unique(Copy1.begin(), Copy1.end()), Copy1.end());
			cout << "------------------------------------" << endl;
			cout << "正在进行作弊对比分析。。。" << endl;
			for (auto check1 = Copy1.begin(); check1 != Copy1.end() - 1; check1++) {
				auto check2 = check1 + 1;
				while (check2 != Copy1.end()) {
					name1 = *check1;
					name2 = *check2;
					//跳过助教、老师的代码
					if (name1 == "szuzy" || name1 == "zj07" || name2 == "szuzy" || name2 == "zj07") {
						check2++;
						continue;
					}
					//在studentvec中寻找学生id相同对象，it指向Student对象
					auto checkIT1 = find_if(studentVec.begin(), studentVec.end(), [name1](Student s)->bool {return s.studentID == name1; });
					submitTime1 = checkIT1->sameProblemNum(toBeCheckID);
					//在studentvec中寻找学生id相同对象，it指向Student对象
					auto checkIT2 = find_if(studentVec.begin(), studentVec.end(), [name2](Student s)->bool {return s.studentID == name2; });
					submitTime2 = checkIT2->sameProblemNum(toBeCheckID);
					toBeOpenFileName1 = "E:\\大学\\课程\\面向对象程序设计（荣誉）\\大作业1\\素材1\\" + name1 + "_" + toBeCheckID + "_" + to_string(submitTime1) + ".cpp";
					toBeOpenFileName2 = "E:\\大学\\课程\\面向对象程序设计（荣誉）\\大作业1\\素材1\\" + name2 + "_" + toBeCheckID + "_" + to_string(submitTime2) + ".cpp";
					int temp = checkFile(toBeOpenFileName1, toBeOpenFileName2, name1, name2, toBeCheckID);
					//只要有一对人作弊，ifCheat=1
					if (temp == 1)
						ifCheat = 1;
					//对比下一位
					check2++;
				}
			}
			if (ifCheat != 1)
				cout << "此题没有人作弊。" << endl;
			cout << "作弊对比分析完成" << endl;
			cout << "------------------------------------" << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "请输入你要查询的题目的ID：（输入-1退出查询）" << endl;
		cout << "------------------------------------" << endl;
		cin >> toBeCheckID;
	}
}

void exitProgram() {
	cout << "感谢使用！" << endl;
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
