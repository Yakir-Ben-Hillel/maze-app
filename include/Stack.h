#ifndef __STACK_H
#define __STACK_H

#include "./Node.h"

class Stack
{
public:
    Stack();
    ~Stack();
    bool isEmpty();
    bool searchNodeInStack(int given_h, int given_w);
    void push(int h, int w, char ch);
    void push(Node* node);
    Node *pop();
    Node *Top() const;
    void makeEmpty();

private:
    Node *top;
};
#endif