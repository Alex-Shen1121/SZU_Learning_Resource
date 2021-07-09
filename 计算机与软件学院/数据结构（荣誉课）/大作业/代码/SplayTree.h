#pragma once
#include<iostream>
using namespace std;

class SplayTreeNode
{
public:
	long long int key;
	SplayTreeNode* leftChild;
	SplayTreeNode* rightChild;
	SplayTreeNode* parent;
	SplayTreeNode(long long int key)
	{
		this->key = key;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
};

class SplayTree
{
private:
	SplayTreeNode* root;
	void LeftRotate(SplayTreeNode*);
	void RightRotate(SplayTreeNode*);
	void Splay(SplayTreeNode*);
	void PreOrderSTPrint(SplayTreeNode*);
	void InOrderSTPrint(SplayTreeNode*);
	void SufOrderSTPrint(SplayTreeNode*);
	void DeleteNoOrOneChildSTNode(SplayTreeNode*, SplayTreeNode*);
public:
	SplayTree();
	void InsertSplayTree(long long int);
	bool DeleteSplayTree(long long int);
	bool UpdataSplayTree(long long int, long long int);
	SplayTreeNode* FindSplayTree(long long int);
	void PreOrderSTPrint();
	void InOrderSTPrint();
	void SufOrderSTPrint();
};