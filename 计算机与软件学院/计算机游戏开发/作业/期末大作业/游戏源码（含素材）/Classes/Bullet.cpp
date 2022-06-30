#include "Bullet.h"
#include "MapManager.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

Bullet* Bullet::create(Vec2 position, float speed, int dir, int kind, int id, int life)
{
    Bullet* pRet = new(std::nothrow) Bullet();
    if (pRet && pRet->init(position, speed, dir, kind, id, life))
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

bool Bullet::init(Vec2 position, float speed, int dir, int kind, int id, int life)
{
    if (!BaseObject::init())
    {
        return false;
    }

    this->setName("Bullet");

    if (kind == 3)
        m_texture = Director::getInstance()->getTextureCache()->addImage("bullet3.png");
    else if(kind == 2)
        m_texture = Director::getInstance()->getTextureCache()->addImage("bullet2.png");
    else
        m_texture = Director::getInstance()->getTextureCache()->addImage("bullet1.png");

    switch (dir)
    {
    case BULLET_UP:
        m_sprite = Sprite::createWithTexture(m_texture, Rect(0, 0, 8, 8));
        break;
    case BULLET_DOWN:
        m_sprite = Sprite::createWithTexture(m_texture, Rect(8 * 2, 0, 8, 8));
        break;
    case BULLET_LEFT:
        m_sprite = Sprite::createWithTexture(m_texture, Rect(8 * 3, 0, 8, 8));
        break;
    default:
    case BULLET_RIGHT:
        m_sprite = Sprite::createWithTexture(m_texture, Rect(8, 0, 8, 8));
        break;
    }

    m_sprite->setPosition(Vec2::ZERO);
    this->addChild(m_sprite);

    this->setID(id);
    this->setLife(life);
    this->setPosition(position);
    this->setDirection(dir);
    this->setKind(kind);
    this->setSpeed(speed);
    this->setRect(Rect(position.x - 4, position.y - 4, 8, 8));  // rect

    this->scheduleUpdate();

    return true;
}

void Bullet::update(float delta)
{
    if (this->getLife() <= 0)
    {
        this->blast();
    }

    if (this->getDirection() == BULLET_UP)
    {
        this->setPositionY(this->getPositionY() + this->getSpeed());
    }
    if (this->getDirection() == BULLET_DOWN)
    {
        this->setPositionY(this->getPositionY() - this->getSpeed());
    }
    if (this->getDirection() == BULLET_LEFT)
    {
        this->setPositionX(this->getPositionX() - this->getSpeed());
    }
    if (this->getDirection() == BULLET_RIGHT)
    {
        this->setPositionX(this->getPositionX() + this->getSpeed());
    }

    this->setRect(Rect(getPositionX() - 4, getPositionY() - 4, 8, 8)); // 更新rect
}

void Bullet::blast()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("music/hitWall.wav");

    this->setVisible(false);   // 子弹消失
    this->unscheduleUpdate();

    auto explode = Sprite::create("explode1.png");
    this->getParent()->addChild(explode, 20);
    explode->setPosition(this->getPosition());  // 显示爆炸
    explode->runAction(Sequence::create(
        DelayTime::create(0.1f),
        FadeOut::create(0.1f),                   // 爆炸消失
        CallFunc::create(std::bind(&Sprite::removeFromParent, explode)),
        NULL
    ));
}
