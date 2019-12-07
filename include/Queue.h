#ifndef __QUEUE_H
#define __QUEUE_H
const int MAX_SIZE = 2000;
#include "./Point.h"
class Queue
{
public:
    Queue();
    ~Queue();
    void makeEmpty(void);
    bool isEmpty(void);
    Point front(void);
    void enQueue(Point item);
    Point deQueue(void);

private:
    int head, tail;
    Point data[MAX_SIZE];
    static int addOne(int x);
};
#endif