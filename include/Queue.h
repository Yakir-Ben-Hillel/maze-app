#ifndef __QUEUE_H
#define __QUEUE_H

class Queue{
public:
Queue();
~Queue();
void makeEmpty();
bool isEmpty();
void EnQueue(int h,int w,char data);
void DeQueue(int& p_h,int& p_w);//we get two addresses and set the values 
private:
char queue_data;//if the data is '*' or ' ' or '$'
int h,w;//the place of the object in the maze
int head,tail;//head and tail of the queue
static int AddOne(int x);
};
#endif