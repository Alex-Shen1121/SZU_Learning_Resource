#pragma once
#include<iostream>
using namespace std;

class ComputerRoom {
public:
	//��������
	string RoomName;
	//�����
	int RoomNum;
	//��������
	int ComputerNum;
	//������ʼʱ��
	int StartTime;
	//���Ž���ʱ��
	int EndTime;
	//Ĭ�Ϲ���
	ComputerRoom() {
		RoomName = "";
		RoomNum = 0;
		ComputerNum = 0;
		StartTime = 0;
		EndTime = 0;
	}
	//�вι���
	ComputerRoom(string s, int a, int b, int c, int d) {
		RoomName = s;
		RoomNum = a;
		ComputerNum = b;
		StartTime = c;
		EndTime = d;
	}
};