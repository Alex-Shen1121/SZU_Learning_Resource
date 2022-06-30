#include "aStar.h"

//定义从OPEN表插入节点到CLOSED表中的函数：
void insertNodeToClosedList(closedList* close, openList*& open)
{
	//将节点状态设置为在CLOSED表中
	if (open->openNode->status != IN_CLOSEDLIST)
		open->openNode->status = IN_CLOSEDLIST;
	//如果CLOSED表为空
	if (close->closedNode == nullptr)
	{
		//将OPEN表第一个元素直接插入CLOSED表，然后删除该元素
		close->closedNode = open->openNode;
		openList* tempOpen = open;
		open = open->next;
		delete tempOpen;
		return;
	}
	//如果CLOSED表不空，向后找到最后一个元素
	while (close->next != nullptr)
		close = close->next;
	//将OPEN表第一个元素插入CLOSED表末尾
	closedList* tempClose = new closedList;
	tempClose->closedNode = open->openNode;
	tempClose->next = nullptr;
	close->next = tempClose;
	//OPEN表删除第一个元素
	openList* tempOpen = open;
	open = open->next;
	delete tempOpen;
}

void calculateValues(mapNode** map, int x, int y, int i, mapNode* node, mapNode* destination)
{
	//若沿对角线移动，g值增加1.4个单位边长，否则g值增加1个单位边长
	if (i == 0 || i == 2 || i == 5 || i == 7)
		map[x][y].gValue = node->gValue + 1.4 * UNIT;
	else
		map[x][y].gValue = node->gValue + UNIT;
	//h值为该相邻节点沿水平、竖直方向移动到终点的距离
	map[x][y].hValue = (abs(destination->xCoordinate - x) + abs(destination->yCoordinate - y)) * UNIT;
	map[x][y].fValue = map[x][y].gValue + map[x][y].hValue;
}

void insertToOpenList(openList* open, mapNode* node)
{
	//若当前节点不是起点，将状态设置为在OPEN表中
	if (node->status != DESTINATION)
	{
		node->status = IN_OPENLIST;
	}
	//新建一个openList元素
	openList* tempOpen = new openList;
	tempOpen->next = nullptr;
	tempOpen->openNode = node;
	//从OPEN表头开始寻找
	while (open->next != nullptr)
	{
		//若当前节点f值小于表中元素的f值
		if (node->fValue < open->next->openNode->fValue)
		{
			//将新建元素插入到表中元素之前
			openList* tempAdd = open->next;
			tempOpen->next = tempAdd;
			open->next = tempOpen;
			break;
		}
		//若不小于，则继续向后寻找
		else
			open = open->next;
	}
	//若未找到，则将新建元素插入到OPEN表末尾
	open->next = tempOpen;
}

bool ifChangeParent(mapNode** map, int x, int y, int i, mapNode* node)
{
	//若沿对角线移动
	if (i == 0 || i == 2 || i == 5 || i == 7)
	{
		//若相邻节点g值大于当前节点g值超过1.4个单位
		if (map[x][y].gValue > node->gValue + 1.4 * UNIT)
		{
			//设置当前节点为父节点
			map[x][y].parent = node;
			//修改节点的g，f值，h值不变
			map[x][y].gValue = node->gValue + 1.4 * UNIT;
			map[x][y].fValue = map[x][y].gValue + map[x][y].hValue;
		}
		return true;
	}
	//若沿水平、垂直方向移动，同理
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


//定义检验当前节点相邻8个方向的节点的函数
bool checkNeighboringNodes(mapNode** map, openList* open, mapNode* node, mapNode* destination)
{
	//定义当前节点相邻8个方向的坐标变化
	const int neighborDirection[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
	for (int i = 0; i < 8; i++)
	{
		//得到相邻节点的x，y坐标
		int neighborX = node->xCoordinate + neighborDirection[i][0];
		int neighborY = node->yCoordinate + neighborDirection[i][1];
		//若相邻节点位于地图之外、或不可到达、或已在COLSED表中则不考虑		
		if (neighborX >= 0 && neighborY >= 0 && neighborX < MAP_WIDTH && neighborY < MAP_HEIGHT
			&& map[neighborX][neighborY].status != NOT_ACCESS
			&& map[neighborX][neighborY].status != IN_CLOSEDLIST)
		{

			//若相邻节点已在OPEN表中
			if (map[neighborX][neighborY].status == IN_OPENLIST)
				//判断是否有更小的g值，有则改变父节点
				ifChangeParent(map, neighborX, neighborY, i, node);
			//若相邻节点为可到达
			else
			{
				//将当前节点设为其父节点
				map[neighborX][neighborY].parent = node;
				//计算该相邻节点的f，g，h值
				calculateValues(map, neighborX, neighborY, i, node, destination);
				//将该相邻节点插入OPEN表
				insertToOpenList(open, &map[neighborX][neighborY]);
			}
		}
	}
	return true;
}