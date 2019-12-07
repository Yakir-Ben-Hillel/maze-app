#ifndef __Point
#define __Point
class Point
{
public:
    Point();
    Point(int h, int w);
    Point(Point &other);
    void getPoint(int &h, int &w) const;
    void setPoint(int h, int w);

private:
    int h, w;
};
#endif