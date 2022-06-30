#ifndef  _A_STAR_H
#define _A_STAR_H

#include <iostream>
#include <math.h>

using namespace std;

#define MAP_WIDTH 32  
#define MAP_HEIGHT 20
#define UNIT 32 

//定义节点的各种状态：
#define ACCESS 1		   //方格可到达、不可到达
#define NOT_ACCESS 2 
#define DANGEROUS 7
#define ORIGIN 3         //路径起点、终点
#define DESTINATION 4	   
#define IN_OPENLIST 5    //节点在OPEN表、CLOSED表中
#define IN_CLOSEDLIST 6  

//定义节点结构：
struct mapNode
{
	int status;           //节点的状态标志
	int xCoordinate;	   //节点的横、纵坐标
	int yCoordinate;
	int fValue;		   //节点的f值，g值，h值
	int gValue;
	int hValue;
	bool isDangerous = false;
	mapNode* parent;    //节点的父节点指针
};

//定义OPEN表结构：
struct openList
{
	mapNode *openNode;
	openList* next;
};

//定义CLOSED表结构：
struct closedList
{
	mapNode *closedNode;
	closedList* next;
};

void insertNodeToClosedList(closedList* close, openList* &open);

void calculateValues(mapNode** map, int x, int y, int i, mapNode* node, mapNode* destination);

void insertToOpenList(openList* open, mapNode* node);

bool ifChangeParent(mapNode** map, int x, int y, int i, mapNode * node);

bool checkNeighboringNodes(mapNode** map, openList* open, mapNode* node, mapNode* destination);


#endif

