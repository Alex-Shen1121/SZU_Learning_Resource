#ifndef __CONTACTLISTENER_H__
#define __CONTACTLISTENER_H__

#include "config_set.h"
#include "Hero.h"
#include "Enemy.h"

class MyContactListener : public Node
{
public:
	MyContactListener();
	~MyContactListener();

	static MyContactListener* create(Node* parent, Hero* hero, Enemy* enemy);
	virtual bool init(Node* parent, Hero* hero, Enemy* enemy);
	void update(float delta);

	// set and get
	Hero* getHero() { return m_hero; }
	void setHero(Hero* hero) { m_hero = hero; }

	Enemy* getEnemy() { return m_enemy; }
	void setEnemy(Enemy* enemy) { m_enemy = enemy; } 

private:
	Vector<Sprite*> m_contactList;
	Hero* m_hero;
	Enemy* m_enemy;
};

#endif