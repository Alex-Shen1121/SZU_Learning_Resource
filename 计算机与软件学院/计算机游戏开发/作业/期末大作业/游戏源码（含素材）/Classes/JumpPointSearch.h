#pragma once

#include "cocos2d.h"
#include "MapManager.h"
USING_NS_CC;
using namespace cocos2d;

#define SEARCH_UP 1
#define SEARCH_DOWN 2
#define SEARCH_LEFT 3
#define SEARCH_RIGHT 4

#define SEARCH_BLOCKED 0
#define SEARCH_ACCESS 1
#define SEARCH_FOUND 2

#define SEARCH_WIDTH 59
#define SEARCH_HEIGHT 39

class JumpPointSearch
{
    struct Int2D
    {
        bool operator==(const Int2D& it) { return x == it.x && y == it.y; }

        int x, y;
    };

    struct JumpPoint
    {
        JumpPoint(JumpPoint* parent, int vx, int vy, float value);
        JumpPoint(JumpPoint* parent, Int2D point, float value);
        
        JumpPoint* parent;
        int x, y;
        float value;
    };

public:
    static bool solve(Vec2 start, Vec2 destination, std::list<Vec2>(&path));

private:
    JumpPointSearch(Int2D start, Int2D destination);
    ~JumpPointSearch();

    JumpPoint* main_loop();

    bool search_up(int x, int y, Int2D* point);
    bool search_down(int x, int y, Int2D* point);
    bool search_left(int x, int y, Int2D* point);
    bool search_right(int x, int y, Int2D* point);

    float count_value(Int2D point);
    float count_value(int x, int y);

    static Int2D convert(Vec2 point);
    static Vec2 convert(Int2D point);
    static Vec2 convert(int x, int y);

    
    std::list<JumpPoint*> m_open_list;
    std::list<JumpPoint*> m_close_list;
    int** m_status_map;
    Int2D m_start;
    Int2D m_destination;
};