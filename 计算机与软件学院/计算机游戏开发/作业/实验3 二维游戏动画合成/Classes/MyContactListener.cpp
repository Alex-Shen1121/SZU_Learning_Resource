#include "MyContactListener.h"

//************************************
// Method:    ContactListener
// FullName:  ContactListener::ContactListener
// Access:    public 
// Returns:   
// Qualifier:
//************************************
MyContactListener::MyContactListener()
{

}

//************************************
// Method:    ~ContactListener
// FullName:  ContactListener::~ContactListener
// Access:    public 
// Returns:   
// Qualifier:
//************************************
MyContactListener::~MyContactListener()
{

}

//************************************
// Method:    init
// FullName:  ContactListener::init
// Access:    virtual public 
// Returns:   bool
// Qualifier:
//************************************
bool MyContactListener::init(Node* parent, Hero* hero, Enemy* enemy)
{
	if (!Node::init())
	{
		return false;
	}
	m_hero = hero;
	m_enemy = enemy;
	parent->addChild(this);
	this->scheduleUpdate();
	return true;
}

//************************************
// Method:    update
// FullName:  ContactListener::update
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float delta
//************************************
void MyContactListener::update(float delta)
{
	// hero ¹¥»÷ enemy
	Vec2 hero_p_1 = m_hero->getArmature()->getBone("Layer17")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,0));
	Vec2 hero_p_2 = m_hero->getArmature()->getBone("Layer17")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,15));
	Vec2 hero_p_3 = m_hero->getArmature()->getBone("Layer17")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,30));
	Vec2 hero_p_4 = m_hero->getArmature()->getBone("Layer17")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,50));
	Rect enemy_rec = Rect(m_enemy->getPositionX(),m_enemy->getPositionY() - 40, 20, 40);
	if (!m_enemy->isDeath() && m_hero->isAttack() && (enemy_rec.containsPoint(hero_p_1) || enemy_rec.containsPoint(hero_p_2) 
		|| enemy_rec.containsPoint(hero_p_3) || enemy_rec.containsPoint(hero_p_4)))
	{
		// CCLOG("attack....enemy....");
		m_enemy->hurt();
		m_hero->setAttack(false);
	}
	
	// enemy ¹¥»÷ hero
	Vec2 enemy_p_1 = m_enemy->getArmature()->getBone("ax")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,0));
	Vec2 enemy_p_2 = m_enemy->getArmature()->getBone("ax")->getDisplayRenderNode()->convertToWorldSpaceAR(Vec2(0,30));
	Rect hero_rec = Rect(m_hero->getPositionX() - 10,m_hero->getPositionY() - 20,20,40);
	if (!m_hero->isDeath() && m_enemy->isAttack() &&(hero_rec.containsPoint(enemy_p_1) || hero_rec.containsPoint(enemy_p_2)))
	{
		// CCLOG("attack...hero....");
		m_hero->hurt();
		m_enemy->setAttack(false);
	}
}

//************************************
// Method:    create
// FullName:  ContactListener::create
// Access:    public static 
// Returns:   ContactListener*
// Qualifier:
// Parameter: Hero * hero
// Parameter: Enemy * enemy
//************************************
MyContactListener* MyContactListener::create(Node* parent, Hero* hero, Enemy* enemy)
{
	MyContactListener *pRet = new(std::nothrow) MyContactListener();
	if (pRet && pRet->init(parent, hero, enemy))
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
