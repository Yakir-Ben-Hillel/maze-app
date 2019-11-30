#include "../../include/stack.h"

Stack::Stack()
{
    this->top = nullptr;
}
Stack::~Stack()
{
    this->makeEmpty();
}
void Stack::makeEmpty(void)
{
    Node *temp;
    while (this->top == nullptr)
    {
        temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}
void Stack::push(Type item)
{
    this->top = new Node(item, this->top);
}
Type Stack::pop(void)
{
    if (this->isEmpty())
    {
        cout << "Error:STACK UNDERFLOW" << endl;
        exit(1);
    }
    Node *temp = this->top;
    Type item = this->top->data;
    this->top = this->top->next;
    delete temp;
    return item;
}