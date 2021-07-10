#ifndef __AIMANAGER_H__
#define __AIMANAGER_H__

#include "config_set.h"
#include "Enemy.h"
#include "Hero.h"
class AIManager : public Node
{
public:
	AIManager();
	~AIManager();

	static AIManager* create(Node* parent);
	void setAI(Enemy* enemy, Hero* hero);

	void moveLeft();
	void moveRight();
	void attack();
	void stand();

private:
	virtual bool init(Node* parent);
	void update(float delta);

private:
	Enemy* m_enemy;
	Hero* m_hero;

	State m_enemy_state; 
};

#endif