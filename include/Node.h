#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Node{
public:
friend class Stack;
Node()=delete;
Node(int h,int w,char ch,Node* next=nullptr);
Node(const Node& other);
~Node();
void insertAfter(Node* newNode);
Node* deleteAfter();
void setData(int h,int w);
void setChar(char ch);
void setNext(Node* next);
void getData(int& h,int& w) const;
Node* getNext() const;
char getChar() const;
private:
int h,w;
char ch;
Node* next;
};


#endif