#include "GameManager.h"
#include "Config.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	m_gameManager = NULL;
}

bool GameManager::init()
{
	return true;
}

GameManager* GameManager::m_gameManager = NULL;
GameManager* GameManager::getInstance()
{
	if (m_gameManager == NULL)
	{
		m_gameManager = new GameManager();
		m_gameManager->init();
	}
	return m_gameManager;
}

Vec2 GameManager::getMapPosition(TMXTiledMap* map, Node* node)
{
	// 玩家相对于屏幕的坐标
	float px = node->getPositionX();
	float py = node->getPositionY()-node->getContentSize().height/2;

	// 地图相对于屏幕的x坐标
	float mx = abs(map->getPositionX());

	float my = 0;

	// 玩家相对于地图的坐标

	return Vec2(px + mx, py + my);
}

int GameManager::getTileID(TMXTiledMap* map, Node* node)
{
	Vec2 current = getMapPosition(map, node);
	return map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(Vec2((int)(current.x/map->getTileSize().width),(int)(map->getMapSize().height-1-current.y/map->getTileSize().height)));
}
