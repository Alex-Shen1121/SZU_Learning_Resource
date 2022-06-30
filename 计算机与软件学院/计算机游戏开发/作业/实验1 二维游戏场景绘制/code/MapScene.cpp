#include "MapScene.h"

Scene* MapScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MapScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MapScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	m_isJump = false;
	m_jumpDir = Dir::STOP;
	m_jumpSpeed = PLAYER_JUMP_SPEED;
	m_gameOver = false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 加载地图
	loadMap(MAP_TMX_FILE_PATH);

	// 添加玩家
	addPlayer(Vec2(80,40));

	// 游戏逻辑
	this->scheduleUpdate();

	// 添加触屏侦听
	addTouchListener();

	return true;
}

void MapScene::update(float t)
{
	auto player = this->getChildByTag(PLAYER_TAG);
	auto map = (TMXTiledMap *)getChildByTag(MAP_TAG);

	// 玩家相对于屏幕的坐标
	float player_screen_x = player->getPositionX();
	float player_screen_y = player->getPositionY()-player->getContentSize().height/2;

	// 地图相对于屏幕的x坐标
	float map_screen_x = abs(map->getPositionX());
	float map_screen_y = 0;

	// 玩家相对于地图的坐标
	float player_map_x = player_screen_x + map_screen_x;
	float player_map_y = player_screen_y + map_screen_y; 
	if ((int)(player_map_y / map->getTileSize().width) >= 0) {
		int frontTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(Vec2((int)(player_map_x / map->getTileSize().width), (int)(map->getMapSize().height - 2 - player_map_y / map->getTileSize().height)));
		if ((m_isJump == false) && (m_jumpDir == Dir::STOP) && ((frontTiledID == 40) || (frontTiledID == 151) || (frontTiledID == 170) || (frontTiledID == 67) || (frontTiledID == 8))) {
			return;
		}
	}
	// 不跳动时遇到非地面图块自动下落
	if((int)(player_map_y / map->getTileSize().width) >= 0)
	{
		int playerTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(Vec2((int)(player_map_x/map->getTileSize().width),(int)(map->getMapSize().height-1-player_map_y/map->getTileSize().height)));
		if ((m_isJump == false)&&(m_jumpDir == Dir::STOP)&& (playerTiledID != 8) && (playerTiledID != 7) 
			&& (playerTiledID != 151) && (playerTiledID != 170) && (playerTiledID != 171) && (playerTiledID != 172) && (playerTiledID != 149) && (playerTiledID != 133)) {
				m_isJump = true;
				m_jumpDir = Dir::DOWN;
				m_jumpSpeed = 2;
		}
	}

	// 处理玩家的跳跃
	if (m_isJump) {
		if (m_jumpDir == Dir::UP) {
			player->setPositionY(player->getPositionY() + m_jumpSpeed);
			m_jumpSpeed -= 2;
			if(m_jumpSpeed <= 0)
			{
				m_jumpDir = Dir::DOWN;
			}
		}else if(m_jumpDir == Dir::DOWN)
		{
			// 用于记录玩家是否落到地面上
			bool check = false;

			for (int i = 0; i < m_jumpSpeed; i += 2) {

				// 计算当前玩家相对于地图的坐标
				float player_screen_x = player->getPositionX();
				float player_screen_y = player->getPositionY()-player->getContentSize().height/2 + i;

				// 地图相对于屏幕的x坐标
				float map_screen_x = abs(map->getPositionX()); 
				float map_screen_y = 0;

				// 玩家相对于地图的坐标
				float player_map_x = player_screen_x + map_screen_x; 
				float player_map_y = player_screen_y + map_screen_y;

				// 获取玩家脚下的地图块的编号
				if (player_map_y/map->getTileSize().width >= 0) {

					int tiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(Vec2((int)(player_map_x/map->getTileSize().width),(int)(map->getMapSize().height - 1 - player_map_y/map->getTileSize().height)));
					if (tiledID == 8 || tiledID == 7 || tiledID == 151 || tiledID == 170 || tiledID == 171 || tiledID == 172 || tiledID == 149 || tiledID == 133) {
						check = true; 
						player->setPositionY((int)(player_screen_y + player->getContentSize().height/2 - 6));
						m_jumpSpeed = PLAYER_JUMP_SPEED;
						m_jumpDir = Dir::STOP;
						m_isJump = false;
						break;
					}
				}

				if (player_screen_y <= -80) {
					gameOver();  // 角色死亡
				}
			}
			if(!check)
			{
				player->setPositionY(player->getPositionY() - m_jumpSpeed);
				m_jumpSpeed += 2;
				if(m_jumpSpeed > PLAYER_JUMP_SPEED)
				{  
					m_jumpSpeed = PLAYER_JUMP_SPEED;
				}
			}
		}
	}

	this->getChildByTag(MAP_TAG)->setPositionX(this->getChildByTag(MAP_TAG)->getPositionX()-3);
	// 滚动背景地图
	int mapWidth = map->getMapSize().width*map->getTileSize().width;
	int visibleWidth = Director::getInstance()->getWinSize().width;
	if(map->getPositionX() < -(mapWidth-visibleWidth))  
	{
		map->setPositionX(-(mapWidth-visibleWidth));
		// 地图静止后移动角色	
		player->setPositionX(player->getPositionX() + 3);
		if(player->getPositionX() > visibleWidth )
		{
			player->setPositionX(visibleWidth );
			this->unscheduleUpdate();
			this->removeChildByTag(PLAYER_TAG);
			success(); 
			return;
		}
	}
}

void MapScene::gameOver()
{
	this->unscheduleUpdate();

	auto tips = Label::createWithBMFont(TIPS_FNT_PATH,GAME_OVER_TIPS);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	tips->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	this->addChild(tips,10);
}

void MapScene::addPlayer(Vec2 pos)
{
	// 玩家跑动动画
	Vector<SpriteFrame* >frameVector;
	for(int i=0;i<4;i++)
	{
		auto spriteFrame = SpriteFrame::create(PLAYER_IMG_PATH[i], Rect(0,0,PLAYER_WIDTH,PLAYER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.07f);
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(PLAYER_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player,10);
	player->setPosition(pos);
}

void MapScene::loadMap(std::string mapPath)
{
	// 加载地图
	auto map = TMXTiledMap::create(mapPath);
	if (map != NULL)
	{
		this->addChild(map,2);
		map->setTag(MAP_TAG);
		map->setPosition(Vec2(0, 0));
	} else
	{
		CCLOG("load map failed!");
		return ;
	}
}

void MapScene::addTouchListener()
{
	// 加入触摸的处理
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MapScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void MapScene::success()
{
	auto tips = Label::createWithBMFont(TIPS_FNT_PATH,GAME_SUCCESS);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	tips->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	this->addChild(tips,10);
}

bool MapScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (!this->m_isJump) { 
		m_isJump = true;
		m_jumpDir = Dir::UP; 
	}
	return true;
}
