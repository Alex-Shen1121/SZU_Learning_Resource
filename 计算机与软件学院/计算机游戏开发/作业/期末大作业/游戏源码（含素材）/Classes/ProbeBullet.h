#pragma once

#include "cocos2d.h"
#include "Tank.h"
USING_NS_CC;
using namespace cocos2d;

class ProbeBullet : public BaseObject
{
public:
	ProbeBullet();
	~ProbeBullet();
	static ProbeBullet* create(Node *parent, Vec2 position, int dir, int id);

private:
	virtual bool init(Node *parent, Vec2 position, int dir, int id);
	void update(float delta);

};