#ifndef __CONFIG_SET_H__
#define __CONFIG_SET_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;

enum State
{
	STAND,
	MOVELEFT,
	MOVERIGHT,
	ATTACK,
	DEATH,
	SMITTEN,
	DEFEND
};

#endif