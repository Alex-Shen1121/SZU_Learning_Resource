#include "SplayTree.h"

SplayTree::SplayTree()
{
	this->root = NULL;
}

//����
void SplayTree::LeftRotate(SplayTreeNode* tempSTNode)
{
	SplayTreeNode* rChild = tempSTNode->rightChild;
	if (NULL != tempSTNode->parent)//��Ϊ���ڵ�
	{
		if (tempSTNode->parent->leftChild == tempSTNode)
			tempSTNode->parent->leftChild = rChild;
		else
			tempSTNode->parent->rightChild = rChild;
	}
	rChild->parent = tempSTNode->parent;
	tempSTNode->parent = rChild;
	if (rChild->leftChild != NULL)
		rChild->leftChild->parent = tempSTNode;
	tempSTNode->rightChild = rChild->leftChild;
	rChild->leftChild = tempSTNode;
	if (NULL == rChild->parent)
		this->root = rChild;
}

//����
void SplayTree::RightRotate(SplayTreeNode* tempSTNode)
{
	SplayTreeNode* lChild = tempSTNode->leftChild;
	if (NULL != tempSTNode->parent)//��Ϊ���ڵ�
	{
		if (tempSTNode->parent->rightChild == tempSTNode)
			tempSTNode->parent->rightChild = lChild;
		else
			tempSTNode->parent->leftChild = lChild;
	}
	lChild->parent = tempSTNode->parent;
	tempSTNode->parent = lChild;
	if (lChild->rightChild != NULL)
		lChild->rightChild->parent = tempSTNode;
	tempSTNode->leftChild = lChild->rightChild;
	lChild->rightChild = tempSTNode;
	if (NULL == lChild->parent)
		this->root = lChild;
}

//����ǰ�ڵ���չ�ĸ��ڵ�
void SplayTree::Splay(SplayTreeNode* tempSTNode)
{
	while (NULL != tempSTNode && NULL != tempSTNode->parent)
	{
		if (tempSTNode->parent->leftChild == tempSTNode)//���׽ڵ�����
			RightRotate(tempSTNode->parent);
		else LeftRotate(tempSTNode->parent);
	}
}

//����ǰԪ�ز�����չ��
void SplayTree::InsertSplayTree(long long int tempKey)
{
	SplayTreeNode* pre = NULL, * cur = this->root;
	while (cur != NULL)
	{
		pre = cur;
		if (cur->key > tempKey)//tempKey�嵽������
			cur = cur->leftChild;
		else if(cur->key < tempKey)
			cur = cur->rightChild;//�嵽������
		else {
			Splay(cur);
			return;
		}
	}
	SplayTreeNode* tempSTNode = new SplayTreeNode(tempKey);
	tempSTNode->parent = pre;
	if (pre == NULL)//�������Ϊ���ڵ�
	{
		this->root = tempSTNode;
	}
	else if (pre->key > tempSTNode->key)
		pre->leftChild = tempSTNode;
	else pre->rightChild = tempSTNode;
	Splay(tempSTNode);
}

//���ҵ�ǰԪ���Ƿ�����չ��
SplayTreeNode* SplayTree::FindSplayTree(long long int tempKey)
{
	SplayTreeNode* cur = this->root;
	while (cur != NULL)
	{
		if (cur->key == tempKey)
			break;
		else if (cur->key > tempKey)
			cur = cur->leftChild;
		else cur = cur->rightChild;
	}
	Splay(cur);
	return cur;
}

//ɾ�����Һ�����Ϊ�յ����
void SplayTree::DeleteNoOrOneChildSTNode(SplayTreeNode* pre, SplayTreeNode* cur)
{
	if (NULL == cur->leftChild && NULL == cur->rightChild)//���Һ���Ϊ��
	{
		if (NULL == pre)
			this->root = NULL;
		else if (pre->leftChild == cur)
			pre->leftChild = NULL;
		else pre->rightChild = NULL;
		delete cur;
	}
	else if (cur->rightChild != NULL)//����������Ϊ��
	{
		if (NULL == pre)
		{
			this->root = cur->rightChild;
			cur->rightChild->parent = NULL;
		}
		else if (pre->leftChild == cur)
		{
			pre->leftChild = cur->rightChild;
			cur->rightChild->parent = pre;
		}
		else
		{
			pre->rightChild = cur->rightChild;
			cur->rightChild->parent = pre;
		}
		delete cur;
	}
	else if (cur->leftChild != NULL)//����������Ϊ��
	{
		if (NULL == pre)
		{
			this->root = cur->leftChild;
			cur->leftChild->parent = NULL;
		}
		else if (pre->leftChild == cur)
		{
			pre->leftChild = cur->leftChild;
			cur->leftChild->parent = pre;
		}
		else
		{
			pre->rightChild = cur->leftChild;
			cur->leftChild->parent = pre;
		}
		delete cur;
	}
}


//ɾ��Ԫ��������
bool SplayTree::DeleteSplayTree(long long int tempKey)
{
	SplayTreeNode* pre = NULL, * cur = root;
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
	{
		DeleteNoOrOneChildSTNode(pre, cur);
		Splay(pre);
	}
	else //������������Ϊ��
	{
		SplayTreeNode* rPre = cur, * rCur = cur->rightChild;//�ҵ���������СԪ��
		while (rCur->leftChild != NULL)
		{
			rPre = rCur;
			rCur = rCur->leftChild;
		}
		cur->key = rCur->key;
		DeleteNoOrOneChildSTNode(rPre, rCur);
		Splay(rPre);
	}
	return true;
}

//�޸ĺ���
bool SplayTree::UpdataSplayTree(long long int oldKey, long long int newKey)
{
	if (DeleteSplayTree(oldKey))
	{
		InsertSplayTree(newKey);
		return true;
	}
	return false;
}

//ǰ��������������
void SplayTree::PreOrderSTPrint(SplayTreeNode* tempSTNode)
{
	if (NULL == tempSTNode)
		return;
	cout << tempSTNode->key << "    ";
	PreOrderSTPrint(tempSTNode->leftChild);
	PreOrderSTPrint(tempSTNode->rightChild);
}
void SplayTree::PreOrderSTPrint()
{
	PreOrderSTPrint(this->root);
}

//����������������
void SplayTree::InOrderSTPrint(SplayTreeNode* tempSTNode)
{
	if (NULL == tempSTNode)
		return;
	InOrderSTPrint(tempSTNode->leftChild);
	cout << tempSTNode->key << "   ";
	InOrderSTPrint(tempSTNode->rightChild);
}
void SplayTree::InOrderSTPrint()
{
	InOrderSTPrint(this->root);
}

//������������������
void SplayTree::SufOrderSTPrint(SplayTreeNode* tempSTNode)
{
	if (NULL == tempSTNode)
		return;
	SufOrderSTPrint(tempSTNode->leftChild);
	SufOrderSTPrint(tempSTNode->rightChild);
	cout << tempSTNode->key << "    ";
}
void SplayTree::SufOrderSTPrint()
{
	SufOrderSTPrint(this->root);
}

