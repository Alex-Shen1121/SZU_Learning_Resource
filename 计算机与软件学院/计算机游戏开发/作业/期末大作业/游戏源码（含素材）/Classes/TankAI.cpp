#include "TankAI.h"
#include "BattleScene.h"
#include "JumpPointSearch.h"
#include "ProbeBullet.h"

TankAI::TankAI()
{
}

TankAI::~TankAI()
{
}

TankAI* TankAI::create(Node *parent)
{
	TankAI* pRet = new(std::nothrow) TankAI();
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

bool TankAI::init(Node *parent)
{
	if (!Node::init())
	{
		return false;
	}

	parent->addChild(this);
	m_tank = (Tank*)parent;
	m_position = Vec2(0, 0);
	
	m_attack = Attack_Positive;
	m_move = Move_Wander;
	m_probe = DIR_NONE;


    m_prepare_fire = 0;
	m_attack_interval = 0;
    m_move_interval = 0;
    m_trace_interval = 0;

	this->scheduleUpdate();

	m_draw = DrawNode::create();
	m_tank->getParent()->addChild(m_draw, 64);

	return true;
}

void TankAI::update(float delta)
{
	if (m_tank->getLife() <= 0)
	{
		m_draw->removeFromParent();
		this->unscheduleUpdate();
		return;
	}

	probe(delta);

	// 根据已有信息改变AI姿态
	if (m_attack_interval > 2.0)
	{
		settingNewCourse();
		m_attack_interval = 0;
	}

	if (m_probe > 0)
	{
		m_draw->clear();
		m_move = Move_Stand;
		m_tank->stay(m_probe);
	}
	if (m_attack_interval == 0 && m_move == Move_Stand)
	{
		m_draw->clear();
		m_move = Move_Wander;
	}

	if (m_move == Move_Trace && (m_path.empty() || m_trace_interval > 3.0))
	{
		m_trace_interval = 0;
		m_draw->clear();
		m_move = Move_Wander;
	}

	if (m_move == Move_Trace)
		m_attack = Attack_Passive;
	else
		m_attack = Attack_Positive;

	attack(delta);
	move(delta);
}

void TankAI::move(float delta)
{
	m_trace_interval += delta;
	m_move_interval += delta;
    if (m_tank->isMoving())
        m_move_interval = 0;

	if (m_move == Move_Stand)
	{
		if (m_probe > 0)
			m_tank->stay(m_probe);
	}

	// 路径移动
	if (m_move == Move_Trace)
	{
		if (!m_path.empty())
		{
			Vec2 start = m_tank->getPosition();
			Vec2 end = m_path.back();
			constexpr float delta = 0.5; // 移动不连续，接近一定距离就行
			if (start.x <= end.x - delta)
			{
				if (m_tank->getHindered() != DIR_RIGHT)
					m_tank->moveRight();
				else
					m_path.push_back(Vec2(start.x, end.y));
            }
            else if (start.y <= end.y - delta)
            {
                if (m_tank->getHindered() != DIR_UP)
                    m_tank->moveUp();
				else
					m_path.push_back(Vec2(end.x, start.y));
            }
            else if (start.x >= end.x + delta)
            {
                if (m_tank->getHindered() != DIR_LEFT)
                    m_tank->moveLeft();
				else
					m_path.push_back(Vec2(start.x, end.y));
            }
            else if (start.y >= end.y + delta)
            {
                if (m_tank->getHindered() != DIR_DOWN)
                    m_tank->moveDown();
				else
					m_path.push_back(Vec2(end.x, start.y));
            }
            else if (m_trace_interval > 0.10)
            {
				m_trace_interval = 0;
                m_path.pop_back();
                m_tank->stay(m_tank->getDirection());
            }
            else
            {
                m_trace_interval = 0;
                m_draw->clear();
                m_move = Move_Wander;
			}
		}
	}

	// 随机移动
	if (m_move == Move_Wander)
	{
        int hinder = m_tank->getHindered();
        switch (hinder)
        {
        case DIR_UP:m_tank->moveRight(); break;
        case DIR_RIGHT:m_tank->moveDown(); break;
        case  DIR_DOWN:m_tank->moveLeft(); break;
        case DIR_LEFT:m_tank->moveUp(); break;
        default:
            if (!m_tank->isMoving())
            {
                switch (rand() % 4 + 1)
                {
                case 1:m_tank->moveUp(); break;
                case 2:m_tank->moveDown(); break;
                case 3:m_tank->moveLeft(); break;
                case 4:m_tank->moveRight(); break;
                }
            }
        }
	}
}

void TankAI::attack(float delta)
{
	m_attack_interval += delta;
	if (m_attack != Attack_Disable)
	{
		m_probe_interval += delta;
		if (m_probe_interval > 1.0)
			m_probe = Probe_Ready;

		// 攻击敌人
		if (m_probe > 0)
		{
			m_prepare_fire += delta;
			if (m_prepare_fire > 0.5)
			{
				m_tank->fire();
				m_prepare_fire = 0;
				m_attack_interval = 0;
				m_probe = Probe_Ready;
			}
		}

		// 探测敌人
		if (m_probe == Probe_Ready)
		{
			m_probe_interval = 0;
			if (m_attack == Attack_Passive)
			{
				m_probe = -1;
				ProbeBullet* bullet = ProbeBullet::create(this, Vec2(0, 0), m_tank->getDirection(), m_tank->getID());
				m_list.push_back(bullet);
			}
			if (m_attack == Attack_Positive)
			{
				m_probe = -4;
				ProbeBullet* bullet = ProbeBullet::create(this, Vec2(0, 0), Probe_Up, m_tank->getID());
				m_list.push_back(bullet);
				bullet = ProbeBullet::create(this, Vec2(0, 0), Probe_Down, m_tank->getID());
				m_list.push_back(bullet);
				bullet = ProbeBullet::create(this, Vec2(0, 0), Probe_Left, m_tank->getID());
				m_list.push_back(bullet);
				bullet = ProbeBullet::create(this, Vec2(0, 0), Probe_Right, m_tank->getID());
				m_list.push_back(bullet);
			}
		}
	}
}

void TankAI::settingNewCourse()
{
	if (JumpPointSearch::solve(m_tank->getPosition(), MapManager::guard_point, m_path))
	{
        m_move = Move_Trace;
	}
	else if (BattleScene::player_tank && JumpPointSearch::solve(m_tank->getPosition(), BattleScene::player_tank->getPosition(), m_path))
	{
        m_move = Move_Trace;
	}
	else
	{
		m_draw->clear();
		m_move = Move_Wander;
	}

	if (!m_path.empty())
	{
        m_draw->clear();
        auto i = m_path.begin();
        auto j = i; ++j;
        while (j != m_path.end())
        {
            m_draw->drawLine(*i, *j, Color4F(1.0, 1.0, 1.0, 1.0));
            ++i;
            ++j;
        }
	}
}

void TankAI::probe(float delta)
{
	for (auto i = m_list.begin(); i != m_list.end();)
	{
		if (!(*i)->isVisible())
		{
			(*i)->removeFromParent();
			i = m_list.erase(i);
		}
		else
			++i;
	}

    if (m_list.empty() && m_probe < 0)
        m_probe = Probe_Ready;

    for (auto i = m_list.begin(); i != m_list.end(); ++i)
    {
		Rect rect = (*i)->getRect();
		rect.setRect(rect.origin.x + m_tank->getPositionX(),
			rect.origin.y + m_tank->getPositionY(),
			rect.size.width, rect.size.height);

		// 边界判断
        if (rect.getMidY() >= MAP_HEIGHT * MAP_TILE_SIZE - rect.size.height / 2
            || rect.getMidY() <= rect.size.height / 2
            || rect.getMidX() >= MAP_WIDTH * MAP_TILE_SIZE - rect.size.width / 2
            || rect.getMidX() <= rect.size.width / 2)
        {
			(*i)->setVisible(false);
			continue;
        }

        int blockType = MapManager::Block_Concrete;
        if (MapManager::intersectsBlock(rect, blockType))
        {
			if (m_tank->getLevel() != 4)
				(*i)->setVisible(false);
        }
		blockType = MapManager::Block_Guard;
		if (MapManager::intersectsBlock(rect, blockType))
        {
            m_probe = (*i)->getDirection();
			(*i)->setVisible(false);
		}

        for (auto j = BattleScene::object_list.begin(); j != BattleScene::object_list.end(); ++j)
        {
            if (rect.intersectsRect((*j)->getRect()) && (*j)->getName() == "Tank")
            {
				Tank* tank = (Tank*)(*j);
				if (tank->getKind() != m_tank->getKind())
				{
					m_probe = (*i)->getDirection();
				}
				if (tank->getID() != m_tank->getID())
					(*i)->setVisible(false);
            }
        }
    }
}
