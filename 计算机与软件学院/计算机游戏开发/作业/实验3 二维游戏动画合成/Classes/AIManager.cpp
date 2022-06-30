#include "AIManager.h"

//************************************
// Method:    create
// FullName:  AIManager::create
// Access:    public static 
// Returns:   AIManager*
// Qualifier:
// Parameter: Node * parent
//************************************
AIManager* AIManager::create(Node* parent)
{
	AIManager* pRet = new(std::nothrow) AIManager();
	if (pRet && pRet->init(parent))
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

//************************************
// Method:    setAI
// FullName:  AIManager::setAI
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: Enemy * enemy
//************************************
void AIManager::setAI(Enemy* enemy, Hero* hero)
{
	m_enemy = enemy;
	m_hero = hero;
	this->scheduleUpdate();
	auto sss = Sequence::create(
		DelayTime::create(0.8f),
		CallFunc::create(CC_CALLBACK_0(AIManager::moveLeft, this)),
		DelayTime::create(1.0f),
		CallFunc::create(CC_CALLBACK_0(AIManager::attack, this)),
		DelayTime::create(0.3f),
		CallFunc::create(CC_CALLBACK_0(AIManager::moveRight, this)),
		DelayTime::create(1.0f),
		CallFunc::create(CC_CALLBACK_0(AIManager::stand, this)),
		DelayTime::create(0.5f),
		CallFunc::create(CC_CALLBACK_0(AIManager::attack, this)),
		NULL
		);
	auto act = RepeatForever::create(sss);
	this->runAction(act);
}

//************************************
// Method:    init
// FullName:  AIManager::init
// Access:    virtual private 
// Returns:   bool
// Qualifier:
// Parameter: Node * parent
//************************************
bool AIManager::init(Node* parent)
{
	if (!Node::init())
	{
		return false;
	}
	parent->addChild(this);

	return true;
}

//************************************
// Method:    update
// FullName:  AIManager::update
// Access:    private 
// Returns:   void
// Qualifier:
// Parameter: float delta
//************************************
void AIManager::update(float delta)
{
	// µÐÈË¶¯×÷
	if (m_enemy_state == State::STAND)
	{
		m_enemy->play(STAND);
	} else if (m_enemy_state == State::MOVELEFT)
	{
		m_enemy->play(MOVELEFT);
	} else if (m_enemy_state == State::MOVERIGHT)
	{
		m_enemy->play(MOVERIGHT);
	} else if (m_enemy_state == State::ATTACK)
	{
		m_enemy->play(ATTACK);
	}
}

//************************************
// Method:    AIManager
// FullName:  AIManager::AIManager
// Access:    public 
// Returns:   
// Qualifier:
//************************************
AIManager::AIManager()
{
	m_enemy_state = State::MOVELEFT;
}

//************************************
// Method:    ~AIManager
// FullName:  AIManager::~AIManager
// Access:    public 
// Returns:   
// Qualifier:
//************************************
AIManager::~AIManager()
{

}

//************************************
// Method:    moveLeft
// FullName:  AIManager::moveLeft
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void AIManager::moveLeft()
{
	m_enemy_state = MOVELEFT;
}

//************************************
// Method:    moveRight
// FullName:  AIManager::moveRight
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void AIManager::moveRight()
{
	m_enemy_state = State::MOVERIGHT;
}

//************************************
// Method:    attack
// FullName:  AIManager::attack
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void AIManager::attack()
{
	m_enemy_state = State::ATTACK;
}

//************************************
// Method:    stand
// FullName:  AIManager::stand
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void AIManager::stand()
{
	m_enemy_state = State::STAND;
}

