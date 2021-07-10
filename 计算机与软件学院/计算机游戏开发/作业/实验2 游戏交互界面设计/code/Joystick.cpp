#include "Joystick.h"
#include <cmath>

Joystick::Joystick()
{

}

Joystick::~Joystick()
{

}
// ��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
bool Joystick::init(Vec2 aPoint, float aRadius, char* aJsSprite, char* aJsBg)
{
	if (!Layer::init())
	{
		return false;
	}
	m_radius = aRadius;//ҡ�˰뾶
	m_centerPoint = aPoint;//ҡ�˿�������
	m_currentPoint = m_centerPoint;

	m_jsSprite = Sprite::create(aJsSprite);//ҡ�˿��Ƶ�
	m_jsSprite->setPosition(m_centerPoint);

	auto _aJsBg = Sprite::create(aJsBg);//ҡ�˱���
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
	Joystick* pRet = new(std::nothrow) Joystick();
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

// ��ȡҡ�˵�ǰ����
Vec2 Joystick::getDirection()
{	
	auto direction = m_currentPoint - m_centerPoint;
	return direction;	
}

// ��ȡҡ������
float Joystick::getVelocity()
{
	return maxSpeed / m_radius * m_centerPoint.getDistance(m_currentPoint);
}

// ����ҡ�˰�ťλ��
void Joystick::update(float dt)
{
	m_jsSprite->setPosition(m_jsSprite->getPosition() + (m_currentPoint - m_jsSprite->getPosition()) * 0.5);
}

bool Joystick::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	auto touchPoint = pTouch->getLocation();
	if (touchPoint.getDistance(m_centerPoint) > m_radius) {
		return false;
	}
	m_currentPoint = touchPoint;
	return true;
}

void Joystick::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	auto touchPoint = pTouch->getLocation();
	if (touchPoint.getDistance(m_centerPoint) > m_radius)
	{
		m_currentPoint = m_centerPoint + (touchPoint - m_centerPoint).getNormalized() * m_radius;
	}
	else {
		m_currentPoint = touchPoint;
	}
}

void Joystick::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	m_currentPoint = m_centerPoint;
}
