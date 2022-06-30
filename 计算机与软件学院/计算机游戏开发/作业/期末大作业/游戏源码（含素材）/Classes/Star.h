#pragma once

#include "cocos2d.h"
#include "Global.h"
#include "BaseObject.h"
USING_NS_CC;
using namespace cocos2d;

class Star : public BaseObject
{
public:
	Star();
	~Star();
	static Star* create(Vec2 position, int kind);

	void blast();

private:
	virtual bool init(Vec2 position, int kind);
	void update(float delta);

private:
	Sprite*     m_sprite;       // Í¼Æ¬¾«Áé
};
