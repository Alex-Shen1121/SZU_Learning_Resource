#pragma once

#include "cocos2d.h"
#include "MapManager.h"
#include "Tank.h"
#include "ProbeBullet.h"

USING_NS_CC;
using namespace cocos2d;

class TankAI : public Node
{
public:
    static constexpr int Attack_Disable = 0;
    static constexpr int Attack_Passive = 1;
    static constexpr int Attack_Positive = 2;

    static constexpr int Move_Stand = 0;
    static constexpr int Move_Wander = 1;
    static constexpr int Move_Trace = 2;

    static constexpr int Probe_Ready = 0;
    static constexpr int Probe_Up = 1;
    static constexpr int Probe_Down = 2;
    static constexpr int Probe_Left = 3;
    static constexpr int Probe_Right = 4;

    TankAI();
    ~TankAI();

    static TankAI* create(Node *parent);
    virtual bool init(Node *parent);
    void update(float delta);

    void settingNewCourse();
    int getProbe() { return m_probe; }

    DrawNode* m_draw; // 画出移动路线
public:
    void move(float delta);      // 根据AI姿态移动
    void attack(float delta);    // 根据AI姿态发起探测或攻击
    void probe(float delta);     // 判断探测

    Tank* m_tank;    // 所控制的坦克
    Vec2 m_position; // 目标位置
    
    int m_attack;    // 坦克攻击设定
    int m_move;      // 坦克移动设定
    int m_probe;     // 敌人所在方向

    float m_prepare_fire;   // 攻击准备时间
    float m_attack_interval;// 距上次攻击时间
    float m_move_interval;  // 距上次移动时间
    float m_trace_interval; // 距上次寻路间隔
    float m_probe_interval; // 距上次探测时间
    
    std::list<Vec2> m_path;
    std::list<ProbeBullet*> m_list;
};