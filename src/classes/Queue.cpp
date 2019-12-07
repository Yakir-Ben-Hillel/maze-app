#include "../../include/Queue.h"
Queue::Queue()
{
    head = 1;
    tail = 0;
}
Queue::~Queue()
{
    this->makeEmpty();
}
Point Queue::front()
{
    return this->data[head];
}
int Queue::addOne(int x)
{
    return ((1 + x) % MAX_SIZE);
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
void Queue::enQueue(Point item)
{
    if (addOne(addOne(tail) == head))
    {
        cout << "Error: QUEUE FULL" << endl;
        exit(1);
    }
    tail = addOne(tail);
    data[tail] = item;
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