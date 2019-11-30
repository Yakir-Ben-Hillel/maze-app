#ifndef __MAZE_H
#define __MAZE_H

#include "Stack.h"
#include "Queue.h"
const int max_h=25;
const int max_w=80;

class Maze{
public:
Maze(int h=max_h,int w=max_w);
Maze(Maze& other)=default;
~Maze();
void createMaze();
const char** getMaze() const;
bool ifValidMaze(char** maze,int h,int w);
int gethight() const;
int getwidth() const;
bool hasNeighbors(int curr_h,int curr_w);
private:
char** maze;
int h,w;
};

#endif