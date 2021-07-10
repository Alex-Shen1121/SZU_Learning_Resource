// 摇杆

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "cocos2d.h"
#include <vector>
USING_NS_CC;

enum Joystick_dir
{
	_LEFT,
	_RIGHT,
	_STOP
};

class Joystick : public Layer
{
public:
	Joystick();
	~Joystick();

	// 创建摇杆，aPoint是摇杆中心 aRadius是摇杆半径 aJsSprite是摇杆控制点 aJsBg是摇杆背景
	static Joystick* create(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);

	// 获取摇杆方向
	Vec2 getDirection();
	float getVelocity();   // 摇杆力度

private:
	double maxSpeed = 6;
	void update(float dt); 
	// 初始化，aPoint是摇杆中心 aRadius是摇杆半径 aJsSprite是摇杆控制点 aJsBg是摇杆背景
	virtual bool init(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	Vec2 m_centerPoint;    // 摇杆中心
	Vec2 m_currentPoint;   // 摇杆当前位置
	float m_radius;        // 摇杆半径
	Sprite* m_jsSprite;    //摇杆控制点
};

#endif
