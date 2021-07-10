// ��5������
#ifndef __MAPSCENE_H__
#define __MAPSCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Config.h"
USING_NS_CC;

using namespace cocos2d::ui; 

class MapScene : public cocos2d::Layer
{
public:

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MapScene);

	// ���ص�ͼ
	void loadMap(std::string mapPath);

	// ��ʾ����
	void addPlayer(Vec2 pos);

	// ��Ӵ�������
	void addTouchListener();
	bool onTouchBegan(Touch *touch, Event *unused_event);

	// ��Ϸ�߼�
	void update(float t);

	void gameOver();
	void success();

	bool m_gameOver; // ��Ϸ�Ƿ����
	Dir m_jumpDir;   // ��ʾ����ķ��� 1��up 2 down
	int m_jumpSpeed; // ��Ծ�ٶ�
	bool m_isJump;   // ��ʾ�Ƿ�������Ծ�������Ծ��������Ļ�Ĵ���
};

#endif // __HELLOWORLD_SCENE_H__
