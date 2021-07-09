#pragma once
#include<iostream>
using namespace std;

struct BinarySearchTreeNode
{
	long long int key;
	BinarySearchTreeNode* leftChild;
	BinarySearchTreeNode* rightChild;
	BinarySearchTreeNode(long long int tempKey)
	{
		key = tempKey;
		leftChild = NULL;
		rightChild = NULL;
	}
};

class BinarySearchTree
{
private:
	BinarySearchTreeNode* Root;
public:
	BinarySearchTree();
	BinarySearchTreeNode* GetRoot();
	BinarySearchTreeNode* FindBST(long long int);
	bool UpdataBSTNode(long long int, long long int);
	void InsertBSTNode(long long int);
	bool DeleteBSTNode(long long int);
	bool SearchBSTNode(long long int);
	void DeleteNoOrOneChildBSTNode(BinarySearchTreeNode*, BinarySearchTreeNode*);
	void PreOrderBSTPrint(BinarySearchTreeNode*);
	void InOrderBSTPrint(BinarySearchTreeNode*);
	void SufOrderBSTPrint(BinarySearchTreeNode*);
};