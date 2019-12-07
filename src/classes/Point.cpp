#include "../../include/Point.h"
Point::Point()
{
    this->h = 1;
    this->w = 0;
}
Point::Point(int h, int w)
{
    setPoint(h, w);
}
Point::Point(Point &other)
{
    this->h = other.h;
    this->w = other.w;
}
void Point::getPoint(int &h, int &w) const
{
    h = this->h;
    w = this->w;
}
void Point::setPoint(int h, int w)
{
    this->h = h;
    this->w = w;
}