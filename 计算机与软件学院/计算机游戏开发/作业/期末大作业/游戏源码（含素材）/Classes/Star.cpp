#include "Star.h"

Star::Star()
{

}

Star::~Star()
{

}

Star* Star::create(Vec2 position, int kind)
{
    Star* pRet = new(std::nothrow) Star();
    if (pRet && pRet->init(position, kind))
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

bool Star::init(Vec2 position, int kind)
{
    if (!BaseObject::init())
    {
        return false;
    }

    switch (kind)
    {
    case 1:
        m_sprite = Sprite::create("shield.png");
        break;
    case 2:
        m_sprite = Sprite::create("update.png");
        break;
    };
    
    m_sprite->setPosition(Vec2::ZERO);
    this->addChild(m_sprite);

    this->setName("Star");
    this->setID(0);
    this->setLife(1);
    this->setPosition(position);
    this->setDirection(DIR_NONE);
    this->setKind(kind);
    this->setSpeed(0);
    this->setRect(Rect(position.x - 8, position.y - 8, 16, 16));  // rect

    this->scheduleUpdate();

    return true;
}

void Star::update(float delta)
{
}

void Star::blast()
{
    this->setVisible(false);
    this->unscheduleUpdate();
}
