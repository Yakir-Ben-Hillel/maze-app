#ifndef __STACK
#define __STACK
#include <iostream>
#include "./node.h"
typedef int Type;
using namespace std;
class Node;
class Stack
{
private:
    Node *top;

public:
    Stack() = default;
    ~Stack();
    void makeEmpty(void);
    int isEmpty(void);
    void push(Type item);
    Type pop(void);
    Type top(void);
};
#endif