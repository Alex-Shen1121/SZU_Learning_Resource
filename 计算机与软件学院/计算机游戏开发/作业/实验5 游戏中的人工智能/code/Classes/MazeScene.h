#ifndef  _MAZE_SCENE_H
#define _MAZE_SCENE_H
#include "aStar.h"
#include "cocos2d.h"
USING_NS_CC;

#define SMILE_TAG  1
#define DRAW_TAG  2
#define FORBID_TAG 3
#define BOX_TAG 4
#define TIP_TAG 5
#define NOT_ACCESS_TILE 80

class MazeScene : public cocos2d::Layer
{
private:
	//��Ƭ��ͼ��ͼ�����
	TMXLayer* m_mapLayer;
	//����·���Ļ�ͼ�ڵ����
	DrawNode* m_draw;
	//��Ļ�Ŀɼ��ߴ�
	Size m_visibleSize;
	//��ͼ����ָ��
	mapNode** m_map;
	//Ѱ·���ָ��
	mapNode* m_origin;
	//Ѱ·�յ�ָ��
	mapNode* m_destination;
	//�ж��Ƿ�����ڵ�ͼ���ƶ�
	bool m_isReadyToMove; 
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MazeScene);
	//��ʼ����ͼ����
	void initMap();
	//���ƾ�����·���ƶ�
	void moveOnPath(mapNode* tempNode);
	//A*�㷨������
	int aStar(mapNode** map, mapNode* origin, mapNode* destination);
	//�����Ļ��������
	void addTouchListener();
	void addKeyPressedListener();
	//��ʱ������
	void update(float delta);
	void Next(string s);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	bool onKeyPressedBegan(EventKeyboard::KeyCode keycode, Event* unused_event);
	void onKeyPressedEnded(EventKeyboard::KeyCode keycode, Event* unused_event);
};
#endif

