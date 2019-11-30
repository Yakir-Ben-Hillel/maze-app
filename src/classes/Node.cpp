#include "../../include/node.h"
Node::Node()
{
    next = nullptr;
}
Node::Node(Type item, Node *ptr)
{
    data = item;
    next = ptr;
}
void Node::insertAfter(Node *newnode)
{
    newnode->next = this->next;
    this->next = newnode;
}
Node *Node::DeleteAfter(void)
{
    Node *temp = this->next;
    if (this->next == nullptr)
        return nullptr;
    this->next = temp->next;
    return temp;
}