#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()
{
	Root = NULL;
}


//返回二叉查找树根节点
BinarySearchTreeNode* BinarySearchTree::GetRoot()
{
	return this->Root;
}


//插入新结点
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

//功能：插入新结点
void BinarySearchTree::InsertBSTNode(long long int tempKey)
{
	BinarySearchTreeNode* pre = NULL, * cur = this->Root;
	while (cur != NULL)
	{
		pre = cur;
		if (cur->key > tempKey)//tempKey插到左子树
			cur = cur->leftChild;
		else if (cur->key < tempKey)
			cur = cur->rightChild;//插到右子树
		else
			return;
	}
	BinarySearchTreeNode* tempNode = new BinarySearchTreeNode(tempKey);
	if (pre == NULL)//若插入的为根节点
	{
		this->Root = tempNode;
	}
	else if (pre->key > tempNode->key)
		pre->leftChild = tempNode;
	else pre->rightChild = tempNode;
}



//更新节点元素
bool BinarySearchTree::UpdataBSTNode(long long int oldKey, long long int newKey)
{
	if (DeleteBSTNode(oldKey))
		InsertBSTNode(newKey);
	else
		return false;
}

//删除左右孩子有为空的情况
void BinarySearchTree::DeleteNoOrOneChildBSTNode(BinarySearchTreeNode* pre, BinarySearchTreeNode* cur)
{
	if (NULL == cur->leftChild && NULL == cur->rightChild)//左右孩子为空
	{
		if (NULL == pre)
			Root = NULL;
		else if (pre->leftChild == cur)
			pre->leftChild = NULL;
		else pre->rightChild = NULL;
		delete cur;
	}
	else if (cur->rightChild != NULL)//若右子树不为空
	{
		if (NULL == pre)
			Root = cur->rightChild;
		else if (pre->leftChild == cur)
			pre->leftChild = cur->rightChild;
		else
			pre->rightChild = cur->rightChild;
		delete cur;
	}
	else if (cur->leftChild != NULL)//若左子树不为空
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


//删除元素主函数
bool BinarySearchTree::DeleteBSTNode(long long int tempKey)
{
	BinarySearchTreeNode* pre = NULL, * cur = Root;
	while (cur != NULL)//寻找待删除元素
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
	else //左右子树都不为空
	{
		BinarySearchTreeNode* rPre = cur, * rCur = cur->rightChild;//找到右子树最小元素
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
	while (cur != NULL)//寻找元素
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

//前序遍历二叉查找树
void BinarySearchTree::PreOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	cout << tempRoot->key << "    ";
	PreOrderBSTPrint(tempRoot->leftChild);
	PreOrderBSTPrint(tempRoot->rightChild);
}

//中序遍历二叉查找树
void BinarySearchTree::InOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	InOrderBSTPrint(tempRoot->leftChild);
	cout << tempRoot->key << "    ";
	InOrderBSTPrint(tempRoot->rightChild);
}

//后序遍历二叉查找树树
void BinarySearchTree::SufOrderBSTPrint(BinarySearchTreeNode* tempRoot)
{
	if (NULL == tempRoot)
		return;
	SufOrderBSTPrint(tempRoot->leftChild);
	SufOrderBSTPrint(tempRoot->rightChild);
	cout << tempRoot->key << "    ";
}
