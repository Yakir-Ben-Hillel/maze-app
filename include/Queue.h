#ifndef __QUEUE_H
#define __QUEUE_H
#include "./Maze.h"
class Queue
{
public:
    Queue(int h=25, int w=79);
    ~Queue();
    void makeEmpty(void);
    bool isEmpty(void);
    Point front(void);
    void enQueue(int h, int w);
    Point deQueue(void);

private:
    int head, tail;
    const int size;
    Point *data;
    int addOne(int x);
};
#endif