#ifndef __MAZE_H
#define __MAZE_H

#include "Stack.h"
#include "Queue.h"
const int max_h=25;
const int max_w=80;

class Maze{
public:
Maze();
Maze(Maze& other);
~Maze();
private:
char** maze;
};

#endif