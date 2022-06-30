// ��6������2 -- �ۺ϶�������

#ifndef __ANIMATION_SCENE_H__
#define __ANIMATION_SCENE_H__

#include "config_set.h"
#include "Joystick.h"
#include "Hero.h"
#include "Enemy.h"
#include "MyContactListener.h"
#include "AIManager.h"

class AnimationScene : public Layer
{
public:
	AnimationScene();
	~AnimationScene();
	virtual bool init();
	CREATE_FUNC(AnimationScene);
	static Scene* createScene();

	void update(float delta);

	void attackCallback(Ref* pSender);
	void defendCallback(Ref* pSender);
	void menuReplayCallback(Ref* pSender);
	
private:
	Joystick* m_joystick;   // ҡ��
	MyContactListener* m_contactListener;  // ��ײ���
	AIManager* m_aimanager;  // AI manager

	Hero* m_player;
	Enemy* m_enemy;
	Label* scoreboard;

	Sprite* m_bloodBar_h;
	Sprite* m_bloodBar_e;
};

#endif