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

    DrawNode* m_draw; // �����ƶ�·��
public:
    void move(float delta);      // ����AI��̬�ƶ�
    void attack(float delta);    // ����AI��̬����̽��򹥻�
    void probe(float delta);     // �ж�̽��

    Tank* m_tank;    // �����Ƶ�̹��
    Vec2 m_position; // Ŀ��λ��
    
    int m_attack;    // ̹�˹����趨
    int m_move;      // ̹���ƶ��趨
    int m_probe;     // �������ڷ���

    float m_prepare_fire;   // ����׼��ʱ��
    float m_attack_interval;// ���ϴι���ʱ��
    float m_move_interval;  // ���ϴ��ƶ�ʱ��
    float m_trace_interval; // ���ϴ�Ѱ·���
    float m_probe_interval; // ���ϴ�̽��ʱ��
    
    std::list<Vec2> m_path;
    std::list<ProbeBullet*> m_list;
};