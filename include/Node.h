#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

class Node{
public:
friend class Stack;//we allow to class stack to access the nodes private members 
Node()=delete;
Node(int h,int w,Node* next=nullptr);
Node(const Node& other);
~Node();
void insertAfter(Node* newNode);
Node* deleteAfter();
void setData(int h,int w);
void setNeighborPlace(int i);
bool getNeighborPlace(int i) const;
void setNext(Node* next);
void getData(int& h,int& w) const;
Node* getNext() const;
private:
int h,w;
bool neighbors[4];//every node in the maze knows what neighbors he already visited or didn't visit,by this order: up,left,down,right ,also if it is false this point did not visit the current neighbor
Node* next;
};


#endif