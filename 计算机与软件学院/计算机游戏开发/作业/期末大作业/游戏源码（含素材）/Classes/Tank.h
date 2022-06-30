#ifndef __TANK_H__
#define __TANK_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "BaseObject.h"
#include "Bullet.h"
#include "Star.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;
using namespace CocosDenshion;

class Tank : public BaseObject
{
public:
	static constexpr int Tank_Size = 24;
	static constexpr int Tank_None = 0;
	static constexpr int Tank_Up = 1;
	static constexpr int Tank_Down = 2;
	static constexpr int Tank_Left = 3;
	static constexpr int Tank_Right = 4;

	static Tank* create(int ID, float x, float y, int dir, int kind, int level);
	void blink(float distance, int dir = DIR_NONE); // ˲���ƶ�
	void invincible(float time); // �޵�
	
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stay(int dir);

	void fire();  // ����
	void hurt();  // ����
	void blast(); // ��ը

	bool isMoving() { return m_move; };
private:
	virtual bool init(int ID, float x, float y, int dir, int kind, int level);
	void paint(float delta);
	void update(float delta);

private:
	Sprite*     m_sprite;          // ͼƬ����
	Texture2D*  m_texture;         // ����texture

	bool  m_move;               // ̹�������ƶ�

	bool  m_hurt;               // �Ƿ�������״̬
	float m_frametime;	        // �л�ͼƬʱ�䲽��
	float m_texchange;	        // ̹���Ĵ������л�����
	int   m_textureX;           
	int   m_textureY;
};

#endif