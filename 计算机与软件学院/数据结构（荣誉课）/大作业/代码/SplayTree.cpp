#include "SplayTree.h"

SplayTree::SplayTree()
{
	this->root = NULL;
}

//左旋
void SplayTree::LeftRotate(SplayTreeNode* tempSTNode)
{
	SplayTreeNode* rChild = tempSTNode->rightChild;
	if (NULL != tempSTNode->parent)//不为根节点
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

//右旋
void SplayTree::RightRotate(SplayTreeNode* tempSTNode)
{
	SplayTreeNode* lChild = tempSTNode->leftChild;
	if (NULL != tempSTNode->parent)//不为根节点
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

//将当前节点伸展的根节点
void SplayTree::Splay(SplayTreeNode* tempSTNode)
{
	while (NULL != tempSTNode && NULL != tempSTNode->parent)
	{
		if (tempSTNode->parent->leftChild == tempSTNode)//父亲节点右旋
			RightRotate(tempSTNode->parent);
		else LeftRotate(tempSTNode->parent);
	}
}

//将当前元素插入伸展树
void SplayTree::InsertSplayTree(long long int tempKey)
{
	SplayTreeNode* pre = NULL, * cur = this->root;
	while (cur != NULL)
	{
		pre = cur;
		if (cur->key > tempKey)//tempKey插到左子树
			cur = cur->leftChild;
		else if(cur->key < tempKey)
			cur = cur->rightChild;//插到左子树
		else {
			Splay(cur);
			return;
		}
	}
	SplayTreeNode* tempSTNode = new SplayTreeNode(tempKey);
	tempSTNode->parent = pre;
	if (pre == NULL)//若插入的为根节点
	{
		this->root = tempSTNode;
	}
	else if (pre->key > tempSTNode->key)
		pre->leftChild = tempSTNode;
	else pre->rightChild = tempSTNode;
	Splay(tempSTNode);
}

//查找当前元素是否在伸展树
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

//删除左右孩子有为空的情况
void SplayTree::DeleteNoOrOneChildSTNode(SplayTreeNode* pre, SplayTreeNode* cur)
{
	if (NULL == cur->leftChild && NULL == cur->rightChild)//左右孩子为空
	{
		if (NULL == pre)
			this->root = NULL;
		else if (pre->leftChild == cur)
			pre->leftChild = NULL;
		else pre->rightChild = NULL;
		delete cur;
	}
	else if (cur->rightChild != NULL)//若右子树不为空
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
	else if (cur->leftChild != NULL)//若左子树不为空
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


//删除元素主函数
bool SplayTree::DeleteSplayTree(long long int tempKey)
{
	SplayTreeNode* pre = NULL, * cur = root;
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
	{
		DeleteNoOrOneChildSTNode(pre, cur);
		Splay(pre);
	}
	else //左右子树都不为空
	{
		SplayTreeNode* rPre = cur, * rCur = cur->rightChild;//找到右子树最小元素
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

//修改函数
bool SplayTree::UpdataSplayTree(long long int oldKey, long long int newKey)
{
	if (DeleteSplayTree(oldKey))
	{
		InsertSplayTree(newKey);
		return true;
	}
	return false;
}

//前序遍历二叉查找树
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

//中序遍历二叉查找树
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

//后序遍历二叉查找树树
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

