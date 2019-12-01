#include "../../include/Maze.h"

Maze::Maze(int h , int w )
{
    this->maze = new char *[h];
    for (int x = 0; x < w; x++)
    {
        this->maze[x] = new char[w];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            this->maze[h][w] = '*';
        }
    }
    this->maze[1][0] = ' ';
    this->maze[h - 2][w - 1] = ' ';
}
Maze::~Maze()
{
    for (int i = 0; i < this->h; i++)
    {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}
const char **Maze::getMaze() const
{
    return this->maze;
}

int Maze::gethight() const
{
    return this->h;
}
int Maze::getwidth() const
{
    return this->w;
}

void Maze::createMaze()
{
    //in the constractor we make the full maze so,we already know that the member from the main who call this function is a full maze.
    Stack s;
    int curr_h,curr_w;
    s.push(1,1,'*');//setting the stack to the first element in the maze.
    while(!s.isEmpty)
    {
        Node* temp;
        temp=s.pop();
        temp->getData(curr_h,curr_w);//updating the curr_h and curr_w by ref
        this->maze[curr_h][curr_w]=' ';//mark the point we popped from the stack
        if(hasNeighbors(curr_h,curr_w))
        {

        }
    }
}

bool Maze::hasNeighbors(int curr_h,int curr_w)
{

}