#include "aStar.h"

//�����OPEN�����ڵ㵽CLOSED���еĺ�����
void insertNodeToClosedList(closedList* close, openList*& open)
{
	//���ڵ�״̬����Ϊ��CLOSED����
	if (open->openNode->status != IN_CLOSEDLIST)
		open->openNode->status = IN_CLOSEDLIST;
	//���CLOSED��Ϊ��
	if (close->closedNode == nullptr)
	{
		//��OPEN���һ��Ԫ��ֱ�Ӳ���CLOSED��Ȼ��ɾ����Ԫ��
		close->closedNode = open->openNode;
		openList* tempOpen = open;
		open = open->next;
		delete tempOpen;
		return;
	}
	//���CLOSED���գ�����ҵ����һ��Ԫ��
	while (close->next != nullptr)
		close = close->next;
	//��OPEN���һ��Ԫ�ز���CLOSED��ĩβ
	closedList* tempClose = new closedList;
	tempClose->closedNode = open->openNode;
	tempClose->next = nullptr;
	close->next = tempClose;
	//OPEN��ɾ����һ��Ԫ��
	openList* tempOpen = open;
	open = open->next;
	delete tempOpen;
}

void calculateValues(mapNode** map, int x, int y, int i, mapNode* node, mapNode* destination)
{
	//���ضԽ����ƶ���gֵ����1.4����λ�߳�������gֵ����1����λ�߳�
	if (i == 0 || i == 2 || i == 5 || i == 7)
		map[x][y].gValue = node->gValue + 1.4 * UNIT;
	else
		map[x][y].gValue = node->gValue + UNIT;
	//hֵΪ�����ڽڵ���ˮƽ����ֱ�����ƶ����յ�ľ���
	map[x][y].hValue = (abs(destination->xCoordinate - x) + abs(destination->yCoordinate - y)) * UNIT;
	map[x][y].fValue = map[x][y].gValue + map[x][y].hValue;
}

void insertToOpenList(openList* open, mapNode* node)
{
	//����ǰ�ڵ㲻����㣬��״̬����Ϊ��OPEN����
	if (node->status != DESTINATION)
	{
		node->status = IN_OPENLIST;
	}
	//�½�һ��openListԪ��
	openList* tempOpen = new openList;
	tempOpen->next = nullptr;
	tempOpen->openNode = node;
	//��OPEN��ͷ��ʼѰ��
	while (open->next != nullptr)
	{
		//����ǰ�ڵ�fֵС�ڱ���Ԫ�ص�fֵ
		if (node->fValue < open->next->openNode->fValue)
		{
			//���½�Ԫ�ز��뵽����Ԫ��֮ǰ
			openList* tempAdd = open->next;
			tempOpen->next = tempAdd;
			open->next = tempOpen;
			break;
		}
		//����С�ڣ���������Ѱ��
		else
			open = open->next;
	}
	//��δ�ҵ������½�Ԫ�ز��뵽OPEN��ĩβ
	open->next = tempOpen;
}

bool ifChangeParent(mapNode** map, int x, int y, int i, mapNode* node)
{
	//���ضԽ����ƶ�
	if (i == 0 || i == 2 || i == 5 || i == 7)
	{
		//�����ڽڵ�gֵ���ڵ�ǰ�ڵ�gֵ����1.4����λ
		if (map[x][y].gValue > node->gValue + 1.4 * UNIT)
		{
			//���õ�ǰ�ڵ�Ϊ���ڵ�
			map[x][y].parent = node;
			//�޸Ľڵ��g��fֵ��hֵ����
			map[x][y].gValue = node->gValue + 1.4 * UNIT;
			map[x][y].fValue = map[x][y].gValue + map[x][y].hValue;
		}
		return true;
	}
	//����ˮƽ����ֱ�����ƶ���ͬ��
	else
	{
		if (map[x][y].gValue > node->gValue + UNIT)
		{
			map[x][y].parent = node;
			map[x][y].gValue = node->gValue + UNIT;
			map[x][y].fValue = map[x][y].gValue + map[x][y].hValue;
		}
		return true;
	}
	return false;
}


//������鵱ǰ�ڵ�����8������Ľڵ�ĺ���
bool checkNeighboringNodes(mapNode** map, openList* open, mapNode* node, mapNode* destination)
{
	//���嵱ǰ�ڵ�����8�����������仯
	const int neighborDirection[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
	for (int i = 0; i < 8; i++)
	{
		//�õ����ڽڵ��x��y����
		int neighborX = node->xCoordinate + neighborDirection[i][0];
		int neighborY = node->yCoordinate + neighborDirection[i][1];
		//�����ڽڵ�λ�ڵ�ͼ֮�⡢�򲻿ɵ��������COLSED�����򲻿���		
		if (neighborX >= 0 && neighborY >= 0 && neighborX < MAP_WIDTH && neighborY < MAP_HEIGHT
			&& map[neighborX][neighborY].status != NOT_ACCESS
			&& map[neighborX][neighborY].status != IN_CLOSEDLIST)
		{

			//�����ڽڵ�����OPEN����
			if (map[neighborX][neighborY].status == IN_OPENLIST)
				//�ж��Ƿ��и�С��gֵ������ı丸�ڵ�
				ifChangeParent(map, neighborX, neighborY, i, node);
			//�����ڽڵ�Ϊ�ɵ���
			else
			{
				//����ǰ�ڵ���Ϊ�丸�ڵ�
				map[neighborX][neighborY].parent = node;
				//��������ڽڵ��f��g��hֵ
				calculateValues(map, neighborX, neighborY, i, node, destination);
				//�������ڽڵ����OPEN��
				insertToOpenList(open, &map[neighborX][neighborY]);
			}
		}
	}
	return true;
}