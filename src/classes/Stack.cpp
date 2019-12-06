#include "../../include/Stack.h"

Stack::Stack()
{
    this->top = nullptr;
}
Stack::~Stack()
{
    makeEmpty();
}
bool Stack::isEmpty()
{
    return (top == nullptr);
}
void Stack::push(int h, int w)
{
    Node *temp = this->top;
    this->top = new Node(h, w,temp);
}
void Stack::push(Node *other)
{
    other->next = this->top;
    this->top = other;
}
Node *Stack::pop()
{
    if (Stack::isEmpty())
    {
        cout << "Error stack is underflow!" << endl;
        exit(1);
    }
    Node *temp = top;
    top = top->next;
    return (temp); //in temp we need to take the h,w and ch and then delete that node.
}
Node *Stack::Top() const
{
    return top;
}
void Stack::makeEmpty()
{
    Node *temp;
    while (this->top != nullptr)
    {
        temp = this->top;
        this->top = this->top->next;
        delete (temp);
    }
}