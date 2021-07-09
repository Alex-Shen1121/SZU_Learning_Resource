#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()
{
	Root = NULL;
}


//���ض�����������ڵ�
BinarySearchTreeNode* BinarySearchTree::GetRoot()
{
	return this->Root;
}


//�����½��
BinarySearchTreeNode* BinarySearchTree::FindBST(long long int tempKey)
{
	BinarySearchTreeNode* cur = this->Root;
	while (cur != NULL)
	{
		if (cur->key == tempKey)
			break;
		else if (cur->key > tempKey)
			cur = cur->leftChild;
		else cur = cur->rightChild;
	}
	return cur;
}

//���ܣ������½��
void BinarySearchTree::InsertBSTNode(long long int tempKey)
{
	BinarySearchTreeNode* pre = NULL, * cur = this->Root;
	while (cur != NULL)
	{
		pre = cur;
		if (cur->key > tempKey)//tempKey�嵽������
			cur = cur->leftChild;
		else if (cur->key < tempKey)
			cur = cur->rightChild;//�嵽������
		else
			return;
	}
	BinarySearchTreeNode* tempNode = new BinarySearchTreeNode(tempKey);
	if (pre == NULL)//�������Ϊ���ڵ�
	{
		this->Root = tempNode;
	}
	else if (pre->key > tempNode->key)
		pre->leftChild = tempNode;
	else pre->rightChild = tempNode;
}



//���½ڵ�Ԫ��
bool BinarySearchTree::UpdataBSTNode(long long int oldKey, long long int newKey)
{
	if (DeleteBSTNode(oldKey))
		InsertBSTNode(newKey);
	else
		return false;
}

//ɾ�����Һ�����Ϊ�յ����
void BinarySearchTree::DeleteNoOrOneChildBSTNode(BinarySearchTreeNode* pre, BinarySearchTreeNode* cur)
{
	if (NULL == cur->leftChild && NULL == cur->rightChild)//���Һ���Ϊ��
	{
		if (NULL == pre)
			Root = NULL;
		else if (pre->leftChild == cur)
			pre->leftChild = NULL;
		else pre->rightChild = NULL;
		delete cur;
	}
	else if (cur->rightChild != NULL)//����������Ϊ��
	{
		if (NULL == pre)
			Root = cur->rightChild;
		else if (pre->leftChild == cur)
			pre->leftChild = cur->rightChild;
		else
			pre->rightChild = cur->rightChild;
		delete cur;
	}
	else if (cur->leftChild != NULL)//����������Ϊ��
	{
		if (NULL == pre)
			Root = cur->leftChild;
		else if (pre->leftChild == cur)
			pre->leftChild = cur->leftChild;
		else
			pre->rightChild = cur->leftChild;
		delete cur;
	}
}


//ɾ��Ԫ��������
bool BinarySearchTree::DeleteBSTNode(long long int tempKey)
{
	BinarySearchTreeNode* pre = NULL, * cur = Root;
	while (cur != NULL)//Ѱ�Ҵ�ɾ��Ԫ��
	{
		if (cur->key == tempKey)
			break;
		else
		{
			pre = cur;
			if (cur->key > tempKey)
				cur = cur->leftChild;
			else cur = cur->rightChild;
		}
	}
	if (NULL == cur)return false;
	if (NULL == cur->leftChild || NULL == cur->rightChild)
		DeleteNoOrOneChildBSTNode(pre, cur);
	else //������������Ϊ��
	{
		BinarySearchTreeNode* rPre = cur, * rCur = cur->rightChild;//�ҵ���������СԪ��
		while (rCur->leftChild != NULL)
		{
			rPre = rCur;
			rCur = rCur->leftChild;
		}
		cur->key = rCur->key;
		DeleteNoOrOneChildBSTNode(rPre, rCur);
	}
}

bool BinarySearchTree::SearchBSTNode(long long int tempKey)
{
	BinarySearchTreeNode* pre = NULL, * cur = Root;
	while (cur != NULL)//Ѱ��Ԫ��
	{
		if (cur->key == tempKey)
			break;
		else
		{
			pre = cur;
			if (cur->key > tempKey)
				cur = cur->leftChild;
			else cur = cur->rightChild;
		}
	}
	if (NULL == cur)return false;
	return true;
}

//ǰ��������������
void BinarySearchTree::PreOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	cout << tempRoot->key << "    ";
	PreOrderBSTPrint(tempRoot->leftChild);
	PreOrderBSTPrint(tempRoot->rightChild);
}

//����������������
void BinarySearchTree::InOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	InOrderBSTPrint(tempRoot->leftChild);
	cout << tempRoot->key << "    ";
	InOrderBSTPrint(tempRoot->rightChild);
}

//������������������
void BinarySearchTree::SufOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	SufOrderBSTPrint(tempRoot->leftChild);
	SufOrderBSTPrint(tempRoot->rightChild);
	cout << tempRoot->key << "    ";
}
