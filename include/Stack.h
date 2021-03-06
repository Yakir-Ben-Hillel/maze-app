#ifndef __STACK_H
#define __STACK_H

#include "./Node.h"

class Stack
{
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int h, int w);
    void push(Node* node);
    Node *pop();
    Node *Top() const;
    void makeEmpty();

private:
    Node *top;
};
#endif