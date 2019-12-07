#ifndef __Point
#define __Point
#include "Maze.h"
class Point
{
public:
    Point() = default;
    Point(int h, int w);
    Point(Point &other);
    void getPoint(int &h, int &w) const;
    void setPoint(int h, int w);

private:
    int h, w;
};
#endif