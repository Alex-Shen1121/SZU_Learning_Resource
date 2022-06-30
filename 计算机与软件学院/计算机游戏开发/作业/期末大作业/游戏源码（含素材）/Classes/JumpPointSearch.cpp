#include "JumpPointSearch.h"

bool JumpPointSearch::solve(Vec2 start, Vec2 destination, std::list<Vec2>(&path))
{
    Int2D s = convert(start);
    Int2D d = convert(destination);

    JumpPointSearch* jps = new JumpPointSearch(s, d);
    JumpPoint* jp = jps->main_loop();

    path.clear();
    while (jp && jp->parent != nullptr)
    {
        path.push_back(convert(jp->x, jp->y));
        jp = jp->parent;
    }

    delete jps;
    if (path.empty())
        return false;
    else
        return true;
}

JumpPointSearch::JumpPoint::JumpPoint(JumpPoint *parent, int vx,int vy, float value)
    :parent(parent), x(vx), y(vy), value(value)
{
}

JumpPointSearch::JumpPoint::JumpPoint(JumpPoint *parent, Int2D point, float value)
    :parent(parent), x(point.x), y(point.y), value(value)
{
}

JumpPointSearch::JumpPointSearch(Int2D start, Int2D destination)
    :m_start(start), m_destination(destination)
{
    int** map = MapManager::block_map;
    m_status_map = new decltype(*map + 0)[SEARCH_WIDTH];
    for (int i = 0; i < SEARCH_WIDTH; ++i)
    {
        m_status_map[i] = new decltype(**map + 0)[SEARCH_HEIGHT];
        for (int j = 0; j < SEARCH_HEIGHT; ++j)
        {
            bool flag[4] = {
                map[i][j] != MapManager::Block_Access && map[i][j] != MapManager::Block_Guard,
                map[i + 1][j] != MapManager::Block_Access && map[i + 1][j] != MapManager::Block_Guard,
                map[i][j + 1] != MapManager::Block_Access && map[i][j + 1] != MapManager::Block_Guard,
                map[i + 1][j + 1] != MapManager::Block_Access && map[i + 1][j + 1] != MapManager::Block_Guard
            };
            if (flag[0] || flag[1] || flag[2] || flag [3])
                m_status_map[i][j] = SEARCH_BLOCKED;
            else
                m_status_map[i][j] = SEARCH_ACCESS;
        }
    }

    m_open_list.push_back(new JumpPoint(nullptr, m_start, 0.0));
}

JumpPointSearch::~JumpPointSearch()
{
    if (m_status_map)
    {
        for (int i = 0; i < SEARCH_WIDTH; ++i)
            delete m_status_map[i];
        delete m_status_map;
    }

    for (JumpPoint* p : m_open_list)
        delete p;

    for (JumpPoint* p : m_close_list)
        delete p;
}

JumpPointSearch::JumpPoint* JumpPointSearch::main_loop()
{
    while (!m_open_list.empty())
    {
        // 选取权值最低结点
        auto it = m_open_list.begin();
        for (auto i = it; i != m_open_list.end(); ++i)
        {
            if ((*i)->value < (*it)->value)
                it = i;
        }
        auto select = *it;
        m_close_list.push_back(*it);
        m_open_list.erase(it);
        Int2D point;
        int& x = select->x, & y = select->y;

        // 直线搜索
        bool (JumpPointSearch:: * search_line[4])(int, int, Int2D*) =
        {
            &JumpPointSearch::search_up,
            &JumpPointSearch::search_down,
            &JumpPointSearch::search_left,
            &JumpPointSearch::search_right
        };
        for (int i = 0; i < 4; ++i)
        {
            if ((this->*search_line[i])(x, y, &point))
            {
                auto j = new JumpPoint(select, point, count_value(point));
                m_open_list.push_back(j);
                if (point == m_destination)
                    return j;
            }
        }

        // 添加对角方格-逆时针优先
        bool flag[4] =
        {
            y - 1 > 0 && m_status_map[x][y - 1] != SEARCH_BLOCKED,               // 0上
            y + 1 < SEARCH_HEIGHT && m_status_map[x][y + 1] != SEARCH_BLOCKED,   // 1下
            x - 1 > 0 && m_status_map[x - 1][y] != SEARCH_BLOCKED,               // 2左
            x + 1 < SEARCH_WIDTH && m_status_map[x + 1][y] != SEARCH_BLOCKED     // 3右
        };
        if (flag[0] && flag[2] && m_status_map[x - 1][y - 1] == SEARCH_ACCESS)   //左上
        {
            m_status_map[x - 1][y - 1] = SEARCH_FOUND;
            JumpPoint* mid = new JumpPoint(select, x, y - 1, count_value(x, y - 1));
            m_close_list.push_back(mid);
            m_open_list.push_back(new JumpPoint(mid, x - 1, y - 1, count_value(x - 1, y - 1)));
            if (m_destination.x == x && m_destination.y == y)
                return m_open_list.back();
        }
        if (flag[0] && flag[3] && m_status_map[x + 1][y - 1] == SEARCH_ACCESS)   //右上
        {
            m_status_map[x + 1][y - 1] = SEARCH_FOUND;
            JumpPoint* mid = new JumpPoint(select, x + 1, y, 0.0);
            m_close_list.push_back(mid);
            m_open_list.push_back(new JumpPoint(mid, x + 1, y - 1, count_value(x + 1, y - 1)));
            if (m_destination.x == x && m_destination.y == y)
                return m_open_list.back();
        }
        if (flag[1] && flag[2] && m_status_map[x - 1][y + 1] == SEARCH_ACCESS)   //左下
        {
            m_status_map[x - 1][y + 1] = SEARCH_FOUND;
            JumpPoint* mid = new JumpPoint(select, x - 1, y, 0.0);
            m_close_list.push_back(mid);
            m_open_list.push_back(new JumpPoint(mid, x - 1, y + 1, count_value(x - 1, y + 1)));
            if (m_destination.x == x && m_destination.y == y)
                return m_open_list.back();
        }
        if (flag[1] && flag[3] && m_status_map[x + 1][y + 1] == SEARCH_ACCESS)   //右下
        {
            m_status_map[x + 1][y + 1] = SEARCH_FOUND;
            JumpPoint* mid = new JumpPoint(select, x, y + 1, 0.0);
            m_close_list.push_back(mid);
            m_open_list.push_back(new JumpPoint(mid, x + 1, y + 1, count_value(x + 1, y + 1)));
            if (m_destination.x == x && m_destination.y == y)
                return m_open_list.back();
        }
    }
    return nullptr;
}

bool JumpPointSearch::search_up(int x, int y, Int2D* point)
{
    for (int j = y - 1; j > 0; --j)
    {
        if (m_status_map[x][j] != SEARCH_ACCESS)
            return false;
        m_status_map[x][j] = SEARCH_FOUND;
        bool flag[3] = // 是否有强迫邻居
        {
            x == m_destination.x && j == m_destination.y,
            x - 1 > 0 && m_status_map[x - 1][j + 1] == SEARCH_BLOCKED
            && m_status_map[x - 1][j] == SEARCH_ACCESS,
            x + 1 < SEARCH_WIDTH && m_status_map[x + 1][j + 1] == SEARCH_BLOCKED
            && m_status_map[x + 1][j] == SEARCH_ACCESS
        };
        if (flag[0] || flag[1] || flag[2])
        {
            point->x = x;
            point->y = j;
            return true;
        }
    }
    return false;
}

bool JumpPointSearch::search_down(int x, int y, Int2D* point)
{
    for (int j = y + 1; j < SEARCH_HEIGHT; ++j)
    {
        if (m_status_map[x][j] != SEARCH_ACCESS)
            return false;
        m_status_map[x][j] = SEARCH_FOUND;
        bool flag[3] = // 是否有强迫邻居
        {
            x == m_destination.x && j == m_destination.y,
            x - 1 > 0 && m_status_map[x - 1][j - 1] == SEARCH_BLOCKED
            && m_status_map[x - 1][j] == SEARCH_ACCESS,
            x + 1 < SEARCH_WIDTH && m_status_map[x + 1][j - 1] == SEARCH_BLOCKED
            && m_status_map[x + 1][j] == SEARCH_ACCESS
        };
        if (flag[0] || flag[1] || flag[2])
        {
            point->x = x;
            point->y = j;
            return true;
        }
    }
    return false;
}

bool JumpPointSearch::search_left(int x, int y, Int2D* point)
{
    for (int i = x - 1; i > 0; --i)
    {
        if (m_status_map[i][y] != SEARCH_ACCESS)
            return false;
        m_status_map[i][y] = SEARCH_FOUND;
        bool flag[3] = // 是否有强迫邻居
        {
            i == m_destination.x && y == m_destination.y,
            y - 1 > 0 && m_status_map[i + 1][y - 1] == SEARCH_BLOCKED
            && m_status_map[i][y - 1] == SEARCH_ACCESS,
            y + 1 < SEARCH_HEIGHT && m_status_map[i + 1][y + 1] == SEARCH_BLOCKED
            && m_status_map[i][y + 1] == SEARCH_ACCESS
        };
        if (flag[0] || flag[1] || flag[2])
        {
            point->x = i;
            point->y = y;
            return true;
        }
    }
    return false;
}

bool JumpPointSearch::search_right(int x, int y, Int2D* point)
{
    for (int i = x + 1; i < SEARCH_WIDTH; ++i)
    {
        if (m_status_map[i][y] != SEARCH_ACCESS)
            return false;
        m_status_map[i][y] = SEARCH_FOUND;
        bool flag[3] = // 是否有强迫邻居
        {
            i == m_destination.x && y == m_destination.y,
            y - 1 > 0 && m_status_map[i - 1][y - 1] == SEARCH_BLOCKED
            && m_status_map[i][y - 1] == SEARCH_ACCESS,
            y + 1 < SEARCH_HEIGHT && m_status_map[i - 1][y + 1] == SEARCH_BLOCKED
            && m_status_map[i][y + 1] == SEARCH_ACCESS
        };
        if (flag[0] || flag[1] || flag[2])
        {
            point->x = i;
            point->y = y;
            return true;
        }
    }
    return false;
}

float JumpPointSearch::count_value(Int2D point)
{
    return count_value(point.x, point.y);
}

float JumpPointSearch::count_value(int x, int y)
{
    return fabsf(m_start.x - x) + fabsf(m_start.y - y)
        + fabsf(m_destination.x - x) + fabsf(m_destination.y - y);
}

JumpPointSearch::Int2D JumpPointSearch::convert(Vec2 point)
{
    return { int(point.x - 8.0) / MAP_TILE_SIZE,int(MAP_HEIGHT * MAP_TILE_SIZE - point.y - 8.0) / MAP_TILE_SIZE };
}

Vec2 JumpPointSearch::convert(Int2D point)
{
    return convert(point.x, point.y);
}

Vec2 JumpPointSearch::convert(int x, int y)
{
    return { x * MAP_TILE_SIZE + 16.0f, MAP_HEIGHT * MAP_TILE_SIZE - y * MAP_TILE_SIZE - 16.0f };
}

