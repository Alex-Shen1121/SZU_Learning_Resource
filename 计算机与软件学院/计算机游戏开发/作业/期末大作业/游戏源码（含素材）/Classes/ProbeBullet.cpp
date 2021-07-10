#include "ProbeBullet.h"
#include "MapManager.h"
#include "TankAI.h"

ProbeBullet::ProbeBullet()
{

}

ProbeBullet::~ProbeBullet()
{

}

ProbeBullet* ProbeBullet::create(Node *parent, Vec2 position, int dir, int id)
{
	ProbeBullet* pRet = new(std::nothrow) ProbeBullet();
	if (pRet && pRet->init(parent, position, dir, id))
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

bool ProbeBullet::init(Node *parent, Vec2 position, int dir, int id)
{
	if (!BaseObject::init())
	{
		return false;
	}
	parent->addChild(this);
    this->setName("ProbeBullet");
    this->setID(id);
	this->setLife(1);
	this->setPosition(position);
	this->setDirection(dir);
	this->setKind(0);
	this->setSpeed(8);
	this->scheduleUpdate();
	this->setRect(Rect(position.x - 4, position.y - 4, 8, 8));  // rect
	return true;
}

void ProbeBullet::update(float delta)
{
    if (this->getDirection() == DIR_UP)
    {
        this->setPositionY(this->getPositionY() + this->getSpeed());
    }
    if (this->getDirection() == DIR_DOWN)
    {
        this->setPositionY(this->getPositionY() - this->getSpeed());
    }
    if (this->getDirection() == DIR_LEFT)
    {
        this->setPositionX(this->getPositionX() - this->getSpeed());
    }
    if (this->getDirection() == DIR_RIGHT)
    {
        this->setPositionX(this->getPositionX() + this->getSpeed());
    }

    this->setRect(Rect(getPositionX() - 4, getPositionY() - 4, 8, 8)); // ¸üÐÂrect
}


