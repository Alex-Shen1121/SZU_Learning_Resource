#include "AVLTree.h"


AVLTree::AVLTree()
{
	root = NULL;
}

//返回当前节点高度
int AVLTree::GetHeight(AVLTreeNode* tempNode)
{
	return NULL == tempNode ? -1 : tempNode->height;
}

//返回元素所在节点
AVLTreeNode* AVLTree::Search(long long int tempKey, AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return NULL;
	else if (tempKey == tempNode->key)
		return tempNode;
	else if (tempKey < tempNode->key)
		return Search(tempKey, tempNode->leftChild);
	return Search(tempKey, tempNode->rightChild);
}
bool AVLTree::Search(long long int tempKey)
{
	if (NULL == Search(tempKey, root))
		return false;
	return true;
}

//左旋调平衡
AVLTreeNode* AVLTree::LeftRotate(AVLTreeNode* tempNode)
{
	AVLTreeNode* lChildNode = tempNode->rightChild->leftChild, * newRoot = tempNode->rightChild;
	tempNode->rightChild->leftChild = tempNode;
	tempNode->rightChild = lChildNode;
	tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
	if (NULL != tempNode->rightChild)
		tempNode->rightChild->height = max(GetHeight(tempNode->rightChild->leftChild), GetHeight(tempNode->rightChild->rightChild)) + 1;
	return newRoot;
}

//右旋调平衡
AVLTreeNode* AVLTree::RightRotate(AVLTreeNode* tempNode)
{
	AVLTreeNode* rChildNode = tempNode->leftChild->rightChild, * newRoot = tempNode->leftChild;
	tempNode->leftChild->rightChild = tempNode;
	tempNode->leftChild = rChildNode;
	tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
	if (NULL != tempNode->leftChild)
		tempNode->leftChild->height = max(GetHeight(tempNode->leftChild->leftChild), GetHeight(tempNode->leftChild->rightChild)) + 1;
	return newRoot;
}

//先左旋后右旋调平衡
AVLTreeNode* AVLTree::LeftAndRightRotate(AVLTreeNode* tempNode)
{
	tempNode->leftChild = LeftRotate(tempNode->leftChild);
	return RightRotate(tempNode);
}

//先右旋后左旋调平衡
AVLTreeNode* AVLTree::RightAndLeftRotate(AVLTreeNode* tempNode)
{
	tempNode->rightChild = RightRotate(tempNode->rightChild);
	return LeftRotate(tempNode);
}

//插入元素到当前节点的子树
AVLTreeNode* AVLTree::Insert(long long int tempKey, AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return tempNode = new AVLTreeNode(tempKey);
	else
	{
		if (tempKey == tempNode->key)
			return tempNode;
		else if (tempKey < tempNode->key)
			tempNode->leftChild = Insert(tempKey, tempNode->leftChild);
		else tempNode->rightChild = Insert(tempKey, tempNode->rightChild);
	}
	//tempNode->height=max(GetHeight(tempNode->leftChild),GetHeight(tempNode->rightChild))+1;
	if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
	{
		if (tempKey < tempNode->leftChild->key)
			tempNode = RightRotate(tempNode);
		else tempNode = LeftAndRightRotate(tempNode);
	}
	else if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
	{
		if (tempKey > tempNode->rightChild->key)
			tempNode = LeftRotate(tempNode);
		else tempNode = RightAndLeftRotate(tempNode);
	}
	tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
	return tempNode;
}
void AVLTree::Insert(long long int tempKey)
{
	root = Insert(tempKey, root);
}

//删除元素
AVLTreeNode* AVLTree::Delete(bool& isDelSucceed, long long int tempKey, AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return NULL;
	else
	{
		if (tempKey == tempNode->key)
		{
			if (NULL == tempNode->rightChild)
			{
				AVLTreeNode* cur = tempNode;
				tempNode = tempNode->leftChild;
				delete cur;
				isDelSucceed = true;
				return tempNode;
			}
			else//找到右子树最小的元素代替，然后删除 
			{
				AVLTreeNode* cur = tempNode->rightChild;
				while (cur->leftChild != NULL)
					cur = cur->leftChild;
				tempNode->key = cur->key;
				tempNode->rightChild = Delete(isDelSucceed, cur->key, tempNode->rightChild);
			}
		}
		else if (tempKey < tempNode->key)
			tempNode->leftChild = Delete(isDelSucceed, tempKey, tempNode->leftChild);
		else tempNode->rightChild = Delete(isDelSucceed, tempKey, tempNode->rightChild);

		if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))//删除的是左子树上的
		{
			if (GetHeight(tempNode->rightChild->rightChild) >= GetHeight(tempNode->rightChild->leftChild))
				tempNode = LeftRotate(tempNode);
			else tempNode = RightAndLeftRotate(tempNode);
		}
		else if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
		{
			if (GetHeight(tempNode->leftChild->leftChild) >= GetHeight(tempNode->leftChild->rightChild))
				tempNode = RightRotate(tempNode);
			else tempNode = LeftAndRightRotate(tempNode);
		}
		tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
	}
	return tempNode;
}
bool AVLTree::Delete(long long int tempKey)
{
	bool isDelSucceed = false;
	root = Delete(isDelSucceed, tempKey, root);
	return isDelSucceed;
}

//修改函数
bool AVLTree::Updata(long long int oldKey, long long int newKey)
{
	if (Delete(oldKey))
	{
		Insert(newKey);
		return true;
	}
	return false;
}

//前序遍历二叉查找树
void AVLTree::PreOrderPrint(AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return;
	cout << tempNode->key << "    ";
	PreOrderPrint(tempNode->leftChild);
	PreOrderPrint(tempNode->rightChild);
}
void AVLTree::PreOrderPrint()
{
	PreOrderPrint(this->root);
}

//中序遍历二叉查找树
void AVLTree::InOrderPrint(AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return;
	InOrderPrint(tempNode->leftChild);
	cout << tempNode->key << "   ";
	InOrderPrint(tempNode->rightChild);
}
void AVLTree::InOrderPrint()
{
	InOrderPrint(root);
}

//后序遍历二叉查找树树
void AVLTree::SufOrderPrint(AVLTreeNode* tempNode)
{
	if (NULL == tempNode)
		return;
	SufOrderPrint(tempNode->leftChild);
	SufOrderPrint(tempNode->rightChild);
	cout << tempNode->key << "    ";
}
void AVLTree::SufOrderPrint()
{
	SufOrderPrint(root);
}



