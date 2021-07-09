#include <iostream>
#include<random>
#include<algorithm>
#include <cstdlib>
#include <Windows.h>
#include <random>
#include <chrono>
#include <vector>
#include<iomanip>
#include "AVLTree.h"
#include "SkipList.h"
#include "SplayTree.h"
#include "BinarySearchTree.h"
using namespace std;



void Menu1() {
	cout << "------------------------------------" << endl;
	cout << "1.二叉平衡树                        " << endl;
	cout << "2.二叉搜索树                        " << endl;
	cout << "3.二叉伸展树                        " << endl;
	cout << "4.跳表                              " << endl;
	cout << "5.数组                              " << endl;
	cout << "6.大数据性能评测                    " << endl;
	cout << "7.退出程序                          " << endl;
	cout << "请输入序号，选择要评测的数据结构 " << endl;
	cout << "------------------------------------" << endl;
}

void AVLTree_Menu() {
	system("CLS");
	int val, choice, newVal;
	AVLTree myAVLTree;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.增" << endl;
			cout << "       2.删" << endl;
			cout << "       3.改" << endl;
			cout << "       4.查" << endl;
			cout << "       5.显示" << endl;
			cout << "       6.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "请输入要插入的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			myAVLTree.Insert(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "请输入要删除的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myAVLTree.Delete(val))
				cout << "删除成功!" << endl;
			else cout << "删除失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "请输入要修改的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "请输入要改成的数字[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (myAVLTree.Updata(val, newVal))
				cout << "修改成功!" << endl;
			else cout << "修改失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "请输入要查找的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (NULL != myAVLTree.Search(val))
				cout << "查找成功!" << endl;
			else cout << "查找失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========前序==============" << endl;
			myAVLTree.PreOrderPrint();
			cout << endl << "==========中序================" << endl;
			myAVLTree.InOrderPrint();
			cout << endl << "==========后序===============" << endl;
			myAVLTree.SufOrderPrint();
			cout << endl << "*****************************" << endl;
			system("pause");
			system("CLS");
		}
		else return;
	}
}

void AVLTree_Test() {
	system("CLS");
	double num;
	double N[] = { 1,2,3,4,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7 };
	vector<double> data[3];
	for (int K = 0; K < 25; K++) {
		num = N[K];
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "数据量总数 量级1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//添加数据
		start = GetTickCount64();
		AVLTree myAVLTree;
		long long int i;
		long long int num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			myAVLTree.Insert(val);
		}
		end = GetTickCount64() - start;
		data[0].push_back((double)end / sum * 1000);
		cout << "Average Insert time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;
		
		//查找均匀分布数据
		double a = 0, b = 0;
		double sum2 = 0;
		while (n--) {
			start = GetTickCount64();
			for (long long int i = 0; i < 1e6; i++) {

				long long int key = dist(rng);
				if (myAVLTree.Search(key))
					a++;
				else
					b++;
			}
			end = GetTickCount64() - start;
			cout << "查找成功的概率:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "微秒" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
		cout << endl;

		//删除数据
		start = GetTickCount64();
		num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			if (myAVLTree.Delete(val))
				num1++;
		}
		end = GetTickCount64();
		end = end - start;
		data[2].push_back((double)end / sum * 1000);
		cout << "Average Delete time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;
	}
	//打印数据
	for (int i = 0; i < 3; i++) {
		for (auto x : data[i])
			cout << x << '\t';
		cout << endl;
	}
	system("pause");
	system("CLS");

}

void BST_Menu() {
	system("CLS");
	int val, choice, newVal;
	BinarySearchTree myBST;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.增" << endl;
			cout << "       2.删" << endl;
			cout << "       3.改" << endl;
			cout << "       4.查" << endl;
			cout << "       5.显示" << endl;
			cout << "       6.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "请输入要插入的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			myBST.InsertBSTNode(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "请输入要删除的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myBST.DeleteBSTNode(val))
				cout << "删除成功!" << endl;
			else cout << "删除失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "请输入要修改的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "请输入要改成的数字[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (myBST.UpdataBSTNode(val, newVal))
				cout << "修改成功!" << endl;
			else cout << "修改失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "请输入要查找的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myBST.SearchBSTNode(val))
				cout << "查找成功!" << endl;
			else cout << "查找失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========前序==============" << endl;
			myBST.PreOrderBSTPrint(myBST.GetRoot());
			cout << endl << "==========中序================" << endl;
			myBST.InOrderBSTPrint(myBST.GetRoot());
			cout << endl << "==========后序===============" << endl;
			myBST.SufOrderBSTPrint(myBST.GetRoot());
			cout << endl << "*****************************" << endl;
			system("pause");
			system("CLS");
		}
		else return;
	}
}

void BST_Test() {
	system("CLS");
	double num = 0;
	int opt;
	while (true) {
		cout << "-------------二叉查找树-------------" << endl;
		cout << "1. 有序数列插入\n2. 随机数列插入\n";
		cout << "请输入[     ]\b\b\b\b";
		cin >> opt;
		if (opt == 1 || opt == 2)
			break;
		else {
			cout << "请重新输入" << endl;
			system("pause");
			system("CLS");
		}
	}
	if (opt == 1) {
		double N[] = { 1,2,3,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5 };
		vector<double> data[3];
		for (int K = 0; K < 23; K++) {
			num = N[K];
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "数据量总数 量级1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//添加有序数据
			start = GetTickCount64();
			BinarySearchTree myBST;
			long long int i;
			long long int num1 = 0;
			for (i = 0; i <= sum; i++) {
				myBST.InsertBSTNode(i);
			}
			end = GetTickCount64() - start;
			data[0].push_back((double)end / sum * 1000);
			cout << "Average Insert time:" << (double)end / sum * 1000 << "微秒" << endl;
			cout << endl;


			//查找均匀分布数据
			double a = 0, b = 0;
			int n = 5;
			double sum2 = 0;
			while (n--) {
				start = GetTickCount64();
				for (long long int i = 0; i < 1e5; i++) {
					long long int key = dist(rng);
					if (myBST.SearchBSTNode(key))
						a++;
					else
						b++;
				}
				end = GetTickCount64() - start;
				cout << "查找成功的概率:" << a / (a + b) << '\t';
				cout << "Average Search time:" << (double)end / 1e5 * 1000 << "微秒" << endl;
				sum2 += (double)end / 1e5 * 1000;
			}
			data[1].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
			cout << endl;

			//删除数据
			start = GetTickCount64();
			num1 = 0;
			for (i = 0; i < sum; i++) {
				long long int val = dist(rng);
				if (myBST.DeleteBSTNode(val))
					num1++;
			}
			end = GetTickCount64();
			end = end - start;
			data[2].push_back((double)end / sum * 1000);
			cout << "Average Delete time:" << (double)end / sum * 1000 << "微秒" << endl;
			cout << endl;
		}

		//打印数据
		for (int i = 0; i < 3; i++) {
			for (auto x : data[i])
				cout << x << '\t';
			cout << endl;
		}
	}
	else if (opt == 2) {
		double N[] = { 1,2,3,4,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7 };
		vector<double> data[4];
		for (int K = 0; K < 25; K++) {
			num = N[K];
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "数据量总数 量级1*10^" << num << endl;
			int n = 5;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//添加无序数据
			start = GetTickCount64();
			BinarySearchTree myBST;
			long long int i;
			long long int num1 = 0;
			for (i = 0; i < sum; i++) {
				long long int val = dist(rng);
				myBST.InsertBSTNode(val);
			}
			end = GetTickCount64() - start;
			data[0].push_back((double)end / sum * 1000);
			cout << "Average Insert time:" << (double)end / sum * 1000 << "微秒" << endl;
			cout << endl;
			
			//查询数据
			double a = 0, b = 0; 
			double sum2 = 0;
			while (n--) {
				start = GetTickCount64();
				for (long long int i = 0; i < 1e6; i++) {

					long long int key = dist(rng);
					if (myBST.SearchBSTNode(key))
						a++;
					else
						b++;
				}
				end = GetTickCount64() - start;
				cout << "查找成功的概率:" << a / (a + b) << '\t';
				cout << "Average Search time:" << (double)end / 1e6 * 1000 << "微秒" << endl;
				sum2 += (double)end / 1e6 * 1000;
			}
			data[1].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
			cout << endl;

			//删除数据
			start = GetTickCount64();
			num1 = 0;
			for (i = 0; i < sum; i++) {
				long long int val = dist(rng);
				if (myBST.DeleteBSTNode(val))
					num1++;
			}
			end = GetTickCount64();
			end = end - start;
			data[2].push_back((double)end / sum * 1000);
			cout << "Average Delete time:" << (double)end / sum * 1000 << "微秒" << endl;
			cout << endl;
		}

		//打印数据
		for (int i = 0; i < 3; i++) {
			for (auto x : data[i])
				cout << x << '\t';
			cout << endl;
		}
	}
	system("pause");
	system("CLS");
}

void SkipList_Menu() {
	system("CLS");
	int val, choice, newVal;
	skiplist myList;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.增" << endl;
			cout << "       2.删" << endl;
			cout << "       3.查" << endl;
			cout << "       4.显示" << endl;
			cout << "       5.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
		if (1 == choice)
		{
			cout << "请输入要插入的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			myList.insert(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "请输入要删除的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			myList.delete_val(val);
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "请输入要查找的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			long long int countRet = 0;
			if (myList.search(val))
				cout << val << "查找成功!" << endl;
			else cout << val << "查找失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			for (int i = 0; i < 30; i++)
				myList.insert(i);
			myList.print();
			system("pause");
			system("CLS");
		}
		else return;
	}
}

void SkipList_Test() {
	system("CLS");
	double num;
	double N[] = { 1,2,3,4,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2,6.3,6.4,6.5 };
	vector<double> data[3];
	for (int K = 0; K < 20; K++) {
		num = N[K];
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "数据量总数 量级1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//添加数据
		start = GetTickCount64();
		skiplist myList;
		long long int i;
		long long int num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			myList.insert(val);
		}
		end = GetTickCount64() - start;
		data[0].push_back((double)end / sum * 1000);
		cout << "Average Insert time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;

		//查找数据
		n = 5;
		double sum1 = 0, sum2 = 0;
		while (n--) {
			start = GetTickCount64();
			double a = 0, b = 0;
			long long int countSum = 0;
			for (long long int i = 0; i < 1e5; i++) {
				long long int key = dist(rng);
				if (myList.search(key))
					a++;
				else
					b++;
			}
			end = GetTickCount64() - start;
			cout << "查找成功的概率:" << a / (a + b) << '\t';
			sum2 += (double)end / 1e5 * 1000;
			cout << "Average Search time:" << (double)end / 1e5 * 1000 << "微秒" << endl;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
		cout << endl;

		//删除数据
		start = GetTickCount64();
		num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			myList.delete_val(val);
		}
		end = GetTickCount64();
		end = end - start;
		data[2].push_back((double)end / sum * 1000);
		cout << "Average Delete time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;
	}
	
	//打印数据
	for (int i = 0; i < 3; i++) {
		for (auto x : data[i])
			cout << x << '\t';
		cout << endl;
	}
	system("pause");
	system("CLS");
}

void SplayTree_Menu() {
	system("CLS");
	int val, choice, newVal;
	SplayTree mySplayTree;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.增" << endl;
			cout << "       2.删" << endl;
			cout << "       3.改" << endl;
			cout << "       4.查" << endl;
			cout << "       5.显示" << endl;
			cout << "       6.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "请输入要插入的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			mySplayTree.InsertSplayTree(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "请输入要删除的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (mySplayTree.DeleteSplayTree(val))
				cout << "删除成功!" << endl;
			else cout << "删除失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "请输入要修改的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "请输入要改成的数字[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (mySplayTree.UpdataSplayTree(val, newVal))
				cout << "修改成功!" << endl;
			else cout << "修改失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "请输入要查找的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			if (NULL != mySplayTree.FindSplayTree(val))
				cout << "查找成功!" << endl;
			else cout << "查找失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========前序==============" << endl;
			mySplayTree.PreOrderSTPrint();
			cout << endl << "==========中序================" << endl;
			mySplayTree.InOrderSTPrint();
			cout << endl << "==========后序===============" << endl;
			mySplayTree.SufOrderSTPrint();
			cout << endl << "*****************************" << endl;
			system("pause");
			system("CLS");
		}
		else return;
	}
}

void SplayTree_Test() {
	system("CLS");
	double num;

	double N[] = { 1,2,3,4,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7 };
	vector<double> data[4];
	for (int K = 0; K < 25; K++) {
		num = N[K];
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "数据量总数 量级1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//添加数据
		start = GetTickCount64();
		SplayTree mySplayTree;
		long long int i;
		long long int num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			mySplayTree.InsertSplayTree(val);
		}
		end = GetTickCount64() - start;
		data[0].push_back((double)end / sum * 1000);
		cout << "Average Insert time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;

		//查找均匀分布数据
		double a = 0, b = 0;
		double sum2 = 0;
		while (n--) {
			start = GetTickCount64();
			for (long long int i = 0; i < 1e6; i++) {

				long long int key = dist(rng);
				if (mySplayTree.FindSplayTree(key))
					a++;
				else
					b++;
			}
			end = GetTickCount64() - start;
			cout << "查找成功的概率:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "微秒" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
		cout << endl;

		//查找正态分布数据
		n = 5, sum2 = 0;
		while (n--) {
			start = GetTickCount64();
			a = 0, b = 0;
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::default_random_engine gen(seed);
			long long int EX = sum / 2, DX = 0;
			if (sum <= 1e4)
				DX = sum / 5;
			else
				DX = sum / 100;
			std::normal_distribution<long double> dis(EX, DX);
			for (long long int i = 0; i < 1e6; i++) {

				long long int key = dis(gen);
				if (mySplayTree.FindSplayTree(key))
					a++;
				else
					b++;
			}
			end = GetTickCount64() - start;
			cout << "查找成功的概率:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "微秒" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[2].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
		cout << endl;

		//删除数据
		start = GetTickCount64();
		num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			if (mySplayTree.DeleteSplayTree(val))
				num1++;
		}
		end = GetTickCount64() - start;
		data[3].push_back((double)end / sum * 1000);
		cout << "Average Delete time:" << (double)end / sum * 1000 << "微秒" << endl;
		cout << endl;
	}

	//打印数据
	for (int i = 0; i < 4; i++) {
		for (auto x : data[i])
			cout << x << '\t';
		cout << endl;
	}

	system("pause");
	system("CLS");
}

void Vec_Menu() {
	system("CLS");
	int val, choice, newVal;
	vector<int> data;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.增" << endl;
			cout << "       2.删" << endl;
			cout << "       3.改" << endl;
			cout << "       4.查" << endl;
			cout << "       5.显示" << endl;
			cout << "       6.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "请输入要插入的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if (it == data.end()) {
				data.push_back(val);
				cout << "插入成功" << endl;
			}				
			else
				cout << "插入失败" << endl;
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "请输入要删除的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if ( it != data.end()) {
				data.erase(it);
				cout << "删除成功!" << endl;
			}
				
			else cout << "删除失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "请输入要修改的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "请输入要改成的数字[        ]\b\b\b\b\b\b";
			cin >> newVal;
			auto it = find(data.begin(), data.end(), val);
			if (it != data.end()) {
				cout << "修改成功!" << endl;
				*it = newVal;
			}				
			else cout << "修改失败，不存在数字!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "请输入要查找的数字[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if (it != data.end())
				cout << "查找成功!" << endl;
			else cout << "查找失败!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			for (auto x : data)
				cout << x << ' ';
			cout << endl << "*****************************" << endl;
			system("pause");
			system("CLS");
		}
		else return;
	}
}

void Vec_Test() {
	system("CLS");
	double num = 0;
	int opt;
	while (true) {
		cout << "-------------二叉查找树-------------" << endl;
		cout << "1. 顺序查找\n2. 二分查找\n";
		cout << "请输入[     ]\b\b\b\b";
		cin >> opt;
		if (opt == 1 || opt == 2)
			break;
		else {
			cout << "请重新输入" << endl;
			system("pause");
			system("CLS");
		}
	}
	//顺序查找
	if (opt == 1) {
		double N[] = { 1,2,3,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5 };
		vector<double> data[1];
		vector<int> datavec;
		for (int K = 0; K < 23; K++) {
			datavec.clear();
			num = N[K];
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "数据量总数 量级1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//添加数据
			start = GetTickCount64();
			long long int i;
			long long int num1 = 0;
			for (i = 0; i <= sum; i++) {
				long long int val = dist(rng);
				auto it = find(datavec.begin(), datavec.end(), val);
				if (it == datavec.end()) {
					datavec.push_back(val);
				}
			}
			end = GetTickCount64() - start;
			cout << endl;

			//查找
			double a = 0, b = 0;
			int n = 5;
			double sum2 = 0;
			while (n--) {
				a = 0;
				start = GetTickCount64();
				for (long long int i = 0; i < 1e5; i++) {
					long long int key = dist(rng);
					for (auto x : datavec) {
						if (x == key) {
							a++;
							break;
						}
					}
				}
				end = GetTickCount64() - start;
				cout << "查找成功的概率:" << a / 1e5 << '\t';
				cout << "Average Search time:" << (double)end / 1e5 * 1000 << "微秒" << endl;
				sum2 += (double)end / 1e5 * 1000;
			}
			data[0].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
			cout << endl;
		}

		//打印数据
		for (int i = 0; i < 1; i++) {
			for (auto x : data[i])
				cout << x << '\t';
			cout << endl;
		}
	}
	else if (opt == 2) {
		double N[] = { 1,2,3,4,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7 };
		vector<double> data[4];
		vector<int> datavec;
		for (int K = 0; K < 25; K++) {
			datavec.clear();
			num = N[K];
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "数据量总数 量级1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//添加数据
			start = GetTickCount64();
			long long int i;
			long long int num1 = 0;
			for (i = 0; i <= sum; i++) {
				datavec.push_back(i);
			}
			end = GetTickCount64() - start;cout << endl;

			//二分查找数据
			double a = 0, b = 0;
			int n = 5;
			double sum2 = 0;
			while (n--) {
				a = 0;
				start = GetTickCount64();
				for (long long int i = 0; i < 1e6; i++) {
					long long int key = dist(rng);
					int low, high, mid;
					low = 0;
					high = datavec.size();
					while (low <= high)
					{
						mid = (low + high) / 2;
						if (datavec[mid] == key)
							break;
						if (datavec[mid] > key)
							high = mid - 1;
						if (datavec[mid] < key)
							low = mid + 1;
					}
				}

				end = GetTickCount64() - start;
				cout << "Average Search time:" << (double)end / 1e6 * 1000 << "微秒" << endl;
				sum2 += (double)end / 1e6 * 1000;
			}
			data[0].push_back(sum2 / 5);
			cout << endl;
			cout << "Average Search time:" << sum2 / 5 << "微秒" << endl;
			cout << endl;
		}
		
		//打印数据
		for (int i = 0; i < 3; i++) {
			for (auto x : data[i])
				cout << x << '\t';
			cout << endl;
		}
	}
	system("pause");
	system("CLS");
}

void Test() {
	system("CLS");
	int choice;
	while (true)
	{
		do
		{
			cout << "-----------------------------------" << endl;
			cout << "       1.二叉平衡树" << endl;
			cout << "       2.二叉查找树" << endl;
			cout << "       3.二叉伸展树" << endl;
			cout << "       4.跳表" << endl;
			cout << "       5.数组" << endl;
			cout << "       6.返回" << endl;
			cout << "请输入你的选项[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			AVLTree_Test();
		}
		else if (2 == choice)
		{
			BST_Test();
		}
		else if (3 == choice)
		{
			SplayTree_Test();
		}
		else if (4 == choice)
		{
			SkipList_Test();
		}
		else if (5 == choice)
		{
			Vec_Test();
		}
		else return;
	}
}

void exitProgram() {
	cout << "感谢使用！" << endl;
	exit(-1);
}

void wrongInput() {
	cout << "输入错误请重新输入。" << endl;
	system("pause");
	return;
}

int main() {
	
	while (true) {
		system("CLS");
		Menu1();
		int opt;
		cin >> opt;
		switch (opt) {
		case 1:AVLTree_Menu(); break;
		case 2:BST_Menu(); break;
		case 3:SplayTree_Menu(); break;
		case 4:SkipList_Menu(); break;
		case 5:Vec_Menu(); break;
		case 6:Test(); break;
		case 7:exitProgram(); break;
		default: wrongInput(); break;
		}
	}
	system("pause");
	return 0;
}
