#ifndef __MAZE_H
#define __MAZE_H

#include "Stack.h"
#include "Queue.h"
const int max_h=25;
const int max_w=80;

class Maze{
public:
Maze(int h=max_h,int w=max_w,char** maze=nullptr);
Maze(Maze& other)=default;
~Maze();
void createMaze();//TODO
void solutionMaze();//TODO
void setMaze(char** maze);
char** getMaze() const;
friend bool ifValidMaze(char** maze,int h,int w);//TODO
int gethight() const;
int getwidth() const;
friend void showMaze(const char** maze,int h,int w);
private:
char** maze;
int h,w;
bool hasNeighbors(int curr_h,int curr_w);//TODO
};

#endif