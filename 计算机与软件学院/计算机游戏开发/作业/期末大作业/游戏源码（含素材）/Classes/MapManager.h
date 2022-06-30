#pragma once

#include "cocos2d.h"
#include "Global.h"
USING_NS_CC;
using namespace cocos2d;

#define MAP_WIDTH 60
#define MAP_HEIGHT 40
#define MAP_TILE_SIZE 16

class MapManager : public Node
{
public:
    static constexpr int Block_Access = 0,
        Block_Brick = 1,
        Block_Concrete = 2,
        Block_Water = 4,
        Block_Guard = 8;

    MapManager();
    ~MapManager();

    static MapManager* create(Node* parent, std::string tmxFile);
    virtual bool init(Node* parent, std::string tmxFile);

    static bool intersectsBlock(Rect rect, int type, Vec2* coordinate = nullptr);
    static void removeBlock(Vec2 coordinate);
    static void damageGuard();


    static int** block_map;  // 记录地形数据
    static std::list<Vec2> enemy_point_list;
    static Vec2 player_point;
    static Vec2 guard_point;
    
private:
    static TMXTiledMap* m_TMXTiledMap;
	static TMXLayer* m_TMXLayer;
    static TMXObjectGroup* m_TMXObjectGroup;
};