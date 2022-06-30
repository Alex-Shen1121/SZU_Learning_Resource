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
	void blink(float distance, int dir = DIR_NONE); // 瞬间移动
	void invincible(float time); // 无敌
	
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stay(int dir);

	void fire();  // 开火
	void hurt();  // 受伤
	void blast(); // 爆炸

	bool isMoving() { return m_move; };
private:
	virtual bool init(int ID, float x, float y, int dir, int kind, int level);
	void paint(float delta);
	void update(float delta);

private:
	Sprite*     m_sprite;          // 图片精灵
	Texture2D*  m_texture;         // 保存texture

	bool  m_move;               // 坦克正在移动

	bool  m_hurt;               // 是否处于受伤状态
	float m_frametime;	        // 切换图片时间步长
	float m_texchange;	        // 坦克履带纹理切换控制
	int   m_textureX;           
	int   m_textureY;
};

#endif