#include "Joystick.h"

Joystick::Joystick()
{

}

Joystick::~Joystick()
{

}

bool Joystick::init(Vec2 aPoint , float aRadius , char* aJsSprite, char* aJsBg)
{
	if (!Layer::init())
	{
		return false;
	}
	m_radius = aRadius;
	m_centerPoint = aPoint;
	m_currentPoint = m_centerPoint;

	m_jsSprite = Sprite::create(aJsSprite);
	m_jsSprite->setPosition(m_centerPoint);

	auto _aJsBg = Sprite::create(aJsBg);
	_aJsBg->setPosition(m_centerPoint);
	_aJsBg->setTag(88);
	this->addChild(_aJsBg);
	this->addChild(m_jsSprite);
	this->scheduleUpdate(); 

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Joystick::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

Joystick* Joystick::create(Vec2 aPoint, float aRadius, char* aJsSprite, char* aJsBg)
{
	Joystick *pRet = new(std::nothrow) Joystick();
	if (pRet && pRet->init(aPoint, aRadius, aJsSprite, aJsBg)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

// 获取摇杆当前方向
Joystick_dir Joystick::getDirection()
{
	if ((m_currentPoint - m_centerPoint).x > 0)
	{
		return Joystick_dir::_RIGHT;
	} else if ((m_currentPoint - m_centerPoint).x < 0)
	{
		return Joystick_dir::_LEFT;
	} 

	return Joystick_dir::_STOP;
}

// 获取摇杆力度
float Joystick::getVelocity()
{
	return m_centerPoint.getDistance(m_currentPoint);
}

// 更新摇杆按钮位置
void Joystick::update(float dt)
{
	m_jsSprite->setPosition(m_jsSprite->getPosition() + (m_currentPoint - m_jsSprite->getPosition()) * 0.5);
}

bool Joystick::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	auto touchPoint = pTouch->getLocation();
	if (touchPoint.getDistance(m_centerPoint) > m_radius){
		return false;
	}
	m_currentPoint = touchPoint;
	return true;
}

void Joystick::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	auto touchPoint = pTouch->getLocation();
	if (touchPoint.getDistance(m_centerPoint) > m_radius)
	{
		m_currentPoint = m_centerPoint + (touchPoint - m_centerPoint).getNormalized() * m_radius;
	}else {
		m_currentPoint = touchPoint;
	}
}

void Joystick::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	m_currentPoint = m_centerPoint;
}
