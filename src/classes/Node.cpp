#include "../../include/Node.h"

Node::Node(int h, int w, char ch, Node *next) : h(h), w(w), ch(ch)
{
    this->next = next;
}
Node::~Node()
{
    this->next = nullptr;
}
Node::Node(const Node &node)
{
    setData(node.h, node.w);
    setChar(node.ch);
    setNext(node.next);
}
void Node::insertAfter(Node *newNode)
{
    newNode->next = this->next;
    this->next = newNode;
}
Node *Node::deleteAfter()
{
    Node *temp = this->next;
    if (this->next == nullptr)
        return nullptr;
    this->next = temp->next;
    return (temp);
}
void Node::setData(int h, int w)
{
    this->h = h;
    this->w = w;
}
void Node::setNext(Node *next)
{
    this->next = next;
}
void Node::setChar(char ch)
{
    this->ch = ch;
}
void Node::getData(int &h, int &w) const
{
    h = this->h;
    w = this->w;
}
Node *Node::getNext() const
{
    return this->next;
}
char Node::getChar() const
{
    return this->ch;
}