#include "../../include/Stack.h"

Stack::Stack()
{
    top = nullptr;
}
Stack::~Stack()
{
    makeEmpty();
}
bool Stack::isEmpty()
{
    return (top == nullptr);
}
void Stack::push(int h, int w, char ch)
{
    top = new Node(this->top->h, this->top->w, this->top->ch, this->top->next);
}
Node *Stack::pop()
{
    if (Stack::isEmpty())
    {
        cout<<"Error stack is underflow!"<<endl;
        exit(1);
    }
    Node* temp;
    top=top->next;
    return(temp);//in temp we need to take the h,w and ch and then delete that node.
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
        temp = top;
        top = top->next;
        delete temp;
    }
}
