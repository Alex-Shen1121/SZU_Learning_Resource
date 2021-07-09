#include<iostream>
using namespace std;
class Student {
private:
	int id;	//ѧ��
	int score; //�ɼ�
	static int  maxscore;	//��߷���
	static int maxid;		//��߷���ѧ��ѧ��
public:
	Student(int ti = 0, int ts = 0):id(ti), score(ts){}
	static void findMax(Student& st); //Ѱ����߳ɼ���ѧ��
	static int getMaxScore(); //������߳ɼ�
	static int getMaxID();		//������߳ɼ���ѧ��
};

int Student::maxscore = 0;
int Student::maxid = 0;

int main() {
	int n;
	cin >> n;	
	for (int i = 0; i < n; i++) {
		int id, score;
		cin >> id >> score;
		Student S(id, score);
		S.findMax(S);
	}
	cout << Student::getMaxID() << "--" << Student::getMaxScore() << endl;
 	return 0;
}

void Student::findMax(Student& st)
{
	if (st.score > maxscore) {
		maxscore = st.score;
		maxid = st.id;
	}
}

int Student::getMaxScore()
{
	return maxscore;
}

int Student::getMaxID()
{
	return maxid;
}

