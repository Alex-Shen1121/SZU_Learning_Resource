#include "MapManager.h"

int** MapManager::block_map = nullptr;
std::list<Vec2> MapManager::enemy_point_list = std::list<Vec2>();
Vec2 MapManager::player_point = Vec2(0, 0);
Vec2 MapManager::guard_point = Vec2(0, 0);

TMXTiledMap* MapManager::m_TMXTiledMap = nullptr;
TMXLayer* MapManager::m_TMXLayer = nullptr;
TMXObjectGroup* MapManager::m_TMXObjectGroup = nullptr;

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
    if (block_map)
    {
        for (int i = 0; i < MAP_WIDTH; ++i)
            delete block_map[i];
        delete block_map;
    }
}

MapManager* MapManager::create(Node* parent, std::string tmxFile)
{
    MapManager* pRet = new(std::nothrow) MapManager();
    if (pRet && pRet->init(parent, tmxFile))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool MapManager::init(Node* parent, std::string tmxFile)
{
    if (!Node::init())
    {
        return false;
    }

    m_TMXTiledMap = TMXTiledMap::create(tmxFile);
    m_TMXLayer = m_TMXTiledMap->getLayer("back");
    m_TMXObjectGroup = m_TMXTiledMap->getObjectGroup("objects");
    parent->addChild(this);
    parent->addChild(m_TMXTiledMap, 16);

    // 玩家出生点
    auto obj = m_TMXObjectGroup->getObject("player_point");
    player_point = Vec2(obj["x"].asFloat(), obj["y"].asFloat());

    // 守护对象点
    obj = m_TMXObjectGroup->getObject("guard_point");
    guard_point = Vec2(obj["x"].asFloat(), obj["y"].asFloat());

    // 敌人出生点
    enemy_point_list.clear();
    for (int i = 1; (obj = m_TMXObjectGroup->getObject("enemy_point_" + Value(i).asString())).empty() == false; ++i)
    {
        enemy_point_list.push_back(Vec2(obj["x"].asFloat(), obj["y"].asFloat()));
    }

    block_map = new decltype(*block_map + 0)[MAP_WIDTH];
    for (int i = 0; i < MAP_WIDTH; ++i)
    {
        block_map[i] = new decltype(**block_map + 0)[MAP_HEIGHT];
        for (int j = 0; j < MAP_HEIGHT; ++j)
        {
            switch (m_TMXLayer->getTileGIDAt(Vec2(i, j)))
            {
            case 1:case 2:case 15:case 16:
                block_map[i][j] = Block_Brick;
                break;
            case 3:case 4:case 17:case 18:
                block_map[i][j] = Block_Concrete;
                break;
            case 7:case 8:case 9:case 10:
            case 21:case 22:case 23:case 24:
                block_map[i][j] = Block_Water;
                break;
            case 11:case 12:case 25:case 26:
                block_map[i][j] = Block_Guard;
                break;
            default:
                block_map[i][j] = Block_Access;
            }
        }
    }

    return true;
}

bool MapManager::intersectsBlock(Rect rect, int type, Vec2* coordinate)
{
    int min_x = rect.getMinX() / MAP_TILE_SIZE;
    int max_x = rect.getMaxX() / MAP_TILE_SIZE;
    int min_y = (MAP_TILE_SIZE * MAP_HEIGHT - rect.getMaxY()) / MAP_TILE_SIZE;
    int max_y = (MAP_TILE_SIZE * MAP_HEIGHT - rect.getMinY()) / MAP_TILE_SIZE;

    for (int i = min_x; i <= max_x; ++i)
        for (int j = min_y; j <= max_y; ++j)
        {
            if (i < MAP_WIDTH && j < MAP_HEIGHT && (block_map[i][j] & type) != 0)
            {
                if (coordinate)
                    *coordinate = Vec2(i, j);
                return true;
            }
        }
    return false;
}

void MapManager::removeBlock(Vec2 coordinate)
{
    int i = coordinate.x;
    int j = coordinate.y;
    block_map[i][j] = Block_Access;
    m_TMXLayer->removeTileAt(coordinate);
}

void MapManager::damageGuard()
{
    for (int i = 0; i < MAP_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_HEIGHT; ++j)
        {
            switch (m_TMXLayer->getTileGIDAt(Vec2(i, j)))
            {
            case 11:
                block_map[i][j] = 13;
                m_TMXLayer->setTileGID(block_map[i][j], Vec2(i, j));
                break;
            case 12:
                block_map[i][j] = 14;
                m_TMXLayer->setTileGID(block_map[i][j], Vec2(i, j));
                break;
            case 25:
                block_map[i][j] = 27;
                m_TMXLayer->setTileGID(block_map[i][j], Vec2(i, j));
                break;
            case 26:
                block_map[i][j] = 28;
                m_TMXLayer->setTileGID(block_map[i][j], Vec2(i, j));
                break;
            default:
                break;
            }
        }
    }
}