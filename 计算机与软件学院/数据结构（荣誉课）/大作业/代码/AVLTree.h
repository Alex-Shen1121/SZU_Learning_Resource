#pragma once
#include <iostream>
using namespace std;

struct AVLTreeNode
{
	long long key;
	int height;
	AVLTreeNode* leftChild;
	AVLTreeNode* rightChild;
	AVLTreeNode(int tempKey)
	{
		height = 0;
		key = tempKey;
		leftChild = NULL;
		rightChild = NULL;
	}
};

class AVLTree
{
private:
	AVLTreeNode* root;
	AVLTreeNode* Search(long long int, AVLTreeNode*);
	AVLTreeNode* LeftRotate(AVLTreeNode*);
	AVLTreeNode* LeftAndRightRotate(AVLTreeNode*);
	AVLTreeNode* RightRotate(AVLTreeNode*);
	AVLTreeNode* RightAndLeftRotate(AVLTreeNode*);
	int GetHeight(AVLTreeNode*);
	void PreOrderPrint(AVLTreeNode*);
	void InOrderPrint(AVLTreeNode*);
	void SufOrderPrint(AVLTreeNode*);
	AVLTreeNode* Insert(long long int, AVLTreeNode*);
	AVLTreeNode* Delete(bool&, long long int, AVLTreeNode*);
public:
	AVLTree();
	void Insert(long long int);
	bool Search(long long int);
	bool Delete(long long int);
	bool Updata(long long int, long long int);
	void PreOrderPrint();
	void InOrderPrint();
	void SufOrderPrint();
};