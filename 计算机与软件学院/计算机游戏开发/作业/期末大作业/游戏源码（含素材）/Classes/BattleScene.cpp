#include "BattleScene.h"

std::list<BaseObject*> BattleScene::object_list = std::list<BaseObject*>();
Tank* BattleScene::player_tank = nullptr;

int BattleScene::player_life = 0;
int BattleScene::enemy_life = 0;
int BattleScene::guard_life = 0;
int BattleScene::enemy_left = 0;

BattleScene* BattleScene::object_manager = nullptr;
MapManager* BattleScene::map_manager = nullptr;

BattleScene::BattleScene()
{
}

BattleScene::~BattleScene()
{
}

BattleScene* BattleScene::create(int stage)
{
    BattleScene* pRet = new(std::nothrow) BattleScene();
    if (pRet && pRet->init(stage))
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

bool BattleScene::init(int stage)
{
    if (!Node::init())
    {
        return false;
    }

    Director::getInstance()->setProjection(Director::Projection::_2D); // 改为正交投影，避免图片模糊
    srand(time(NULL));
    object_list.clear();
    object_manager = this;


    // 关卡设置
    player_life = 3;
	enemy_life = level * 6;
    guard_life = 1;
    enemy_left = 0;
    std::string mapName;
    switch (stage)
    {
    default:
    case 1:
        mapName = "map1.tmx"; break;
    case 2:
        mapName = "map2.tmx"; break;
    case 3:
        mapName = "map3.tmx"; break;
    }
    map_manager = MapManager::create(this, mapName);

    // 玩家坦克
    player_tank = Tank::create(803, map_manager->player_point.x, map_manager->player_point.y, 1, 1, 1);
    this->addChild(player_tank);
    object_list.push_back(player_tank);

    // 碰撞检测
    this->scheduleUpdate();

    // 键盘事件
    auto key_listener = EventListenerKeyboard::create();
    key_listener->onKeyPressed = CC_CALLBACK_2(BattleScene::onKeyPressed, this);
    key_listener->onKeyReleased = CC_CALLBACK_2(BattleScene::onKeyReleased, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(key_listener, this);

    return true;
}

void BattleScene::update(float delta)
{
    //successOrFail(delta);

    for (auto i = object_list.begin(); i != object_list.end();)
    {
        if (!(*i)->isVisible())
        {
            if ((*i)->getName() == "Tank" && (*i)->getKind() == 2)
            {
                --enemy_left;
                player_score++;
            }
            if ((*i) != player_tank)
                (*i)->removeFromParent();
            i = object_list.erase(i);
        }
        else
            ++i;
    }

    // 物体与地图交互
    for (auto i = object_list.begin(); i != object_list.end(); ++i)
    {
        collideBlock(*i);
    }

    // 物体与物体交互
    for (auto i = object_list.begin(); i != object_list.end(); ++i)
    {
        for (auto j = object_list.begin(); j != object_list.end(); ++j)
        {
            if (i != j && (*i)->getRect().intersectsRect((*j)->getRect()))
            {
                collideObject((*i), (*j));
            }
        }
    }

    reinforce(delta);

}

void BattleScene::collideBlock(BaseObject* (&a))
{
    // 边界判断
    if (a->getPositionY() >= MAP_HEIGHT * MAP_TILE_SIZE - a->getRect().size.height / 2
        || a->getPositionY() <= a->getRect().size.height / 2
        || a->getPositionX() >= MAP_WIDTH * MAP_TILE_SIZE - a->getRect().size.width / 2
        || a->getPositionX() <= a->getRect().size.width / 2)
    {
        if (a->getName() == "Bullet")
        {
            Bullet* (&bullet) = (Bullet*&)a;
            bullet->blast();
        }
    }
    if (a->getName() == "Tank")
    {
        Tank* (&tank) = (Tank*&)a;
        if (a->getPositionY() >= MAP_HEIGHT * MAP_TILE_SIZE - a->getRect().size.height / 2)
        {
            tank->setHindered(DIR_UP);
            tank->setPositionY(tank->getPositionY() - tank->getSpeed());
        }
        if (a->getPositionY() <= a->getRect().size.height / 2)
        {
            tank->setHindered(DIR_DOWN);
            tank->setPositionY(tank->getPositionY() + tank->getSpeed());
        }
        if (a->getPositionX() >= MAP_WIDTH * MAP_TILE_SIZE - a->getRect().size.width / 2)
        {
            tank->setHindered(DIR_RIGHT);
            tank->setPositionX(tank->getPositionX() - tank->getSpeed());
        }
        if (a->getPositionX() <= a->getRect().size.width / 2)
        {
            tank->setHindered(DIR_LEFT);
            tank->setPositionX(tank->getPositionX() + tank->getSpeed());
        }
    }

    // 方块互动
    Vec2 coordinate;  // 互动方块坐标
    if (a->getName() == "Tank")
    {
        Tank* (&tank) = (Tank*&)a;
        int blockType = MapManager::Block_Brick | MapManager::Block_Concrete | MapManager::Block_Water | MapManager::Block_Guard;
        if (MapManager::intersectsBlock(tank->getRect(), blockType))
        {
            tank->setHindered(tank->getDirection());
            if (tank->getDirection() == DIR_UP) // 避免检测成功后坦克持续受阻，无法行动造成卡住
                tank->setPositionY(tank->getPositionY() - 2 * tank->getSpeed());
            if (tank->getDirection() == DIR_DOWN)
                tank->setPositionY(tank->getPositionY() + 2 * tank->getSpeed());
            if (tank->getDirection() == DIR_LEFT)
                tank->setPositionX(tank->getPositionX() + 2 * tank->getSpeed());
            if (tank->getDirection() == DIR_RIGHT)
                tank->setPositionX(tank->getPositionX() - 2 * tank->getSpeed());
        }
    }
    if (a->getName() == "Bullet")
    {
        Bullet* (&bullet) = (Bullet*&)a;
        int blockType = MapManager::Block_Brick;
        if (MapManager::intersectsBlock(bullet->getRect(), blockType, &coordinate))
        {
            bullet->blast();
            MapManager::removeBlock(coordinate);
        }
        blockType = MapManager::Block_Concrete;
        if (MapManager::intersectsBlock(bullet->getRect(), blockType, &coordinate))
        {
            bullet->blast();
            if (bullet->getKind() == 3)
                MapManager::removeBlock(coordinate);
        }
        blockType = MapManager::Block_Guard;
        if (MapManager::intersectsBlock(bullet->getRect(), blockType))
        {
            bullet->blast();
            --guard_life;
            MapManager::damageGuard();
        }
    }
}

void BattleScene::collideObject(BaseObject* (&a), BaseObject* (&b))
{
    std::string typeA = a->getName(), typeB = b->getName();
    if (typeA == "Tank" && typeB == "Tank")
    {
        Tank* (&tank) = (Tank*&)a;
        Tank* (&anotherTank) = (Tank*&)b;
        tank->stay(tank->getDirection());
        anotherTank->stay(anotherTank->getDirection());
        Vec2 v1 = Vec2(tank->getRect().getMidX(), tank->getRect().getMidY()),
            v2 = Vec2(anotherTank->getRect().getMidX(), anotherTank->getRect().getMidY());
        if (fabsf(v1.y - v2.y) > fabsf(v1.x - v2.x))
        {
            if (v1.y < v2.y)
            {
                tank->setPositionY(tank->getPositionY() - 2 * tank->getSpeed()); // 避免检测成功后坦克持续受阻，无法行动造成卡住
                anotherTank->setPositionY(anotherTank->getPositionY() + anotherTank->getSpeed());
            }
            else
            {
                tank->setPositionY(tank->getPositionY() + 2 * tank->getSpeed());
                anotherTank->setPositionY(anotherTank->getPositionY() - anotherTank->getSpeed());
            }
        }
        else
        {
            if (v1.x < v2.x)
            {
                tank->setPositionX(tank->getPositionX() - 2 * tank->getSpeed());
                anotherTank->setPositionX(anotherTank->getPositionX() + anotherTank->getSpeed());
            }
            else
            {
                tank->setPositionX(tank->getPositionX() + 2 * tank->getSpeed());
                anotherTank->setPositionX(anotherTank->getPositionX() - anotherTank->getSpeed());
            }
        }
    }
    if (typeA == "Bullet" && typeB == "Bullet")
    {
        Bullet* (&bullet) = (Bullet*&)a;
        Bullet* (&anotherBullet) = (Bullet*&)b;
        //if (bullet->getLevel() <= anotherBullet->getLevel())
            bullet->blast();
        //if (bullet->getLevel() >= anotherBullet->getLevel())
            anotherBullet->blast();
    }
    if (typeA == "Bullet" && typeB == "Tank")
    {
        Bullet* (&bullet) = (Bullet*&)a;
        Tank* (&tank) = (Tank*&)b;
        if (tank->getID() != bullet->getID())
        {
            bullet->setLife(bullet->getLife() - 1);
            tank->hurt();
        }
    }
    if (typeA == "Star" && typeB == "Tank")
    {
        Star* (&star) = (Star*&)a;
        Tank* (&tank) = (Tank*&)b;
        if (star->getKind() == 1)
        {
            if (tank->getLevel() < 4)
            {
                tank->setLevel(tank->getLevel() + 1);
                tank->setLife(tank->getLevel());
            }
        }
        else
        {
            tank->invincible(3.0f);
        }
        star->blast();
    }
}



void BattleScene::reinforce(float delta)
{
    static float interval = 0;
    interval += delta;
    if (interval < 1.0)
        return;
    interval = 0;

    if (player_tank->getLife() <= 0)
    {
        if (--player_life > 0)
        {
            player_tank->removeFromParent();
            player_tank = Tank::create(player_tank->getID(),
                MapManager::player_point.x, MapManager::player_point.y,
                DIR_UP,
                1, // 种类
                player_tank->getLevel() > 1 ? player_tank->getLevel() - 1 : 1); // 等级
            addObeject(player_tank, 8);

            player_tank->invincible(2.0f); // 无敌时间
        }
    }

    if (enemy_left < 4 && enemy_life > 0)
    {
        ++enemy_left;
        --enemy_life;

        Vec2 spawn = Vec2(MAP_WIDTH * MAP_TILE_SIZE / 2, MAP_HEIGHT * MAP_TILE_SIZE / 2);
        if (!MapManager::enemy_point_list.empty())
        {
            static int p = 0;
            p = (p + 1) % MapManager::enemy_point_list.size();
            //int t = rand() % MapManager::enemy_point_list.size() + 1;
            auto it = MapManager::enemy_point_list.begin();
            for (int i = 0; i < p; ++i)
                ++it;
            spawn = *it;
        }
        Tank* tank = Tank::create(enemy_life,
            spawn.x, spawn.y,
            DIR_DOWN, // 方向
            2, // 种类
            rand() % 3 + 1); // 等级
        addObeject(tank, 8);
        TankAI* ai = TankAI::create(tank);

        tank->invincible(2.0f);
    }
}

void BattleScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        if (player_tank)
            player_tank->moveLeft();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
        if (player_tank)
            player_tank->moveUp();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
        if (player_tank)
            player_tank->moveDown();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        if (player_tank)
            player_tank->moveRight();
        break;
    }
}

void BattleScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        if (player_tank->getLife() > 0 && player_tank->getDirection() == DIR_LEFT)
            player_tank->stay(DIR_LEFT);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
        if (player_tank->getLife() > 0 && player_tank->getDirection() == DIR_UP)
            player_tank->stay(DIR_UP);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
        if (player_tank->getLife() > 0 && player_tank->getDirection() == DIR_DOWN)
            player_tank->stay(DIR_DOWN);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        if (player_tank->getLife() > 0 && player_tank->getDirection() == DIR_RIGHT)
            player_tank->stay(DIR_RIGHT);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_K:
        if (player_tank->getLife() > 0)
            player_tank->fire();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_P:
        if (player_tank->getLife() > 0)
            player_tank->blink(64);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_O:
        if (player_tank->getLife() > 0)
            player_tank->invincible(5.0f);
        break;
    }
}

void BattleScene::addObeject(BaseObject* obj, int zOrder)
{
    object_manager->addChild(obj, zOrder);
    object_list.push_back(obj);
}


