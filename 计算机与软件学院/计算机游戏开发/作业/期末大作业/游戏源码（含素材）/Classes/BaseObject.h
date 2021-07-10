#pragma once

#include "cocos2d.h"
#include "Global.h"
USING_NS_CC;
using namespace cocos2d;

class BaseObject : public Sprite
{
public:
    BaseObject() {};
    virtual ~BaseObject() {};

    CREATE_FUNC(BaseObject);
    virtual bool init();

    // set and get
    int		getLife() { return m_life; };
    float	getSpeed() { return m_speed; };
    int		getKind() { return m_kind; };
    int     getDirection() { return m_direction; };
    int     getLevel() { return m_level; };
    int     getID() { return m_ID; };
    int     getHindered() { return m_hindered; };
    Rect    getRect() { return m_rect; }

    void	setLife(int l) { m_life = l; };
    void	setSpeed(float s) { m_speed = s; };
    void    setDirection(float d) { m_direction = d; };
    void    setKind(int k) { m_kind = k; };
    void    setLevel(int lev) { m_level = lev; };
    void    setID(int id) { m_ID = id; };
    void    setHindered(int hindered) { m_hindered = hindered; };
    void    setRect(Rect rect) { m_rect = rect; }

private:
    int     m_ID;            // OBJECT的ID
    float   m_speed;         // OBJECT的移动速度
    int     m_life;          // OBJECT的生命值(或有效值)
    int     m_direction;     // OBJECT移动的方向
    int     m_kind;          // OBJECT所属的类型,在不同的派生类中有不同的意思
    int     m_level;         // OBJECT等级
    int     m_hindered;      // OBJECT在四个方向上是否受到阻碍up.down.left.right
    Rect    m_rect;
};
