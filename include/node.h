#ifndef __NODE
#define __NODE
typedef int Type;
using namespace std;

class Node
{
public:
    Type data;
    Node *next;
    Node();
    Node(Type item, Node *ptr = nullptr);
    ~Node();
    void insertAfter(Node *newnode);
    Node *DeleteAfter(void);
};
#endif