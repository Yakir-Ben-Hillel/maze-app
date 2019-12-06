#ifndef __MAZE_H
#define __MAZE_H

#include "Stack.h"
#include "Queue.h"
const int max_h=25;
const int max_w=80;

class Maze{
public:
Maze(int h=max_h,int w=max_w,char** maze=nullptr);
~Maze();
void createMaze();
void setMaze(char** maze);
char** getMaze() const;
int gethight() const;
int getwidth() const;
void showMaze();
private:
char** maze;
int h,w;
bool hasNeighbors(int curr_h,int curr_w,int& neighbor_h,int& neighbor_w,Node& curr);
};

#endif