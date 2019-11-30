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
void createMaze(int h,int w);
const char** getMaze() const;
bool ifValidMaze(char** maze,int h,int w);
int gethight() const;
int getwidth() const;
private:
char** maze;
int h,w;
};

#endif