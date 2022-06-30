#pragma once

#include "cocos2d.h"
#include "Global.h"
#include "MapManager.h"
#include "TankAI.h"
#include "Score.h"
USING_NS_CC;
using namespace cocos2d;

class BattleScene : public Scene
    {
public:
    BattleScene();
    ~BattleScene();
    
    static BattleScene* create(int stage = 1);
    virtual bool init(int stage);

    static void addObeject(BaseObject *obj, int zOrder);

    static std::list<BaseObject*> object_list;
    static Tank* player_tank;


    static int player_life;
    static int enemy_life;
    static int guard_life;
    static int enemy_left;
    
private:
    static BattleScene* object_manager;
    static MapManager* map_manager;

    void update(float delta);
    void collideObject(BaseObject* (&a), BaseObject* (&b));
    void collideBlock(BaseObject* (&a));
    void reinforce(float delta);     // 复活玩家，敌人增援

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

};