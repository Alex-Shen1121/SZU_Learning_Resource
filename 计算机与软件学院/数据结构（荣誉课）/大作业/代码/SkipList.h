#pragma once
#include<iostream>
using namespace std;
#define MAXLEVEL 30


class node {
public:
	node(int val, int level) {
		this->val = val;
		this->level = level;
		for (int i = 0; i < MAXLEVEL; i++) {
			forword[i] = NULL;
		}
	}
	~node() {};
	int val;
	int level;
	node* forword[MAXLEVEL];//指向node*的数组
};

class skiplist {
private:
	node* head;
	int max_length;
public:
	skiplist();
	void insert(int val);
	bool search(int val);
	void delete_val(int val);
	void print();
	int get_max_length();
};
