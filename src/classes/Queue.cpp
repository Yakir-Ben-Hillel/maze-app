#include "../../include/Queue.h"
Queue::Queue(int h, int w) : size(h * w)
{
    head = 1;
    tail = 0;
    this->data = new Point[h * w];
}
Queue::~Queue()
{
    this->makeEmpty();
    delete[] this->data;
}
Point Queue::front()
{
    return this->data[head];
}
int Queue::addOne(int x)
{
    return ((1 + x) % this->size);
}
bool Queue::isEmpty(void)
{
    return (addOne(tail) == head);
}
void Queue::makeEmpty()
{
    head = 1;
    tail = 0;
}
void Queue::enQueue(int h, int w)
{
    if ((addOne(addOne(tail)) == head))
    {
        cout << "Error: QUEUE FULL" << endl;
        exit(1);
    }
    tail = addOne(tail);
    Point p(h, w);
    data[tail] = p;
}
Point Queue::deQueue(void)
{
    if (isEmpty())
    {
        cout << "Error: QUEUE EMPTY" << endl;
        exit(1);
    }
    Point item = data[head];
    head = addOne(head);
    return item;
}