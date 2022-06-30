#include "Tank.h"
#include "BattleScene.h"
#include "MapManager.h"

Tank* Tank::create(int ID, float x, float y, int dir, int kind, int level)
{
	Tank* pRet = new(std::nothrow) Tank();
	if (pRet && pRet->init(ID, x, y, dir, kind, level))
	{
		pRet->autorelease();
		return pRet;
	} else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Tank::init(int ID, float x, float y, int dir, int kind, int level)
{
	if (!BaseObject::init())
	{
		return false;
	}

	this->setName("Tank");
	this->setLife(level);
	this->setSpeed(1);
	this->setLevel(level);
	this->setHindered(DIR_NONE);

	m_move = false;
	m_hurt = false;
	m_frametime = 0.0f;

	// tank init ifo
	setID(ID);
	this->setPositionX(x);
	this->setPositionY(y);
	setDirection(dir);
	setKind(kind);

	// tank kind
	if (kind == 1)
	{
		m_texture = Director::getInstance()->getTextureCache()->addImage("player1.png");
	}
	if (kind == 2)
	{
		m_texture = Director::getInstance()->getTextureCache()->addImage("player2.png");
	}

    m_sprite = Sprite::createWithTexture(m_texture, Rect(m_textureX - 14.0, m_textureY - 14.0, 28, 28));
    m_sprite->setScale(float(Tank_Size) / 28);
    this->addChild(m_sprite, 16);

	paint(0);

	this->setRect(Rect(this->getPositionX() - Tank_Size / 2, this->getPositionY() - Tank_Size / 2, Tank_Size, Tank_Size));

	this->scheduleUpdate();
	
	return true;
}

void Tank::update(float delta)
{

	if (this->getLife() <= 0)
	{
		this->blast();
	}

    if (m_move && this->getDirection() != this->getHindered())
    {
        if (this->getDirection() == DIR_UP)
        {
            setHindered(Tank_None);
            this->setPositionY(this->getPositionY() + this->getSpeed());
        }
        if (this->getDirection() == DIR_DOWN)
        {
            setHindered(Tank_None);
            this->setPositionY(this->getPositionY() - this->getSpeed());
        }
        if (this->getDirection() == DIR_LEFT)
        {
            setHindered(Tank_None);
            this->setPositionX(this->getPositionX() - this->getSpeed());
        }
        if (this->getDirection() == DIR_RIGHT)
        {
            setHindered(Tank_None);
            this->setPositionX(this->getPositionX() + this->getSpeed());
        }
    }
	
	paint(delta);

	this->setRect(Rect(this->getPositionX() - Tank_Size / 2, this->getPositionY() - Tank_Size / 2, Tank_Size, Tank_Size)); // 更新rect
}

void Tank::blink(float distance, int dir)
{
	if (dir == DIR_NONE)
		dir = this->getDirection();

	 int blockType = MapManager::Block_Brick | MapManager::Block_Concrete | MapManager::Block_Water | MapManager::Block_Guard;

	 while (distance > 0)
	 {
		 Rect rect = this->getRect();
		 setHindered(Tank_None);
		 if (dir == DIR_UP)
		 {
			 rect.setRect(rect.origin.x, rect.origin.y + distance,
				 rect.size.width, rect.size.height);
		 }
		 if (dir == DIR_DOWN)
		 {
			 rect.setRect(rect.origin.x, rect.origin.y - distance,
				 rect.size.width, rect.size.height);
		 }
		 if (dir == DIR_LEFT)
		 {
			 rect.setRect(rect.origin.x - distance, rect.origin.y,
				 rect.size.width, rect.size.height);
		 }
		 if (dir == DIR_RIGHT)
		 {
			 rect.setRect(rect.origin.x + distance, rect.origin.y,
				 rect.size.width, rect.size.height);
		 }
		 if (rect.getMinX() > 0
			 && rect.getMaxX() < MAP_WIDTH * MAP_TILE_SIZE
			 && rect.getMinY() > 0
			 && rect.getMaxY() < MAP_HEIGHT * MAP_TILE_SIZE
			 && !MapManager::intersectsBlock(rect, blockType))
		 {
			 setHindered(Tank_None);
			 this->setPosition(rect.getMidX(), rect.getMidY());
			 break;
		 }
		 else
			 distance -= 4;
	 }
}

void Tank::invincible(float time)
{
	if (this->getLife() <= this->getLevel())
	{
		this->setLife(999);
		auto func = [this]() -> void { this->setLife(this->getLevel()); };
		auto sequence = Sequence::create(
			DelayTime::create(time),
            CallFunc::create(func),
            NULL);
		this->runAction(sequence);

		auto tintToBlack = TintTo::create(0.20f, 20, 20, 20);
		auto tintToWhite = TintTo::create(0.20f, 127, 127, 127);
        auto tintBack = TintTo::create(0.20f, 255, 255, 255);
		auto s = Sequence::create(
			tintToBlack,
            tintBack,
            NULL);
		auto action = Repeat::create(s, (time - 0.2) / 0.4);
		sequence = Sequence::create(
			action,
            tintBack,
            NULL);
		m_sprite->runAction(sequence);
	}
}

void Tank::moveUp()
{
	m_move = true;
	this->setDirection(Tank_Up);
}

void Tank::moveDown()
{
	m_move = true;
	this->setDirection(Tank_Down);
}

void Tank::moveLeft()
{
	m_move = true;
	this->setDirection(Tank_Left);
}

void Tank::moveRight()
{
	m_move = true;
	this->setDirection(Tank_Right);
}

void Tank::stay(int dir)
{
	m_move = false;
	this->setDirection(dir);
}

void Tank::fire()
{
	Vec2 position;
	switch (this->getDirection())
	{
	case Tank_Up:
		position = Vec2(this->getPositionX(), this->getPositionY() + 14);
		break;
	case Tank_Down:
		position = Vec2(this->getPositionX(), this->getPositionY() - 14);
		break;
	case Tank_Left:
		position = Vec2(this->getPositionX() - 14, this->getPositionY());
		break;
	case Tank_Right:
		position = Vec2(this->getPositionX() + 14, this->getPositionY());
		break;
	}
	auto bullet = Bullet::create(position, 
		this->getLevel() >= 2 ? 5 : 3, // 速度
		this->getDirection(),
		this->getLevel() == 4 ? 3 : (this->getLevel() == 3 ? 2 : 1), // 种类
		this->getID(),
		this->getLevel() >= 3 ? 3 : 1); // 生命值
	BattleScene::addObeject(bullet, 32);
}

void Tank::hurt()
{
	this->setLife(this->getLife() - 1);
	if (this->getLife() < this->getLevel()) // 靠生命值判断是否显示受伤动作
	{
        auto tintToRed = TintTo ::create(0.05f, 255, 0, 0);
		auto tintBack = TintTo ::create(0.1f, 255, 255, 255);
        auto sequence = Sequence::create(
			tintToRed,
			tintBack,
			NULL);
		m_sprite->stopAllActions();
        m_sprite->runAction(sequence);
	}
}

void Tank::blast()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("music/explode.wav");
	this->setLife(0);

	this->setVisible(false);   // 坦克消失
	this->unscheduleUpdate();

	auto explode = Sprite::create("explode2.png");
	explode->setScale(0.75);
	this->getParent()->addChild(explode, 24);
	explode->setPosition(this->getPosition());  // 显示爆炸
	explode->runAction(Sequence::create(
		DelayTime::create(0.3f),
		FadeOut::create(0.3f),                  // 爆炸消失
		CallFunc::create(std::bind(&Sprite::removeFromParent, explode)),
		NULL
		));

	if (rand() % 4 + this->getLevel() >= 4) // 掉落率
	{
		Star* star = Star::create(this->getPosition(), rand() % 2 + 1);
		BattleScene::addObeject(star, 20);
	}
}

void Tank::paint(float delta)
{
    m_textureX = ((this->getLevel() - 1) * 4 + 1) * 14;   // get tank textureX

    // 控制坦克履带转动
    if (m_move)
    {
		m_texchange += delta;
        if (m_texchange > 0.05)
        {
            m_texchange = 0;
            static int  tex = (tex + 1) % 2;

            switch (tex)
            {
            case 0:
                m_textureX = ((this->getLevel() - 1) * 4 + 1) * 14;
                break;
            case 1:
                m_textureX = ((this->getLevel() - 1) * 4 + 1) * 14 + 2 * 14;
                break;
            }
        }
    }

    switch (getDirection())
    {
    case Tank_Up:
        m_textureY = 1 * 14;
        break;
    case Tank_Down:
        m_textureY = 5 * 14;
        break;
    case Tank_Left:
        m_textureY = 7 * 14;
        break;
    case Tank_Right:
        m_textureY = 3 * 14;
        break;
    }

	m_sprite->setTextureRect(Rect(m_textureX - 14.0, m_textureY - 14.0, 28, 28));
}
