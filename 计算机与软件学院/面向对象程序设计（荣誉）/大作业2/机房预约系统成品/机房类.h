#pragma once
#include<iostream>
using namespace std;

class ComputerRoom {
public:
	//机房名字
	string RoomName;
	//房间号
	int RoomNum;
	//机房数量
	int ComputerNum;
	//开放起始时间
	int StartTime;
	//开放结束时间
	int EndTime;
	//默认构造
	ComputerRoom() {
		RoomName = "";
		RoomNum = 0;
		ComputerNum = 0;
		StartTime = 0;
		EndTime = 0;
	}
	//有参构造
	ComputerRoom(string s, int a, int b, int c, int d) {
		RoomName = s;
		RoomNum = a;
		ComputerNum = b;
		StartTime = c;
		EndTime = d;
	}
};