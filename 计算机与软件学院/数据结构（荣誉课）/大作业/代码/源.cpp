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
	cout << "1.����ƽ����                        " << endl;
	cout << "2.����������                        " << endl;
	cout << "3.������չ��                        " << endl;
	cout << "4.����                              " << endl;
	cout << "5.����                              " << endl;
	cout << "6.��������������                    " << endl;
	cout << "7.�˳�����                          " << endl;
	cout << "��������ţ�ѡ��Ҫ��������ݽṹ " << endl;
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
			cout << "       1.��" << endl;
			cout << "       2.ɾ" << endl;
			cout << "       3.��" << endl;
			cout << "       4.��" << endl;
			cout << "       5.��ʾ" << endl;
			cout << "       6.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "������Ҫ���������[        ]\b\b\b\b\b\b";
			cin >> val;
			myAVLTree.Insert(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "������Ҫɾ��������[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myAVLTree.Delete(val))
				cout << "ɾ���ɹ�!" << endl;
			else cout << "ɾ��ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "������Ҫ�޸ĵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "������Ҫ�ĳɵ�����[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (myAVLTree.Updata(val, newVal))
				cout << "�޸ĳɹ�!" << endl;
			else cout << "�޸�ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "������Ҫ���ҵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			if (NULL != myAVLTree.Search(val))
				cout << "���ҳɹ�!" << endl;
			else cout << "����ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========ǰ��==============" << endl;
			myAVLTree.PreOrderPrint();
			cout << endl << "==========����================" << endl;
			myAVLTree.InOrderPrint();
			cout << endl << "==========����===============" << endl;
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
		cout << "���������� ����1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//�������
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
		cout << "Average Insert time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;
		
		//���Ҿ��ȷֲ�����
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
			cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "΢��" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
		cout << endl;

		//ɾ������
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
		cout << "Average Delete time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;
	}
	//��ӡ����
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
			cout << "       1.��" << endl;
			cout << "       2.ɾ" << endl;
			cout << "       3.��" << endl;
			cout << "       4.��" << endl;
			cout << "       5.��ʾ" << endl;
			cout << "       6.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "������Ҫ���������[        ]\b\b\b\b\b\b";
			cin >> val;
			myBST.InsertBSTNode(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "������Ҫɾ��������[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myBST.DeleteBSTNode(val))
				cout << "ɾ���ɹ�!" << endl;
			else cout << "ɾ��ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "������Ҫ�޸ĵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "������Ҫ�ĳɵ�����[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (myBST.UpdataBSTNode(val, newVal))
				cout << "�޸ĳɹ�!" << endl;
			else cout << "�޸�ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "������Ҫ���ҵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			if (myBST.SearchBSTNode(val))
				cout << "���ҳɹ�!" << endl;
			else cout << "����ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========ǰ��==============" << endl;
			myBST.PreOrderBSTPrint(myBST.GetRoot());
			cout << endl << "==========����================" << endl;
			myBST.InOrderBSTPrint(myBST.GetRoot());
			cout << endl << "==========����===============" << endl;
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
		cout << "-------------���������-------------" << endl;
		cout << "1. �������в���\n2. ������в���\n";
		cout << "������[     ]\b\b\b\b";
		cin >> opt;
		if (opt == 1 || opt == 2)
			break;
		else {
			cout << "����������" << endl;
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
			cout << "���������� ����1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//�����������
			start = GetTickCount64();
			BinarySearchTree myBST;
			long long int i;
			long long int num1 = 0;
			for (i = 0; i <= sum; i++) {
				myBST.InsertBSTNode(i);
			}
			end = GetTickCount64() - start;
			data[0].push_back((double)end / sum * 1000);
			cout << "Average Insert time:" << (double)end / sum * 1000 << "΢��" << endl;
			cout << endl;


			//���Ҿ��ȷֲ�����
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
				cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
				cout << "Average Search time:" << (double)end / 1e5 * 1000 << "΢��" << endl;
				sum2 += (double)end / 1e5 * 1000;
			}
			data[1].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
			cout << endl;

			//ɾ������
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
			cout << "Average Delete time:" << (double)end / sum * 1000 << "΢��" << endl;
			cout << endl;
		}

		//��ӡ����
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
			cout << "���������� ����1*10^" << num << endl;
			int n = 5;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//�����������
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
			cout << "Average Insert time:" << (double)end / sum * 1000 << "΢��" << endl;
			cout << endl;
			
			//��ѯ����
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
				cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
				cout << "Average Search time:" << (double)end / 1e6 * 1000 << "΢��" << endl;
				sum2 += (double)end / 1e6 * 1000;
			}
			data[1].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
			cout << endl;

			//ɾ������
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
			cout << "Average Delete time:" << (double)end / sum * 1000 << "΢��" << endl;
			cout << endl;
		}

		//��ӡ����
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
			cout << "       1.��" << endl;
			cout << "       2.ɾ" << endl;
			cout << "       3.��" << endl;
			cout << "       4.��ʾ" << endl;
			cout << "       5.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
		if (1 == choice)
		{
			cout << "������Ҫ���������[        ]\b\b\b\b\b\b";
			cin >> val;
			myList.insert(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "������Ҫɾ��������[        ]\b\b\b\b\b\b";
			cin >> val;
			myList.delete_val(val);
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "������Ҫ���ҵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			long long int countRet = 0;
			if (myList.search(val))
				cout << val << "���ҳɹ�!" << endl;
			else cout << val << "����ʧ��!" << endl;
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
		cout << "���������� ����1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//�������
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
		cout << "Average Insert time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;

		//��������
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
			cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
			sum2 += (double)end / 1e5 * 1000;
			cout << "Average Search time:" << (double)end / 1e5 * 1000 << "΢��" << endl;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
		cout << endl;

		//ɾ������
		start = GetTickCount64();
		num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			myList.delete_val(val);
		}
		end = GetTickCount64();
		end = end - start;
		data[2].push_back((double)end / sum * 1000);
		cout << "Average Delete time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;
	}
	
	//��ӡ����
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
			cout << "       1.��" << endl;
			cout << "       2.ɾ" << endl;
			cout << "       3.��" << endl;
			cout << "       4.��" << endl;
			cout << "       5.��ʾ" << endl;
			cout << "       6.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "������Ҫ���������[        ]\b\b\b\b\b\b";
			cin >> val;
			mySplayTree.InsertSplayTree(val);
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "������Ҫɾ��������[        ]\b\b\b\b\b\b";
			cin >> val;
			if (mySplayTree.DeleteSplayTree(val))
				cout << "ɾ���ɹ�!" << endl;
			else cout << "ɾ��ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "������Ҫ�޸ĵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "������Ҫ�ĳɵ�����[        ]\b\b\b\b\b\b";
			cin >> newVal;
			if (mySplayTree.UpdataSplayTree(val, newVal))
				cout << "�޸ĳɹ�!" << endl;
			else cout << "�޸�ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "������Ҫ���ҵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			if (NULL != mySplayTree.FindSplayTree(val))
				cout << "���ҳɹ�!" << endl;
			else cout << "����ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (5 == choice)
		{
			cout << endl << "*****************************" << endl;
			cout << endl << "==========ǰ��==============" << endl;
			mySplayTree.PreOrderSTPrint();
			cout << endl << "==========����================" << endl;
			mySplayTree.InOrderSTPrint();
			cout << endl << "==========����===============" << endl;
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
		cout << "���������� ����1*10^" << num << endl;
		int n = 5;
		cout << endl;
		long long int sum = pow(10, num);
		DWORD start, end;
		std::uniform_int_distribution<long long> dist(0, sum);
		std::random_device rd; // Non-deterministic seed source
		std::default_random_engine rng{ rd() }; // Create random number generator

		//�������
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
		cout << "Average Insert time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;

		//���Ҿ��ȷֲ�����
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
			cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "΢��" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[1].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
		cout << endl;

		//������̬�ֲ�����
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
			cout << "���ҳɹ��ĸ���:" << a / (a + b) << '\t';
			cout << "Average Search time:" << (double)end / 1e6 * 1000 << "΢��" << endl;
			sum2 += (double)end / 1e6 * 1000;
		}
		data[2].push_back(sum2 / 5);
		cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
		cout << endl;

		//ɾ������
		start = GetTickCount64();
		num1 = 0;
		for (i = 0; i < sum; i++) {
			long long int val = dist(rng);
			if (mySplayTree.DeleteSplayTree(val))
				num1++;
		}
		end = GetTickCount64() - start;
		data[3].push_back((double)end / sum * 1000);
		cout << "Average Delete time:" << (double)end / sum * 1000 << "΢��" << endl;
		cout << endl;
	}

	//��ӡ����
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
			cout << "       1.��" << endl;
			cout << "       2.ɾ" << endl;
			cout << "       3.��" << endl;
			cout << "       4.��" << endl;
			cout << "       5.��ʾ" << endl;
			cout << "       6.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
		if (1 == choice)
		{
			cout << "������Ҫ���������[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if (it == data.end()) {
				data.push_back(val);
				cout << "����ɹ�" << endl;
			}				
			else
				cout << "����ʧ��" << endl;
			system("pause");
			system("CLS");
		}
		else if (2 == choice)
		{
			cout << "������Ҫɾ��������[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if ( it != data.end()) {
				data.erase(it);
				cout << "ɾ���ɹ�!" << endl;
			}
				
			else cout << "ɾ��ʧ��!" << endl;
			system("pause");
			system("CLS");
		}
		else if (3 == choice)
		{
			cout << "������Ҫ�޸ĵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			cout << "������Ҫ�ĳɵ�����[        ]\b\b\b\b\b\b";
			cin >> newVal;
			auto it = find(data.begin(), data.end(), val);
			if (it != data.end()) {
				cout << "�޸ĳɹ�!" << endl;
				*it = newVal;
			}				
			else cout << "�޸�ʧ�ܣ�����������!" << endl;
			system("pause");
			system("CLS");
		}
		else if (4 == choice)
		{
			cout << "������Ҫ���ҵ�����[        ]\b\b\b\b\b\b";
			cin >> val;
			auto it = find(data.begin(), data.end(), val);
			if (it != data.end())
				cout << "���ҳɹ�!" << endl;
			else cout << "����ʧ��!" << endl;
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
		cout << "-------------���������-------------" << endl;
		cout << "1. ˳�����\n2. ���ֲ���\n";
		cout << "������[     ]\b\b\b\b";
		cin >> opt;
		if (opt == 1 || opt == 2)
			break;
		else {
			cout << "����������" << endl;
			system("pause");
			system("CLS");
		}
	}
	//˳�����
	if (opt == 1) {
		double N[] = { 1,2,3,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5 };
		vector<double> data[1];
		vector<int> datavec;
		for (int K = 0; K < 23; K++) {
			datavec.clear();
			num = N[K];
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "���������� ����1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//�������
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

			//����
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
				cout << "���ҳɹ��ĸ���:" << a / 1e5 << '\t';
				cout << "Average Search time:" << (double)end / 1e5 * 1000 << "΢��" << endl;
				sum2 += (double)end / 1e5 * 1000;
			}
			data[0].push_back(sum2 / 5);
			cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
			cout << endl;
		}

		//��ӡ����
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
			cout << "���������� ����1*10^" << N[K] << endl;
			cout << endl;
			long long int sum = pow(10, num);
			DWORD start, end;
			std::uniform_int_distribution<long long> dist(0, sum);
			std::random_device rd; // Non-deterministic seed source
			std::default_random_engine rng{ rd() }; // Create random number generator

			//�������
			start = GetTickCount64();
			long long int i;
			long long int num1 = 0;
			for (i = 0; i <= sum; i++) {
				datavec.push_back(i);
			}
			end = GetTickCount64() - start;cout << endl;

			//���ֲ�������
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
				cout << "Average Search time:" << (double)end / 1e6 * 1000 << "΢��" << endl;
				sum2 += (double)end / 1e6 * 1000;
			}
			data[0].push_back(sum2 / 5);
			cout << endl;
			cout << "Average Search time:" << sum2 / 5 << "΢��" << endl;
			cout << endl;
		}
		
		//��ӡ����
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
			cout << "       1.����ƽ����" << endl;
			cout << "       2.���������" << endl;
			cout << "       3.������չ��" << endl;
			cout << "       4.����" << endl;
			cout << "       5.����" << endl;
			cout << "       6.����" << endl;
			cout << "���������ѡ��[   ]\b\b\b";
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
	cout << "��лʹ�ã�" << endl;
	exit(-1);
}

void wrongInput() {
	cout << "����������������롣" << endl;
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
