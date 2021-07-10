#pragma once
#include "cocos2d.h"
#include "BattleScene.h"
#include "Interface.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
using namespace CocosDenshion;

class storyscene : public Scene
{
public:
	storyscene();
	~storyscene();
	static storyscene* create();
	bool init();
	void start();
};