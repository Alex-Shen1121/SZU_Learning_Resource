// ҡ��

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

	// ����ҡ�ˣ�aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
	static Joystick* create(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);

	// ��ȡҡ�˷���
	Vec2 getDirection();
	float getVelocity();   // ҡ������

private:
	double maxSpeed = 6;
	void update(float dt); 
	// ��ʼ����aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
	virtual bool init(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	Vec2 m_centerPoint;    // ҡ������
	Vec2 m_currentPoint;   // ҡ�˵�ǰλ��
	float m_radius;        // ҡ�˰뾶
	Sprite* m_jsSprite;    //ҡ�˿��Ƶ�
};

#endif
