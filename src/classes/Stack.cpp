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
void Stack::push(int h, int w, char ch)
{
    Node *temp = this->top;
    this->top = new Node(h, w, ch, temp);
}
void Stack::push(Node *other)
{
    other->next = this->top;
    this->top = other;
}
bool Stack::searchNodeInStack(int given_h, int given_w)
{
    bool flag = false;
    Stack temp;
    Node *curr = nullptr;
    while (!(this->isEmpty()) && flag == false)
    {
        Node *curr = this->top;
        if (given_h == curr->h && given_w == curr->w)
        {
            if (curr->ch == '$')
            {
                flag = true;
            }
        }
        else
        {
            curr = this->pop();
            temp.push(curr);
        }
    }
    while (!temp.isEmpty())
    {
        curr = temp.pop();
        this->push(curr);
    }
    return flag;
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
        temp = top;
        top = top->next;
        delete temp;
    }
}